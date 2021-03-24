#include "KillerGarfield.h"

void KillerGarfield::gainLVL(){
	const int ghp = getValInRange(3, 5), gspd = getValInRange(2, 5), gatk = getValInRange(1, 3), gdef = getValInRange(1, 2);
	++lvl;
	max_hp +=ghp;
	hp = max_hp;
	spd += gspd;
	atk += gatk;
	def += gdef;
// 	lvlUP *= 2.15/2;
}

Item* KillerGarfield::addrareDrop(){
	switch(rand()%6){
		case 0:
			return new Gun(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 1:
			return new Tinyhammer(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 2:
			return new Keytar(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 3:
			return new Bulletarmor(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 4:
			return new Hardhat(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 5:
			return new Glockenspiel(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
	}
    return nullptr;
}

Item* KillerGarfield::addVeryRareDrop(){
	switch(rand()%2){
		case 0:
			return new Killergarfieldsvoice(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 1:
			return new Voidpouch(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
	}
    return nullptr;
}