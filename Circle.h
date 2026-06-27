#pragma once
#include <string>
#include <sstream>   
#include <iomanip>
#include "Shape.h"
#include "Point3D.h"

class Circle : public Shape
{
private:
    double radius;
    Point3D centerPoint;

public:
    Circle(double, Point3D);

    double area() const override; 
    double perimeter() const override;
    std::string info() const override;

    double getRadius() const;
    void setRadius(double);
    Point3D getCenterPoint() const;
    void setCenterPoint(Point3D);
};

