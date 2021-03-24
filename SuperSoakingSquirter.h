#ifndef SUPERSOAKINGSQUIRTER_H
#define SUPERSOAKINGSQUIRTER_H

#include "Monster.h"

class SuperSoakingSquirter : public Monster {
	public:
	SuperSoakingSquirter() : Monster(boss, "Super Soaking Squirter", /*base_hp*/ 25, /*base_spd*/ 3, /*base_atk*/ 16, /*base_def*/ 11, /*critChance*/ 4, /*critMultiplier*/ 4, /*accuracy*/ 80, /*evasion*/ 20) {}
	SuperSoakingSquirter(std::string name) : Monster(boss, name, "Super Soaking Squirter", /*base_hp*/ 25, /*base_spd*/ 3, /*base_atk*/ 16, /*base_def*/ 11, /*critChance*/ 4, /*critMultiplier*/ 4, /*accuracy*/ 80, /*evasion*/ 20) {}
	SuperSoakingSquirter(std::string name, std::string cret, int hp, int mhp, int lvl, int spd, int atk, int def, int wallet, int exp, int lvlup, Item* W, Item* D) : Monster(boss, name, cret, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, /*critChance*/ 4, /*critMultiplier*/ 4, /*accuracy*/ 80, /*evasion*/ 20, W, D){}
	void gainLVL();
// 	void encounterOutput() {output( "The SAVAGE "<< name << " is signaled suddenly of your sorry stealth, seizing you sinisterly." << std::endl << "Screeching, squealing, or shrieking shall only sully your situation." << std::endl;}
// 	void attackOutput(Character &defense){output( name << " squirts acid at " << defense.getName() << std::endl;}
	Item* addLegendaryDrop();
	Item* soleDrop(){return new Squirtgun(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));}
	Item* soleDrop2() {return new Umbrella(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));}
	int iExp() {return 18 + rand()%8;}
	Character* spawnMon() {
		Item* W = nullptr, *D = nullptr;
		if(hasWeapon()){
			W = Weapon->grabFromStack();
		}
		if(hasDefensive()){
			D = Defensive->grabFromStack();
		}
		return new SuperSoakingSquirter(name, cret, hp, max_hp, lvl, spd, atk, def, wallet, exp, lvlUP, W, D);
	}
};

#endif