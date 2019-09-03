#include"Header.h"

Pawn::Pawn()
{
}

Pawn::Pawn(string name, string color, char symb, int moves, int limit, bool hasMoved) : Figure(name, color, symb, moves, limit, hasMoved)
{
}

Pawn::~Pawn()
{
}

CELL_FIGURE Pawn::chekCell(string type)
{
	if (type == "space")
		return EMPTY;
	else if (this->getColor() == type)
		return FRIEND;
	else
		return ENEMY;
}

bool Pawn::validateAttack(Gameboard * g)
{
	int fromX = from.getX();
	int fromY = from.getY();
	int toX = to.getX();
	int toY = to.getY();
	string figColor = this->color;
	if (figColor == "white")
	{
		if (abs(fromX - toX) == 1 && (abs(fromY - toY) == 1) && (fromX > toX))
			return true;
	}
	if (figColor == "black")
	{
		if (abs(fromX - toX) == 1 && abs(toY - fromY) == 1 && (fromX < toX))
			return true;
	}
	this->fillWay(fromX, fromY, toX, toY);
	return false;
}

bool Pawn::validateAttack(Gameboard * g, int toX, int toY)
{
	int fromX = from.getX();
	int fromY = from.getY();
	string figColor = this->color;
	if (figColor == "white")
	{
		if (abs(fromX - toX) == 1 && (abs(fromY - toY) == 1) && (fromX > toX))
			return true;
	}
	if (figColor == "black")
	{
		if (abs(fromX - toX) == 1 && abs(toY - fromY) == 1 && (fromX < toX))
			return true;
	}
	this->fillWay(fromX, fromY, toX, toY);
	return false;
}

bool Pawn::validateMove(Gameboard * g)
{
	int fromX = from.getX();
	int fromY = from.getY();
	int toX = to.getX();
	int toY = to.getY();
	Figure* fig;
	CELL_FIGURE whatOnCell;
	int counter = 0;
	string nextColor;
	string figColor = this->color;
	// if not a vertical direction
	if (fromY != toY)
		return false;
	// white pawn
	if (figColor == "white")
	{
		if (fromX > toX)
		{
			// if pawn is on the start position
			if (fromX == 6)
				this->setMoves(2);
			// if pawn is at or after 3 line
			else
				this->setMoves(1);
			if (abs(fromX - toX) > this->moves)
				return false;
			for (int i = fromX; i > toX; i--)
			{
				fig = g->getFigure(i, fromY);
				nextColor = g->getColor(i - 1, fromY);
				whatOnCell = fig->chekCell(nextColor);
				if (whatOnCell == FRIEND)
					break;
				else if (whatOnCell == ENEMY)
					break;
				else
					counter++;
			}
		}
		else
			return false;
	}
	// black pawn
	else if (figColor == "black")
	{
		if (fromX < toX)
		{
			// if pawn is on the start position
			if (fromX == 1)
				this->setMoves(2);
			// if pawn is at or after 3 line
			else
				this->setMoves(1);
			if (abs(fromX - toX) > this->moves)
				return false;
			for (int i = fromX; i < toX; i++)
			{
				fig = g->getFigure(i, fromY);
				nextColor = g->getColor(i + 1, fromY);
				whatOnCell = fig->chekCell(nextColor);
				if (whatOnCell == FRIEND)
					break;
				else if (whatOnCell == ENEMY)
					break;
				else
					counter++;
			}
		}
		else
			return false;
	}
	this->fillWay(fromX, fromY, toX, toY);
	if (counter == abs(fromX - toX))
		return true;
	return false;
}

bool Pawn::validateMove(Gameboard * g, int toX, int toY)
{
	int fromX = from.getX();
	int fromY = from.getY();
	Figure* fig;
	CELL_FIGURE whatOnCell;
	int counter = 0;
	string nextColor;
	string figColor = this->color;
	// if not a vertical direction
	if (fromY != toY)
		return false;
	// white pawn
	if (figColor == "white")
	{
		if (fromX > toX)
		{
			// if pawn is on the start position
			if (fromX == 6)
				this->setMoves(2);
			// if pawn is at or after 3 line
			else
				this->setMoves(1);
			if (abs(fromX - toX) > this->moves)
				return false;
			for (int i = fromX; i > toX; i--)
			{
				fig = g->getFigure(i, fromY);
				nextColor = g->getColor(i - 1, fromY);
				whatOnCell = fig->chekCell(nextColor);
				if (whatOnCell == FRIEND)
					break;
				else if (whatOnCell == ENEMY)
					break;
				else
					counter++;
			}
		}
		else
			return false;
	}
	// black pawn
	else if (figColor == "black")
	{
		if (fromX < toX)
		{
			// if pawn is on the start position
			if (fromX == 1)
				this->setMoves(2);
			// if pawn is at or after 3 line
			else
				this->setMoves(1);
			if (abs(fromX - toX) > this->moves)
				return false;
			for (int i = fromX; i < toX; i++)
			{
				fig = g->getFigure(i, fromY);
				nextColor = g->getColor(i + 1, fromY);
				whatOnCell = fig->chekCell(nextColor);
				if (whatOnCell == FRIEND)
					break;
				else if (whatOnCell == ENEMY)
					break;
				else
					counter++;
			}
		}
		else
			return false;
	}
	this->fillWay(fromX, fromY, toX, toY);
	if (counter == abs(fromX - toX))
		return true;
	return false;
}

bool Pawn::validateCheck(Gameboard * g)
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
	if (figColor == "white")
	{
		if (abs(fromX - toX) == 1 && (abs(fromY - toY) == 1))
			return true;
	}
	if (figColor == "black")
	{
		if (abs(fromX - toX) == 1 && abs(toY - fromY) == 1)
			return true;
	}
	this->fillWay(fromX, fromY, toX, toY);
	return false;
}

void Pawn::fillWay(int fromX, int fromY, int toX, int toY)
{
	if (!this->way.empty())
		this->way.clear();
	int lX, lY, bX, bY;
	int wayX[8];
	int wayY[8];
	int waySize = 0;
	int x = 0, y = 0;
	this->setLessBigCoord(fromX, fromY, toX, toY, lX, lY, bX, bY);
	for (int i = lX, j = 0; i < bX; i++)
	{
		wayX[j] = i + 1;
		waySize++;
		j++;
	}
	for (int i = 0; i < waySize; i++)
	{
		wayY[i] = fromY;
	}
	for (int i = 0; i < waySize; i++)
	{
		x = wayX[i];
		y = wayY[i];
		this->way.push_back(Coord(x, y));
	}
	this->way.shrink_to_fit();
}
