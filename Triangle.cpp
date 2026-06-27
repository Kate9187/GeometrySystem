#include <algorithm>
#include <cmath>
#include <sstream> 
#include <iomanip> 
#include "Triangle.h"

Triangle::Triangle(Point3D vA, Point3D vB, Point3D vC) :
    vertexA(vA), vertexB(vB), vertexC(vC){
    if (!isValidTriangle(vA, vB, vC)) {
        throw std::invalid_argument("Invalid triangle: vertices are collinear");
    }
}

void Triangle::setVertices(Point3D vA, Point3D vB, Point3D vC) {
    if (!isValidTriangle(vA, vB, vC)) {
        throw std::invalid_argument("Invalid triangle: vertices are collinear");
    }
    vertexA = vA;
    vertexB = vB;
    vertexC = vC;
}

// Проверяет валидность треугольника: три вершины не должны быть коллинеарны
bool Triangle::isValidTriangle(Point3D vA, Point3D vB, Point3D vC) {
    const double EPSILON = 1e-6;

    Point3D AB = vB - vA;
    Point3D AC = vC - vA;

    Point3D cross = AB.cross(AC);
    double magnitude = std::sqrt(cross.x * cross.x + cross.y * cross.y + cross.z * cross.z);

    return magnitude > EPSILON;
}


std::array<Point3D, 3> Triangle::getVertices() const {
    return { vertexA, vertexB, vertexC };
}

double Triangle::area() const {
    double a = vertexA.distanceTo(vertexB);
    double b = vertexB.distanceTo(vertexC);
    double c = vertexC.distanceTo(vertexA);

    double s = (a + b + c) / 2.0;
    double value = s * (s - a) * (s - b) * (s - c);
    return std::sqrt(std::max(0.0, value)); // защита от погрешности вычислений
}

double Triangle::perimeter() const {
    return vertexA.distanceTo(vertexB)
        + vertexB.distanceTo(vertexC)
        + vertexC.distanceTo(vertexA);
}

std::string Triangle::info() const {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1);
    oss << "Triangle: vertices = A" << vertexA.toString()
        << ", B" << vertexB.toString()
        << ", C" << vertexC.toString()
        << ", area = " << area()
        << ", perimeter = " << perimeter();
    return oss.str();
}