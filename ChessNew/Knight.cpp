#include"Header.h"

Knight::Knight()
{
}

Knight::Knight(string name, string color, char symb, int moves, int limit, bool hasMoved) :Figure(name, color, symb, moves, limit, hasMoved)
{
}

Knight::~Knight()
{
}

CELL_FIGURE Knight::chekCell(string type)
{
	if (type == "space")
		return EMPTY;
	else if (this->getColor() == type)
		return FRIEND;
	else
		return ENEMY;
}

bool Knight::validateAttack(Gameboard * g)
{
	if (validateMove(g))
		return true;
	return false;
}

bool Knight::validateAttack(Gameboard * g, int toX, int toY)
{
	if (validateMove(g, toX, toY))
		return true;
	return false;
}

bool Knight::validateMove(Gameboard * g)
{
	int fromX = from.getX();
	int fromY = from.getY();
	int toX = to.getX();
	int toY = to.getY();

	if (toY == (fromY + 2) && toX == (fromX + 1))
		return true;
	if (toY == (fromY + 2) && toX == (fromX - 1))
		return true;
	if (toY == (fromY + 1) && toX == (fromX + 2))
		return true;
	if (toY == (fromY + 1) && toX == (fromX - 2))
		return true;

	if (toY == (fromY - 2) && toX == (fromX + 1))
		return true;
	if (toY == (fromY - 2) && toX == (fromX - 1))
		return true;
	if (toY == (fromY - 1) && toX == (fromX + 2))
		return true;
	if (toY == (fromY - 1) && toX == (fromX - 2))
		return true;
	return false;
}

bool Knight::validateMove(Gameboard * g, int toX, int toY)
{
	int fromX = from.getX();
	int fromY = from.getY();
	if (toY == (fromY + 2) && toX == (fromX + 1))
		return true;
	if (toY == (fromY + 2) && toX == (fromX - 1))
		return true;
	if (toY == (fromY + 1) && toX == (fromX + 2))
		return true;
	if (toY == (fromY + 1) && toX == (fromX - 2))
		return true;

	if (toY == (fromY - 2) && toX == (fromX + 1))
		return true;
	if (toY == (fromY - 2) && toX == (fromX - 1))
		return true;
	if (toY == (fromY - 1) && toX == (fromX + 2))
		return true;
	if (toY == (fromY - 1) && toX == (fromX - 2))
		return true;
	return false;
}

bool Knight::validateCheck(Gameboard * g)
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

	if (toY == (fromY + 2) && toX == (fromX + 1))
		return true;
	if (toY == (fromY + 2) && toX == (fromX - 1))
		return true;
	if (toY == (fromY + 1) && toX == (fromX + 2))
		return true;
	if (toY == (fromY + 1) && toX == (fromX - 2))
		return true;

	if (toY == (fromY - 2) && toX == (fromX + 1))
		return true;
	if (toY == (fromY - 2) && toX == (fromX - 1))
		return true;
	if (toY == (fromY - 1) && toX == (fromX + 2))
		return true;
	if (toY == (fromY - 1) && toX == (fromX - 2))
		return true;
	return false;
}

void Knight::fillWay(int fromX, int fromY, int toX, int toY)
{
	return;
}
