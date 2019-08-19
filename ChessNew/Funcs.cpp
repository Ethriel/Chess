#include"Header.h"

bool validateHorizontal(Gameboard* g, int fromX, int fromY, int toX, int toY)
{
	CELL_FIGURE whatOnCell;
	Figure* fig;
	int counter = 0;
	string nextColor;
	// if not a horizontal direction
	if (fromX != toX)
		return false;
	// from right to left
	if (fromY > toY)
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
	// from left to right
	else if (fromY < toY)
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
	// if not a vertical direction
	if (fromY != toY)
		return false;
	// from top to bot
	if (fromX < toX)
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
	// from bot to top
	else if (fromX > toX)
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
	// from bot-left to top-right
	if (fromX > toX && fromY < toY)
	{
		while (true)
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
	// from bot-right to top-left
	else if (fromX > toX && fromY > toY)
	{
		while (true)
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
	// from top-right to bot-left
	else if (fromX < toX && fromY > toY)
	{
		while (true)
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
	// from top-left to bot-right
	else if (fromX < toX && fromY < toY)
	{
		while (true)
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
	Figure* fig = g->getFigure(fromX, fromY);
	// DIAGONAL CHECK: if way free to the point BEFORE destination
	// diagonal left-right-top
	if (fromX > toX && fromY < toY && (abs(fromX - toX) == abs(fromY - toY)))
	{
		if (validateDiagonal(g, fromX, fromY, toX - 1, toY + 1))
			return true;
	}
	// diagonal right-left-bot
	else if (fromX < toX && fromY > toY && (abs(fromX - toX) == abs(fromY - toY)))
	{
		if (validateDiagonal(g, fromX, fromY, toX + 1, toY - 1))
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