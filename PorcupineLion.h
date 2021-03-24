#ifndef PORCUPINELION_H
#define PORCUPINELION_H

#include "Monster.h"

class PorcupineLion : public Monster {
	public:
	PorcupineLion() : Monster(UNIQUE, "Porcupine Lion", /*base_hp*/ 35, /*base_spd*/ 9, /*base_atk*/ 8, /*base_def*/ 8, /*critChance*/ 5, /*critMultiplier*/ 4, /*accuracy*/ 85, /*evasion*/ 30) {}
	PorcupineLion(std::string name) : Monster(UNIQUE, name, "Porcupine Lion", /*base_hp*/ 35, /*base_spd*/ 9, /*base_atk*/ 8, /*base_def*/ 8, /*critChance*/ 5, /*critMultiplier*/ 4, /*accuracy*/ 85, /*evasion*/ 30) {}
	PorcupineLion(std::string name, std::string cret, int hp, int mhp, int lvl, int spd, int atk, int def, int wallet, int exp, int lvlup, Item* W, Item* D) : Monster(UNIQUE, name, cret, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, /*critChance*/ 5, /*critMultiplier*/ 4, /*accuracy*/ 85, /*evasion*/ 30, W, D){}
	void gainLVL();
// 	void attackOutput(Character &defense){std::cout << name << " turns away from " << defense.getName() << " and fires thousands of needles." << std::endl;}
	Item* soleDrop(){return new Needles(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));}
	Item* soleDrop2() {return new Bandages(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));}
	Character* spawnMon() {
		Item* W = nullptr, *D = nullptr;
		if(hasWeapon()){
			W = Weapon->grabFromStack();
		}
		if(hasDefensive()){
			D = Defensive->grabFromStack();
		}
		return new PorcupineLion(name, cret, hp, max_hp, lvl, spd, atk, def, wallet, exp, lvlUP, W, D);
	}
};

#endif