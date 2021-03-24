#ifndef ORC_H
#define ORC_H

#include "Monster.h"

class Orc : public Monster {
	public:
	Orc() : Monster(regular, "Orc", /*base_hp*/ 20, /*base_spd*/ 4, /*base_atk*/ 8, /*base_def*/ 8, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 75, /*evasion*/ 10) {}
	Orc(std::string name) : Monster(regular, name, "Orc", /*base_hp*/ 20, /*base_spd*/ 4, /*base_atk*/ 8, /*base_def*/ 8, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 75, /*evasion*/ 10) {}
	Orc(std::string name, std::string cret, int hp, int mhp, int lvl, int spd, int atk, int def, int wallet, int exp, int lvlup, Item* W, Item* D) : Monster(regular, name, cret, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 75, /*evasion*/ 10, W, D){}
	void gainLVL();
	void encounterOutput() {if(rand()%1000 == 69){output("a massive, meaty cock with intimidating girth. That's all you see. this orc is naked… and? hard???? run.", true); return; }Monster::encounterOutput();}
// 	void attackOutput(Character &defense){std::cout << name << " swings a club at " << defense.getName() << "--THUNK!!" << std::endl;}
	Item* addUncommonDrop();
	Item* soleDrop(){return new Club(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));}
	Item* soleDrop2() {return new Loincloth(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));}
	int iExp() {return 10 + rand()%3;}
	Character* spawnMon() {
		Item* W = nullptr, *D = nullptr;
		if(hasWeapon()){
			W = Weapon->grabFromStack();
		}
		if(hasDefensive()){
			D = Defensive->grabFromStack();
		}
		return new Orc(name, cret, hp, max_hp, lvl, spd, atk, def, wallet, exp, lvlUP, W, D);
	}


};

#endif