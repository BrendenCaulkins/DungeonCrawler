#ifndef MONSTER_H
#define MONSTER_H

#include "Character.h"
#include "Items.h"
	enum mType {regular, special, boss, UNIQUE};

class Monster : public Character {
protected:
	mType monster;
	std::string cret;
// 	std::string dragonColor;
public:
	Monster(mType mon, std::string name, int hp, int spd, int atk, int def, int critChance, double critMultiplier, int accuracy, int evasion) : Character(MONSTER, name, hp, spd, atk, def, critChance, critMultiplier, accuracy, evasion), monster(mon), cret(name) {}
	Monster(mType mon, std::string name, std::string cret, int hp, int spd, int atk, int def, int critChance, double critMultiplier, int accuracy, int evasion) : Character(MONSTER, name, hp, spd, atk, def, critChance, critMultiplier, accuracy, evasion), monster(mon), cret(cret) {}
	Monster(mType mon, std::string name, std::string cret, int hp, int mhp, int lvl, int spd, int atk, int def, int wallet, int exp, int lvlup,  int critChance, double critMultiplier, int accuracy, int evasion, Item* W, Item* D) :Character(MONSTER, name, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, critChance, critMultiplier, accuracy, evasion, W, D), monster(mon), cret(cret) {}
	void lvlTO(int lvl);
		virtual std::vector<Item*> dropItems(int& money);
		std::string getCreature() {return cret;}
		void changeName(std::string nName) {name = nName;}
	void interactOutput();
		virtual Character* spawnMon() {return nullptr;}
		bool isMon() {return true;}
	void displayStats();
protected:
	virtual void gainLVL() = 0;
	std::string getType();
	int expCalc(int pLVL);
	virtual int iExp() {return 0;}
	void outputDrop(const std::vector<Item*> &drop, int money);
	Item* commonDrop();
	Item* uncommonDrop();
	Item* rareDrop();
	Item* veryRareDrop();
	Item* uveryRareDrop();
	Item* legendaryDrop(){return addLegendaryDrop();}
	Item* uniqueDrop();
	void regDrop(std::vector<Item*> &drop, int numDrop);
	void specDrop(std::vector<Item*> &drop, int numDrop);
	void bossDrop(std::vector<Item*> &drop, int numDrop);
	virtual Item* addUncommonDrop(){return nullptr;}
	virtual Item* addrareDrop(){return nullptr;}
	virtual Item* addVeryRareDrop(){return nullptr;}
	virtual Item* addLegendaryDrop(){return nullptr;}
	virtual Item* soleDrop(){return nullptr;}
	virtual Item* soleDrop2(){return nullptr;}
	virtual void attackOutput(Character &defense);
	void encounterOutput();
	int loadAndUseOutputs(std::string type);
	void feedOutput();
	void petOutput();
	void batheOutput();
	void playOutput();
	void napOutput();
	void chaosCast(int& HP, int& SPD, int& ATK, int& DEF,const int pool);
};

#endif