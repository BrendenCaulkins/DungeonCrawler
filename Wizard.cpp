#include "Wizard.h"

//constructor defined inline

void Wizard::gainLVL(){
	const int ghp = getValInRange(3, 5), gspd = getValInRange(1, 4), gatk = getValInRange(3, 6), gdef = getValInRange(1, 3);
	output( getType() + " " + name + " has gained a level!", false );
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
	char k;
	std::cin.get(k);
}