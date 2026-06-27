#pragma once
#include <string>
#include <array>
#include <sstream>    
#include <iomanip>
#include "Shape.h"
#include "Point3D.h"

class Triangle : public Shape
{
private:
    Point3D vertexA, vertexB, vertexC;
    static bool isValidTriangle(Point3D, Point3D, Point3D);

public:
    Triangle(Point3D, Point3D, Point3D);

    double area() const override;
    double perimeter() const override;
    std::string info() const override;

    std::array<Point3D, 3> getVertices() const;

    void setVertices(Point3D, Point3D, Point3D);
};

