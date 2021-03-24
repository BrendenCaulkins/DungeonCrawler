#ifndef BIGCHUNGUS_H
#define BIGCHUNGUS_H

#include "Monster.h"

class BigChungus : public Monster {
public:
	BigChungus() : Monster(special, "Big Chungus", /*base_hp*/ 30, /*base_spd*/ 3, /*base_atk*/ 6, /*base_def*/ 6, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 25) {}
		BigChungus(std::string name) : Monster(special, name, "Big Chungus", /*base_hp*/ 30, /*base_spd*/ 3, /*base_atk*/ 6, /*base_def*/ 6, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 25) {}

	BigChungus(std::string name, std::string cret, int hp, int mhp, int lvl, int spd, int atk, int def, int wallet, int exp, int lvlup, Item* W, Item* D) : Monster(special, name,cret, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 25, W, D){}
private:
	void gainLVL();
// 	void encounterOutput() {std::cout << "Needs encounter output" << std::endl;}
// 	void attackOutput(Character &defense){std::cout << name << " slaps with meaty arm " << defense.getName() << "-- CHUNG!!" << std::endl;}
	Item* addrareDrop();
	Item* addVeryRareDrop();
	Item* soleDrop(){return new Enchantedbow(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));}
	Item* soleDrop2(){return new Enchantedshield(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));}
	int iExp() {return 12 + rand()%4;}
	Character* spawnMon() {
		Item* W = nullptr, *D = nullptr;
		if(hasWeapon()){
			W = Weapon->grabFromStack();
		}
		if(hasDefensive()){
			D = Defensive->grabFromStack();
		}
		return new BigChungus(name, cret, hp, max_hp, lvl, spd, atk, def, wallet, exp, lvlUP, W, D);
	}
};

#endif