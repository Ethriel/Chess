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

void Coord::switchCoord()
{
	switch (this->yC)
	{
	case 'a':
	case 'A':
	{
		this->y = 0;
		break;
	}
	case 'b':
	case 'B':
	{
		this->y = 1;
		break;
	}
	case 'c':
	case 'C':
	{
		this->y = 2;
		break;
	}
	case 'd':
	case 'D':
	{
		this->y = 3;
		break;
	}
	case 'e':
	case 'E':
	{
		this->y = 4;
		break;
	}
	case 'f':
	case 'F':
	{
		this->y = 5;
		break;
	}
	case 'g':
	case 'G':
	{
		this->y = 6;
		break;
	}
	case 'h':
	case 'H':
	{
		this->y = 7;
		break;
	}
	default:
		this->y = -1;
	}
}
