#ifndef JIVINFUNKYBADGER_H
#define JIVINFUNKYBADGER_H

#include "Monster.h"

class JivinFunkyBadger : public Monster {
	public:
	JivinFunkyBadger() : Monster(regular, "Jivin' Funky Badger", /*base_hp*/ 1, /*base_spd*/ 20, /*base_atk*/ 19, /*base_def*/ 0, /*critChance*/ 1, /*critMultiplier*/ 2.5, /*accuracy*/ 5, /*evasion*/ 25) {}
	JivinFunkyBadger(std::string name) : Monster(regular, name, "Jivin' Funky Badger", /*base_hp*/ 1, /*base_spd*/ 20, /*base_atk*/ 19, /*base_def*/ 0, /*critChance*/ 1, /*critMultiplier*/ 2.5, /*accuracy*/ 5, /*evasion*/ 25) {}
	JivinFunkyBadger(std::string name, std::string cret, int hp, int mhp, int lvl, int spd, int atk, int def, int wallet, int exp, int lvlup, Item* W, Item* D) : Monster(regular, name, cret, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, /*critChance*/ 1, /*critMultiplier*/ 2.5, /*accuracy*/ 5, /*evasion*/ 25, W, D){}
	void gainLVL();
// 	void encounterOutput() {std::cout << name << " challenges you to a deadly dance competition. Watch out, he's funky" << std::endl;}
// 	void attackOutput(Character &defense){std::cout << name << " aggressively dances at " << defense.getName() << " and tail smacks them" << std::endl;}
	Item* addUncommonDrop();
		Item* soleDrop(){return new Flipphone(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));}
	Item* soleDrop2() {return new Antenna(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));}
	int iExp() {return 7 + rand()%4;}
	Character* spawnMon() {
		Item* W = nullptr, *D = nullptr;
		if(hasWeapon()){
			W = Weapon->grabFromStack();
		}
		if(hasDefensive()){
			D = Defensive->grabFromStack();
		}
		return new JivinFunkyBadger(name, cret, hp, max_hp, lvl, spd, atk, def, wallet, exp, lvlUP, W, D);
	}


};

#endif