#pragma once
#include "Shape.h"
#include <iostream>
class Circle :
    public Shape
{
private:
    int radius;
public:
    // Constructors
    Circle();
    Circle(int radius);
    Circle(Circle& otherCircle);
    // getters and setters
    void setRadius(int radius);
    int getRadius();
    double getArea();
    // operator overloads
    Circle& operator=(Circle& otherCircle);
    friend std::ostream& operator<<(std::ostream& strm, Circle& circle);
    std::ostream& draw(std::ostream& strm)const override;

};

