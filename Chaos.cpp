#include "Chaos.h"

Chaos::Chaos(std::string name) : Character(MONSTER, name, /*base_hp*/ 0, /*base_spd*/ 0, /*base_atk*/ 0, /*base_def*/ 0, /*critChance*/ 0, /*critMultiplier*/ 0, /*accuracy*/ 0, /*evasion*/ 0) {
// 	int c = 6;
	switch(rand()%7){
		case 0:
			type = PALADIN;
			Weapon = new RustySword();
			Defensive = new RustyShield();
			break;
		case 1:
			type = WIZARD;
			Weapon = new RandomStick();
			Defensive = new Weakdefensespell();
			break;
		case 2:
			type = ARCHER;
			Weapon = new OldBow();
			Defensive = new Thiccleathershirt();
			break;
		case 3:
			type = ANDROID;
			Weapon = new Glowstick();
			Defensive = new Asslesschaps();
			break;
		case 4:
			type = TAMER;
			break;
		case 5:
			type = MONSTER;
// 			determineEquip();
			break;
		case 6:
			type = INTERN;
			switch(rand()%5){
				case 0:
					Weapon = new RustySword();
					Defensive = new RustyShield();
					break;
				case 1:
					Weapon = new RandomStick();
					Defensive = new Weakdefensespell();
					break;
				case 2:
					Weapon = new OldBow();
					Defensive = new Thiccleathershirt();
					break;
				case 3:
					Weapon = new Glowstick();
					Defensive = new Asslesschaps();
					break;
				case 4:
					break;
			}
			break;
	}
	chaosCast(hp, spd, atk, def, /*base pool*/getValInRange(45, 69));
	max_hp = hp;
}

Chaos::Chaos(std::string name, int hp, int mhp,int lvl,int spd, int atk,int def,int wallet,int exp,int lvlup,Item* W,Item* D):Character(MONSTER, name, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, /*critChance*/ 0, /*critMultiplier*/ 0, /*accuracy*/ 0, /*evasion*/ 0,W, D){
	switch(rand()%7){
		case 0:
			type = PALADIN;
			break;
		case 1:
			type = WIZARD;
			break;
		case 2:
			type = ARCHER;
			break;
		case 3:
			type = ANDROID;
			break;
		case 4:
			type = TAMER;
			break;
		case 5:
			type = MONSTER;
// 			determineEquip();
			break;
		case 6:
			type = INTERN;
	}
}

std::string Chaos::getType() {
	std::string name;
	char letter;
	int length = 6 + rand()%4;
	for(int i = 0; i < length; ++i){
		letter = 32 + rand()%95;
		name += letter;
	}
	return name;
}

void Chaos::gainLVL(){
	int ghp, gspd, gatk, gdef;
	chaosCast(ghp, gspd, gatk, gdef, /*lvlup pool*/getValInRange(15,20));
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

void Chaos::chaosCast(int& HP, int& SPD, int& ATK, int& DEF,const int pool){
	int sum = 0;
	while(sum != pool){
		sum = 0;
		HP = getValInRange(1, pool);
		SPD = getValInRange(0, pool);
		ATK = getValInRange(0, pool);
		DEF = getValInRange(0, pool);
		sum += HP;
		sum +=SPD;
		sum +=ATK;
		sum +=DEF;
	}
}

Item* Chaos::equipItem(Item*temp){
	if(type != MONSTER){
		return Character::equipItem(temp);
	}
	else{
		if(canEquip(temp)){
			return attemptEquip(temp);
		}
		output("unable to equip item.", false);
		return nullptr;
	}
	output("unable to equip item.", false);
	return nullptr;
}

bool Chaos::canEquip(Item*temp){
	for(unsigned i = 0; i < equippableItems.size(); ++i){
		if(temp -> getName() == equippableItems.at(i)){
			return true;
		}
	}
	if(rand()%2 == 0){
		equippableItems.push_back(temp -> getName());
		return true;
	}
	return false;
}

// void Chaos::determineEquip(){
// 	std::ifstream inFS("EquippableItems.txt");
// 	if(!inFS.is_open()){
// 		std::cout << "ERROR, changing type." << std::endl;
// 		type = TAMER;
// 		return;
// 	}
// 	std::vector<std::string> totalPool;
// 	std::string newItems;
// 	while(std::getline(inFS, newItems)){
// 		totalPool.push_back(newItems);
// 	}
// 	for(unsigned i = 0; i < totalPool.size(); ++i){
// 		if(rand()%2 == 1){
// 			equippableItems.push_back(totalPool.at(i));
// 		}
// 	}
// 	inFS.close();
// 	std::ofstream outFS("TESTFILE.txt");
// 	for(unsigned i = 0; i < equippableItems.size(); ++i){
// 		outFS << equippableItems.at(i) << std::endl;
// 	}
// }

// void Chaos::displayE(){
// 	for(auto i: equippableItems){
// 		std::cout << i << std::endl;
// 	}
// }

Item* Chaos::attemptEquip(Item*temp){
	if(temp -> wType() == wep){
		return MequipWeapon(temp);
	}
	else if(temp -> wType() == shi){
		return MequipDefensive(temp);
	}
    return nullptr;
}

Item* Chaos::MequipWeapon(Item *nWeapon){
	if(lvl >= nWeapon -> getLVL()||type == INTERN){
		Item *temp = unequipWeapon();
		Weapon = nWeapon;
		return temp;
	}
	else if(lvl < nWeapon -> getLVL())
		output("Unable to equip item, you're too weak.", false);
	return nullptr;
}
Item* Chaos::MequipDefensive(Item *nDefensive){
	if(lvl >= nDefensive -> getLVL()|| type == INTERN){
		Item *temp = unequipDefensive();
		Defensive = nDefensive;
		return temp;
	}
	output("Unable to equip item, you're too weak.", false);
	return nullptr;
}
