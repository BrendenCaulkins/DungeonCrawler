#ifndef GAME_H
#define Game_H
//adds player specifics such as player class, bag, and savefile
#include "Dungeon.h"
#include "includePlayerClasses.h"
#include <vector>
#include "extraFunctions.h"

struct inBattleItemsUsed {
	bool healthUsed;
	std::vector<Item*> used;
	inBattleItemsUsed(): healthUsed(false) {};
	void itemUsed(Item*& p){ if(p->isPotion()){healthUsed = true;}used.push_back(p);}
	void resetUsed(Character* player){
		healthUsed = false;
		used.resize(0);
	}
};

class Game : public Dungeon{
private:
	Character *player;
	std::string pClass;
	std::string saveFile;
	std::vector<Item*> bag;
	inBattleItemsUsed usedItems;
public:
	Game(char choice, std::string name);
	/*next two functions located in gameSL.h*/
	Game(std::ifstream& ofs);
	~Game(){delete player; while(!bag.empty()){Item* temp = bag.at(bag.size()-1); bag.pop_back(); delete temp; }}
	void saveGame(std::ofstream& ofs);
	void move(char step);
	void displayStats();
	void displayBag();
	void nextDungeon();
	void seeChest(){treasure.visible = !treasure.visible;}
private:
	/*next handful of functions located in gameSL.h*/
	Item* createItems(std::ifstream& ifs);
	Item* newItem(std::ifstream &ifs, std::string name);
	Item* newMon(std::ifstream& ifs, std::string type);
	Item* newIngredient(std::string name, int num);
	Item* newPotion(std::string name, int num);
	Item* newBook(std::string name, std::string list);
	Item* newRecipe(std::string name);
	bool isItem(std::string name);
	bool isMonster(std::string name);
	bool isPotion(std::string name);
	bool isBook(std::string name);
	bool isRecipe(std::string name);
	bool isIngredient(std::string name);
	void saveCharacter(std::ofstream& ofs, Character* p);
	void saveItem(std::ofstream& ofs, Item* p);
	
	Item* selectPotion();
	void usePotion(Character *& healed, Item *& Potion);
	void interactWItem(Character*& p, Item *& selected, bool isEquipped);
	Item* showEquippable(int lvl);
	void tryForChest();
	void addToBag(std::vector <Item*>);
	void addToBag(Item*&);
	void sortBag();
	void equipItem(Character*& p, Item *& selected);
	void unequipItem(Character*& p, Item*& selected);
	void dropItem(Item*&);
	void battleCheck();
	void startBattle(Character *&);
	void monsterDrop(Character *&);
	void killMon();
	int translate(std::string);
	bool chaosTime(){if(pClass == "chaos" && player -> getName() == "Chaos"){return true;}return false;}
	void atShop(){if(Store.loc.x == pCoord.x && Store.loc.y == pCoord.y){Store.store.enterShop(*player, bag);}}
	void chaosGame();
	void chaosLook();
	void characterLore(std::string player);
	bool isVowel(char v){ v = std::toupper(v);if(v == 'A' || v == 'E' || v == 'I' || v == 'O' || v == 'U'){return true;}return false;}
	bool contains(std::vector<int> v, int val){for(unsigned i = 0; i < v.size(); ++i){if(v.at(i) == val){return true;}}return false;}
	std::vector<int> generatePattern(int spd1, int spd2);
};
#endif