#include "SuperSoakingSquirter.h"

void SuperSoakingSquirter::gainLVL(){
	const int ghp = getValInRange(4, 8), gspd = getValInRange(1, 3), gatk = getValInRange(3, 4), gdef = getValInRange(2, 3);
	++lvl;
	max_hp +=ghp;
	hp = max_hp;
	spd += gspd;
	atk += gatk;
	def += gdef;
// 	lvlUP *= 2.15/2;
}

Item* SuperSoakingSquirter::addLegendaryDrop(){
	switch(rand()%2){
		case 0:
			return new Squirtgun(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 1:
			return new Umbrella(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
	}
    return nullptr;
}
