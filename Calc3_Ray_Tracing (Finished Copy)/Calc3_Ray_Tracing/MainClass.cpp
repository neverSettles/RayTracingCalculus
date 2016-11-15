//Christopher Settles
//10/11/2016 - 11/12/2016
//Calculus 3 Honors Project : Ray Tracing
#pragma once
#include <iostream>
#include <windows.h>
#include <vector>
#include "Capsule.h"
#include "Ray.h"
#include "Shape.h"
#include "Sphere.h"
using namespace std;
const double PI = 3.1415926;
const COLORREF backgroundcolor = COLORREF(RGB(0, 204, 204));

void draw(Direction userstartdirection, Point userstartpoint, vector <Shape*> listofshapes);


	int main() 
	{
		//The user will tell the draw function that there are a list of spheres and capsules (shapes), and 
		//How he wants to look at those shapes (Point and direction); 
		Point userstartpoint = Point(20, 0, 0);
		//The direction really states the distance to the screen as the x component
		Direction userstartdirection = Direction(-360, 0, 0); //Can only have an x component 
		//Can only look in the -x direction because we want to look left when y becomes more negative (look in negative x dir)
		vector <Shape *> listofshapes;

		
		//Examples of shapes 
		//This will create a spiral of circles, but because it creates many circles it is slowwwww
		//for (double i = -PI* 4; i < PI*8; i+= 0.40) {
		//	listofshapes.push_back(new Sphere(-20  - 10*i, 20 *cos(i),  20 * sin(i), 3, RGB(0, 0, 255)));//Blue Sphere 
		//}

		//listofshapes.push_back(new Sphere(-5, -10, 2, 3, RGB(0, 0, 255)));//Blue Sphere 
		//listofshapes.push_back(new Sphere( 0, 0  , 2, 3, RGB(0, 0, 255)));//Blue Sphere 
		//listofshapes.push_back(new Sphere( 5, 10 , 2, 3, RGB(0, 0, 255)));//Blue Sphere 

		listofshapes.push_back(new Capsule(Point(-2, 0, 15), Point(-225, 0, 15), 3, RGB(255, 0, 120)));//Pink Capsule Top 
		listofshapes.push_back(new Capsule(Point(-2,-15, 0), Point(-225,-15, 0), 3, RGB(255, 0, 120)));//Pink Capsule Left
		listofshapes.push_back(new Capsule(Point(-2, 15, 0), Point(-225, 15, 0), 3, RGB(255, 0, 120)));//Pink Capsule Right
		listofshapes.push_back(new Capsule(Point(-2, 0,-15), Point(-225, 0,-15), 3, RGB(255, 0, 120)));//Pink Capsule Bottom
		//listofshapes.push_back(new Capsule(Point(-2, 0, 0),  Point(-225, 0, 0), 3, RGB(255, 0, 120))); //Pink Capsule Center 

		//listofshapes.push_back(new Capsule(Point(-2, -5, 2), Point(-2, 0, 2), 3,  RGB(255, 0, 120)));//Pink Capsule 


		draw(userstartdirection, userstartpoint, listofshapes);
		return 0;
	}

	void draw(Direction userstartdirection, Point userstartpoint, vector <Shape*> listofshapes)
	{
		
		HWND myconsole = GetConsoleWindow();
		HDC mydc = GetDC(myconsole);
		int width = 50, height = 50; 
		int pixel = 0;

		RECT rect;
		if (GetWindowRect(myconsole, &rect))
		{
			width = rect.right - rect.left;
			height = rect.bottom - rect.top;
		}

		//Choose any color
		COLORREF COLOR = RGB(rand() % 256, rand() % 256, rand() % 256);

		//Filling the screen with a random color
		for (int i = 5; i < width; i++) {
			for (int j = 5; j < height; j++) {
				SetPixel(mydc, i, j, backgroundcolor);
			}
		}

		for (int j = 0; j < width; j++) {
			for (int k = 0; k < height; k++) {
				Ray *PixelRay = new Ray(Direction(userstartdirection.getx(), j - width / 2, -(k - height/2) /*height/2 - k*/ ), userstartpoint);
				//The x dir doesn't change, j = y direction, k = z direction. The z direction is minus because 0,0,0 is 
				//in the top left corner instead of bottom left (how a computer thinks)
				double shortestdistance = DBL_MAX;
				for (int i = 0; i < listofshapes.size(); i++) {
					if (PixelRay->Collideswith(listofshapes[i]) && PixelRay->distanceto(listofshapes[i]) < shortestdistance) {
						shortestdistance = PixelRay->distanceto(listofshapes[i]);
						SetPixel(mydc, j, k, listofshapes[i]->getColor());
						//cerr << "Shape " <<i;
					}
				}
			}
		}

		ReleaseDC(myconsole, mydc);
	}
	