#pragma once
//Christopher Settles
#include "Direction.h"
#include "Point.h"
#include "Shape.h"

class Shape;

class Ray
{

private:
	Direction dir;
	Point p;

public:
	Ray(Direction inputdir = Direction(0,0,0), Point inputp = Point(0,0,0));
	bool Collideswith(Shape *sh);

	double distanceto(Shape *sh);

	Direction getdir();

	Point getpoint();

};