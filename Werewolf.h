#ifndef WEREWOLF_H
#define WEREWOLF_H

#include "Monster.h"

class Werewolf : public Monster {
	public:
	Werewolf() : Monster(boss, "Werewolf", /*base_hp*/ 35, /*base_spd*/ 7, /*base_atk*/ 7, /*base_def*/ 6, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 20) {}
	Werewolf(std::string name) : Monster(boss, name, "Werewolf", /*base_hp*/ 35, /*base_spd*/ 7, /*base_atk*/ 7, /*base_def*/ 6, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 20) {}
	Werewolf(std::string name, std::string cret, int hp, int mhp, int lvl, int spd, int atk, int def, int wallet, int exp, int lvlup, Item* W, Item* D) : Monster(boss, name, cret, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 20, W, D){}
	void gainLVL();
// 	void encounterOutput() {output("A giant beast with flesh-rending claws lurks towards you");}
// 	void attackOutput(Character &defense){output(name + " bites " + defense.getName() + "--CHOMP!!");}
	Item* addLegendaryDrop();
		Item* soleDrop(){return new Excalibur(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));}
	Item* soleDrop2() {return new Svalinn(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));}
	int iExp() {return 18 + rand()%8;}
	Character* spawnMon() {
		Item* W = nullptr, *D = nullptr;
		if(hasWeapon()){
			W = Weapon->grabFromStack();
		}
		if(hasDefensive()){
			D = Defensive->grabFromStack();
		}
		return new Werewolf(name, cret, hp, max_hp, lvl, spd, atk, def, wallet, exp, lvlUP, W, D);
	}

};

#endif