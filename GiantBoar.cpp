#include "GiantBoar.h"

void GiantBoar::gainLVL(){
	const int ghp = getValInRange(3, 5), gspd = getValInRange(2, 4), gatk = getValInRange(1, 3), gdef = getValInRange(1, 3);
	++lvl;
	max_hp +=ghp;
	hp = max_hp;
	spd += gspd;
	atk += gatk;
	def += gdef;
// 	lvlUP *= 2.15/2;
}

Item* GiantBoar::addUncommonDrop(){
	switch(rand()%2){
		case 0:
			return new Crossbow(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 1:
			return new Chainmail(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
	}
    return nullptr;
}
