#ifndef GOBLIN_H
#define GOBLIN_H

#include "Monster.h"

class Goblin : public Monster {
	public:
	Goblin() : Monster(regular, "Goblin", /*base_hp*/ 15, /*base_spd*/ 7, /*base_atk*/ 3, /*base_def*/ 5, /*critChance*/ 5, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 10) {}
	Goblin(std::string name) : Monster(regular, name, "Goblin", /*base_hp*/ 15, /*base_spd*/ 7, /*base_atk*/ 3, /*base_def*/ 5, /*critChance*/ 5, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 10) {}
	Goblin(std::string name, std::string cret, int hp, int mhp, int lvl, int spd, int atk, int def, int wallet, int exp, int lvlup, Item* W, Item* D) : Monster(regular, name, cret, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, /*critChance*/ 5, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 10, W, D){}
	void gainLVL();
// 	void encounterOutput() {std::cout <<"You come across a squat figure with dark, beady eyes and a striking bone structure. \nYou think to ask if they model, but they emerge from the shadows with a shrill cry for blood."<< std::endl;}
// 	void attackOutput(Character &defense){std::cout << name << " swipes at " << defense.getName() << "--SCRATCH!!" << std::endl;}
	Item* addUncommonDrop();
	Item* soleDrop(){return new Pointyhat(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));}
	Item* soleDrop2() {return new Redraggedyscarf(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));}
	int iExp() {return 5 + rand()%3;}
	Character* spawnMon() {
		Item* W = nullptr, *D = nullptr;
		if(hasWeapon()){
			W = Weapon->grabFromStack();
		}
		if(hasDefensive()){
			D = Defensive->grabFromStack();
		}
		return new Goblin(name, cret, hp, max_hp, lvl, spd, atk, def, wallet, exp, lvlUP, W, D);
	}

};

#endif