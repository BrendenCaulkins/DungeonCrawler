#include "Intern.h"

Intern::Intern(std::string name) : Character(INTERN, name, /*base_hp*/ 24, /*base_spd*/ 15, /*base_atk*/ 3, /*base_def*/ 3, /*critChance*/ 5, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 20){
		if(name == "gun"||name == "Gun"||name == "GUn"||name=="GUN"||name=="GuN"||name=="gUN"||name=="gUn"||name=="guN"||name =="chris"){
			return;
		}
		if(name == "Kenneth"||name == "Karen"||name=="Kaleb"||name=="Susan"||name=="Patricia"||name=="Matt"||name=="Lyle"||name=="Lauren"||name=="Gavin"||name=="Kyle"||name=="Thanos"||name=="Tim"||name=="Keke"){
			Weapon = new Gun(1);
			Defensive = new Bulletarmor(1);
			return;
		}
		if(name=="Gunn"){
			Weapon = new Banishingcrystal(1);
			Defensive = new Summoningslime(1);
				return;
		}
		switch(rand()%3){
			case 0:
				Weapon = new Scythe(1);
				Defensive = new Wheatstalk(1);
			break;
			case 1:
				Weapon = new Oldstaff(1);
				Defensive = new Moderatedefensespell(1);
			break;
			case 2:
				Weapon = new Crossbow(1);
				Defensive = new Chainmail(1);
			break;
		}
	} 
void Intern::gainLVL(){
	const int ghp = getValInRange(3, 6), gspd = getValInRange(2, 7), gatk = getValInRange(1, 2), gdef = getValInRange(1, 3);
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