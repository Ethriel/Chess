#include"Header.h"

bool validateHorizontal(Gameboard* g, int fromX, int fromY, int toX, int toY)
{
	CELL_FIGURE whatOnCell;
	Figure* fig;
	int counter = 0;
	string nextColor;
	if (fromX != toX) // if not a horizontal direction
		return false;
	if (fromY > toY) // from right to left
	{
		for (int i = fromY; i > toY; i--)
		{
			fig = g->getFigure(fromX, i);
			nextColor = g->getColor(fromX, i - 1);
			whatOnCell = fig->chekCell(nextColor);
			if (whatOnCell == FRIEND)
				break;
			else if (whatOnCell == ENEMY)
				break;
			else
				counter++;
		}
	}
	else if (fromY < toY) // from left to right
	{
		for (int i = fromY; i < toY; i++)
		{
			fig = g->getFigure(fromX, i);
			nextColor = g->getColor(fromX, i + 1);
			whatOnCell = fig->chekCell(nextColor);
			if (whatOnCell == FRIEND)
				break;
			else if (whatOnCell == ENEMY)
				break;
			else
				counter++;
		}
	}
	if (counter == abs(fromY - toY))
		return true;
	return false;
}

bool validateVertical(Gameboard* g, int fromX, int fromY, int toX, int toY)
{
	CELL_FIGURE whatOnCell;
	Figure* fig;
	int counter = 0;
	string nextColor;
	if (fromY != toY) // if not a vertical direction
		return false;
	if (fromX < toX) // from top to bot
	{
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
	else if (fromX > toX) // from bot to top
	{
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
	if (counter == abs(fromX - toX))
		return true;
	return false;
}

bool validateDiagonal(Gameboard* g, int fromX, int fromY, int toX, int toY)
{
	if (abs(fromX - toX) != abs(fromY - toY))
		return false;
	CELL_FIGURE whatOnCell;
	int counter = 0;
	string nextColor;
	Figure* fig;
	int checkX = fromX, checkY = fromY;
	int nextX = 0, nextY = 0;
	if (fromX > toX && fromY < toY) // from bot-left to top-right
	{
		while (checkX != toX || checkY != toY)
		{
			if (validateOutOfRange(checkX, checkY))
				break;
			fig = g->getFigure(checkX, checkY);
			nextX = checkX - 1;
			nextY = checkY + 1;
			if (validateOutOfRange(nextX, nextY))
				break;
			nextColor = g->getColor(nextX, nextY);
			whatOnCell = fig->chekCell(nextColor);
			if (whatOnCell == FRIEND)
				break;
			else if (whatOnCell == ENEMY)
				break;
			else
				counter++;
			checkX--;
			checkY++;
		}
	}
	else if (fromX > toX && fromY > toY) // from bot-right to top-left
	{
		while (checkX != toX || checkY != toY)
		{
			if (validateOutOfRange(checkX, checkY))
				break;
			fig = g->getFigure(checkX, checkY);
			nextX = checkX - 1;
			nextY = checkY - 1;
			if (validateOutOfRange(nextX, nextY))
				break;
			nextColor = g->getColor(nextX, nextY);
			whatOnCell = fig->chekCell(nextColor);
			if (whatOnCell == FRIEND)
				break;
			else if (whatOnCell == ENEMY)
				break;
			else
				counter++;
			checkX--;
			checkY--;
		}
	}
	else if (fromX < toX && fromY > toY) // from top-right to bot-left
	{
		while (checkX != toX || checkY != toY)
		{
			if (validateOutOfRange(checkX, checkY))
				break;
			fig = g->getFigure(checkX, checkY);
			nextX = checkX + 1;
			nextY = checkY - 1;
			if (validateOutOfRange(nextX, nextY))
				break;
			nextColor = g->getColor(nextX, nextY);
			whatOnCell = fig->chekCell(nextColor);
			if (whatOnCell == FRIEND)
				break;
			else if (whatOnCell == ENEMY)
				break;
			else
				counter++;
			checkX++;
			checkY--;
		}
	}
	else if (fromX < toX && fromY < toY) // from top-left to bot-right
	{
		while (checkX != toX || checkY != toY)
		{
			if (validateOutOfRange(checkX, checkY))
				break;
			fig = g->getFigure(checkX, checkY);
			nextX = checkX + 1;
			nextY = checkY + 1;
			if (validateOutOfRange(nextX, nextY))
				break;
			nextColor = g->getColor(nextX, nextY);
			whatOnCell = fig->chekCell(nextColor);
			if (whatOnCell == FRIEND)
				break;
			else if (whatOnCell == ENEMY)
				break;
			else
				counter++;
			checkX++;
			checkY--;
		}
	}
	if (counter == abs(fromX - toX))
		return true;
	return false;
}

bool validateHorizontalAttack(Gameboard* g, int fromX, int fromY, int toX, int toY)
{
	// HORIZONTAL CHECK: if way free to the point BEFORE destination
	// left-right
	if (fromX == toX && fromY < toY)
	{
		if (validateHorizontal(g, fromX, fromY, toX, toY - 1))
			return true;
	}
	// right-left
	else if (fromX == toX && fromY > toY)
	{
		if (validateHorizontal(g, fromX, fromY, toX, toY + 1))
			return true;
	}
	return false;
}

bool validateVerticalAttack(Gameboard* g, int fromX, int fromY, int toX, int toY)
{
	// VERTICAL CHECK: if way free to the point BEFORE destination
	// top-bot
	if (fromX < toX && fromY == toY)
	{
		if (validateVertical(g, fromX, fromY, toX - 1, toY))
			return true;
	}
	// bot-top
	else if (fromX > toX && fromY == toY)
	{
		if (validateVertical(g, fromX, fromY, toX + 1, toY))
			return true;
	}
	return false;
}

bool validateDiagonalAttack(Gameboard* g, int fromX, int fromY, int toX, int toY)
{
	// DIAGONAL CHECK: if way free to the point BEFORE destination
	// diagonal left-right-top
	if (fromX > toX && fromY < toY && (abs(fromX - toX) == abs(fromY - toY)))
	{
		if (validateDiagonal(g, fromX, fromY, toX + 1, toY - 1))
			return true;
	}
	// diagonal right-left-bot
	else if (fromX < toX && fromY > toY && (abs(fromX - toX) == abs(fromY - toY)))
	{
		if (validateDiagonal(g, fromX, fromY, toX - 1, toY + 1))
			return true;
	}
	// diagonal right-left-top
	else if (fromX > toX && fromY > toY && (abs(fromX - toX) == abs(fromY - toY)))
	{
		if (validateDiagonal(g, fromX, fromY, toX + 1, toY + 1))
			return true;
	}
	// diagonal left-right-bot
	else if (fromX < toX && fromY < toY && (abs(fromX - toX) == abs(fromY - toY)))
	{
		if (validateDiagonal(g, fromX, fromY, toX - 1, toY - 1))
			return true;
	}
	return false;
}

bool validateOutOfRange(int x, int y)
{
	if (x < 0 || y < 0 || x > 7 || y > 7)
		return true;
	return false;
}

void gotoxy(Cursor &c)
{
	COORD pos = { c.x,c.y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

bool resetCursX(int& x)
{
	if (x < 5)
	{
		x = 5;
		return true;
	}
	if (x > 40)
	{
		x = 40;
		return true;
	}
	return false;
}
bool resetCursY(int& y)
{
	if (y < 2)
	{
		y = 2;
		return true;
	}
	if (y > 16)
	{
		y = 16;
		return true;
	}
	return false;
}

void resetCoord(int & c)
{
	if (c < 0)
		c = 0;
	if (c > 7)
		c = 7;
}