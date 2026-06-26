#include "Scene.h"
#include <iostream>

void Scene::addShape(std::unique_ptr<Shape> shape)
{
    if (!shape)
    {
        throw std::invalid_argument("Cannot add null shape to scene");
    }

    shapes.push_back(std::move(shape));
}

void Scene::removeShape(size_t index)
{
    if (index >= shapes.size())
    {
        throw std::out_of_range("Shape index is out of range");
    }

    shapes.erase(shapes.begin() + index);
}

void Scene::printAllInfo() const
{
    if (shapes.empty())
    {
        std::cout << "Scene is empty." << std::endl;
        return;
    }

    for (size_t i = 0; i < shapes.size(); i++)
    {
        std::cout << "Shape " << i << ":" << std::endl;
        std::cout << shapes[i]->info() << std::endl;
    }
}

double Scene::totalArea() const
{
    double total = 0.0;

    for (const auto& shape : shapes)
    {
        total += shape->area();
    }

    return total;
}