#include <iostream>
#include <memory>
#include <iomanip>

#include "Scene.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Group.h"
#include "Point3D.h"

int main()
{
    std::cout << std::fixed << std::setprecision(2);

    try
    {
        // Создание нескольких фигур
        auto circle = std::make_unique<Circle>(5.0, Point3D{ 0.0, 0.0, 0.0 });
        auto triangle = std::make_unique<Triangle>(
            Point3D{ 0.0, 0.0, 0.0 },
            Point3D{ 3.0, 0.0, 0.0 },
            Point3D{ 0.0, 4.0, 0.0 }
        );
        auto rectangle = std::make_unique<Rectangle>(
            Point3D{ 0.0, 0.0, 0.0 },
            Point3D{ 4.0, 0.0, 0.0 },
            Point3D{ 4.0, 2.0, 0.0 },
            Point3D{ 0.0, 2.0, 0.0 }
        );

        // Добавление фигур в сцену
        Scene scene;
        scene.addShape(std::move(circle));
        scene.addShape(std::move(triangle));
        scene.addShape(std::move(rectangle));

        // Создание группы и добавление в неё фигур
        auto group = std::make_unique<Group>();
        group->addShape(std::make_unique<Circle>(2.5, Point3D{ 1.0, 1.0, 0.0 }));
        group->addShape(std::make_unique<Rectangle>(
            Point3D{ 1.0, 1.0, 0.0 },
            Point3D{ 3.0, 1.0, 0.0 },
            Point3D{ 3.0, 2.0, 0.0 },
            Point3D{ 1.0, 2.0, 0.0 }
        ));

        // Добавление группы как фигуры в сцену
        scene.addShape(std::move(group));

        // Вывод информации всех фигур
        std::cout << "All shapes in scene:" << std::endl;
        scene.printAllInfo();
        std::cout << "Total area of scene: " << scene.totalArea() << std::endl;

        // Удаление одной фигуры из сцены
        std::cout << "\nRemoving shape with index 1\n" << std::endl;
        scene.removeShape(1);

        // Повторный вывод информации после удаления
        std::cout << "Scene after removal:" << std::endl;
        scene.printAllInfo();
        std::cout << "Total area of scene: " << scene.totalArea() << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    std::cout << "\nPress Enter to exit\n" << std::endl;
    std::cin.get();
    return 0;
}