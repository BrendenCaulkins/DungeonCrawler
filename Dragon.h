#ifndef DRAGON_H
#define DRAGON_H

#include "Monster.h"

class Dragon : public Monster {
	public:
	Dragon() : Monster(boss, "Dragon", /*base_hp*/ 35, /*base_spd*/ 6, /*base_atk*/ 8, /*base_def*/ 6, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 20) {}
	Dragon(std::string name) : Monster(boss, name, "Dragon", /*base_hp*/ 35, /*base_spd*/ 6, /*base_atk*/ 8, /*base_def*/ 6, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 20) {}
	Dragon(std::string name, std::string cret, int hp, int mhp, int lvl, int spd, int atk, int def, int wallet, int exp, int lvlup, Item* W, Item* D) : Monster(boss, name, cret, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 20, W, D){}
	void gainLVL();
// 	void encounterOutput() {std::cout <<"A fearsome " << name << " blocks your path, creating a wall of fire to block your escape" << std::endl;}
// 	void attackOutput(Character &defense){std::cout << name << " shoots fire at " << defense.getName() << "--BURN!!" << std::endl;}
	Item* addLegendaryDrop();
	Item* soleDrop(){return new Dragonsbreath(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));}
	Item* soleDrop2() {return new Dragonsvapepen(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));}
	int iExp() {return 18 + rand()%8;}
	Character* spawnMon() {
		Item* W = nullptr, *D = nullptr;
		if(hasWeapon()){
			W = Weapon->grabFromStack();
		}
		if(hasDefensive()){
			D = Defensive->grabFromStack();
		}
		return new Dragon(name, cret, hp, max_hp, lvl, spd, atk, def, wallet, exp, lvlUP, W, D);
	}

};

#endif