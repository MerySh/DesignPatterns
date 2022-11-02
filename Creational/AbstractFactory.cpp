#include <iostream>

/* First Product Interface */
class Coffee {
public:
    virtual ~Coffee() = 0;
    virtual void makeCoffee() = 0;
};

/* Concrete First Products */
class IceCoffee : public Coffee {
public:
    ~IceCoffee() override = default;
    void makeCoffee() override 
    {
        std::cout << "Making ice coffee..." << std::endl;
    }
};

class HotCoffee : public Coffee {
public:
    ~HotCoffee() override = default;
    void makeCoffee() override 
    {
        std::cout << "Making hot coffee..." << std::endl;
    }
};

/* Second Product Interface */
class Tea {
public:
    virtual ~Tea() = 0;
    virtual void makeTea() = 0;
};

/* Concrete Second Products */
class IceTea : public Tea {
public:
    ~IceTea() override = default;
    void makeTea() override 
    {
        std::cout << "Making ice tea..." << std::endl;
    }
};

class HotTea : public Tea {
public:
    ~HotTea() override = default;
    void makeTea() override 
    {
        std::cout << "Making hot tea..." << std::endl;
    }
};

/* Abstract Factory */
class DrinkFactory {
public:
    virtual Coffee *CreateCoffee() = 0;
    virtual Tea *CreateTea() = 0;
};

/* Hot Drinks Factory */
class HotDrinksFactory : public DrinkFactory {
public:
    Coffee *CreateCoffee() override 
    {
        return new HotCoffee;
    }
    
    Tea *CreateTea() override
    {
        return new HotTea;
    }
};

/* Ice Drinks Factory */
class IceDrinksFactory : public DrinkFactory {
public:
    Coffee *CreateCoffee() override 
    {
        return new IceCoffee;
    }
    
    Tea *CreateTea() override
    {
        return new IceTea;
    }
};

/* Client Code */
void ClientCode(DrinkFactory &factory)
{
    Coffee *coffee = factory.CreateCoffee();
    Tea *tea = factory.CreateTea();

    coffee->makeCoffee();
    tea->makeTea();

    //delete coffee;
    //delete tea;
}

int main()
{
    std::cout << "_____Hot Drinks Factory_____" << std::endl;
    HotDrinksFactory *factory1 = new HotDrinksFactory();
    ClientCode(*factory1);
    //delete factory1;

    std::cout << std::endl << "_____Ice Drinks Factory_____" << std::endl;
    IceDrinksFactory *factory2 = new IceDrinksFactory();
    ClientCode(*factory2);
    //delete factory2;

    return 0;
}
