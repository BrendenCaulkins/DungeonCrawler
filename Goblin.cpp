#include "Goblin.h"

void Goblin::gainLVL(){
	const int ghp = getValInRange(1, 3), gspd = getValInRange(1, 4), gatk = getValInRange(1, 2), gdef = getValInRange(1, 3);
	++lvl;
	max_hp +=ghp;
	hp = max_hp;
	spd += gspd;
	atk += gatk;
	def += gdef;
// 	lvlUP *= 2.15/2;
}

Item* Goblin::addUncommonDrop(){
	switch(rand()%2){
		case 0:
			return new Pointyhat(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 1:
			return new Redraggedyscarf(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
	}
    return nullptr;
}
