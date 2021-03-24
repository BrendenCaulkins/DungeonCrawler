#ifndef THUGCACTUS_H
#define THUGCACTUS_H

#include "Monster.h"

class ThugCactus : public Monster {
	public:
	ThugCactus() : Monster(special, "Thug Cactus", /*base_hp*/ 20, /*base_spd*/ 5, /*base_atk*/ 10, /*base_def*/ 10, /*critChance*/ 5, /*critMultiplier*/ 3, /*accuracy*/ 80, /*evasion*/ 20) {}
	ThugCactus(std::string name) : Monster(special, name, "Thug Cactus", /*base_hp*/ 20, /*base_spd*/ 5, /*base_atk*/ 10, /*base_def*/ 10, /*critChance*/ 5, /*critMultiplier*/ 3, /*accuracy*/ 80, /*evasion*/ 20) {}
	ThugCactus(std::string name, std::string cret, int hp, int mhp, int lvl, int spd, int atk, int def, int wallet, int exp, int lvlup, Item* W, Item* D) : Monster(special, name, cret, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, /*critChance*/ 5, /*critMultiplier*/ 3, /*accuracy*/ 80, /*evasion*/ 20, W, D){}
	void gainLVL();
// 	void encounterOutput() {output("A burly green creature appears before you, heavily decorated with weaponry. \nHe is clothed only in a backwards-facing ball cap and \na thick, golden chain around what you presume to be his neck, \nmatched with a pair of shiny sunglasses." << std::endl;}
// 	void attackOutput(Character &defense){output( name << " shoots needles at " << defense.getName() << "--*needle noises*!!" << std::endl;}
	Item* addrareDrop();
	Item* addVeryRareDrop();
		Item* soleDrop(){return new Chainsaw(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));}
	Item* soleDrop2() {return new Leafblower(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));}
	int iExp() {return 12 + rand()%4;}
	Character* spawnMon() {
		Item* W = nullptr, *D = nullptr;
		if(hasWeapon()){
			W = Weapon->grabFromStack();
		}
		if(hasDefensive()){
			D = Defensive->grabFromStack();
		}
		return new ThugCactus(name, cret, hp, max_hp, lvl, spd, atk, def, wallet, exp, lvlUP, W, D);
	}

};

#endif