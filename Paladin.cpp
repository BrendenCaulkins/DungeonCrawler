#include "Paladin.h"

//constructor defined inline

void Paladin::gainLVL(){
	const int ghp = getValInRange(2, 5), gspd = getValInRange(2, 3), gatk = getValInRange(2, 4), gdef = getValInRange(3, 6);
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