#include"Header.h"

Figure::Figure()
{
}

Figure::Figure(string name, string color, char symb, int moves, int limit, bool hasMoved):name(name), color(color), symb(symb), moves(moves), limit(limit), hasMoved(hasMoved)
{
	for (int i = 0; i < 8; i++)
		this->way.push_back(Coord(0, 0));
}

Figure::~Figure()
{
}

char Figure::getSymb() const
{
	return symb;
}

string Figure::getColor() const
{
	return color;
}

string Figure::getName() const
{
	return name;
}

int Figure::getMoves() const
{
	return moves;
}

void Figure::setMoves(int moves)
{
	this->moves = moves;
}

void Figure::setFrom(int x, int y)
{
	from.setCoords(x, y);
}

void Figure::setTo(int x, int y)
{
	to.setCoords(x, y);
}

void Figure::setFromTo(int xF, int yF, int xT, int yT)
{
	this->setFrom(xF, yF);
	this->setTo(xT, yT);
}

void Figure::swapCoords()
{
	swap(this->from, this->to);
}

void Figure::setNewFrom(int x, int y)
{
	this->from.setCoords(x, y);
}

void Figure::setLessBigCoord(int fromX, int fromY, int toX, int toY, int& lX, int& lY, int& bX, int& bY)
{
	if (fromX > toX)
	{
		bX = fromX;
		lX = toX;
	}
	else if (toX > fromX)
	{
		bX = toX;
		lX = fromX;
	}
	else
		lX = bX = fromX;

	if (fromY > toY)
	{
		bY = fromY;
		lY = toY;
	}
	else if (toY > fromY)
	{
		bY = toY;
		lY = fromY;
	}
	else
		lY = bY = fromY;
}

vector<Coord> Figure::getWay() const
{
	return this->way;
}

int Figure::getFromX() const
{
	return this->from.getX();
}

int Figure::getFromY() const
{
	return this->from.getY();
}

int Figure::getToX() const
{
	return this->to.getX();
}

int Figure::getToY() const
{
	return this->to.getY();
}

int Figure::getLimit() const
{
	return this->limit;
}

bool Figure::getHasMoved() const
{
	return this->hasMoved;
}

void Figure::setHasMoved(bool hasMoved)
{
	this->hasMoved = hasMoved;
}
