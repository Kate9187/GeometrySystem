#pragma once
#include <cmath>
#include <string>
#include <sstream> 
#include <iomanip> 

struct Point3D {
    double x;
    double y;
    double z;

    // Расстояние между двумя точками
    double distanceTo(const Point3D& other) const {
        return std::sqrt(
            (x - other.x) * (x - other.x) +
            (y - other.y) * (y - other.y) +
            (z - other.z) * (z - other.z));
    }

    // Скалярное произведение 
    double dot(const Point3D& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    // Векторное произведение
    Point3D cross(const Point3D& other) const {
        return {
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        };
    }


    // Оператор вычитания 
    Point3D operator-(const Point3D& other) const {
        return { x - other.x, y - other.y, z - other.z };
    }

    std::string toString() const {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(1);
        oss << "(" << x << ", " << y << ", " << z << ")";
        return oss.str();
    }
};