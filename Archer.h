#ifndef ARCHER_H
#define ARCHER_H

#include "Character.h"


class Archer : public Character {
public:
	Archer(std::string name) : Character(ARCHER, name, /*base_hp*/ 18, /*base_spd*/ 15, /*base_atk*/ 5, /*base_def*/ 7, /*critChance*/ 40, /*critMultiplier*/ 2.5, /*accuracy*/ 90, /*evasion*/ 60){Weapon = new OldBow();Defensive = new Thiccleathershirt();} 
	Archer(std::string name, int hp, int mhp,int lvl,int spd, int atk,int def,int wallet,int exp,int lvlup,Item* W,Item* D):Character(ARCHER, name, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, /*critChance*/ 40, /*critMultiplier*/ 2.5, /*accuracy*/ 90, /*evasion*/ 60,W, D){}
private:
	void gainLVL();
};

#endif