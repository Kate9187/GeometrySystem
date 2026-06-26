#include <sstream> 
#include <iomanip> 
#include "Rectangle.h"

Rectangle::Rectangle(Point3D vA, Point3D vB, Point3D vC, Point3D vD) 
    : vertexA(vA), vertexB(vB), vertexC(vC), vertexD(vD) {
    if (!checkRightAngles(vA, vB, vC, vD)) {
        throw std::invalid_argument("Invalid rectangle vertices: all angles must be 90 degrees");
    }
}

void Rectangle::setVertices(Point3D vA, Point3D vB, Point3D vC, Point3D vD) {
    if (!checkRightAngles(vA, vB, vC, vD)) {
        throw std::invalid_argument("Invalid rectangle vertices: all angles must be 90 degrees");
    }
    vertexA = vA;
    vertexB = vB;
    vertexC = vC;
    vertexD = vD;
}

std::array<Point3D, 4> Rectangle::getVertices() const {
    return { vertexA, vertexB, vertexC, vertexD };
}
// Проверяет, что все углы прямоугольника равны 90 градусам
// Использует скалярное произведение векторов: если dot = 0, угол = 90°
bool Rectangle::checkRightAngles(Point3D vA, Point3D vB, Point3D vC, Point3D vD) {
    const double EPSILON = 1e-6;

    Point3D BA = vA - vB;
    Point3D BC = vC - vB;
    if (std::abs(BA.dot(BC)) > EPSILON) return false;

    Point3D CB = vB - vC;
    Point3D CD = vD - vC;
    if (std::abs(CB.dot(CD)) > EPSILON) return false;

    Point3D DC = vC - vD;
    Point3D DA = vA - vD;
    if (std::abs(DC.dot(DA)) > EPSILON) return false;

    Point3D AD = vD - vA;
    Point3D AB = vB - vA;
    if (std::abs(AD.dot(AB)) > EPSILON) return false;

    return true;
}


double Rectangle::area() const {
    double side1 = vertexA.distanceTo(vertexB);
    double side2 = vertexB.distanceTo(vertexC);
    return side1 * side2;
}


double Rectangle::perimeter() const {
    double side1 = vertexA.distanceTo(vertexB);
    double side2 = vertexB.distanceTo(vertexC);
    return 2 * (side1 + side2);
}

std::string Rectangle::info() const {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1);
    oss << "Rectangle: vertices = A" << vertexA.toString()
        << ", B" << vertexB.toString()
        << ", C" << vertexC.toString()
        << ", D" << vertexD.toString()
        << ", area = " << area()
        << ", perimeter = " << perimeter();
    return oss.str();
}

