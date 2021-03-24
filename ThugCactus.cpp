#include "ThugCactus.h"

void ThugCactus::gainLVL(){
	const int ghp = getValInRange(3, 6), gspd = getValInRange(1, 3), gatk = getValInRange(1, 3), gdef = getValInRange(1, 3);
	++lvl;
	max_hp +=ghp;
	hp = max_hp;
	spd += gspd;
	atk += gatk;
	def += gdef;
	//lvlUP *= 2.15/2;
}

Item* ThugCactus::addrareDrop(){
	switch(rand()%6){
		case 0:
			return new Enchantedbrassknuckles(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 1:
			return new Needles(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 2:
			return new Microphone(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 3:
			return new Enchantedgoldchain(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 4:
			return new Bandages(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 5:
			return new Noisecancellingheadphones(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
	}
    return nullptr;
}

Item* ThugCactus::addVeryRareDrop(){
	switch(rand()%2){
		case 0:
			return new Chainsaw(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 1:
			return new Leafblower(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
	}
    return nullptr;
}