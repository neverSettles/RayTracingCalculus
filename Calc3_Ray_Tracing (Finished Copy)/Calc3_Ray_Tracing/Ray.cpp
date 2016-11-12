#include "Ray.h"

Ray::Ray(Direction inputdir, Point inputp)
{
	dir = inputdir;
	p = inputp;
}

bool Ray::Collideswith(Shape * sh)
{
	return sh->Collideswith(this);
}

double Ray::distanceto(Shape * sh)
{
	return 0.0;
}


Direction Ray::getdir()
{
	return dir;
}
Point Ray::getpoint()
{
	return p;
}