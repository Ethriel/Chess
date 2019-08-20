#include"Header.h"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

Gameboard::Gameboard()
{

}

Gameboard::Gameboard(const Gameboard & g)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			this->board[i][j] = g.board[i][j];
		}
	}
}

Gameboard::~Gameboard()
{

}

void Gameboard::fillBoard()
{
	space = new Space("space", "space", '*', 0, -1, false);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i >= 2 && i < 6) // space
			{
				board[i][j] = new Space("space", "space", '*', 0, -1, false);
				spaces.push_back(Coord(i, j));
			}
			else if (i == 6) // white pawns
			{
				board[i][j] = new Pawn("pawn", "white", 'P', 2, 0, false);
				white.push_back(Coord(i, j));
			}
			else if (i == 1) // black pawns
			{
				board[i][j] = new Pawn("pawn", "black", 'p', 2, 7, false);
				black.push_back(Coord(i, j));
			}
			else if ((i == 7 && j == 0) || (i == 7 && j == 7)) // white rooks
			{
				board[i][j] = new Rook("rook", "white", 'R', 8, -1, false);
				white.push_back(Coord(i, j));
			}
			else if ((i == 0 && j == 0) || (i == 0 && j == 7)) // black rooks
			{
				board[i][j] = new Rook("rook", "black", 'r', 8, -1, false);
				black.push_back(Coord(i, j));
			}
			else if ((i == 7 && j == 1) || (i == 7 && j == 6)) // white knights
			{
				board[i][j] = new Knight("knight", "white", 'N', 8, -1, false);
				white.push_back(Coord(i, j));
			}
			else if ((i == 0 && j == 1) || (i == 0 && j == 6)) // black knights
			{
				board[i][j] = new Knight("knight", "black", 'n', 8, -1, false);
				black.push_back(Coord(i, j));
			}
			else if ((i == 7 && j == 2) || (i == 7 && j == 5)) // white bishops
			{
				board[i][j] = new Bishop("bishop", "white", 'B', 8, -1, false);
				white.push_back(Coord(i, j));
			}
			else if ((i == 0 && j == 2) || (i == 0 && j == 5)) // black bishops
			{
				board[i][j] = new Bishop("knight", "black", 'b', 8, -1, false);
				black.push_back(Coord(i, j));
			}
			else if (i == 7 && j == 4) // white king
			{
				board[i][j] = new King("king", "white", 'K', 1, -1, false);
				white.push_back(Coord(i, j));
				whiteKing.setCoords(i, j);
			}
			else if (i == 0 && j == 4) // black king
			{
				board[i][j] = new King("king", "black", 'k', 1, -1, false);
				black.push_back(Coord(i, j));
				blackKing.setCoords(i, j);
			}
			else if (i == 7 && j == 3) // white queen
			{
				board[i][j] = new Queen("queen", "white", 'Q', 1, -1, false);
				white.push_back(Coord(i, j));
			}
			else if (i == 0 && j == 3) // black queen
			{
				board[i][j] = new Queen("queen", "black", 'q', 1, -1, false);
				black.push_back(Coord(i, j));
			}
			board[i][j]->setFrom(i, j); // set coords
		}
	}
	for (int i = 0; i < 8; i++)
	{
		whiteLine.push_back(Coord(5, i));
		blackLine.push_back(Coord(2, i));
	}
}

