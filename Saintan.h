#ifndef SAINTAN_H
#define SAINTAN_H

#include "Monster.h"

class Saintan : public Monster {
	public:
	Saintan() : Monster(special, "Saintan", /*base_hp*/ 15, /*base_spd*/ 10, /*base_atk*/ 10, /*base_def*/ 10, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 20) {}
	Saintan(std::string name) : Monster(special, name, "Saintan", /*base_hp*/ 15, /*base_spd*/ 10, /*base_atk*/ 10, /*base_def*/ 10, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 20) {}
	Saintan(std::string name, std::string cret, int hp, int mhp, int lvl, int spd, int atk, int def, int wallet, int exp, int lvlup, Item* W, Item* D) : Monster(special, name, cret, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 20, W, D){}
	void gainLVL();
// 	void encounterOutput() {output(name << " rears his massive frock-clad goatlike frame in your direction."<< std::endl << "You feel both empty and fulfilled and consider the merits of conversion." << std::endl;}
// 	void attackOutput(Character &defense){output(name <<" rends a fiery cross in " << defense.getName() << "'s chest." <<std::endl;}
	Item* addrareDrop();
	Item* addVeryRareDrop();
	Item* soleDrop(){return new Musicalkatana(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));}
	Item* soleDrop2() {return new Offkeyarmor(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));}
	int iExp() {return 12 + rand()%4;}
	Character* spawnMon() {
		Item* W = nullptr, *D = nullptr;
		if(hasWeapon()){
			W = Weapon->grabFromStack();
		}
		if(hasDefensive()){
			D = Defensive->grabFromStack();
		}
		return new Saintan(name, cret, hp, max_hp, lvl, spd, atk, def, wallet, exp, lvlUP, W, D);
	}


};

#endif