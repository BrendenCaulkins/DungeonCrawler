#include "Fighter.h"

//constructor defined inline

void Fighter::gainLVL(){
	const int ghp = 0, gspd = getValInRange(2, 4), gatk = getValInRange(7, 10), gdef = 0;
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