void Gameboard::fillTestBoard()
{
	space = new Space("space", "space", '*', 0, -1, false);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			// STALEMATE TEST
			/*
			if ((i == 4 && j == 1) || (i == 3 && j == 2) || (i == 2 && j == 7))
			{
				board[i][j] = new Pawn("pawn", "white", 'P', 1, 0, false);
				white.push_back(Coord(i, j));
			}
			else if ((i == 3 && j == 1) || (i == 2 && j == 2))
			{
				board[i][j] = new Pawn("pawn", "black", 'p', 1, 7, false);
				black.push_back(Coord(i, j));
			}
			else if (i == 0 && j == 7)
			{
				board[i][j] = new King("king", "black", 'k', 1, -1, false);
				black.push_back(Coord(i, j));
				blackKing.setCoords(i, j);
			}
			else if (i == 2 && j == 5)
			{
				board[i][j] = new King("king", "white", 'K', 1, -1, false);
				white.push_back(Coord(i, j));
				whiteKing.setCoords(i, j);
			}
			else if (i == 6 && j == 2)
			{
				board[i][j] = new Queen("queen", "white", 'Q', 8, -1, false);
				white.push_back(Coord(i, j));
			}
			else
			{
				board[i][j] = new Space("space", "space", '*', 0, -1, false);
				spaces.push_back(Coord(i, j));
			}
			board[i][j]->setFrom(i, j);
			*/
			// TEST ATTACKS
			/*
			if ((i == 3 && j == 0) || (i == 3 && j == 2) || (i == 1 && j == 5))
			{
				board[i][j] = new Pawn("pawn", "black", 'p', 1, 7, false);
				black.push_back(Coord(i, j));
			}
			else if (i == 4 && j == 1)
			{
				board[i][j] = new Bishop("bishop", "white", 'B', 8, -1, false);
				white.push_back(Coord(i, j));
			}
			else if (i == 4 && j == 2)
			{
				board[i][j] = new Rook("rook", "white", 'R', 8, -1, false);
				white.push_back(Coord(i, j));
			}
			else if (i == 7 && j == 4)
			{
				board[i][j] = new King("king", "white", 'K', 1, -1, false);
				white.push_back(Coord(i, j));
				whiteKing.setCoords(i, j);
			}
			else if (i == 0 && j == 4)
			{
				board[i][j] = new King("king", "black", 'k', 1, -1, false);
				black.push_back(Coord(i, j));
				blackKing.setCoords(i, j);
			}
			else
			{
				board[i][j] = new Space("space", "space", '*', 0, -1, false);
				spaces.push_back(Coord(i, j));
			}
			board[i][j]->setFrom(i, j);
			*/
			// TEST CHECK
			/*
			if ((i == 0 && j == 3) || (i == 0 && j == 5))
			{
				board[i][j] = new Pawn("pawn", "black", 'p', 1, 7, false);
				black.push_back(Coord(i, j));
			}
			else if (i == 1 && j == 3)
			{
				board[i][j] = new Rook("rook", "black", 'r', 8, -1, false);
				black.push_back(Coord(i, j));
			}
			else if (i == 6 && j == 5)
			{
				board[i][j] = new Rook("rook", "white", 'R', 8, -1, false);
				white.push_back(Coord(i, j));
			}
			else if (i == 0 && j == 4)
			{
				board[i][j] = new King("king", "black", 'k', 1, -1, false);
				black.push_back(Coord(i, j));
				blackKing.setCoords(i, j);
			}
			else if (i == 7 && j == 4)
			{
				board[i][j] = new King("king", "white", 'K', 1, -1, false);
				white.push_back(Coord(i, j));
				whiteKing.setCoords(i, j);
			}
			else
			{
				board[i][j] = new Space("space", "space", '*', 0, -1, false);
				spaces.push_back(Coord(i, j));
			}
			board[i][j]->setFrom(i, j);
			*/
			// TEST CHECKMATE
			if ((i == 0 && j == 3) || (i == 0 && j == 5))
			{
				board[i][j] = new Pawn("pawn", "black", 'p', 1, 7, false);
				black.push_back(Coord(i, j));
			}
			else if ((i == 6 && j == 3) || (i == 6 && j == 5))
			{
				board[i][j] = new Rook("rook", "white", 'R', 8, -1, false);
				white.push_back(Coord(i, j));
			}
			else if (i == 0 && j == 4)
			{
				board[i][j] = new King("king", "black", 'k', 1, -1, false);
				black.push_back(Coord(i, j));
				blackKing.setCoords(i, j);
			}
			else if (i == 7 && j == 4)
			{
				board[i][j] = new King("king", "white", 'K', 1, -1, false);
				white.push_back(Coord(i, j));
				whiteKing.setCoords(i, j);
			}
			else if (i == 7 && j == 5)
			{
				board[i][j] = new Queen("queen", "white", 'Q', 1, -1, false);
				white.push_back(Coord(i, j));
			}
			else
			{
				board[i][j] = new Space("space", "space", '*', 0, -1, false);
				spaces.push_back(Coord(i, j));
			}
			board[i][j]->setFrom(i, j);
		}
	}
	for (int i = 0; i < 8; i++)
	{
		whiteLine.push_back(Coord(5, i));
		blackLine.push_back(Coord(2, i));
	}
}

void Gameboard::printBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i == 0 && j == 0)
			{
				SetConsoleTextAttribute(hConsole, 14);
				cout << "     A    B    C    D    E    F    G    H\n";
				cout << "__________________________________________\n";
			}
			if (j == 0)
			{
				SetConsoleTextAttribute(hConsole, 14);
				cout << i + 1 << "|";
			}
			if (board[i][j]->getColor() == "black")
				SetConsoleTextAttribute(hConsole, 12);
			if (board[i][j]->getColor() == "white")
				SetConsoleTextAttribute(hConsole, 15);
			if (board[i][j]->getColor() == "space")
				SetConsoleTextAttribute(hConsole, 10);
			cout << setw(4) << board[i][j]->getSymb();
			SetConsoleTextAttribute(hConsole, 14);
			cout << "|";
		}
		cout << endl;
		cout << "__________________________________________\n";
	}
	cout << endl;
	cout << endl;
	SetConsoleTextAttribute(hConsole, 15);
}

void Gameboard::printBoard(int x, int y)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i == 0 && j == 0)
			{
				SetConsoleTextAttribute(hConsole, 14);
				cout << "     A    B    C    D    E    F    G    H\n";
				cout << "__________________________________________\n";
			}
			if (j == 0)
			{
				SetConsoleTextAttribute(hConsole, 14);
				cout << i + 1 << "|";
			}
			if (board[i][j]->getColor() == "black")
				SetConsoleTextAttribute(hConsole, 12);
			if (board[i][j]->getColor() == "white")
				SetConsoleTextAttribute(hConsole, 15);
			if (board[i][j]->getColor() == "space")
				SetConsoleTextAttribute(hConsole, 10);
			if(i==x && j == y)
				SetConsoleTextAttribute(hConsole, 13);
			cout << setw(4) << board[i][j]->getSymb();
			SetConsoleTextAttribute(hConsole, 14);
			cout << "|";
		}
		cout << endl;
		cout << "__________________________________________\n";
	}
	cout << endl;
	cout << endl;
	SetConsoleTextAttribute(hConsole, 15);
}

string Gameboard::getColor(int x, int y) const
{
	return board[x][y]->getColor();
}

Figure * Gameboard::getFigure(int x, int y) const
{
	return board[x][y];
}

Coord Gameboard::getWhiteKing() const
{
	return whiteKing;
}

Coord Gameboard::getBlackKing() const
{
	return blackKing;
}

bool Gameboard::validateBorders(int fromX, int fromY, int toX, int toY)
{
	if (fromX < 0 || fromY < 0 || toX > 7 || toY > 7)
		return false;

	return true;
}

