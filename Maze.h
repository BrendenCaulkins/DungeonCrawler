#ifndef MAZE_H
#define MAZE_H
#include "extrafunctions.h"

//creates maze along with character to move within it, can be used on it's own to create a simple maze program
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

struct Coord {
	int x, y;
	Coord (int x, int y) : x(x), y(y) {};
	Coord() : x(0), y(0){};
	void operator=(Coord p){x = p.x;y = p.y;}
	bool operator==(Coord p){if(x == p.x && y == p.y){return true;}return false;}
	bool operator!=(Coord p){if(x != p.x || y != p.y){return true;}return false;}
};

class Maze {
protected:
	const int numRow, numCol; 
	int startpointy, endpointx, endpointy;
	Coord pCoord;
	std::vector<std::vector<std::string>> maze, map;
	std::vector<std::vector<bool>> visited;
	bool mazeComplete;
	/*const */std::string playerSymbol, wallMaterial, emptySpace;
public:
	Maze();
	void newMaze();
	void displayMaze();
	void displayMasked();
	bool mazeSolved();
	void move(char dir);
	void solveMaze();
private:
	//creates maze
	void makeMaze(int x, int y);
	bool makeBranch();
	void makeBranch(int &x, int &y);
	bool canMove(const int x, const int y);
	void move(int &x, int &y);
	void fillMaze();
	bool canMoveNorth(const int x, const int y);
	bool canMoveSouth(const int x, const int y);
	bool canMoveEast(const int x, const int y);
	bool canMoveWest(const int x, const int y);
protected:
	bool isSpace(const int x, const int y);
	bool isPlayerSymbol(int x, int y);
	bool isWall(int x, int y);
	void findSpace(int& x, int& y);
	//sets players position/moves player through maze
	int findMazeStart();
	void resetMap();
	void updateMap(int x, int y);
	void updateVisited(int x, int y);
	bool inSight(int x, int y);
	void setPosition(int x, int y);
	void erasePosition(int x, int y);
	void erasePositionMaze(int x, int y);
	void erasePositionMap(int x, int y);
	bool canMove(char dir);
private:
	//autosolver
	void sMove(char move);
	bool sCanMove(char move);
	
};
#endif
