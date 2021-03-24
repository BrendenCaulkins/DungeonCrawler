#ifndef WIZARD_H
#define WIZARD_H

#include "Character.h"


class Wizard : public Character {
public:
	Wizard(std::string name) : Character(WIZARD, name, /*base_hp*/ 20, /*base_spd*/ 8, /*base_atk*/ 12, /*base_def*/ 5, /*critChance*/ 10, /*critMultiplier*/ 2.8, /*accuracy*/ 75, /*evasion*/ 20){ Weapon = new RandomStick();Defensive = new Weakdefensespell();} 
	Wizard(std::string name, int hp, int mhp,int lvl,int spd, int atk,int def,int wallet,int exp,int lvlup,Item* W,Item* D): Character(WIZARD, name, hp, mhp,lvl, spd, atk, def, wallet, exp, lvlup, /*critChance*/ 10, /*critMultiplier*/ 2.8, /*accuracy*/ 75, /*evasion*/ 20, W, D){}
private:
	void gainLVL();
};

#endif