void Gameboard::fillKingPossMove(vector<Coord>& kingPossMoves, int kingX, int kingY) // adds only empty cells
{
	if (!kingPossMoves.empty())
		kingPossMoves.clear();
	string type;
	CELL_FIGURE figure;
	int x = 0;
	int y = 0;
	// left and right points
	x = kingX;
	y = kingY + 1;
	if (!(y < 0 || y > 7))
	{
		type = board[x][y]->getColor();
		figure = board[x][y]->chekCell(type);
		if (figure == EMPTY)
			kingPossMoves.push_back(Coord(x, y));
	}
	y = kingY - 1;
	if (!(y < 0 || y > 7))
	{
		type = board[x][y]->getColor();
		figure = board[x][y]->chekCell(type);
		if (figure == EMPTY)
			kingPossMoves.push_back(Coord(x, y));
	}
	// top and bot
	y = kingY;
	x = kingX + 1;
	if (!(x < 0 || x > 7))
	{
		type = board[x][y]->getColor();
		figure = board[x][y]->chekCell(type);
		if (figure == EMPTY)
			kingPossMoves.push_back(Coord(x, y));
	}
	x = kingX - 1;
	if (!(x < 0 || x > 7))
	{
		type = board[x][y]->getColor();
		figure = board[x][y]->chekCell(type);
		if (figure == EMPTY)
			kingPossMoves.push_back(Coord(x, y));
	}
	// left bot corner
	x = kingX - 1;
	y = kingY - 1;
	if (!(y < 0 || y > 7 || x < 0 || x > 7))
	{
		type = board[x][y]->getColor();
		figure = board[x][y]->chekCell(type);
		if (figure == EMPTY)
			kingPossMoves.push_back(Coord(x, y));
	}
	// right bot corner
	x = kingX + 1;
	y = kingY + 1;
	if (!(y < 0 || y > 7 || x < 0 || x > 7))
	{
		type = board[x][y]->getColor();
		figure = board[x][y]->chekCell(type);
		if (figure == EMPTY)
			kingPossMoves.push_back(Coord(x, y));
	}
	// left bot corner
	x = kingX + 1;
	y = kingY - 1;
	if (!(y < 0 || y > 7 || x < 0 || x > 7))
	{
		type = board[x][y]->getColor();
		figure = board[x][y]->chekCell(type);
		if (figure == EMPTY)
			kingPossMoves.push_back(Coord(x, y));
	}
	// right top corner
	x = kingX - 1;
	y = kingY + 1;
	if (!(y < 0 || y > 7 || x < 0 || x > 7))
	{
		type = board[x][y]->getColor();
		figure = board[x][y]->chekCell(type);
		if (figure == EMPTY)
			kingPossMoves.push_back(Coord(x, y));
	}
}

void Gameboard::setCoords(int fromX, int fromY, int toX, int toY)
{
	board[fromX][fromY]->setFrom(fromX, fromY);
	board[fromX][fromY]->setTo(toX, toY);
}

void Gameboard::setNewCoords(int oldX, int oldY, int newX, int newY)
{
	board[oldX][oldY]->setFromTo(newX, newY, newX, newY);
}

void Gameboard::move(int fromX, int fromY, int toX, int toY)
{
	string player = board[fromX][fromY]->getColor();
	if (board[fromX][fromY]->getName() == "king")
	{
		if (player == "white")
			whiteKing.setCoords(toX, toY);
		if (player == "black")
			blackKing.setCoords(toX, toY);
	}
	board[fromX][fromY]->setHasMoved(true);
	swapCoordsMove(fromX, fromY, toX, toY);
	board[fromX][fromY]->setNewFrom(toX, toY); // new fromCoords for fromFigure = toCoords of toFigure
	board[toX][toY]->setFromTo(fromX, fromY, fromX, fromY); // set new coords for space
	swap(board[fromX][fromY], board[toX][toY]); // swap fromFigure and space
}

void Gameboard::attack(int fromX, int fromY, int toX, int toY)
{
	string player = board[fromX][fromY]->getColor();
	string opponent;
	if (player == "white")
		opponent = "black";
	else if (player == "black")
		opponent == "white";
	else
		return;
	if (board[fromX][fromY]->getName() == "king") // if king moves, we need to change his coords
	{
		if (player == "white")
			whiteKing.setCoords(toX, toY);
		if (player == "black")
			blackKing.setCoords(toX, toY);
	}
	if (board[toX][toY]->getName() == "king") // if a king was attacked after attack validation this is checkmate to an opponent
	{
		cout << "Checkmate to " << opponent << " king\n";
		system("pause");
		exit(0);
	}
	board[fromX][fromY]->setHasMoved(true);
	swapCoordsAttack(fromX, fromY, toX, toY);
	board[fromX][fromY]->setNewFrom(toX, toY); // new fromCoords for fromFigure = toCoords of toFigure
	swap(board[fromX][fromY], board[toX][toY]); // swap two figures
	board[fromX][fromY] = space; // replace beaten figure with space
	board[fromX][fromY]->setFromTo(fromX, fromY, fromX, fromY); // set new coords for this space
}

void Gameboard::attackOnMove(int moveX, int moveY, int attFromX, int attFromY, int attToX, int attToY)
{
	board[attFromX][attFromY]->setHasMoved(true); // attacker has moved
	eraseDefender(attFromX, attFromY, moveX, moveY); // delete defender's coords from it's vector
	swapCoordsMove(attFromX, attFromY, attToX, attToY); // swap attacker's and space coords's
	board[attFromX][attFromY]->setNewFrom(attToX, attToY); // new fromCoords for fromFigure = toCoords of toFigure
	swap(board[attFromX][attFromY], board[attToX][attToY]); // swap space and pawn
	board[moveX][moveY] = space; // replace beaten figure with space
	board[attFromX][attFromY]->setFromTo(attFromX, attFromY, attFromX, attFromY); // set new coords for this space
}

