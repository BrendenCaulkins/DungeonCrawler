#ifndef FISH_H
#define FISH_H

#include "Monster.h"

class Fish : public Monster {
	public:
	Fish() : Monster(boss, "Fish", /*base_hp*/ 35, /*base_spd*/ 6, /*base_atk*/ 7, /*base_def*/ 7, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 20) {}
	Fish(std::string name) : Monster(boss, name, "Fish", /*base_hp*/ 35, /*base_spd*/ 6, /*base_atk*/ 7, /*base_def*/ 7, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 20) {}
	Fish(std::string name, std::string cret, int hp, int mhp, int lvl, int spd, int atk, int def, int wallet, int exp, int lvlup, Item* W, Item* D) : Monster(boss, name, cret, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 20, W, D){}
	void gainLVL();
// 	void encounterOutput() {std::cout << "A " << name << " splishy splashes in your direction, how they survive out of water we’ll never know."<< std::endl;}
// 	void attackOutput(Character &defense){std::cout << name << " splashes " << defense.getName() << "--SPLISH!!" << std::endl;}
	Item* addLegendaryDrop();
	Item* soleDrop(){return new Egg(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));}
	Item* soleDrop2() {return new Chicken(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));}
	int iExp() {return 18 + rand()%8;}
	Character* spawnMon() {
		Item* W = nullptr, *D = nullptr;
		if(hasWeapon()){
			W = Weapon->grabFromStack();
		}
		if(hasDefensive()){
			D = Defensive->grabFromStack();
		}
		return new Fish(name, cret, hp, max_hp, lvl, spd, atk, def, wallet, exp, lvlUP, W, D);
	}


};

#endif