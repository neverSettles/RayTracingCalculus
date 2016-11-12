
#include "Sphere.h"


Sphere::Sphere(int inputx, int inputy, int inputz, int inputr, COLORREF inputcolor) //: Shape()
{
	p.setx(inputx);
	p.sety(inputy);
	p.setz(inputz);
	r = inputr;
	color = inputcolor;
}

COLORREF Sphere::getColor()
{
	return color;

}

Point Sphere::getpoint()
{
	return p;
}
int Sphere::getradius()
{
	return r;
}

bool Sphere::Collideswith(Ray *myRay)
{
	//If interested in learning where math came from, see math notebook for Calc 3. 
	double a =
		(double)
		pow((myRay->getdir().getx()), 2) +
		pow((myRay->getdir().gety()), 2) +
		pow((myRay->getdir().getz()), 2);

	double b =
		(double)
		2 * (myRay->getdir().getx())*(myRay->getpoint().getx() - this->getpoint().getx()) +
		2 * (myRay->getdir().gety())*(myRay->getpoint().gety() - this->getpoint().gety()) +
		2 * (myRay->getdir().getz())*(myRay->getpoint().getz() - this->getpoint().getz());

	double c =
		(double)
		pow((myRay->getpoint().getx() - this->getpoint().getx()), 2) +
		pow((myRay->getpoint().gety() - this->getpoint().gety()), 2) +
		pow((myRay->getpoint().getz() - this->getpoint().getz()), 2);

	if ((-pow(b, 2) + 4 * a * c) / (4 * a) < pow(this->getradius(),2) && -b/(2*a) > 0 )
	{
		return true;
	}
	else
	{
		return false;
	}
}