void Gameboard::eraseDefender(int attX, int attY, int defX, int defY)
{
	int attI, defI;
	Coord att(attX, attY), def(defX, defY);
	string color = board[attX][attY]->getColor(); // attacker color
	if (color == "white")
	{
		for (int i = 0; i < white.size(); i++) // find attacker index
		{
			if (white[i] == att)
			{
				attI = i;
				break;
			}
		}
		for (int i = 0; i < black.size(); i++) // find defender index
		{
			if (black[i] == def)
			{
				defI = i;
				break;
			}
		}
		int defX = black[defI].getX();
		int defY = black[defI].getY();
		spaces.push_back(Coord(defX, defY)); // add coords of defender to the spaces
		if (defI == 0)
			black.erase(black.begin()); // delete coord of defender
		else
			black.erase(black.begin() + defI);
	}
	if (color == "black")
	{
		for (int i = 0; i < black.size(); i++) // find attacker index
		{
			if (black[i] == att)
			{
				attI = i;
				break;
			}
		}
		for (int i = 0; i < white.size(); i++) // find defender index
		{
			if (white[i] == def)
			{
				defI = i;
				break;
			}
		}
		int defX = white[defI].getX();
		int defY = white[defI].getY();
		spaces.push_back(Coord(defX, defY));
		if (defI == 0)
			white.erase(white.begin());
		else
			white.erase(white.begin() + defI); // delete coord of defender
	}
}

void Gameboard::swapCoordsAttack(int fromX, int fromY, int toX, int toY)
{
	int attI, defI;
	Coord att(fromX, fromY), def(toX, toY);
	string color = board[fromX][fromY]->getColor(); // attacker color
	if (color == "white")
	{
		for (int i = 0; i < white.size(); i++) // find white index
		{
			if (white[i] == att)
			{
				attI = i;
				break;
			}
		}
		for (int i = 0; i < black.size(); i++) // find black index
		{
			if (black[i] == def)
			{
				defI = i;
				break;
			}
		}
		int defX = black[defI].getX();
		int defY = black[defI].getY();
		white[attI].setCoords(defX, defY); // set attacker's coords to values of def coords
		if (defI == 0)
			black.erase(black.begin()); // delete coord of defender
		else
			black.erase(black.begin() + defI);
	}
	if (color == "black")
	{
		for (int i = 0; i < black.size(); i++) // find black index
		{
			if (black[i] == att)
			{
				attI = i;
				break;
			}
		}
		for (int i = 0; i < white.size(); i++) // find white index
		{
			if (white[i] == def)
			{
				defI = i;
				break;
			}
		}
		int defX = white[defI].getX();
		int defY = white[defI].getY();
		black[attI].setCoords(defX, defY); // set attacker's coords to values of def coords
		if (defI == 0)
			white.erase(white.begin());
		else
			white.erase(white.begin() + defI); // delete coord of defender
	}
	spaces.push_back(Coord(fromX, fromY));
}

void Gameboard::swapCoordsMove(int fromX, int fromY, int toX, int toY)
{
	int figI = 0, spI = 0;
	string color = board[fromX][fromY]->getColor();
	Coord fig(fromX, fromY), sp(toX, toY);
	for (int i = 0; i < spaces.size(); i++) // find space index
	{
		if (spaces[i] == sp)
		{
			spI = i;
			break;
		}
	}
	if (color == "white")
	{
		for (int i = 0; i < white.size(); i++) // find white index
		{
			if (white[i] == fig)
			{
				figI = i;
				break;
			}
		}
		swap(white[figI], spaces[spI]); // swap coords
	}
	if (color == "black")
	{
		for (int i = 0; i < black.size(); i++) // find black index
		{
			if (black[i] == fig)
			{
				figI = i;
				break;
			}
		}
		swap(black[figI], spaces[spI]); // swap coords
	}
}

void Gameboard::validateInput(int& fromX, int& fromY, int& toX, int& toY, string player)
{
	fromX = 0, fromY = 0, toX = 0, toY = 0;
	int turn = 0;
	if (player == "white")
		turn = 1;
	if (player == "black")
		turn = 2;
	cout << "Player " << turn << " select cell to move from\n"; // Player selects a figure
	selectFigure(fromX, fromY);
	cout << "Player " << turn << " select cell to move to\n"; // Player choses position to move to
	selectFigure(toX, toY);
	while (!validateBorders(fromX, fromY, toX, toY)) // validate borders
	{
		fromX = 0, fromY = 0, toX = 0, toY = 0;
		cout << "Out of borders! Enter again!\n";
		cout << "From:\n";
		selectFigure(fromX, fromY);
		cout << "To:\n";
		selectFigure(toX, toY);
	}
}

