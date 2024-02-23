#include <iostream>

class Shape 
{
public:
    virtual double cal() const { return 0; }
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
        return 3.14 * radius * radius;
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
void print(const Shape* ptr) 
{
    std::cout << "Area: " << ptr->cal() << std::endl;
}

int main() {
    Circle circle(7.0);
    Rectangle rectangle(15.0, 4.0);
    print(&circle);
    print(&rectangle);
    return 0;
}
