#include "Dragon.h"

void Dragon::gainLVL(){
	const int ghp = getValInRange(5, 7), gspd = getValInRange(1, 3), gatk = getValInRange(2, 5), gdef = getValInRange(1, 3);
	++lvl;
	max_hp +=ghp;
	hp = max_hp;
	spd += gspd;
	atk += gatk;
	def += gdef;
	//lvlUP *= 2.15/2;
}

Item* Dragon::addLegendaryDrop(){
	switch(rand()%2){
		case 0:
			return new Dragonsbreath(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 1:
			return new Dragonsvapepen(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
	}
    return nullptr;
}