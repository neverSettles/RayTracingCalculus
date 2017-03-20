#include "Box.h"


Box::Box(Point _p, Direction d1, Direction d2, Direction d3, COLORREF inputcolor)//: Shape()
{
	p = _p;
	du = d1;
	dv = d2;
	dw = d3;
	color = inputcolor;
}

COLORREF Box::getColor() { return color; }

bool Box::Collideswith(Ray *myRay)
{
	Point point2(
		p.getx() + du.getx() + dv.getx() + dw.getx(),
		p.gety() + du.gety() + dv.gety() + dw.gety(),
		p.getz() + du.getz() + dv.getz() + dw.getz()
	);

	if (
		(new Plane(p, du, dv, color))->Collideswith(myRay) ||
		(new Plane(p, du, dw, color))->Collideswith(myRay) ||
		(new Plane(p, dv, dw, color))->Collideswith(myRay) ||
		(new Plane(point2, -du, -dv, color))->Collideswith(myRay) ||
		(new Plane(point2, -du, -dw, color))->Collideswith(myRay) ||
		(new Plane(point2, -dv, -dw, color))->Collideswith(myRay)
		)
	{
		return true;
	}

	return false;
}
