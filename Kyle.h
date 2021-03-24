#ifndef KYLE_H
#define KYLE_H

#include "Monster.h"

class Kyle : public Monster {
	public:
	Kyle();
	Kyle(std::string name);
	Kyle(std::string name, std::string cret, int hp, int mhp, int lvl, int spd, int atk, int def, int wallet, int exp, int lvlup, Item* W, Item* D) : Monster(boss, name, cret, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, /*critChance*/ 0, /*critMultiplier*/ 0, /*accuracy*/ 0, /*evasion*/ 0, W, D){
		if(cret == "Kyle"){monster = regular;}
		if(cret == "Kenneth"){monster = special;}
		if(cret == "Lucky Luciano"){monster = boss;}
	}
	void gainLVL();
// 	void encounterOutput() {std::cout << name << " has to do it to ya." << std::endl;}
// 	void attackOutput(Character &defense){std::cout << name << " does it to " << defense.getName() << std::endl;}
	std::vector<Item*> dropItems(int&);
	Item* soleDrop();
	Item* soleDrop2();
	int iExp(){return (max_hp + spd + atk + def)/2;}
	//std::string getCreature(){return name;};
	Character* spawnMon() {
		Item* W = nullptr, *D = nullptr;
		if(hasWeapon()){
			W = Weapon->grabFromStack();
		}
		if(hasDefensive()){
			D = Defensive->grabFromStack();
		}
		return new Kyle(name, cret, hp, max_hp, lvl, spd, atk, def, wallet, exp, lvlUP, W, D);
	}
	virtual int getCritChance() {return rand()%101;}
	virtual double getCritMultiplier() {return (rand()%10)/2.0;}
	virtual int getAccuracy() {return rand()%101;}
	virtual int getEvasion() {return rand()%101;}
};

#endif