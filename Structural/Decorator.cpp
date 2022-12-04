#include <iostream>
#include <string>

// Component
class IceCream
{
public:
    virtual int kcal() = 0;
    virtual int price() = 0;
};

// Concrete Component
class ClassicIceCream : public IceCream
{
public:
    int kcal()
    {
        return 100;
    }

    int price()
    {
        return 50;
    }
};

// Decorator
class IceCreamDecorator : public IceCream
{
protected:
    IceCream *iceCream;
public:
    IceCreamDecorator(IceCream *baseIceCream) : iceCream(baseIceCream) {}

    int kcal()
    {
        return iceCream->kcal();
    }

    int price()
    {
        return iceCream->price();
    }
};

// Concrete Decorator
class ChocolateIceCream : public IceCreamDecorator
{
public:
    ChocolateIceCream(IceCream *baseIceCream) : IceCreamDecorator(baseIceCream) {}

    int kcal()
    {
        return iceCream->kcal() + 50;
    }

    int price()
    {
        return iceCream->price() + 50;
    }
};

class VanillaIceCream : public IceCreamDecorator
{
public:
    VanillaIceCream(IceCream *baseIceCream) : IceCreamDecorator(baseIceCream) {}

    int kcal()
    {
        return iceCream->kcal() + 40;
    }

    int price()
    {
        return iceCream->price() + 40;
    }
};

int main()
{
    IceCream *classicIceCream = new ClassicIceCream();
    std::cout << "Classic Ice Cream" << std::endl;
    std::cout << "Kcal: " << classicIceCream->kcal() << "\tPrice: " << classicIceCream->price() << std::endl;

    IceCream *decoratedIceCream = new ChocolateIceCream(classicIceCream);
    std::cout << "Chocolate Ice Cream" << std::endl;
    std::cout << "Kcal: " << decoratedIceCream->kcal() << "\tPrice: " << decoratedIceCream->price() << std::endl;
    delete decoratedIceCream;

    decoratedIceCream = new VanillaIceCream(classicIceCream);
    std::cout << "Vanilla Ice Cream" << std::endl;
    std::cout << "Name: " << decoratedIceCream->kcal() << "\tPrice: " << decoratedIceCream->price() << std::endl;
    delete decoratedIceCream;
    delete classicIceCream;

    return 0;
}
