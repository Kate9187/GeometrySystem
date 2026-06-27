#pragma once

#include <array>
#include <string>
#include <sstream>    
#include <iomanip>
#include "Shape.h"
#include "Point3D.h"

class Rectangle : public Shape
{
private:
    Point3D vertexA, vertexB, vertexC, vertexD;
    static bool checkRightAngles(Point3D, Point3D, Point3D, Point3D);

public:
    Rectangle(Point3D, Point3D, Point3D, Point3D);
    double area() const override;
    double perimeter() const override;
    std::string info() const override;

    std::array<Point3D, 4> getVertices() const;

    void setVertices(Point3D, Point3D, Point3D, Point3D);
};

