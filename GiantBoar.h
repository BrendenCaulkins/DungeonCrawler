#ifndef GIANTBOAR_H
#define GIANTBOAR_H

#include "Monster.h"

class GiantBoar : public Monster {
	public:
	GiantBoar() : Monster(regular, "Giant Boar", /*base_hp*/ 23, /*base_spd*/ 7, /*base_atk*/ 5, /*base_def*/ 5, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 30) {}
	GiantBoar(std::string name) : Monster(regular, name, "Giant Boar", /*base_hp*/ 23, /*base_spd*/ 7, /*base_atk*/ 5, /*base_def*/ 5, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 30) {}
	GiantBoar(std::string name, std::string cret, int hp, int mhp, int lvl, int spd, int atk, int def, int wallet, int exp, int lvlup, Item* W, Item* D) : Monster(regular, name, cret, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 30, W, D){}
	void gainLVL();
// 	void encounterOutput() {std::cout << "a large creature swiftly charges out of the dark, squealing maliciously as it strikes you"<< std::endl;}
// 	void attackOutput(Character &defense){std::cout << name << " charges at " << defense.getName() << "--THUNK!!" << std::endl;}
	Item* addUncommonDrop();
	Item* soleDrop(){return new Crossbow(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));}
	Item* soleDrop2() {return new Chainmail(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));}
	int iExp() {return 7 + rand()%4;}
	Character* spawnMon() {
		Item* W = nullptr, *D = nullptr;
		if(hasWeapon()){
			W = Weapon->grabFromStack();
		}
		if(hasDefensive()){
			D = Defensive->grabFromStack();
		}
		return new GiantBoar(name, cret, hp, max_hp, lvl, spd, atk, def, wallet, exp, lvlUP, W, D);
	}

};

#endif