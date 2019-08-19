#include"Header.h"
Cursor::Cursor():x(5), y(2)
{
}

Cursor::Cursor(int x, int y):x(x), y(y)
{

}
void Cursor::resetCursor()
{
	this->x = 5;
	this->y = 2;
}

void Cursor::setX(int x)
{
	this->x = x;
}

void Cursor::setY(int y)
{
	this->y = y;
}

void Cursor::setCoords(int x, int y)
{
	setX(x);
	setY(y);
}

int Cursor::getX() const
{
	return x;
}

int Cursor::getY() const
{
	return y;
}