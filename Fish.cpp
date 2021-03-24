#include "Fish.h"

void Fish::gainLVL(){
	const int ghp = getValInRange(5, 7), gspd = getValInRange(1, 3), gatk = getValInRange(2, 4), gdef = getValInRange(2, 4);
	++lvl;
	max_hp +=ghp;
	hp = max_hp;
	spd += gspd;
	atk += gatk;
	def += gdef;
// 	lvlUP *= 2.15/2;
}

Item* Fish::addLegendaryDrop(){
	switch(rand()%2){
		case 0:
			return new Egg(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 1:
			return new Chicken(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
	}
    return nullptr;
}
