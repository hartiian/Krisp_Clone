#include <iostream>

class Shape 
{
public:
    virtual double cal() const = 0; 
	virtual ~Shape() {} 
};

class Circle : public Shape 
{
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    virtual double cal() const override 
    {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape 
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}
    virtual double cal() const override 
    {
        return length * width; 
    }
};

int main() 
{
    Circle circle(14.0);
    Rectangle rectangle(7.0, 6.0);
    std::cout << "Circle: " << circle.cal() << std::endl;
    std::cout << "Rectangle: " << rectangle.cal() << std::endl;
    return 0;
}
