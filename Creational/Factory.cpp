#include <iostream>
#include <cmath>

class Square {
private:
    Square(double x) : x(x) {}

    class SquareFactory {
    public:
        static Square* CreateWithSides(double x)
        {
            Square* sq = new Square{ x };
            return sq;
        }

        static Square* CreateWithDiagonal(double x)
        {
            Square* sq = new Square{ sqrt(x*x / 2) };
            return sq;
        }

    private:
        SquareFactory() = default;
    };

public:
    double x;
    static SquareFactory Factory;
    
    void printArea()
    {
        std::cout << x << std::endl;
        std::cout << "Square area: " << x*x << std::endl;
    }

};

int main()
{
    auto sq1 = Square::Factory.CreateWithSides(10);
    sq1->printArea();
    
    auto sq2 = Square::Factory.CreateWithDiagonal(10);
    sq2->printArea();
}
