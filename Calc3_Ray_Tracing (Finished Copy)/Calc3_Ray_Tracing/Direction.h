#pragma once
//Christopher Settles

class Direction
{

private:
	int x, y, z;

public:
	Direction(int = 0, int = 0, int = 0);
	Direction operator+(Direction);
	int getx();
	int gety();
	int getz();
};