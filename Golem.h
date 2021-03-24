#ifndef GOLEM_H
#define GOLEM_H

#include "Monster.h"

class Golem : public Monster {
	public:
	Golem() : Monster(boss, "Golem", /*base_hp*/ 50, /*base_spd*/ 3, /*base_atk*/ 5, /*base_def*/ 11, /*critChance*/ 2, /*critMultiplier*/ 4.5, /*accuracy*/ 80, /*evasion*/ 10) {if(rand()%1000 == 69){name = "Gowem";}}
	Golem(std::string name) : Monster(boss, name, "Golem", /*base_hp*/ 50, /*base_spd*/ 3, /*base_atk*/ 5, /*base_def*/ 11, /*critChance*/ 2, /*critMultiplier*/ 4.5, /*accuracy*/ 80, /*evasion*/ 10) {if(rand()%1000 == 69){name = "Gowem";}}
	Golem(std::string name, std::string cret, int hp, int mhp, int lvl, int spd, int atk, int def, int wallet, int exp, int lvlup, Item* W, Item* D) : Monster(boss, name, cret, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 10, W, D){}
	void gainLVL();
// 	void encounterOutput() {if(name == "Gowem"){std::cout <<"A warge stwone bwocks your pwath, UWU?!?!?! It's mwoving??? nya!!!:3c" << std::endl; return;}std::cout << "A large stone blocks your path. Wait, is it moving?" << std::endl;}
// 	void attackOutput(Character &defense){if(name == "Gowem"){ std::cout << name << " thwows a bouwder at "<< defense.getName() << "--THEN PEWISH!!" << std::endl; return;} std::cout << name << " throws a boulder at " << defense.getName() << "--SMOOSH!!" << std::endl;}
	Item* addLegendaryDrop();
	Item* soleDrop(){return new Smashingboard(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));}
	Item* soleDrop2() {return new Guardingrod(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));}
	int iExp() {return 18 + rand()%8;}
	Character* spawnMon() {
		Item* W = nullptr, *D = nullptr;
		if(hasWeapon()){
			W = Weapon->grabFromStack();
		}
		if(hasDefensive()){
			D = Defensive->grabFromStack();
		}
		return new Golem(name, cret, hp, max_hp, lvl, spd, atk, def, wallet, exp, lvlUP, W, D);
	}
	void displayStats();

};

#endif