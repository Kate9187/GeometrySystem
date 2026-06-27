#pragma once
#include <memory>
#include <vector>
#include <cstddef>
#include "Shape.h"

class Scene
{
private:
	std::vector<std::unique_ptr<Shape>> shapes;

public:
	Scene() = default;

	// Запрещаем копирование и присваивание
	Scene(const Scene&) = delete;
	Scene& operator=(const Scene&) = delete;

	// Разрешаем перемещение
	Scene(Scene&&) = default;
	Scene& operator=(Scene&&) = default;

	void addShape(std::unique_ptr<Shape>); // добавление фигуры(владение передаётся сцене)
	void removeShape(size_t); // удаление фигуры по индексу.
	void printAllInfo() const; // вывод информации обо всех фигурах.
	double totalArea() const; // суммарная площадь всех фигур.
};

