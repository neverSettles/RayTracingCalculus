#pragma once
#include "Point.h"

Point::Point(int inputx, int inputy, int inputz)
{
	x = inputx;
	y = inputy;
	z = inputz;
}

int Point::getx()
{
	return x;
}

int Point::gety()
{
	return y;
}

int Point::getz()
{
	return z;
}

void Point::setx(int _x)
{
	x = _x;
}

void Point::sety(int _y)
{
	y = _y;
}

void Point::setz(int _z)
{
	z = _z;
}

