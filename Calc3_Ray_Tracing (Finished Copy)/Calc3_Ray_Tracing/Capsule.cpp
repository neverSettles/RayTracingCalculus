#include "Capsule.h"


Capsule::Capsule(Point inputstartpoint, Point inputendpoint, int inputr, COLORREF inputcolor) //: Shape()
{
	startpoint = inputstartpoint;
	endpoint = inputendpoint;
	r = inputr;
	color = inputcolor;
}
COLORREF Capsule::getColor()
{
	return color;
}

Direction Capsule::getdir()
{
	return Direction( 
		endpoint.getx() - startpoint.getx(), 
		endpoint.gety() - startpoint.gety(), 
		endpoint.getz() - startpoint.getz());
}

Point Capsule::getpoint()
{
	return startpoint;
}

int Capsule::getradius()
{
	return r;
}

Point Capsule::getendpoint()
{
	return endpoint;
}

bool Capsule::Collideswith(Ray* ray)
{
	//If interested in math, see Calc 3 notebook.
	Capsule *cap = this;

	double g1 =
		pow(ray->getdir().getx(), 2) + pow(ray->getdir().gety(), 2) + pow(ray->getdir().getz(), 2);

	double h1 =
		ray->getdir().getx() * (-1) * cap->getdir().getx() +
		ray->getdir().gety() * (-1) * cap->getdir().gety() +
		ray->getdir().getz() * (-1) * cap->getdir().getz();

	double c1 =
		ray->getdir().getx() * (cap->getpoint().getx() - ray->getpoint().getx()) +
		ray->getdir().gety() * (cap->getpoint().gety() - ray->getpoint().gety()) +
		ray->getdir().getz() * (cap->getpoint().getz() - ray->getpoint().getz());

	double g2 =
		-1 * ray->getdir().getx() * cap->getdir().getx() +
		-1 * ray->getdir().gety() * cap->getdir().gety() +
		-1 * ray->getdir().getz() * cap->getdir().getz(); 

	double h2 = 
		pow(cap->getdir().getx(), 2) + pow(cap->getdir().gety(), 2) + pow(cap->getdir().getz(), 2);

	double c2 = 
		(-1)*cap->getdir().getx() * (cap->getpoint().getx() - ray->getpoint().getx()) +
		(-1)*cap->getdir().gety() * (cap->getpoint().gety() - ray->getpoint().gety()) +
		(-1)*cap->getdir().getz() * (cap->getpoint().getz() - ray->getpoint().getz()); 
	

	double a = (c1 * h2 - c2 * h1) / (g1 * h2 - g2 * h1);
	double b = (c1 * g2 - c2 * g1) / (h1 * g2 - h2 * g1);

	if (b >= 0 && b <= 1)
	{
		double distancesquared = 
			pow(ray->getdir().getx() * a - cap->getdir().getx() * b - cap->getpoint().getx() + ray->getpoint().getx(), 2) +
			pow(ray->getdir().gety() * a - cap->getdir().gety() * b - cap->getpoint().gety() + ray->getpoint().gety(), 2) +
			pow(ray->getdir().getz() * a - cap->getdir().getz() * b - cap->getpoint().getz() + ray->getpoint().getz(), 2);

		if (distancesquared < pow(cap->getradius(), 2))
		{
			return true;
		}
	}

	//Find 

	else if (b < 0) // this is not true because the capsule can be oriented any way it wants to be and start point will no
		//Actually I may be wrong because b is a time that tells you when you are closest to the start point. (wrong, thats a)
		//b is the time (spot) on the line segment you are at. So < 0 means you are away from the startpoint and the line
	{
		//Find distance to startpoint
		Sphere *startsphere = new Sphere(
			cap->getpoint().getx(), 
			cap->getpoint().gety(), 
			cap->getpoint().getz(), 
			cap->getradius(),
			cap->getColor());
		return ray->Collideswith(startsphere);
	}
	else if (b > 1) 
	{
		// Find distance to endpoint 
		Sphere *endsphere = new Sphere(
			cap->getendpoint().getx(),
			cap->getendpoint().gety(),
			cap->getendpoint().getz(),
			cap->getradius(),
			cap->getColor());
		return ray->Collideswith(endsphere);
	}
	else
	{
		
	}

	return false;
}

