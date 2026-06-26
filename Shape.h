#pragma once
#include <string>
#include <sstream>    
#include <iomanip>

class Shape {
public:
	virtual ~Shape() = default;
	virtual double area() const = 0; // вычисление площади.
	virtual double perimeter() const = 0;// вычисление периметра.
	virtual std::string info() const = 0; //возвращает строку с параметрами фигуры (тип, координаты вершин, площадь, периметр)
};