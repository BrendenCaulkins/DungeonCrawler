#include "Saintan.h"

void Saintan::gainLVL(){
	const int ghp = getValInRange(2, 6), gspd = getValInRange(1, 3), gatk = getValInRange(2, 3), gdef = getValInRange(2, 3);
	++lvl;
	max_hp +=ghp;
	hp = max_hp;
	spd += gspd;
	atk += gatk;
	def += gdef;
// 	lvlUP *= 2.15/2;
}

Item* Saintan::addrareDrop(){
	switch(rand()%6){
		case 0:
			return new Lizard(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 1:
			return new Bayonet(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 2:
			return new Candle(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 3:
			return new Lemur(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 4:
			return new Netobay(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 5:
			return new Giantsnuffer(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
	}
    return nullptr;
}

Item* Saintan::addVeryRareDrop(){
	switch(rand()%2){
		case 0:
			return new Musicalkatana(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 1:
			return new Offkeyarmor(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
	}
    return nullptr;
}
