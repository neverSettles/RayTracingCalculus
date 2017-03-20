#pragma once
//Christopher Settles

class Direction
{

private:
	int x, y, z;

public:
	Direction(int = 0, int = 0, int = 0);
	Direction operator+(Direction);
	Direction operator-(Direction);
	Direction operator-();
	int getx();
	int gety();
	int getz();
};