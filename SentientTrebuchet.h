#ifndef SENTIENTTREBUCHET_H
#define SENTIENTTREBUCHET_H

#include "Monster.h"

class SentientTrebuchet : public Monster {
	public:
	SentientTrebuchet() : Monster(boss, "Sentient Trebuchet", /*base_hp*/ 35, /*base_spd*/ 8, /*base_atk*/ 10, /*base_def*/ 2, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 20) {}
	SentientTrebuchet(std::string name) : Monster(boss, name, "Sentient Trebuchet", /*base_hp*/ 35, /*base_spd*/ 8, /*base_atk*/ 10, /*base_def*/ 2, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 20) {}
	SentientTrebuchet(std::string name, std::string cret, int hp, int mhp, int lvl, int spd, int atk, int def, int wallet, int exp, int lvlup, Item* W, Item* D) : Monster(boss, name, cret, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 20, W, D){}
	void gainLVL();
// 	void encounterOutput() {output("A giant wooden structure stands in your way. \nNo one knows how it got here, or how it gained sentience, \nbut it is prepared to lay siege upon any who stand against it." << std::endl;}
// 	void attackOutput(Character &defense){output( name << " launches " << defense.getName() << ", who happens to weigh 90 kilograms, 300 meters" << std::endl;}
	Item* addLegendaryDrop();
	Item* soleDrop(){return new Banishingcrystal(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));}
	Item* soleDrop2() {return new Summoningslime(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));}
	int iExp() {return 18 + rand()%8;}
	Character* spawnMon() {
		Item* W = nullptr, *D = nullptr;
		if(hasWeapon()){
			W = Weapon->grabFromStack();
		}
		if(hasDefensive()){
			D = Defensive->grabFromStack();
		}
		return new SentientTrebuchet(name, cret, hp, max_hp, lvl, spd, atk, def, wallet, exp, lvlUP, W, D);
	}

};

#endif