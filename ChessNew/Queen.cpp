#include"Header.h"

Queen::Queen()
{
}

Queen::Queen(string name, string color, char symb, int moves, int limit, bool hasMoved) :Figure(name, color, symb, moves, limit, hasMoved)
{
}

Queen::~Queen()
{
}

CELL_FIGURE Queen::chekCell(int toX, int toY, string type)
{
	if (type == "space")
		return EMPTY;
	else if (this->getColor() == type)
		return FRIEND;
	else
		return ENEMY;
}

bool Queen::validateAttack(Gameboard * g)
{
	int fromX = from.getX();
	int fromY = from.getY();
	int toX = to.getX();
	int toY = to.getY();
	if (validateHorizontalAttack(g, fromX, fromY, toX, toY) || validateVerticalAttack(g, fromX, fromY, toX, toY) || validateDiagonalAttack(g, fromX, fromY, toX, toY))
	{
		this->fillWay(fromX, fromY, toX, toY);
		return true;
	}
	return false;
}

bool Queen::validateAttack(Gameboard * g, int toX, int toY)
{
	int fromX = from.getX();
	int fromY = from.getY();
	if (validateHorizontalAttack(g, fromX, fromY, toX, toY) || validateVerticalAttack(g, fromX, fromY, toX, toY) || validateDiagonalAttack(g, fromX, fromY, toX, toY))
	{
		this->fillWay(fromX, fromY, toX, toY);
		return true;
	}
	return false;
}

bool Queen::validateMove(Gameboard * g)
{
	int fromX = from.getX();
	int fromY = from.getY();
	int toX = to.getX();
	int toY = to.getY();
	if (validateHorizontal(g, fromX, fromY, toX, toY) || validateVertical(g, fromX, fromY, toX, toY) || validateDiagonal(g, fromX, fromY, toX, toY))
	{
		this->fillWay(fromX, fromY, toX, toY);
		return true;
	}
	return false;
}

bool Queen::validateMove(Gameboard * g, int toX, int toY)
{
	int fromX = from.getX();
	int fromY = from.getY();
	if (validateHorizontal(g, fromX, fromY, toX, toY) || validateVertical(g, fromX, fromY, toX, toY) || validateDiagonal(g, fromX, fromY, toX, toY))
	{
		this->fillWay(fromX, fromY, toX, toY);
		return true;
	}
	return false;
}

bool Queen::validateCheck(Gameboard * g)
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
	if (validateHorizontalAttack(g, fromX, fromY, toX, toY) || validateVerticalAttack(g, fromX, fromY, toX, toY) || validateDiagonalAttack(g, fromX, fromY, toX, toY))
	{
		this->fillWay(fromX, fromY, toX, toY);
		return true;
	}
	return false;
}

void Queen::fillWay(int fromX, int fromY, int toX, int toY)
{
	int lX, lY, bX, bY;
	int wayX[8];
	int wayY[8];
	int waySize = 0;
	int x = 0, y = 0;
	this->setLessBigCoord(fromX, fromY, toX, toY, lX, lY, bX, bY);
	if (lX == bX) // horizontal way
	{
		for (int i = 0; i < (bY - lY - 1); i++)
		{
			wayX[i] = lX;
			waySize++;
		}
		for (int i = lY; i < bY - 1; i++)
		{
			wayY[i] = i + 1;
		}
	}
	if (lY == bY) // vertical way
	{
		for (int i = 0; i < (bX - lY - 1); i++)
		{
			wayY[i] = lY;
			waySize++;
		}
		for (int i = lX; i < bX - 1; i++)
		{
			wayX[i] = i + 1;
		}
	}
	if ((bX - lX) == (bY - lY)) // diagonal
	{
		for (int i = lX; i < bX - 1; i++)
		{
			wayX[i] = i + 1;
			waySize++;
		}
		for (int i = lY; i < bY - 1; i++)
		{
			wayY[i] = i + 1;
		}
	}
	for (int i = 0; i < waySize; i++)
	{
		x = wayX[i];
		y = wayY[i];
		this->way.push_back(Coord(x, y));
	}
	this->way.shrink_to_fit();
}
