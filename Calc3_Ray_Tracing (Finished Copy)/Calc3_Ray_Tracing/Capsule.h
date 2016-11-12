#pragma once
//Christopher Settles
#include "Shape.h"
#include "Sphere.h"
using namespace std;

class Shape;
//Instance of Polymorphism here (and Inheritance) 
//Capsule IS A Shape. (Polymorphism)
//Capsule inherits all the attributes of shape. (Inheritance)
class Capsule: public Shape 
{

private:
	Point startpoint, endpoint;
	int r; 

public:

	Capsule(Point startpoint, Point endpoint, int inputr, COLORREF inputcolor);

	COLORREF getColor();
	bool Collideswith(Ray*);
	Direction getdir();
	Point getpoint();
	int getradius();
	Point getendpoint();
};