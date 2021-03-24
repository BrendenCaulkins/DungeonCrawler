#ifndef CHAOS_H
#define CHAOS_H

#include "Character.h"
#include<fstream>


class Chaos : public Character {
	private:
	std::vector<std::string> equippableItems;
public:
	Chaos(std::string name);
	Chaos(std::string name, int hp, int mhp,int lvl,int spd, int atk,int def,int wallet,int exp,int lvlup, Item* W,Item* D);
private:
	void gainLVL();
	std::string getType();
	bool isChaos() {return true;}
	void chaosCast(int& HP, int& SPD, int& ATK, int& DEF,const int pool);
	Item* equipItem(Item*temp);
	bool canEquip(Item* temp);
// 	void determineEquip();
	Item* attemptEquip(Item*);
	Item* MequipDefensive(Item *nDefensive);
	Item* MequipWeapon(Item*);
	virtual int getCritChance() {return rand()%101;}
	virtual double getCritMultiplier() {return (rand()%10)/2.0;}
	virtual int getAccuracy() {return rand()%101;}
	virtual int getEvasion() {return rand()%101;}
};

#endif