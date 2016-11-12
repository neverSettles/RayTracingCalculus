#pragma once
//Christopher Settles
#include <windows.h>
#include <cmath>
#include "Direction.h" 
#include "Point.h"
#include "Ray.h"

class Ray;

class Shape
{
	//Use of an Abstract base class (A class that has virtual functions in it)
protected:
	COLORREF color;

	//Use of pure virtual functions here (A virtual function is one that must be overridden by a base class) 
public:
	virtual COLORREF getColor() =0;
	virtual bool Collideswith(Ray *) = 0;

};