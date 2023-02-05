#include <iostream>
#include "shape.h"

int main()
{
    Point2D p2d_1{ 1,2 }, p2d_2{ 3,4 };
    Line line(p2d_1, p2d_2);
    std::cout << "type = " << line.getType() << " coord: " << line.getPointA() << " " << line.getPointB() << std::endl;
    line.shift(3, 4);
    std::cout << "type = " << line.getType() << " coord: " << line.getPointA() << " " << line.getPointB() << std::endl;
    line.scaleZ(5);
    std::cout << "type = " << line.getType() << " coord: " << line.getPointA() << " " << line.getPointB() << std::endl;

    Circle circle (p2d_1, 8);
    std::cout << "type = " << circle.getType() << " coord: " << circle.getPointA() << " " << circle.getRadius() << std::endl;

    Sqr sqr(p2d_1, p2d_2);
    std::cout << "type = " << sqr.getType() << " coord: " << sqr.getPointA() << " " << sqr.getPointB() << std::endl;
    sqr.shift(3, 4);
    std::cout << "type = " << sqr.getType() << " coord: " << sqr.getPointA() << " " << sqr.getPointB() << std::endl;
    sqr.scaleZ(5);
    std::cout << "type = " << sqr.getType() << " coord: " << sqr.getPointA() << " " << sqr.getPointB() << std::endl;

    Cylinder cylinder(p2d_1, 9, 12);
    std::cout << "type = " << cylinder.getType() << " coord: " << cylinder.getPointA() << " " << cylinder.getRadius() << " " << cylinder.getHeight() << " " << cylinder.getVolume() << std::endl;

    Point3D p3d_1{ 0, 0, 0 }, p3d_2{ 0, 0, 1 }, p3d_3{0, 1, 0};
    Cube cube(p3d_1, p3d_2, p3d_3);
    std::cout << "type = " << cube.getType() << " coord: " << cube.getPointA() << " " << cube.getPointB() << " " << cube.getPointB() << std::endl;
    cube.shift(3, 4, 5);
    std::cout << "type = " << cube.getType() << " coord: " << cube.getPointA() << " " << cube.getPointB() << " " << cube.getPointB() << std::endl;
    cube.scaleZ(5);
    std::cout << "type = " << cube.getType() << " coord: " << cube.getPointA() << " " << cube.getPointB() << " " << cube.getPointB() << std::endl;

}

