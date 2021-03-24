#ifndef ANDROID_H
#define ANDROID_H

#include "Character.h"

class Android : public Character {
public:
	Android(std::string name) : Character(ANDROID, name, /*base_hp*/ 25, /*base_spd*/ 4, /*base_atk*/ 4, /*base_def*/ 12, /*critChance*/ 2, /*critMultiplier*/ 5, /*accuracy*/ 95, /*evasion*/ 15){ Weapon = new Glowstick();Defensive = new Asslesschaps();} 
	Android(std::string name, int hp, int mhp,int lvl,int spd, int atk,int def,int wallet,int exp,int lvlup,Item* W,Item* D):Character(ANDROID, name, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, /*critChance*/ 2, /*critMultiplier*/ 5, /*accuracy*/ 95, /*evasion*/ 15, W, D){}
private:
	void gainLVL();
};

#endif