#include <iostream>
using namespace std;
//Abstract base class
class Shape
{
public:
    virtual double calculateArea() const = 0; //Pure virtual function

};

// Concrete derived class, Circle
class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r)
    {
        radius = r;
    }
    double calculateArea() const override //Implementation of the pure virtual function
    {
        return 3.14 * radius * radius;
    }
};

// Concrete derived class, Rectangle
class Rectangle : public Shape
{
private:
    double width;
    double height;

public:

    Rectangle(double w, double h)
    {
        width = w;
        height = h;
    }
    double calculateArea() const override  //Implementation of the pure virtual function
    {
        return width * height;
    }
};

int main()
{
    //Create objects of the derived classes
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);
    cout << "Circle Area: " << circle.calculateArea() << endl;
    cout << "Rectangle Area: " << rectangle.calculateArea() << endl;
    return 0;
}
