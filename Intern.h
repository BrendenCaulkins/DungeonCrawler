#ifndef INTERN_H
#define INTERN_H

#include "Character.h"


class Intern : public Character {
public:
	Intern(std::string name);
	Intern(std::string name, int hp, int mhp,int lvl,int spd, int atk,int def,int wallet,int exp,int lvlup,Item* W,Item* D):Character(INTERN, name, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, /*critChance*/ 5, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 20,W, D){}
private:
	void gainLVL();
};

#endif