void Gameboard::selectFigure(int& x, int& y)
{
	Cursor curs;
	char select, direction; // selected figure and direction of cursor's move
	gotoxy(curs);
	while (true)
	{
		while (!_kbhit());
			direction = _getch();
		if (direction == 77) // right
		{
			curs.x += 5;
			gotoxy(curs);
			y += 1;
			if (resetCursX(curs.x))
				gotoxy(curs);
			resetCoord(y);
			select = _getch();
			if (select == 32)
			{
				system("cls");
				printBoard(x, y);
				break;
			}
		}
		else if (direction == 75) // left
		{
			curs.x -= 5;
			gotoxy(curs);
			y -= 1;
			if (resetCursX(curs.x))
				gotoxy(curs);
			resetCoord(y);
			select = _getch();
			if (select == 32)
			{
				system("cls");
				printBoard(x, y);
				break;
			}
		}
		else if (direction == 80) // down
		{
			curs.y += 2;
			gotoxy(curs);
			x += 1;
			if(resetCursY(curs.y))
				gotoxy(curs);
			resetCoord(x);
			select = _getch();
			if (select == 32)
			{
				system("cls");
				printBoard(x, y);
				break;
			}
		}
		else if (direction == 72) // up
		{
			curs.y -= 2;
			gotoxy(curs);
			x -= 1;
			if (resetCursY(curs.y))
				gotoxy(curs);
			resetCoord(x);
			select = _getch();
			if (select == 32)
			{
				system("cls");
				printBoard(x, y);
				break;
			}
		}
	}
}

bool Gameboard::attackOrMove(int fromX, int fromY, int toX, int toY, string player)
{
	Gameboard* g = this; // copy of gameboard to use inside figures
	Figure* from = board[fromX][fromY]; // from figure
	Figure* to = board[toX][toY]; // to figure
	string colorFrom = from->getColor(); // color of from
	string colorTo = to->getColor(); // color of to
	string opponent; // opponent
	if (player == "white") // if player's figures' color is white
		opponent = "black"; // his opponent's ones are black
	if (player == "black") // and
		opponent = "white"; // via versa
	if (colorFrom != player) // not player's figure
		return false;
	if (colorFrom == colorTo) // player tries to move or attack on his own figure
	{
		if ((fromX == toX) && board[fromX][fromY]->getName() == "king" && !check(toX, toY)) // check if it is a castling
		{
			setCoords(fromX, fromY, toX, toY);
			if (validateCastling(fromX, fromY, toX, toY, player))
			{
				castling(fromX, fromY, toX, toY, player);
				return true;
			}
		}
		else
			return false;
	}
	setCoords(fromX, fromY, toX, toY);
	if ((colorFrom != colorTo) && (colorTo == "space")) // if colors are not equal and destinition is space - move
	{
		if (from->validateMove(g))
		{
			if (from->getName() == "pawn" && (toX == 5 || toX == 4))
			{
				if (!tryTakeOnMove(fromX, fromY, toX, toY, player))
				{
					move(fromX, fromY, toX, toY);
					return true;
				}
				else
					return true;
			}
			if (from->getName() == "king")
			{
				if (!canKingMove(opponent))
				{
					return false;
				}
			}
			move(fromX, fromY, toX, toY);
			return true;
		}
	}
	else if ((colorFrom != colorTo) && (colorTo == opponent)) // if colors are not equal and destinition is opponent - attack
	{
		if (from->validateAttack(g))
		{
			attack(fromX, fromY, toX, toY);
			return true;
		}
	}
	return false;
}

bool Gameboard::tryTakeOnMove(int fromX, int fromY, int toX, int toY, string player)
{
	vector<Coord> attacker; // potential attacker vector of coords
	vector<Coord> defLine; // line of potential defender
	vector<Coord> wayFrom = board[fromX][fromY]->getWay(); // way of pawn
	Figure* att; // potential attacker
	string opponent; // opponent
	int attX = 0, attY = 0, lineX = 0, lineY = 0, wayX = 0, wayY = 0; // tmp vars
	Coord line;
	if (player == "white")
	{
		attacker = black;
		defLine = whiteLine;
		opponent = "black";
	}
	if (player == "black")
	{
		attacker = white;
		defLine = blackLine;
		opponent = "white";
	}
	for (int i = 0; i < attacker.size(); i++) // find opponent's pawns
	{
		attX = attacker[i].getX();
		attY = attacker[i].getY();
		att = board[attX][attY];
		if (att->getName() != "pawn") // skip not pawns
			continue;
		for (int j = 0, wayI = 0; j < defLine.size(); j++) // find equal coords of player's pawn move coords and player's line coords
		{
			lineX = defLine[j].getX();
			lineY = defLine[j].getY();
			while (wayI != (wayFrom.size() - 1)) // find way coord
			{
				line.setCoords(lineX, lineY);
				wayX = wayFrom[wayI].getX();
				wayY = wayFrom[wayI].getY();
				if (wayX == -1 || wayY == -1)
				{
					wayI = 0;
					break;
				}
				if (wayFrom[wayI] == line)
				{
					if (att->validateAttack(this, wayX, wayY)) // try attack this point by opponent's pawn
					{
						attackOnMove(fromX, fromY, attX, attY, wayX, wayY);
						return true;
					}
				}
				wayI++;
			}
		}
	}
	return false;
}

void Gameboard::play()
{
	int fromX = 0, fromY = 0, toX = 0, toY = 0;
	string white = "white", black = "black";
	fillBoard();
	for (int i = 0;; i++)
	{
		system("cls");
		printBoard();
		if (i % 2 == 0) // player 1
		{
			validateInput(fromX, fromY, toX, toY, white); // select move
			if (!attackOrMove(fromX, fromY, toX, toY, white)) // move
			{
				cout << "Invalid move!\n";
				system("pause");
				i--;
				continue;
			}
			else
				validateAnyStates(fromX, fromY, toX, toY, toX, white); // check for anything
		}
		else // player 2
		{
			validateInput(fromX, fromY, toX, toY, black);
			if (!attackOrMove(fromX, fromY, toX, toY, black))
			{
				cout << "Invalid move!\n";
				system("pause");
				i--;
				continue;
			}
			else
				validateAnyStates(fromX, fromY, toX, toY, toX, black);
		}
	}
}

