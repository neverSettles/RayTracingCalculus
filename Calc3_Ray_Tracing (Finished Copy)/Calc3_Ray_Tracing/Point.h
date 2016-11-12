#pragma once
//Christopher Settles

class Point
{

private:
	int x, y, z;

public:

	Point(int = 0, int = 0, int  = 0);
	int getx();
	int gety();
	int getz();
	void setx(int);
	void sety(int);
	void setz(int);
};