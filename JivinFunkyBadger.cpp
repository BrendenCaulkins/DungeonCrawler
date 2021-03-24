#include "JivinFunkyBadger.h"

void JivinFunkyBadger::gainLVL(){
	const int ghp = getValInRange(0, 2), gspd = getValInRange(5, 7), gatk = getValInRange(3, 5), gdef = getValInRange(0, 1);
	++lvl;
	max_hp +=ghp;
	hp = max_hp;
	spd += gspd;
	atk += gatk;
	def += gdef;
// 	lvlUP *= 2.15/2;
}

Item* JivinFunkyBadger::addUncommonDrop(){
	switch(rand()%2){
		case 0:
			return new Flipphone(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 1:
			return new Antenna(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
	}
    return nullptr;
}