bool Gameboard::check(int attX, int attY)
{
	Gameboard* g = this;
	return board[attX][attY]->validateCheck(g);
}

bool Gameboard::checkMate(int attPosX, int attPosY)
{
	string color; // enemy king color
	string attColor = board[attPosX][attPosY]->getColor(); // attacker color
	string attName = board[attPosX][attPosY]->getName(); // attacker name
	vector<Coord> way; // attacker way
	int kingX = 0, kingY = 0;
	if (attColor == "white")
	{
		kingX = blackKing.getX();
		kingY = blackKing.getY();
		color = "black";
	}
	if (attColor == "black")
	{
		kingX = whiteKing.getX();
		kingY = whiteKing.getY();
		color = "white";
	}
	if (check(attPosX, attPosY)) // if check - validate possible variants to save king
	{
		board[attPosX][attPosY]->fillWay(attPosX, attPosY, kingX, kingY);
		way = board[attPosX][attPosY]->getWay();
		system("cls");
		printBoard();
		cout << "Check to " << color << " king\n";
		system("pause");
		if (!canAttackerBeTaken(attPosX, attPosY)) // try to take down the attacker
		{
			if (attName == "knight" || attName == "pawn") // if can't and it is pawn or knight - checkmate
				return true;
			if (!canKingBeCovered(way, attColor)) // if can't - try to cover king
			{
				if (canKingMove(attColor)) // can king move? no checkmate
					return false;
				else
					return true; // king can't move? checkmate
				return true;
			}
			else
				return false;
			return true;
		}
		else // can be taken? no checkmate
			return false;
		return true;
	}
	return false;
}

bool Gameboard::canAttackerBeTaken(int attX, int attY)
{
	string attColor = board[attX][attY]->getColor();
	string currColor;
	vector<Coord> defender;
	int defX = 0, defY = 0;
	Figure* def;
	Gameboard* g = this;
	if (attColor == "white")
		defender = black;
	if (attColor == "black")
		defender = white;
	for (int i = 0; i < defender.size(); i++)
	{
		defX = defender[i].getX();
		defY = defender[i].getY();
		def = board[defX][defY];
		if (def->validateAttack(g, attX, attY))
			return true;
	}
	return false;
}

bool Gameboard::canKingBeCovered(vector<Coord> attWay, string attacker)
{
	int attX = 0, attY = 0, defX = 0, defY = 0;
	Gameboard* g = this;
	vector<Coord> defender;
	if (attacker == "white")
		defender = black;
	else if (attacker == "black")
		defender = white;
	else
		return false;
	for (int i = 0; i < defender.size(); i++) // check each defender's side figure for ability to move on eny of attacker's way position
	{
		defX = defender[i].getX();
		defY = defender[i].getY();
		if (board[defX][defY]->getName() == "king")
			continue;
		for (int j = 0; j < attWay.size(); j++) // get attacker's way position coordinates
		{
			attX = attWay[j].getX();
			attY = attWay[j].getY();
			if (attX == -1 || attY == -1)
				break;
			if (board[defX][defY]->validateMove(g, attX, attY))
				return true;
		}
	}
	return false;
}

bool Gameboard::canKingMove(string attacker)
{
	Gameboard* g = this;
	int kingX, kingY; // coords of king
	int kingPossX, kingPossY; // possible coords where king can move
	vector<Coord> possMoves; // vector of possible king moves
	vector<Coord> attackerV;
	int canMove = 0;
	int attX = 0, attY = 0;
	Figure* king;
	Figure* att;
	if (attacker == "white")
	{
		kingX = blackKing.getX();
		kingY = blackKing.getY();
		attackerV = white;
	}
	if (attacker == "black")
	{
		kingX = whiteKing.getX();
		kingY = whiteKing.getY();
		attackerV = black;
	}
	king = board[kingX][kingY]; // king, which is under attack
	fillKingPossMove(possMoves, kingX, kingY); // fill it's possible moves
	if (possMoves.size() == 0)
		return true;
	for (int i = 0; i < possMoves.size(); i++) // check every possible coord
	{
		kingPossX = possMoves[i].getX();
		kingPossY = possMoves[i].getY();
		if (king->validateMove(g, kingPossX, kingPossY))
		{
			canMove++;
			for (int i = 0; i < attackerV.size(); i++)
			{
				attX = attackerV[i].getX();
				attY = attackerV[i].getY();
				att = board[attX][attY];
				if (att->validateMove(g, kingPossX, kingPossY) || att->validateAttack(g, kingPossX, kingPossY))
					canMove--;
			}
		}
	}
	if (canMove >= 1)
		return true;
	return false;
}

bool Gameboard::checkTheCell(CELL_FIGURE figure)
{
	return figure == EMPTY;
}

bool Gameboard::validateChange(int limit, int toX)
{
	if (limit == -1)
		return false;
	if (limit == toX)
		return true;
	return false;
}

