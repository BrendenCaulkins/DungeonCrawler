#include "Kyle.h"

Kyle::Kyle() : Monster(UNIQUE, "Kyle", /*base_hp*/ 0, /*base_spd*/ 0, /*base_atk*/ 0, /*base_def*/ 0, /*critChance*/ 0, /*critMultiplier*/ 0, /*accuracy*/ 0, /*evasion*/ 0) {
	switch(rand()%3){
		case 0:
		monster = regular;
		name = "Kyle";
		cret = "Kyle";
		chaosCast(hp, spd, atk, def, 40);/*regular pool*/
		break;
		case 1:
		monster = special;
		name = "Kenneth";
		cret = "Kenneth";
		chaosCast(hp, spd, atk, def, 45);/*special pool*/
		break;
		case 2:
		monster = boss;
		name = "Lucky Luciano";
		cret = "Lucky Luciano";
		chaosCast(hp, spd, atk, def, 55);/*boss pool*/
		break;
	}
	max_hp = hp;
}

Kyle::Kyle(std::string name) : Monster(UNIQUE, name, "Kyle", /*base_hp*/ 0, /*base_spd*/ 0, /*base_atk*/ 0, /*base_def*/ 0, /*critChance*/ 0, /*critMultiplier*/ 0, /*accuracy*/ 0, /*evasion*/ 0) {
	switch(rand()%3){
		case 0:
		monster = regular;
// 		name = "Kyle";
		cret = "Kyle";
		chaosCast(hp, spd, atk, def, 40);/*regular pool*/
		break;
		case 1:
		monster = special;
// 		name = "Kenneth";
		cret = "Kenneth";
		chaosCast(hp, spd, atk, def, 45);/*special pool*/
		break;
		case 2:
		monster = boss;
// 		name = "Lucky Luciano";
		cret = "Lucky Luciano";
		chaosCast(hp, spd, atk, def, 55);/*boss pool*/
		break;
	}
	max_hp = hp;
}

void Kyle::gainLVL(){
	int ghp, gspd, gatk, gdef;
	switch(monster){
		case regular:
		case special:
			chaosCast(ghp, gspd, gatk, gdef, 15);
			break;
		case boss:
			chaosCast(ghp, gspd, gatk, gdef, 18);
			break;
	}
	++lvl;
	
	max_hp +=ghp;
	hp = max_hp;
	spd += gspd;
	atk += gatk;
	def += gdef;
// 	lvlUP *= 2.15/2;
}

std::vector<Item*> Kyle::dropItems(int& money){
	std::vector <Item *> drop;
// 		drop.push_back(spawnPotion());
		if(drop.back() == nullptr){
			drop.pop_back();
		}
		drop.resize(1 + rand()%5);
		for(unsigned i = 1; i < drop.size(); ++i){
			switch(rand()%2){
				case 0:
					drop.at(i) = soleDrop();
					break;
				case 1:
					drop.at(i) = soleDrop2();
					break;
			}
		}
	money = rand()%1000;
	outputDrop(drop, money);
	return drop;
}

Item* Kyle::soleDrop(){
	return dropWeapon(name, atk, getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
}

Item* Kyle::soleDrop2(){
	return dropDefensive(name, def, getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
}