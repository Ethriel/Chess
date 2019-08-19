#pragma once
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<math.h>
#include<Windows.h>
#include<conio.h>
#define LINE cout << "________________________________________\n"

using namespace std;
class Coord
{
public:
	Coord();
	Coord(int x, int y);
	~Coord();
	void setX(int x);
	void setY(int y);
	void setCoords(int x, int y);
	int getX() const;
	int getY() const;
	bool operator==(Coord& other);
private:
	int x;
	int y;
};

class Cursor {
public:
	Cursor();
	Cursor(int x, int y);
	int x = 5;
	int y = 2;
	void setX(int x);
	void setY(int y);
	void setCoords(int x, int y);
	int getX() const;
	int getY() const;
	void resetCursor();
};

enum CELL_FIGURE
{
	EMPTY = 0,
	FRIEND,
	ENEMY
};

class Gameboard;
class Figure
{
public:
	Figure();
	Figure(string name, string color, char symb, int moves, int limit, bool hasMoved);
	~Figure();
	virtual CELL_FIGURE chekCell(string type) = 0;
	char getSymb() const;
	string getColor() const;
	string getName() const;
	int getMoves() const;
	void setMoves(int moves);
	void setFrom(int x, int y);
	void setTo(int x, int y);
	void setFromTo(int xF, int yF, int xT, int yT);
	void swapCoords();
	void setNewFrom(int x, int y);
	void setLessBigCoord(int fromX, int fromY, int toX, int toY, int& lX, int& lY, int& bX, int& bY);
	virtual bool validateAttack(Gameboard* g) = 0;
	virtual bool validateAttack(Gameboard* g, int toX, int toY) = 0;
	virtual bool validateMove(Gameboard* g) = 0;
	virtual bool validateMove(Gameboard* g, int toX, int toY) = 0;
	virtual bool validateCheck(Gameboard* g) = 0;
	virtual void fillWay(int fromX, int fromY, int toX, int toY) = 0;
	vector<Coord> getWay() const;
	int getFromX() const;
	int getFromY() const;
	int getToX() const;
	int getToY() const;
	int getLimit() const;
	bool getHasMoved() const;
	void setHasMoved(bool hasMoved);
protected:
	string color;
	string name;
	char symb;
	int moves;
	int limit;
	bool hasMoved;
	Coord from;
	Coord to;
	vector<Coord> way;
};

class Pawn : public Figure
{
public:
	Pawn();
	Pawn(string name, string color, char symb, int moves, int limit, bool hasMoved);
	~Pawn();
	CELL_FIGURE chekCell(string type) override;
	bool validateAttack(Gameboard* g) override;
	bool validateAttack(Gameboard* g, int toX, int toY) override;
	bool validateMove(Gameboard* g) override;
	bool validateMove(Gameboard* g, int toX, int toY) override;
	bool validateCheck(Gameboard* g) override;
	void fillWay(int fromX, int fromY, int toX, int toY) override;
private:
};

class Bishop : public Figure
{
public:
	Bishop();
	Bishop(string name, string color, char symb, int moves, int limit, bool hasMoved);
	~Bishop();
	CELL_FIGURE chekCell(string type) override;
	bool validateAttack(Gameboard* g);
	bool validateAttack(Gameboard* g, int toX, int toY) override;
	bool validateMove(Gameboard* g);
	bool validateMove(Gameboard* g, int toX, int toY) override;
	bool validateCheck(Gameboard* g) override;
	void fillWay(int fromX, int fromY, int toX, int toY) override;
private:

};

class Knight : public Figure
{
public:
	Knight();
	Knight(string name, string color, char symb, int moves, int limit, bool hasMoved);
	~Knight();
	CELL_FIGURE chekCell(string type) override;
	bool validateAttack(Gameboard* g) override;
	bool validateAttack(Gameboard* g, int toX, int toY) override;
	bool validateMove(Gameboard* g) override;
	bool validateMove(Gameboard* g, int toX, int toY) override;
	bool validateCheck(Gameboard* g) override;
	void fillWay(int fromX, int fromY, int toX, int toY) override;
private:

};

class Rook : public Figure
{
public:
	Rook();
	Rook(string name, string color, char symb, int moves, int limit, bool hasMoved);
	~Rook();
	CELL_FIGURE chekCell(string type) override;
	bool validateAttack(Gameboard* g) override;
	bool validateAttack(Gameboard* g, int toX, int toY) override;
	bool validateMove(Gameboard* g) override;
	bool validateMove(Gameboard* g, int toX, int toY) override;
	bool validateCheck(Gameboard* g) override;
	void fillWay(int fromX, int fromY, int toX, int toY) override;
private:

};