void Gameboard::changeFigure(int toX, int toY, string player)
{
	bool figureSelected = false;
	char fig;
	while (!figureSelected)
	{
		if (player == "white")
		{
			system("cls");
			cout << "Your pawn has reached the end of gameboard. Select a figure to replace it:\n";
			cout << "Q - queen\n";
			cout << "B - bishop\n";
			cout << "R - rook\n";
			cout << "N - knight\n";
			cin >> fig;
			switch (fig)
			{
			case 'Q':
			{
				board[toX][toY] = new Queen("queen", player, fig, 8, -1, false);
				figureSelected = true;
				break;
			}
			case 'B':
			{
				board[toX][toY] = new Bishop("bishop", player, fig, 8, -1, false);
				figureSelected = true;
				break;
			}
			case 'R':
			{
				board[toX][toY] = new Rook("rook", player, fig, 8, -1, false);
				figureSelected = true;
				break;
			}
			case 'N':
			{
				board[toX][toY] = new Knight("knight", player, fig, 8, -1, false);
				figureSelected = true;
				break;
			}
			default:
			{
				cout << "Error\n";
				system("pause");
				break;
			}
			}
		}
		if (player == "black")
		{
			system("cls");
			cout << "Your pawn has reached the end of gameboard. Select a figure to replace it:\n";
			cout << "q - queen\n";
			cout << "b - bishop\n";
			cout << "r - rook\n";
			cout << " - knight\n";
			cin >> fig;

			switch (fig)
			{
			case 'q':
			{
				board[toX][toY] = new Queen("queen", player, fig, 8, -1, false);
				figureSelected = true;
				break;
			}
			case 'b':
			{
				board[toX][toY] = new Bishop("bishop", player, fig, 8, -1, false);
				figureSelected = true;
				break;
			}
			case 'r':
			{
				board[toX][toY] = new Rook("rook", player, fig, 8, -1, false);
				figureSelected = true;
				break;
			}
			case 'n':
			{
				board[toX][toY] = new Knight("knight", player, fig, 8, -1, false);
				figureSelected = true;
				break;
			}
			default:
			{
				cout << "Error\n";
				system("pause");
				break;
			}
			}
		}
	}
}

bool Gameboard::stalemate(string player)
{
	Gameboard* g(this); // copy of current gameboard to work with
	vector<Coord> attacker; // vector of coords of an attacker
	vector<Coord> defender; // vector of coords of a defender
	vector<Coord> empties = spaces; // vector of spaces
	string opponent;
	int attX = 0, attY = 0, defX = 0, defY = 0, emX = 0, emY = 0; // tmp vars
	int cantMove = 0; // quantity of figures that can't move
	if (player == "white")
	{
		attacker = black;
		defender = white;
		opponent = "black";
	}
	if (player == "black")
	{
		attacker = white;
		defender = black;
		opponent = "white";
	}

	if (!canKingMove(player))
	{
		return true;
	}

	for (int i = 0; i < defender.size(); i++) // check defenders figures for an ability to move
	{
		defX = defender[i].getX(); // def X
		defY = defender[i].getY(); // def Y
		for (int emI = 0; emI < empties.size(); emI++)
		{
			emX = empties[emI].getX(); // space X
			emY = empties[emI].getY(); // space Y
			for (int attI = 0; attI < attacker.size(); attI++)
			{
				if (board[defX][defY]->validateMove(g, emX, emY)) // validate figure's move to every empty cell on board
				{
					g->move(defX, defY, emX, emY); // move to aply changes
					attX = attacker[attI].getX(); // attacker X
					attY = attacker[attI].getY(); // attacker Y
					if (board[attX][attY]->validateCheck(g)) // validate check to def king after move
					{
						cantMove++; // if after move - check to def's king - cant move
						g->move(emX, emY, defX, defY); // move back current figure
						break;
					}
					else
					{
						g->move(emX, emY, defX, defY); // move back current figure
						return false; // can move and no check in process? no stalemate
					}
				}
			}
		}
	}
	return (cantMove == defender.size()); // if quantity of figures that can't move == quannity of def figures - it is a stalemate
}

void Gameboard::validateAnyStates(int fromX, int fromY, int attX, int attY, int pawnX, string player)
{
	string opponent;
	if (player == "white")
		opponent = "black";
	if (player == "black")
		opponent = "white";
	if (checkMate(attX, attY)) // is there a checkmate?
	{
		system("cls");
		printBoard();
		cout << "Checkmate to " << opponent << " king\n";
		system("pause");
		exit(0);
	}
	if (validateChange(board[attX][attY]->getLimit(), pawnX)) // is there a change pawn to another figure?
	{
		changeFigure(attX, attY, player);
		system("cls");
		printBoard();
		return;
	}
	if (!check(attX, attY)) // is there a check?
	{
		if (stalemate(player)) // no? stalemate during player's move?
		{
			system("cls");
			printBoard();
			cout << "Stalemate. Game over\n";
			system("pause");
			exit(0);
		}
	}
}

void Gameboard::castling(int fromX, int fromY, int toX, int toY, string player) // swap king and rook
{
	if (fromY > toY)
		longCastling(fromX, fromY, toX, toY, player);
	if (fromY < toY)
		shortCastling(fromX, fromY, toX, toY, player);
}

void Gameboard::longCastling(int fromX, int fromY, int toX, int toY, string player)
{
	int kingY = fromY - 2; // new king Y coord
	int rookY = toY + 3; // new rook coord
	int checkX = 0, checkY = 0, oldX = 0, oldY = 0; // tmp vars for checks
	vector<Coord> side;
	setNewCoords(fromX, fromY, fromX, kingY); // set new coords for king
	setNewCoords(toX, toY, toX, rookY); // set new coords for rook
	if (player == "white")
	{
		side = white;
		whiteKing.setCoords(fromX, kingY);
	}
	if (player == "black")
	{
		side = black;
		blackKing.setCoords(fromX, kingY);
	}
	for (int i = 0; i < side.size(); i++) // find old king's coords and replace them
	{
		checkX = side[i].getX();
		checkY = side[i].getY();
		if (checkX == fromX && checkY == fromY)
		{
			side[i].setCoords(fromX, kingY);
			break;
		}
	}
	for (int i = 0; i < spaces.size(); i++) // find old space's coords and replace them
	{
		checkX = spaces[i].getX();
		checkY = spaces[i].getY();
		if (checkX == fromX && checkY == kingY)
		{
			spaces[i].setCoords(fromX, fromY);
			break;
		}
	}
	for (int i = 0; i < side.size(); i++) // find old rook's coords and replace them
	{
		checkX = side[i].getX();
		checkY = side[i].getY();
		if (checkX == toX && checkY == toY)
		{
			side[i].setCoords(toX, rookY);
			break;
		}
	}
	for (int i = 0; i < spaces.size(); i++) // find old space's coords and replace them
	{
		checkX = spaces[i].getX();
		checkY = spaces[i].getY();
		if (checkX == toX && checkY == rookY)
		{
			spaces[i].setCoords(toX, toY);
			break;
		}
	}
	if (player == "white")
		white = side;
	if (player == "black")
		black = side;
	swap(board[fromX][fromY], board[fromX][kingY]); // set king to a new position
	swap(board[toX][toY], board[toX][rookY]); // set rook to a new position
}

