#include "shapes.h"
#include <memory>
#include <omp.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    unsigned size, min, max;
    cout << "Enter vector size, minimum and maximum values\n";
    cin >> size >> min >> max;
    RandomShapeGenerator a;
    double t = PI / 4;
    vector<shared_ptr<Shape>> shapes = a.FillRandomShapesVector(size, min, max);
    for (auto shape : shapes)
    {
        shape->GetPoint(t).PrintPoint();
        shape->DerivativeVector(t).PrintVector();
    }
    vector<shared_ptr<Circle>> circles;
    double radius_sum{};
    for (auto shape : shapes)
    {
        auto cir = dynamic_pointer_cast<Circle>(shape);
        if (cir)
        {
            circles.push_back(cir);
        }
    }
    sort(circles.begin(), circles.end(), [](std::shared_ptr<Circle> a, std::shared_ptr<Circle> b) { return a->GetRadius() < b->GetRadius(); });
    cout << "\nRadiuses: ";
    for (auto circle : circles)
    {
        cout << circle->GetRadius() << ' ';
    }
    double SumOfRadii = 0;
#pragma omp parallel for reduction(+ : SumOfRadii)
    for (int i = 0; i < circles.size(); i++)
    {
        SumOfRadii += circles[i]->GetRadius();
    }
    cout << "\nSum of radii: ";
    std::cout << SumOfRadii << "\n";

    return 0;
}