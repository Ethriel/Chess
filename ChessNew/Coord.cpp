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

int Coord::switchCoord(char coord)
{
	switch (coord)
	{
	case 'a':
	case 'A':
		return 0;
	case 'b':
	case 'B':
		return 1;
	case 'c':
	case 'C':
		return 2;
	case 'd':
	case 'D':
		return 3;
	case 'e':
	case 'E':
		return 4;
	case 'f':
	case 'F':
		return 5;
	case 'g':
	case 'G':
		return 6;
	case 'h':
	case 'H':
		return 7;
	default:
		return -1;
	}
	return -1;
}
