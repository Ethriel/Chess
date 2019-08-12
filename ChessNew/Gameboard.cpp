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
			// space
			if (i >= 2 && i < 6)
			{
				board[i][j] = new Space("space", "space", '*', 0, -1, false);
				spaces.push_back(Coord(i, j));
			}
			// white pawns
			else if (i == 6)
			{
				board[i][j] = new Pawn("pawn", "white", 'P', 2, 0, false);
				white.push_back(Coord(i, j));
			}
			// black pawns
			else if (i == 1)
			{
				board[i][j] = new Pawn("pawn", "black", 'p', 2, 7, false);
				black.push_back(Coord(i, j));
			}
			// white rooks
			else if ((i == 7 && j == 0) || (i == 7 && j == 7))
			{
				board[i][j] = new Rook("rook", "white", 'R', 8, -1, false);
				white.push_back(Coord(i, j));
			}
			// black rooks
			else if ((i == 0 && j == 0) || (i == 0 && j == 7))
			{
				board[i][j] = new Rook("rook", "black", 'r', 8, -1, false);
				black.push_back(Coord(i, j));
			}
			// white knights
			else if ((i == 7 && j == 1) || (i == 7 && j == 6))
			{
				board[i][j] = new Knight("knight", "white", 'N', 8, -1, false);
				white.push_back(Coord(i, j));
			}
			// black knights
			else if ((i == 0 && j == 1) || (i == 0 && j == 6))
			{
				board[i][j] = new Knight("knight", "black", 'n', 8, -1, false);
				black.push_back(Coord(i, j));
			}
			// white bishops
			else if ((i == 7 && j == 2) || (i == 7 && j == 5))
			{
				board[i][j] = new Bishop("bishop", "white", 'B', 8, -1, false);
				white.push_back(Coord(i, j));
			}
			// black bishops
			else if ((i == 0 && j == 2) || (i == 0 && j == 5))
			{
				board[i][j] = new Bishop("knight", "black", 'b', 8, -1, false);
				black.push_back(Coord(i, j));
			}
			// white king
			else if (i == 7 && j == 4)
			{
				board[i][j] = new King("king", "white", 'K', 1, -1, false);
				white.push_back(Coord(i, j));
				whiteKing.setCoords(i, j);
			}
			// black king
			else if (i == 0 && j == 4)
			{
				board[i][j] = new King("king", "black", 'k', 1, -1, false);
				black.push_back(Coord(i, j));
				blackKing.setCoords(i, j);
			}
			// white queen
			else if (i == 7 && j == 3)
			{
				board[i][j] = new Queen("queen", "white", 'Q', 1, -1, false);
				white.push_back(Coord(i, j));
			}
			// black queen
			else if (i == 0 && j == 3)
			{
				board[i][j] = new Queen("queen", "black", 'q', 1, -1, false);
				black.push_back(Coord(i, j));
			}
			// set coords
			board[i][j]->setFrom(i, j);
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
	/*
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			board[i][j] = new Space("space", "space", '*', 0, -1, false);
			board[i][j]->setFrom(i, j);
		}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i == 6 && j == 1)
			{
				board[i][j] = new Pawn("pawn", "white", 'P', 2, 0, false);
				white.push_back(Coord(i, j));
				continue;
			}
			if (i == 1 && j == 6)
			{
				board[i][j] = new Pawn("pawn", "black", 'p', 2, 7, false);
				black.push_back(Coord(i, j));
				continue;
			}
			if (i == 7 && j == 4)
			{
				board[i][j] = new King("king", "white", 'K', 1, -1, false);
				white.push_back(Coord(i, j));
				whiteKing.setCoords(i, j);
				continue;
			}
			if (i == 1 && j == 4)
			{
				board[i][j] = new King("king", "black", 'k', 1, -1, false);
				black.push_back(Coord(i, j));
				blackKing.setCoords(i, j);
				continue;
			}
			board[i][j] = new Space("space", "space", '*', 0, -1, false);
			spaces.push_back(Coord(i, j));
			board[i][j]->setFrom(i, j);
		}
		
	}
	*/
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i == 4 && j == 1)
			{
				board[i][j] = new Pawn("pawn", "black", 'p', 2, 7, false);
				black.push_back(Coord(i, j));
				board[i][j]->setFrom(i, j);
				continue;
			}
			if (i == 6 && j == 2)
			{
				board[i][j] = new Pawn("pawn", "white", 'P', 2, 0, false);
				white.push_back(Coord(i, j));
				board[i][j]->setFrom(i, j);
				continue;
			}
			if (i == 0 && j == 3)
			{
				board[i][j] = new King("king", "black", 'k', 1, -1, false);
				black.push_back(Coord(i, j));
				blackKing.setCoords(i, j);
				continue;
			}
			if (i == 7 && j == 3)
			{
				board[i][j] = new King("king", "white", 'K', 1, -1, false);
				white.push_back(Coord(i, j));
				whiteKing.setCoords(i, j);
				continue;
			}
			if (i == 4 && j == 4)
			{
				board[i][j] = new Bishop("bishop", "white", 'B', 8, -1, false);
				white.push_back(Coord(i, j));
				continue;
			}
			board[i][j] = new Space("space", "space", '*', 0, -1, false);
			spaces.push_back(Coord(i, j));
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

