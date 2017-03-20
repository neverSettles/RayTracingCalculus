#pragma once
//Christopher Settles
#include "Plane.h"
#include "Shape.h"
using namespace std;

class Shape;

class Box : public Shape
{

private:
	Point p;
	Direction du, dv, dw;

public:
	Box(Point _p, Direction d1, Direction d2, Direction d3, COLORREF inputcolor);
	COLORREF Box::getColor();
	bool Collideswith(Ray*);

};