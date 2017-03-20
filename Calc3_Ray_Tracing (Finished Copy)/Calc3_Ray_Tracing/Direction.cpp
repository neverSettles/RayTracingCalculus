
#include "Direction.h"

Direction::Direction(int inputx, int inputy, int inputz)
{
	x = inputx;
	y = inputy;
	z = inputz;
}
Direction Direction::operator+(Direction d2)
// Calls the + function using the instance of the left operand
// Which is why I can just use getx() and not d1.getx() or left.getx()
{
	Direction newdirection(getx() + d2.getx(), gety() + d2.gety(), getz() + d2.getz());
	return newdirection;
}

Direction Direction::operator-(Direction d2)
// Calls the + function using the instance of the left operand
// Which is why I can just use getx() and not d1.getx() or left.getx()
{
	Direction newdirection(getx() - d2.getx(), gety() - d2.gety(), getz() - d2.getz());
	return newdirection;
}
Direction Direction::operator-()
// Calls the + function using the instance of the left operand
// Which is why I can just use getx() and not d1.getx() or left.getx()
{
	Direction newdirection(-getx(),-gety(), -getz());
	return newdirection;
}

int Direction::getx()
{
	return x;
}
int Direction::gety()
{
	return y;
}
int Direction::getz()
{
	return z;
}