bool Gameboard::validateBorders(int fromX, int fromY, int toX, int toY)
{
	if (fromX < 0 || fromY < 0 || toX > 7 || toY > 7)
		return false;

	return true;
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

int Gameboard::switchCoord(char coord)
{
	switch (coord)
	{
	case 'a':
	case 'A':
		return 0;
	case 'b':
		return 1;
	case 'c':
		return 2;
	case 'd':
		return 3;
	case 'e':
		return 4;
	case 'f':
		return 5;
	case 'g':
		return 6;
	case 'h':
		return 7;
	case 'B':
		return 1;
	case 'C':
		return 2;
	case 'D':
		return 3;
	case 'E':
		return 4;
	case 'F':
		return 5;
	case 'G':
		return 6;
	case 'H':
		return 7;
	default:
		return -1;
	}
	return -1;
}

void Gameboard::setFigures(Figure *& from, Figure *& to, int fromX, int fromY, int toX, int toY)
{
	from = board[fromX][fromY];
	to = board[toX][toY];
}

void Gameboard::setCoords(int fromX, int fromY, int toX, int toY)
{
	board[fromX][fromY]->setFrom(fromX, fromY);
	board[fromX][fromY]->setTo(toX, toY);
}

void Gameboard::move(int fromX, int fromY, int toX, int toY)
{
	board[fromX][fromY]->setHasMoved(true);
	swapCoordsMove(fromX, fromY, toX, toY);
	board[fromX][fromY]->setNewFrom(toX, toY); // new fromCoords for fromFigure = toCoords of toFigure
	board[toX][toY]->setFromTo(fromX, fromY, fromX, fromY); // set new coords for space
	swap(board[fromX][fromY], board[toX][toY]); // swap fromFigure and space
}

void Gameboard::attack(int fromX, int fromY, int toX, int toY)
{
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
	int turn = 0;
	if (player == "white")
		turn = 1;
	if (player == "black")
		turn = 2;
	char fromYc, toYc;
	cout << "Player " << turn << " enter coordinates of your figure:\n"; // Player selects a figure
	cin >> fromYc;
	cin >> fromX;
	fromY = switchCoord(fromYc);
	while (!cin.good())
	{
		cin.clear();
		cin.ignore();
		cout << "Re-enter second coordinate! Must be a number\n";
		cin >> fromX;
	}
	fromX--;
	cout << "Player " << turn << " enter coordinates where you want to move:\n"; // Player choses position to move to
	cin >> toYc;
	cin >> toX;
	toY = switchCoord(toYc);
	while (!cin.good())
	{
		cin.clear();
		cin.ignore();
		cout << "Re-enter second coordinate! Must be a number\n";
		cin >> toX;
	}
	toX--;
	while (!validateBorders(fromX, fromY, toX, toY))
	{
		cout << "Out of borders! Enter again!\n";
		cout << "From:\n";
		cin >> fromYc;
		cin >> fromX;
		fromY = switchCoord(fromYc);
		while (!cin.good())
		{
			cin.clear();
			cin.ignore();
			cout << "Re-enter second coordinate! Must be a number\n";
			cin >> fromX;
		}
		fromX--;
		cout << "To:\n";
		cin >> toYc;
		cin >> toX;
		toY = switchCoord(toYc);
		while (!cin.good())
		{
			cin.clear();
			cin.ignore();
			cout << "Re-enter second coordinate! Must be a number\n";
			cin >> toX;
		}
		toX--;
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
		return false;
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
	int fromX, fromY, toX, toY;
	string white = "white", black = "black";
	//fillBoard();
	fillTestBoard();
	for (int i = 0;; i++)
	{
		system("cls");
		printBoard();
		if (i % 2 == 0)
		{
			validateInput(fromX, fromY, toX, toY, white);
			if (!attackOrMove(fromX, fromY, toX, toY, white))
			{
				cout << "Invalid move!\n";
				system("pause");
				i--;
				continue;
			}
			else
				validateAnyStates(fromX, fromY, toX, toY, toX, white);
		}
		else
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
	vector<Coord> way = board[attPosX][attPosY]->getWay(); // attacker way
	if (attColor == "white")
		color = "black";
	if (attColor == "black")
		color = "white";
	if (check(attPosX, attPosY)) // if check - validate possible variants to save king
	{
		if (!canAttackerBeTaken(attPosX, attPosY)) // try to take down the attacker
		{
			if (attName == "knight" || attName == "pawn") // if can't and it is pawn or knight - checkmate
				return true;
			if (!canKingBeCovered(way, attColor)) // if can't - try to cover king
			{
				if (canKingMove(way, attColor)) // can king move? yes? then no checkmate
					return false;
				else
					return true; //no? checkmate
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
	Gameboard* g = this;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			currColor = board[i][j]->getColor();
			if (currColor == attColor) // skip enemies
				continue;
			if (currColor == "space") // skip spaces
				continue;
			if (board[i][j]->validateAttack(g, attX, attY)) // try to validate attack on attacker
				return true;
		}
	}
	return false;
}

bool Gameboard::canKingBeCovered(vector<Coord> attWay, string attacker)
{
	int attX, attY;
	Gameboard* g = this;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0; k < attWay.size(); k++)
			{
				attX = attWay[k].getX();
				attY = attWay[k].getY();
				if (board[i][j]->getColor() == attacker) // skip enemies
					continue;
				if (board[i][j]->getColor() == "space") // skip spaces
					continue;
				if (attX == -1 || attY == -1)
					break;
				if (board[i][j]->validateMove(g, attX, attY)) // try to move to any of attaker's way coords
					return true;
			}
		}
	}
	return false;
}

bool Gameboard::canKingMove(vector<Coord> attWay, string attacker)
{
	CELL_FIGURE cellToCheck;
	int xMoves[3] = { 0, -1, 1 }; // possible moves by X
	int yMoves[2] = { -1, 1 }; // possible moves by Y
	int xCheck = 0, yCheck = 0; // coords to check
	int kingX, kingY; // coords of king
	string kingColor, cellColor;
	int wayX, wayY; // coords of way of the attacker
	if (attacker == "white")
	{
		kingX = blackKing.getX();
		kingY = blackKing.getY();
		kingColor = "black";
	}
	if (attacker == "black")
	{
		kingX = whiteKing.getX();
		kingY = whiteKing.getY();
		kingColor = "white";
	}

	// king can move to left or to right
	for (int i = 0; i < 2; i++)
	{
		yCheck = kingY + yMoves[i]; // y coord  to check
		for (int j = 0; j < 3; j++)
		{
			xCheck = kingX + xMoves[j]; // x coord to check
			if (!validateBorders(xCheck, yCheck, xCheck, yCheck)) // skip out of borders
				continue;
			cellColor = board[xCheck][yCheck]->getColor();
			cellToCheck = board[xCheck][yCheck]->chekCell(xCheck, yCheck, cellColor);
			if (checkTheCell(cellToCheck)) // cell is empty?
			{
				for (int k = 0; k < attWay.size(); k++) // check if coords of possible move doesn't cross with coords of way of the attacker
				{
					wayX = attWay[k].getX();
					wayY = attWay[k].getY();
					if (wayX == -1 || wayY == -1)
						break;
					if (xCheck == wayX && yCheck == wayY) // if so - skip
						continue;
					else // no? king can move there
						return true;
				}
			}
		}
	}
	// or up or down
	for (int i = 0; i < 1; i++)
	{
		yCheck = kingX;
		for (int j = 1; j < 2; j++)
		{
			xCheck = kingX + xMoves[j];
			if (!validateBorders(xCheck, yCheck, xCheck, yCheck))
				continue;
			cellToCheck = board[kingX][kingY]->chekCell(xCheck, yCheck, kingColor);
			if (checkTheCell(cellToCheck))
			{
				for (int k = 0; k < attWay.size(); k++)
				{
					wayX = attWay[k].getX();
					wayY = attWay[k].getY();
					if (wayX == -1 || wayY == -1)
						break;
					if (xCheck == wayX && yCheck == wayY)
						continue;
					else
						return true;
				}
			}
		}
	}
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
	system("cls");
	printBoard();
	Gameboard* g(this); // copy of current gameboard to work with
	vector<Coord> attacker; // vector of coords of an attacker
	vector<Coord> defender; // vector of coords of a defender
	vector<Coord> empties = spaces; // vector of spaces
	int attX = 0, attY = 0, defX = 0, defY = 0, emX = 0, emY = 0; // tmp vars
	int cantMove = 0; // quantity of figures that can't move
	Figure* fig;
	Figure* attc;
	if (player == "white")
	{
		attacker = black;
		defender = white;
	}
	if (player == "black")
	{
		attacker = white;
		defender = black;
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
						//g->move(emX, emY, defX, defY); // move back current figure
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
	if ((fromX == attX) && board[fromX][fromY]->getName() == "king" && !check(attX, attY)) // check if it is a castling
	{
		if (validateCastling(fromX, fromY, attX, attY, player))
		{
			castling(fromX, fromY, attX, attY, player);
		}
	}
	if (checkMate(attX, attY))
	{
		system("cls");
		printBoard();
		cout << "Checkmate to " << opponent << " king\n";
		system("pause");
		exit(0);
	}
	if (check(attX, attY))
	{
		cout << "Check to " << opponent << " king\n";
		system("pause");
		return;
	}
	if (validateChange(board[attX][attY]->getLimit(), pawnX))
	{
		changeFigure(attX, attY, player);
		system("cls");
		printBoard();
		return;
	}
	if (!check(attX, attY))
	{
		if (stalemate(player))
		{
			system("cls");
			printBoard();
			cout << "Stalemate. Game over\n";
			system("pause");
			exit(0);
		}
	}
}

void Gameboard::castling(int fromX, int fromY, int toX, int toY, string player)
{
	if (fromX > toX)
		longCastling(fromX, fromY, toX, toY, player);
	if (fromX < toX)
		shortCastling(fromX, fromY, toX, toY, player);
}

void Gameboard::longCastling(int fromX, int fromY, int toX, int toY, string player)
{
	int kingY = fromY - 2; // new king Y coord
	int rookY = toY + 3; // new rook coord
	int checkX = 0, checkY = 0; // tmp vars for checks
	board[fromX][fromY]->setFrom(fromX, kingY); // set new coords for king
	board[toX][toY]->setFrom(toX, rookY); // set new coords for rook
	if (player == "white")
	{
		for (int i = 0; i < white.size(); i++) // find old king's coords and replace them
		{
			checkX = white[i].getX();
			checkY = white[i].getY();
			if (checkX == fromX && checkY == fromY)
			{
				white[i].setCoords(fromX, kingY);
				break;
			}
		}
		for (int i = 0; i < white.size(); i++) // find old rook's coords and replace them
		{
			checkX = white[i].getX();
			checkY = white[i].getY();
			if (checkX == toX && checkY == toY)
			{
				white[i].setCoords(toX, rookY);
				break;
			}
		}
	}
	if (player == "black")
	{
		for (int i = 0; i < black.size(); i++) // find old king's coords and replace them
		{
			checkX = black[i].getX();
			checkY = black[i].getY();
			if (checkX == fromX && checkY == fromY)
			{
				black[i].setCoords(fromX, kingY);
				break;
			}
		}
		for (int i = 0; i < black.size(); i++)  // find old rook's coords and replace them
		{
			checkX = black[i].getX();
			checkY = black[i].getY();
			if (checkX == toX && checkY == toY)
			{
				black[i].setCoords(toX, rookY);
				break;
			}
		}
	}
	swap(board[fromX][fromY], board[fromX][kingY]); // set king to a new position
	swap(board[toX][toY], board[toX][rookY]); // set rook to a new position
}

void Gameboard::shortCastling(int fromX, int fromY, int toX, int toY, string player)
{
	int kingY = fromY + 2; // new king Y coord
	int rookY = toY - 2; // new rook coord
	int checkX = 0, checkY = 0; // tmp vars for checks
	board[fromX][fromY]->setFrom(fromX, kingY); // set new coords for king
	board[toX][toY]->setFrom(toX, rookY); // set new coords for rook
	if (player == "white")
	{
		for (int i = 0; i < white.size(); i++) // find old king's coords and replace them
		{
			checkX = white[i].getX();
			checkY = white[i].getY();
			if (checkX == fromX && checkY == fromY)
			{
				white[i].setCoords(fromX, kingY);
				break;
			}
		}
		for (int i = 0; i < white.size(); i++) // find old rook's coords and replace them
		{
			checkX = white[i].getX();
			checkY = white[i].getY();
			if (checkX == toX && checkY == toY)
			{
				white[i].setCoords(toX, rookY);
				break;
			}
		}
	}
	if (player == "black")
	{
		for (int i = 0; i < black.size(); i++) // find old king's coords and replace them
		{
			checkX = black[i].getX();
			checkY = black[i].getY();
			if (checkX == fromX && checkY == fromY)
			{
				black[i].setCoords(fromX, kingY);
				break;
			}
		}
		for (int i = 0; i < black.size(); i++)  // find old rook's coords and replace them
		{
			checkX = black[i].getX();
			checkY = black[i].getY();
			if (checkX == toX && checkY == toY)
			{
				black[i].setCoords(toX, rookY);
				break;
			}
		}
	}
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
	bool canBeAttacked = false;
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
		for (int j = 0; j < between.size(); j++)
		{
			lineX = between[j].getX();
			lineY = between[j].getY();
			if (board[attX][attY]->validateAttack(g, lineX, lineY)) // if any cell of the line is under attack - false
				return false;
		}
		if (canBeAttacked == false)
			return true;
	}
	return false;
}

void Gameboard::printCoords()
{
	cout << "WHITE\n";
	for (int i = 0; i < white.size(); i++)
	{
		cout << white[i].getX() << " " << white[i].getY() << " -- ";
	}
	cout << endl;
	LINE;
	cout << "BLACK\n";
	for (int i = 0; i < black.size(); i++)
	{
		cout << black[i].getX() << " " << black[i].getY() << " -- ";
	}
	cout << endl;
	LINE;
	cout << "SPACES\n";
	for (int i = 0; i < spaces.size(); i++)
	{
		cout << spaces[i].getX() << " " << spaces[i].getY() << " -- ";
	}
	cout << endl;
	LINE;
}
