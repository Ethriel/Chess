#include"Header.h"

Coord::Coord():x(0), y(0)
{
}

Coord::Coord(int x, int y):x(x), y(y)
{
}

Coord::~Coord()
{
}

void Coord::setX(int x)
{
	this->x = x;
}

void Coord::setY(int y)
{
	this->y = y;
}

void Coord::setCoords(int x, int y)
{
	setX(x);
	setY(y);
}

int Coord::getX() const
{
	return x;
}

int Coord::getY() const
{
	return y;
}

bool Coord::operator==(Coord & other)
{
	return (x == other.x && y == other.y);
}

bool Coord::operator!=(Coord & other)
{
	return (this->x != other.x && this->y != other.y);
}