void Gameboard::shortCastling(int fromX, int fromY, int toX, int toY, string player)
{
	int kingY = fromY + 2; // new king Y coord
	int rookY = toY - 2; // new rook coord
	int checkX = 0, checkY = 0; // tmp vars for checks
	vector<Coord> side;
	setNewCoords(fromX, fromY, fromX, kingY); // set new coords for king
	setNewCoords(toX, toY, toX, rookY); // set new coords for rook
	if (player == "white")
	{
		side = white;
		whiteKing.setCoords(fromX, kingY);
	}
	if (player == "black")
	{
		side = black;
		blackKing.setCoords(fromX, kingY);
	}
	for (int i = 0; i < side.size(); i++) // find old king's coords and replace them
	{
		checkX = side[i].getX();
		checkY = side[i].getY();
		if (checkX == fromX && checkY == fromY)
		{
			side[i].setCoords(fromX, kingY);
			break;
		}
	}
	for (int i = 0; i < spaces.size(); i++) // find old space's coords and replace them
	{
		checkX = spaces[i].getX();
		checkY = spaces[i].getY();
		if (checkX == fromX && checkY == kingY)
		{
			spaces[i].setCoords(fromX, fromY);
			break;
		}
	}
	for (int i = 0; i < side.size(); i++) // find old rook's coords and replace them
	{
		checkX = side[i].getX();
		checkY = side[i].getY();
		if (checkX == toX && checkY == toY)
		{
			side[i].setCoords(toX, rookY);
			break;
		}
	}
	for (int i = 0; i < spaces.size(); i++) // find old space's coords and replace them
	{
		checkX = spaces[i].getX();
		checkY = spaces[i].getY();
		if (checkX == toX && checkY == rookY)
		{
			spaces[i].setCoords(toX, toY);
			break;
		}
	}
	if (player == "white")
		white = side;
	if (player == "black")
		black = side;
	swap(board[fromX][fromY], board[fromX][kingY]); // set king to a new position
	swap(board[toX][toY], board[toX][rookY]); // set rook to a new position
}

bool Gameboard::validateCastling(int fromX, int fromY, int toX, int toY, string player)
{
	Figure* rook; // rook
	Figure* king; // king
	Figure* att; // figure to check atack from
	Gameboard* g = this; // pointer on current gameboard to work with
	vector<Coord> between;
	vector<Coord> attacker;
	int checkY = 0, lY = 0, bY = 0, attX = 0, attY = 0, lineX = 0, lineY = 0; // tmp vars for further checks
	if (fromX != toX || fromY == toY) // if not horizontal
		return false;
	if (player == "white" && (fromX != 7 || toX != 7)) // if white's figures are not at 7-th line
		return false;
	else if (player == "black" && (fromX != 0 || toX != 0)) // if black's figures are not at 0 line
		return false;
	if (board[fromX][fromY]->getName() == "king" && board[toX][toY]->getName() == "rook") // set king and rook
	{
		king = board[fromX][fromY];
		rook = board[toX][toY];
	}
	else // if not - false
		return false;
	if (king->getHasMoved() == true || rook->getHasMoved() == true) // if figures have moved
		return false;
	if (fromY > toY) // set bigger and lesser Y
	{
		bY = fromY;
		lY = toY;
	}
	if (fromY < toY) // set bigger and lesser Y
	{
		bY = toY;
		lY = fromY;
	}
	for (int i = lY; i < bY - 1; i++) // set coordinates of line between king and rook
	{
		between.push_back(Coord(fromX, i + 1));
	}
	for (int i = 0; i < between.size(); i++) // if any cell on line is filled not by space - false
	{
		checkY = between[i].getY();
		if (board[fromX][checkY]->getName() != "space")
			return false;
	}
	if (player == "white") // set attacker coords vector
		attacker = black;
	if (player == "black")
		attacker = white;
	for (int i = 0; i < attacker.size(); i++) // check every of attacker's figures for a possibility of attack on any of line's cels
	{
		attX = attacker[i].getX();
		attY = attacker[i].getY();
		att = board[attX][attY];
		for (int j = 0; j < between.size(); j++)
		{
			lineX = between[j].getX();
			lineY = between[j].getY();
			if (att->validateAttack(g, lineX, lineY)) // if any cell of the line is under attack - false
				return false;
		}
	}
	return true;
}

void Gameboard::printCoords(vector<Coord> coords)
{
	for (int i = 0; i < coords.size(); i++)
	{
		cout << "(" << coords[i].getX() << "), " << "(" << coords[i].getY() << ")" << endl;
	}
	cout << endl;
	LINE;
}
