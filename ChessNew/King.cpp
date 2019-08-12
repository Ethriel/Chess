#include"Header.h"

King::King()
{
}

King::King(string name, string color, char symb, int moves, int limit, bool hasMoved) :Figure(name, color, symb, moves, limit, hasMoved)
{
}

King::~King()
{
}

CELL_FIGURE King::chekCell(int toX, int toY, string type)
{
	if (type == "space")
		return EMPTY;
	else if (this->getColor() == type)
		return FRIEND;
	else
		return ENEMY;
}

bool King::validateAttack(Gameboard * g)
{
	int fromX = from.getX();
	int fromY = from.getY();
	int toX = to.getX();
	int toY = to.getY();
	if ((abs(fromX - toX) != 1) || (abs(fromY - toY) != 1))
		return false;
	if (validateHorizontalAttack(g, fromX, fromY, toX, toY) || validateVerticalAttack(g, fromX, fromY, toX, toY) || validateDiagonalAttack(g, fromX, fromY, toX, toY))
		return true;
	return false;
}

bool King::validateAttack(Gameboard * g, int toX, int toY)
{
	int fromX = from.getX();
	int fromY = from.getY();
	if ((abs(fromX - toX) != 1) || (abs(fromY - toY) != 1))
		return false;
	if (validateHorizontalAttack(g, fromX, fromY, toX, toY) || validateVerticalAttack(g, fromX, fromY, toX, toY) || validateDiagonalAttack(g, fromX, fromY, toX, toY))
		return true;
	return false;
}

bool King::validateMove(Gameboard * g)
{
	int fromX = from.getX();
	int fromY = from.getY();
	int toX = to.getX();
	int toY = to.getY();
	int diffX = abs(fromX - toX);
	int diffY = abs(fromY - toY);
	if ((diffX != 1 && diffY == 0) || (diffY != 1 && diffX == 0) || (diffX != 1 && diffY != 1))
		return false;
	if (validateHorizontal(g, fromX, fromY, toX, toY) || validateVertical(g, fromX, fromY, toX, toY) || validateDiagonal(g, fromX, fromY, toX, toY))
		return true;
	return false;
}

bool King::validateMove(Gameboard * g, int toX, int toY)
{
	return false;
}

bool King::validateCheck(Gameboard * g)
{
	return false;
}

void King::fillWay(int fromX, int fromY, int toX, int toY)
{
	return;
}


