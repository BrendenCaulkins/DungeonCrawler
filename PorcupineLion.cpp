#include "PorcupineLion.h"

void PorcupineLion::gainLVL(){
	const int ghp = getValInRange(4, 5), gspd = getValInRange(3, 5), gatk = getValInRange(3, 5), gdef = getValInRange(3, 5);
	++lvl;
	max_hp +=ghp;
	hp = max_hp;
	spd += gspd;
	atk += gatk;
	def += gdef;
// 	lvlUP *= 2.15/2;
}

