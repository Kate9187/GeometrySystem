#include <sstream>
#include <stdexcept>
#include <iomanip> 
#include "Group.h"

void Group::addShape(std::unique_ptr<Shape> shape)
{
    if (!shape)
    {
        throw std::invalid_argument("Cannot add null shape to group");
    }

    shapes.push_back(std::move(shape));
}

double Group::area() const
{
    double total = 0.0;

    for (const auto& shape : shapes)
    {
        total += shape->area();
    }

    return total;
}

double Group::perimeter() const
{
    double total = 0.0;

    for (const auto& shape : shapes)
    {
        total += shape->perimeter();
    }

    return total;
}


std::string Group::info() const
{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1);
    oss << "Group: " << shapes.size()
        << " shape(s), total area = " << area()
        << ", total perimeter = " << perimeter();

    if (!shapes.empty())
    {
        oss << "\nContained shapes:";
        for (size_t i = 0; i < shapes.size(); i++)
        {
            oss << "\n  [" << i << "] " << shapes[i]->info();
        }
    }

    return oss.str();
}