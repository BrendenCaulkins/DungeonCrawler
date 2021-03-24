#ifndef MINOTAUR_H
#define MINOTAUR_H

#include "Monster.h"

class Minotaur : public Monster {
	public:
	Minotaur() : Monster(boss, "Minotaur", /*base_hp*/ 35, /*base_spd*/ 7, /*base_atk*/ 6, /*base_def*/ 7, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 20) {}
	Minotaur(std::string name) : Monster(boss, name, "Minotaur", /*base_hp*/ 35, /*base_spd*/ 7, /*base_atk*/ 6, /*base_def*/ 7, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 20) {}
	Minotaur(std::string name, std::string cret, int hp, int mhp, int lvl, int spd, int atk, int def, int wallet, int exp, int lvlup, Item* W, Item* D) : Monster(boss, name, cret, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 20, W, D){}
	void gainLVL();
// 	void encounterOutput() {std::cout << name << " leans against a wall, seemingly bored by your advance into his personal space. \n\"You heroes really take life by the horns, don'tcha? Guess I gotta kill ya, bud.\""<< std::endl;}
// 	void attackOutput(Character &defense){std::cout << name << " swings a mighty ax at " << defense.getName() << "--THUNK!!" << std::endl;}
	Item* addLegendaryDrop();
	Item* soleDrop(){return new Thunderbolt(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));}
	Item* soleDrop2() {return new Cloud(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));}
	int iExp() {return 18 + rand()%8;}
	Character* spawnMon() {
		Item* W = nullptr, *D = nullptr;
		if(hasWeapon()){
			W = Weapon->grabFromStack();
		}
		if(hasDefensive()){
			D = Defensive->grabFromStack();
		}
		return new Minotaur(name, cret, hp, max_hp, lvl, spd, atk, def, wallet, exp, lvlUP, W, D);
	}


};

#endif