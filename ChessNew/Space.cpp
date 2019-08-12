#include"Header.h"

Space::Space()
{
}

Space::Space(string name, string color, char symb, int moves, int limit, bool hasMoved) :Figure(name, color, symb, moves, limit, hasMoved)
{
}

Space::~Space()
{
}

CELL_FIGURE Space::chekCell(int toX, int toY, string type)
{
	if (type == "space")
		return EMPTY;
	else if (this->getColor() == type)
		return FRIEND;
	else
		return ENEMY;
}

bool Space::validateAttack(Gameboard * g)
{
	return false;
}

bool Space::validateAttack(Gameboard * g, int toX, int toY)
{
	return false;
}

bool Space::validateMove(Gameboard * g)
{
	return false;
}

bool Space::validateMove(Gameboard * g, int toX, int toY)
{
	return false;
}

bool Space::validateCheck(Gameboard * g)
{
	return false;
}

void Space::fillWay(int fromX, int fromY, int toX, int toY)
{
	return;
}
