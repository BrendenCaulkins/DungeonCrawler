#include "Orc.h"

void Orc::gainLVL(){
	const int ghp = getValInRange(3, 5), gspd = getValInRange(1, 2), gatk = getValInRange(1, 4), gdef = getValInRange(1, 4);
	++lvl;
	max_hp +=ghp;
	hp = max_hp;
	spd += gspd;
	atk += gatk;
	def += gdef;
// 	lvlUP *= 2.15/2;
}

Item* Orc::addUncommonDrop(){
	switch(rand()%2){
		case 0:
			return new Club(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 1:
			return new Loincloth(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
	}
    return nullptr;
}
