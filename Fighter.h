#ifndef FIGHTER_H
#define FIGHTER_H

#include "Character.h"
//calcDamage in Character.cpp has an if statement that makes fighter only take damage on a critical hit

class Fighter : public Character {
public:
	Fighter(std::string name) : Character(FIGHTER, name, /*base_hp*/ 1, /*base_spd*/ 8, /*base_atk*/ 100, /*base_def*/ 0, /*critChance*/ 70, /*critMultiplier*/ 5, /*accuracy*/ 95, /*evasion*/ 85) {} 
	Fighter(std::string name, int hp, int mhp,int lvl,int spd, int atk,int def,int wallet,int exp,int lvlup,Item* W,Item* D):Character(FIGHTER, name, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, /*critChance*/ 70, /*critMultiplier*/ 5, /*accuracy*/ 95, /*evasion*/ 85,W, D){}
private:
	void gainLVL();
};

#endif