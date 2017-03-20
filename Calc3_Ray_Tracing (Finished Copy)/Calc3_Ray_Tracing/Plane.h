#pragma once
//Christopher Settles
#include <Windows.h>
#include "Point.h"
#include "Shape.h"
#include "Ray.h"
using namespace std;

class Shape;

class Plane : public Shape
{

private:
	Point p;
	Direction du, dv;

public:
	Plane(Point _p, Direction d1, Direction d2, COLORREF inputcolor);
	COLORREF Plane::getColor();
	bool Collideswith(Ray*);

};