#ifndef PALADIN_H
#define PALADIN_H

#include "Character.h"


class Paladin : public Character {
public:
	Paladin(std::string name) : Character(PALADIN, name, /*base_hp*/ 23, /*base_spd*/ 5, /*base_atk*/ 7, /*base_def*/ 10, /*critChance*/ 5, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 15) {Weapon = new RustySword();Defensive = new RustyShield();} 
	Paladin(std::string name, int hp, int mhp,int lvl,int spd, int atk,int def,int wallet,int exp,int lvlup,Item* W,Item* D):Character(PALADIN, name, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, /*critChance*/ 5, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 15,W, D){}
private:
	void gainLVL();
};

#endif