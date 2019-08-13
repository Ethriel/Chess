#include"Header.h"

Bishop::Bishop()
{
}

Bishop::Bishop(string name, string color, char symb, int moves, int limit, bool hasMoved) :Figure(name, color, symb, moves, limit, hasMoved)
{
}

Bishop::~Bishop()
{
}

CELL_FIGURE Bishop::chekCell(int toX, int toY, string type)
{
	if (type == "space")
		return EMPTY;
	else if (this->getColor() == type)
		return FRIEND;
	else
		return ENEMY;
}

bool Bishop::validateAttack(Gameboard * g)
{
	int fromX = from.getX();
	int fromY = from.getY();
	int toX = to.getX();
	int toY = to.getY();
	if (validateDiagonalAttack(g, fromX, fromY, toX, toY))
	{
		this->fillWay(fromX, fromY, toX, toY);
		return true;
	}
	return false;
}

bool Bishop::validateAttack(Gameboard * g, int toX, int toY)
{
	int fromX = from.getX();
	int fromY = from.getY();
	if (validateDiagonalAttack(g, fromX, fromY, toX, toY))
	{
		this->fillWay(fromX, fromY, toX, toY);
		return true;
	}
	return false;
}

bool Bishop::validateMove(Gameboard * g)
{
	int fromX = from.getX();
	int fromY = from.getY();
	int toX = to.getX();
	int toY = to.getY();
	if (validateDiagonal(g, fromX, fromY, toX, toY))
	{
		this->fillWay(fromX, fromY, toX, toY);
		return true;
	}
	return false;
}

bool Bishop::validateMove(Gameboard * g, int toX, int toY)
{
	int fromX = from.getX();
	int fromY = from.getY();
	if (validateDiagonal(g, fromX, fromY, toX, toY))
	{
		this->fillWay(fromX, fromY, toX, toY);
		return true;
	}
	return false;
}

bool Bishop::validateCheck(Gameboard * g)
{
	Coord king;
	int fromX = from.getX();
	int fromY = from.getY();
	int toX, toY;
	string figColor = this->color;
	if (figColor == "white")
		king = g->getBlackKing();
	if (figColor == "black")
		king = g->getWhiteKing();
	toX = king.getX();
	toY = king.getY();
	if (validateDiagonalAttack(g, fromX, fromY, toX, toY))
	{
		this->fillWay(fromX, fromY, toX, toY);
		return true;
	}
	return false;
}

void Bishop::fillWay(int fromX, int fromY, int toX, int toY)
{
	this->way.clear();
	int lX, lY, bX, bY;
	int wayX[8];
	int wayY[8];
	int waySize = 0;
	int x = 0, y = 0;
	this->setLessBigCoord(fromX, fromY, toX, toY, lX, lY, bX, bY);
	for (int i = lX; i < bX - 1; i++)
	{
		wayX[i] = i + 1;
		waySize++;
	}
	for (int i = lY; i < bY - 1; i++)
	{
		wayY[i] = i + 1;
	}
	for (int i = 0; i < waySize; i++)
	{
		x = wayX[i];
		y = wayY[i];
		this->way.push_back(Coord(x, y));
	}
	this->way.shrink_to_fit();
}
