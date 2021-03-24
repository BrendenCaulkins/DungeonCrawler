#include "SentientTrebuchet.h"

void SentientTrebuchet::gainLVL(){
	const int ghp = getValInRange(4, 6), gspd = getValInRange(1, 3), gatk = getValInRange(3, 7), gdef = getValInRange(1, 2);
	++lvl;
	max_hp +=ghp;
	hp = max_hp;
	spd += gspd;
	atk += gatk;
	def += gdef;
// 	lvlUP *= 2.15/2;
}

Item* SentientTrebuchet::addLegendaryDrop(){
	switch(rand()%2){
		case 0:
			return new Banishingcrystal(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 1:
			return new Summoningslime(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
	}
    return nullptr;
}

