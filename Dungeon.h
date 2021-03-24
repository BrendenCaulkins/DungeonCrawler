#ifndef DUNGEON_H
#define DUNGEON_H

//sets in map items and monsters, responsible for moving monsters around

#include <stack>
#include <queue>
#include "Maze.h"
#include "includeMonsters.h"
#include "Shop.h"
#include "extraFunctions.h"

struct paperMap {
	Coord loc;
	bool found;
	std::string look = "\u26EF";
};
struct Key {
	Coord loc;
	bool found;
	std::string look = "\u26B7";
};
struct shop {
	Coord loc;
	Shop store;
	std::string look = "\u03FF";
};

struct monster {
	Coord loc;
	Character *type;
	std::string look = "\u0D60";
	bool hasShovel;
	bool encountered;
// 	monster(){type = nullptr;}
	~monster(){}//std::cout << "deleting" << std::endl; delete type; std::cout << "deleted" << std::endl;}
	void operator=(monster m){
// 		std::cout << "assigning" << std::endl;
		loc = m.loc;
		Character* temp;
		temp = type;
		type = m.type;
		m.type = temp;
		hasShovel = m.hasShovel;
		encountered = m.encountered;
// 		std::cout << "assigned" << std::endl;
	}
};

struct chest {
	Coord loc;
	std::vector<Item*> contents;
	std::string look = "C";
	bool visible;
	bool found;
	chest(){}
	~chest(){for(unsigned i = 0; i < contents.size(); ++i){delete contents.at(i);}contents.resize(0);}
};

struct pathFind {
	char firstMove, lastMove;
	Coord currCoord;
	pathFind(int x, int y, char c) : currCoord(x, y), firstMove(c), lastMove(c) {}
	pathFind(int x, int y, char c, char v) : currCoord(x, y), firstMove(c), lastMove(v) {}
};



class Dungeon : public Maze{
protected:
	std::vector <monster> Monsters;
	Character *boss;
	paperMap pmap;
	Key key;
	bool hasShovel;
	shop Store;
	chest treasure;
	bool tp, chestVis;
	int invis;
public:
	Dungeon();
	~Dungeon() { delete boss;}
	void newDungeon();
	void move(char dir);
	bool dungeonClear() {return mazeSolved();}
	//inlined public functions
	bool mapFound() {return pmap.found;}
	void displayDungeon() {displayMaze();}
	std::string getPSymbol() const {return playerSymbol;}
	std::string getMSymbol() const {if(Monsters.size()>0){return Monsters.at(rand()%Monsters.size()).look;}return "\u0D60";}
	std::string getWSymbol() const {return wallMaterial;}
	std::string getMapSymbol() const {return pmap.look;}
	std::string getKSymbol() const {return key.look;}
	std::string getSSymbol() const {return Store.look;}
protected:
	void giveMonShovel(){Monsters.at(rand()%Monsters.size()).hasShovel = true;}
	void tryForMap();
	void tryForKey();
	void setEveryone();
	void setCoords(int &x, int &y, int quadrant);
	void setMonster(int x, int y, int indx);
	bool keyFound() { return key.found;}
	bool chestFound() {return treasure.found;}
	bool chestVisible() {return treasure.visible;}
	bool canDig() {return hasShovel;}
	void setMap();
	void setKey();
	void setShop();
	void setChest();
	void displayKey();
	void displayMap();
	void displayShop();
	void displayChest();
	void makeChestVisible(){treasure.visible = true;}
	void teleportPlayer();
	bool hasShovelCanMove(char dir);
	void moveMonsters();
	void moveMonstersPInvis();
	void moveMonster(int &x, int &y);
	bool checkForMonster(int x, int y, char facing);
	void recalcPath();
	char findShortestPath(int x, int y);
	void updatePath(char pMove);
	Character* createRegularMonster();
	Character* createSpecialMonster();
	void summonBoss();
	void moveForward(int& x,int& y,char facing);
	bool canMoveForward(int x,int y, char facing);
	bool isMonster(int x, int y){if(maze.at(y).at(x) == Monsters.at(0).look){return true;}return false;}
};

#endif