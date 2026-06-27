#define _USE_MATH_DEFINES
#include <cmath>
#include <stdexcept>
#include <sstream> 
#include <iomanip> 
#include "Circle.h"

Circle::Circle(double radius, Point3D center) : centerPoint(center) {
    if (radius <= 0.0) {
        throw std::invalid_argument("Radius must be a positive value");
    }
    else  this->radius = radius;
}

double Circle::getRadius() const {
    return radius;
}

void Circle::setRadius(double r) {
    if (r <= 0.0) throw std::invalid_argument("Radius must be positive");
    else radius = r;
}

Point3D Circle::getCenterPoint() const {
    return centerPoint;
}

void Circle::setCenterPoint(Point3D c) {
    centerPoint = c;
}

double Circle::area() const {
    return M_PI * radius * radius;
}

double Circle::perimeter() const {
    return 2 * M_PI * radius;
}

std::string Circle::info() const {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1);
    oss << "Circle: radius = " << radius
        << ", center = " << centerPoint.toString() 
        << ", area = " << area()
        << ", perimeter = " << perimeter();
    return oss.str();
}