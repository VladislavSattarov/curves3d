#pragma once
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

using namespace std;
const double PI = acos(-1.0);

class Point
{
    double x, y, z;
public:
    void SetCoordinates(double x, double y, double z) { this->x = x; this->y = y; this->z = z; }
    Point(double x, double y, double z) { SetCoordinates(x, y, z); }
    void PrintPoint() { cout << "P = {" << this->x << ' ' << this->y << ' ' << this->z << '}' << "\n"; }
};

class Vector
{
    double x, y, z;
public:
    void SetCoordinates(double x, double y, double z) { this->x = x; this->y = y; this->z = z; }
    Vector(double x, double y, double z) { SetCoordinates(x, y, z); }
    void PrintVector() { cout << "V = {" << this->x << ' ' << this->y << ' ' << this->z << '}' << "\n"; }
};

class Shape
{
public:
    virtual Point GetPoint(double t) const = 0;
    virtual Vector DerivativeVector(double t) const = 0;
};

class Circle : public Shape
{
    double radius;
public:
    Circle(double r);
    virtual Point GetPoint(double t) const override;
    virtual Vector DerivativeVector(double t) const override;
    double GetRadius() const { return radius; }
};

class Ellipse : public Shape
{
    double radius1, radius2;
public:
    Ellipse(double r1, double r2);
    virtual Point GetPoint(double t) const override;
    virtual Vector DerivativeVector(double t) const override;
};

class Helix : public Shape
{
    double radius, step;
public:
    Helix(double r, double s);
    virtual Point GetPoint(double t) const override;
    virtual Vector DerivativeVector(double t) const override;
};

class RandomShapeGenerator {
public:
    shared_ptr<Shape> buildCircle(double r);
    shared_ptr<Shape> buildEllipse(double r1, double r2);
    shared_ptr<Shape> buildHelix(double r, double s);
    vector<shared_ptr<Shape>> FillRandomShapesVector(unsigned count, double min, double max);
};
