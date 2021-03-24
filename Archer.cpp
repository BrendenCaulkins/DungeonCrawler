#include "Archer.h"

//constructor defined inline

void Archer::gainLVL(){
	const int ghp = getValInRange(2, 4), gspd = getValInRange(3, 7), gatk = getValInRange(1, 3), gdef = getValInRange(2, 4);
	output(getType() + " " + name + " has gained a level!", false);
	displayBonuses(ghp, gspd, gatk, gdef);
	++lvl;
	max_hp +=ghp;
	hp = max_hp;
	spd += gspd;
	atk += gatk;
	def += gdef;
	//lvlUP *= 2.15/2;
	displayStats();
	continueRequest();
}