class Queen : public Figure
{
public:
	Queen();
	Queen(string name, string color, char symb, int moves, int limit, bool hasMoved);
	~Queen();
	CELL_FIGURE chekCell(string type) override;
	bool validateAttack(Gameboard* g) override;
	bool validateAttack(Gameboard* g, int toX, int toY) override;
	bool validateMove(Gameboard* g) override;
	bool validateMove(Gameboard* g, int toX, int toY) override;
	bool validateCheck(Gameboard* g) override;
	void fillWay(int fromX, int fromY, int toX, int toY) override;
private:

};

class King : public Figure
{
public:
	King();
	King(string name, string color, char symb, int moves, int limit, bool hasMoved);
	~King();
	CELL_FIGURE chekCell(string type) override;
	bool validateAttack(Gameboard* g) override;
	bool validateAttack(Gameboard* g, int toX, int toY) override;
	bool validateMove(Gameboard* g) override;
	bool validateMove(Gameboard* g, int toX, int toY) override;
	bool validateCheck(Gameboard* g) override;
	void fillWay(int fromX, int fromY, int toX, int toY) override;
private:

};

class Space : public Figure
{
public:
	Space();
	Space(string name, string color, char symb, int moves, int limit, bool hasMoved);
	~Space();
	CELL_FIGURE chekCell(string type) override;
	bool validateAttack(Gameboard* g) override;
	bool validateAttack(Gameboard* g, int toX, int toY) override;
	bool validateMove(Gameboard* g) override;
	bool validateMove(Gameboard* g, int toX, int toY) override;
	bool validateCheck(Gameboard* g) override;
	void fillWay(int fromX, int fromY, int toX, int toY) override;
private:
};

class Gameboard
{
public:
	Gameboard();
	Gameboard(const Gameboard& g);
	~Gameboard();
	void fillBoard(); // main board
	void fillTestBoard(); // test board for tests
	void printBoard();
	void printBoard(int x, int y);
	string getColor(int x, int y) const;
	Figure* getFigure(int x, int y) const;
	Coord getWhiteKing() const;
	Coord getBlackKing() const;
	bool validateBorders(int fromX, int fromY, int toX, int toY); // ok
	void fillKingPossMove(vector<Coord>& kingPossMoves, int kingX, int kingY); // ok
	void setCoords(int fromX, int fromY, int toX, int toY); // ok
	void setNewCoords(int oldX, int oldY, int newX, int newY); // ok
	void move(int fromX, int fromY, int toX, int toY); // ok
	void attack(int fromX, int fromY, int toX, int toY); // ok
	void attackOnMove(int moveX, int moveY, int attFromX, int attFromY, int attToX, int attToY); // ok
	void eraseDefender(int attX, int attY, int defX, int defY); // ok
	void swapCoordsAttack(int fromX, int fromY, int toX, int toY); // ok
	void swapCoordsMove(int fromX, int fromY, int toX, int toY); // ok
	void validateInput(int& fromX, int& fromY, int& toX, int& toY, string player); // ok
	void selectFigure(int& x, int& y);
	bool attackOrMove(int fromX, int fromY, int toX, int toY, string player); //ok
	bool tryTakeOnMove(int fromX, int fromY, int toX, int toY, string player); // ok
	void play(); // ok
	bool check(int attX, int attY); // ok
	bool checkMate(int attPosX, int attPosY); // ok
	bool canAttackerBeTaken(int attX, int attY); // ok
	bool canKingBeCovered(vector<Coord> attWay, string attacker); // ok
	bool canKingMove(string attacker); // ok
	bool checkTheCell(CELL_FIGURE figure); // ok
	bool validateChange(int limit, int toX); // ok
	void changeFigure(int toX, int toY, string player); // ok
	bool stalemate(string player); // ok
	void validateAnyStates(int fromX, int fromY, int attX, int attY, int pawnX, string player); // ok
	void castling(int fromX, int fromY, int toX, int toY, string player); // ok
	void longCastling(int fromX, int fromY, int toX, int toY, string player); // ok
	void shortCastling(int fromX, int fromY, int toX, int toY, string player); // ok
	bool validateCastling(int fromX, int fromY, int toX, int toY, string player); // ok
	void printCoords(vector<Coord> coords); // ok
private:
	Figure* board[8][8];
	Figure* space;
	Coord whiteKing;
	Coord blackKing;
	Coord from;
	Coord to;
	vector<Coord> white;
	vector<Coord> black;
	vector<Coord> spaces;
	vector<Coord> whiteLine;
	vector<Coord> blackLine;
};

bool validateHorizontal(Gameboard* g, int fromX, int fromY, int toX, int toY);
bool validateVertical(Gameboard* g, int fromX, int fromY, int toX, int toY);
bool validateDiagonal(Gameboard* g, int fromX, int fromY, int toX, int toY);
bool validateHorizontalAttack(Gameboard* g, int fromX, int fromY, int toX, int toY);
bool validateVerticalAttack(Gameboard* g, int fromX, int fromY, int toX, int toY);
bool validateDiagonalAttack(Gameboard* g, int fromX, int fromY, int toX, int toY);
bool validateOutOfRange(int x, int y);
void gotoxy(Cursor &c);