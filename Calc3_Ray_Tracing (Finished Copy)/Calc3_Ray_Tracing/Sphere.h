#pragma once
//Christopher Settles
#include <Windows.h>
#include "Point.h"
#include "Shape.h"
#include "Ray.h"
using namespace std;

class Shape;

class Sphere : public Shape
{
	
private:
	int r;
	Point p;

public:
	Sphere(int x, int y, int z , int r, COLORREF inputcolor);
	COLORREF getColor();
	Point getpoint();
	int getradius();
	bool Collideswith(Ray *);
};