#ifndef CERBERUS_H
#define CERBERUS_H

#include "Monster.h"

class Cerberus : public Monster {
	public:
	Cerberus() : Monster(boss, "Cerberus", /*base_hp*/ 35, /*base_spd*/ 8, /*base_atk*/ 6, /*base_def*/ 6, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 20) {}
	Cerberus(std::string name) : Monster(boss, name, "Cerberus", /*base_hp*/ 35, /*base_spd*/ 8, /*base_atk*/ 6, /*base_def*/ 6, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 20) {}
	Cerberus(std::string name, std::string cret, int hp, int mhp, int lvl, int spd, int atk, int def, int wallet, int exp, int lvlup, Item* W, Item* D) : Monster(boss, name, cret, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 20, W, D){}
	void gainLVL();
// 	void encounterOutput() {std::cout << "A pile of fluff blocks your path. A puppy! Omigosh! Two puppies! Wow! Three…… oh no. A three headed dog with jaws of death rushes towards you."<< std::endl;}
// 	void attackOutput(Character &defense){std::cout << name << " snaps at " << defense.getName() << "--CHOMP!!" << std::endl;}
	Item* addLegendaryDrop();
	Item* soleDrop(){return new Shiteyanyoform(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));}
	Item* soleDrop2(){return new Dickbuttform(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));}
	int iExp() {return 18 + rand()%8;}
	Character* spawnMon() {
		Item* W = nullptr, *D = nullptr;
		if(hasWeapon()){
			W = Weapon->grabFromStack();
		}
		if(hasDefensive()){
			D = Defensive->grabFromStack();
		}
		return new Cerberus(name, cret, hp, max_hp, lvl, spd, atk, def, wallet, exp, lvlUP, W, D);
	}

};

#endif