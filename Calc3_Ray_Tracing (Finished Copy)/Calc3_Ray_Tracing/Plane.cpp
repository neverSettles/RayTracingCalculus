#include "Plane.h"


Plane::Plane(Point _p, Direction d1, Direction d2, COLORREF inputcolor)//: Shape()
{
	p = _p;
	du = d1;
	dv = d2;
	color = inputcolor;
}

COLORREF Plane::getColor(){ return color; }

bool Plane::Collideswith(Ray *myRay)
{
	//This is the place that I need to figure out if the line and the plane are orthagonal

	double t, u, v;
	double position_difference_x = (p.getx() - myRay->getpoint().getx());
	double position_difference_y = (p.gety() - myRay->getpoint().gety());
	double position_difference_z = (p.getz() - myRay->getpoint().getz());
	Direction dt = myRay->getdir();
	double MatrixADeterminant =
		(
			dt.getx()*(du.gety()*dv.getz() - dv.gety()*du.getz()) + 
			dt.gety()*(du.getx()*dv.getz() - dv.getx()*du.getz()) +
			dt.getz()*(du.getx()*dv.gety() - dv.getx()*du.gety())
		);
	if (MatrixADeterminant == 0) {
		return false;
	}

	t = (
		(position_difference_x)*(du.gety()*dv.getz() - dv.gety()*du.getz()) +
		(position_difference_y)*(du.getx()*dv.getz() - dv.getx()*du.getz()) +
		(position_difference_z)*(du.getx()*dv.gety() - dv.getx()*du.gety())
		)
		/ MatrixADeterminant;

	u = (
		dt.getx()*((position_difference_y)*(-dv.getz()) + (dv.gety())*(position_difference_z)) +
		dt.gety()*((position_difference_x)*(-dv.getz()) + (dv.getx())*(position_difference_z)) +
		dt.getz()*((position_difference_x)*(-dv.gety()) + (dv.getx())*(position_difference_y))
		)
		/ MatrixADeterminant;

	v = (
		dt.getx()*((-du.gety())* (position_difference_z) + (du.getz())*(position_difference_y)) +
		dt.gety()*((-du.getx())* (position_difference_z) + (du.getz())*(position_difference_x)) +
		dt.getz()*((-du.getx())* (position_difference_y) + (du.gety())*(position_difference_x))
		)
		/ MatrixADeterminant;

	if ((u >= 0 && u <= 1) && (v >= 0 && v <= 1))
	{
		return true;
	}

	return false;
}
