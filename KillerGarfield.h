#ifndef KILLERGARFIELD_H
#define KILLERGARFIELD_H

#include "Monster.h"

class KillerGarfield : public Monster {
	public:
	KillerGarfield() : Monster(special, "Killer Garfield", /*base_hp*/ 27, /*base_spd*/ 9, /*base_atk*/ 6, /*base_def*/ 3, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 25) {}
	KillerGarfield(std::string name) : Monster(special, name, "Killer Garfield", /*base_hp*/ 27, /*base_spd*/ 9, /*base_atk*/ 6, /*base_def*/ 3, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 25) {}
	KillerGarfield(std::string name, std::string cret, int hp, int mhp, int lvl, int spd, int atk, int def, int wallet, int exp, int lvlup, Item* W, Item* D) : Monster(special, name, cret, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 25, W, D){}
	void gainLVL();
// 	void encounterOutput() {std::cout <<"\"Why did the chicken cross the road?\" Garfield implores. \"To get to the other side!\" You wipe the tears from your eyes, laughing. \"Oh Garfield,\" you say. \"You're a killer!\" He chuckles. Darkly. “You’re about to see how right you are.\"" << std::endl;}
// 	void attackOutput(Character &defense){std::cout << name << " screams at " << defense.getName() << "--YOWL!!" << std::endl;}
	Item* addrareDrop();
	Item* addVeryRareDrop();
	Item* soleDrop(){return new Killergarfieldsvoice(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));}
	Item* soleDrop2() {return new Voidpouch(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));}
	int iExp() {return 12 + rand()%4;}
	Character* spawnMon() {
		Item* W = nullptr, *D = nullptr;
		if(hasWeapon()){
			W = Weapon->grabFromStack();
		}
		if(hasDefensive()){
			D = Defensive->grabFromStack();
		}
		return new KillerGarfield(name, cret, hp, max_hp, lvl, spd, atk, def, wallet, exp, lvlUP, W, D);
	}


};

#endif