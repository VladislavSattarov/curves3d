#include "shapes.h"

Circle::Circle(double r)
{
    r >= 0 ? radius = r : throw std::invalid_argument("Radius must be positive");
}

Point Circle::GetPoint(double t) const
{
    return Point(radius * std::cos(t), radius * std::sin(t), 0);
}

Vector Circle::DerivativeVector(double t) const
{
    return Vector(-radius * std::sin(t), radius * std::cos(t), 0);
}

Ellipse::Ellipse(double r1, double r2)
{
    r1 >= 0 ? radius1 = r1 : throw std::invalid_argument("Radius1 must be positive");
    r2 >= 0 ? radius2 = r2 : throw std::invalid_argument("Radius2 must be positive");
}

Point Ellipse::GetPoint(double t) const
{
    return Point(radius1 * cos(t), radius2 * sin(t), 0);
}

Vector Ellipse::DerivativeVector(double t) const
{
    return Vector(-radius1 * sin(t), radius2 * cos(t), 0);
}

Helix::Helix(double r, double s)
{
    r >= 0 ? radius = r : throw std::invalid_argument("Radius must be positive");
    step = s;
}

Point Helix::GetPoint(double t) const
{
    return Point(radius * cos(t), radius * sin(t), step * t / (2 * PI));
}

Vector Helix::DerivativeVector(double t) const
{
    return Vector(-radius * sin(t), radius * cos(t), step / (2 * PI));
}

shared_ptr<Shape> RandomShapeGenerator::buildCircle(double r)
{
    return make_shared<Circle>(r);
}

shared_ptr<Shape> RandomShapeGenerator::buildEllipse(double r1, double r2)
{
    return make_shared<Ellipse>(r1, r2);
}

shared_ptr<Shape> RandomShapeGenerator::buildHelix(double r, double s)
{
    return make_shared<Helix>(r, s);
}

std::vector<std::shared_ptr<Shape>> RandomShapeGenerator::FillRandomShapesVector(unsigned count, double min, double max)
{
    std::vector<std::shared_ptr<Shape>> shapes;
    shapes.reserve(count);
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(min, max);
    uniform_int_distribution<int> distT(0, 2);
    for (size_t i = 0; i < count; i++)
    {
        unsigned t = distT(gen);
        switch (t)
        {
        case 0:
        {
            double r = dist(gen);
            shapes.push_back(buildCircle(r));
            break;
        }
        case 1:
        {
            double a = dist(gen);
            double b = dist(gen);
            shapes.push_back(buildEllipse(a, b));
            break;
        }
        case 2:
        {
            double r = dist(gen);
            double s = dist(gen);
            shapes.push_back(buildHelix(r, s));
            break;
        }
        }
    }
    return shapes;
}