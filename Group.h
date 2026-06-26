#pragma once
#include <memory>
#include <string>
#include <vector>
#include <sstream>   
#include <iomanip>
#include "Shape.h"

class Group : public Shape
{
private:
	std::vector<std::unique_ptr<Shape>> shapes;

public:
    Group() = default;

    // Запрещаем копирование
    Group(const Group&) = delete;
    Group& operator=(const Group&) = delete;

    // Разрешаем перемещение
    Group(Group&&) = default;
    Group& operator=(Group&&) = default;

    void addShape(std::unique_ptr<Shape> shape); //добавление фигуры в группу
    double area() const override; //сумма площадей дочерних фигур
    double perimeter() const override; //сумма периметров
    std::string info() const override;

};

