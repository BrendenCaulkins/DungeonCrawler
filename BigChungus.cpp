#include "BigChungus.h"

void BigChungus::gainLVL(){
	const int ghp = getValInRange(5, 7), gspd = getValInRange(1, 2), gatk = getValInRange(1, 3), gdef = getValInRange(1, 3);
	++lvl;
	max_hp +=ghp;
	hp = max_hp;
	spd += gspd;
	atk += gatk;
	def += gdef;
	//lvlUP *= 2.15/2;
}

Item* BigChungus::addrareDrop(){
	switch(rand()%6){
		case 0:
			return new Flipflop(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 1:
			return new Magiccloak(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 2:
			return new Keyboard(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 3:
			return new Largefoamfinger(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 4:
			return new Desk(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 5:
			return new Magiccensorbar(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));


	}
    return nullptr;
}

Item* BigChungus::addVeryRareDrop(){
	switch(rand()%2){
		case 0:
			return new Enchantedbow(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 1:
			return new Enchantedshield(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
	}
    return nullptr;
}