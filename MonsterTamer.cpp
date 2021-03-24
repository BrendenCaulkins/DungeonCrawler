#include "MonsterTamer.h"

MonsterTamer::MonsterTamer(std::string name) : Character(TAMER, name, /*base_hp*/ 20, /*base_spd*/ 8, /*base_atk*/ 9, /*base_def*/8, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 20){
	Character *f;
	if(name == "Arianne Kisner"||name == "Arianne"||name == "arianne"){
		f = new PorcupineLion();
	}
	else{
	if(rand()%250 == 69){
		switch(rand()%3){
			case 0:
				f = new Fish();
				break;
			case 1:
				f = new Golem();
				break;
			case 2:
				f = new PorcupineLion();
		}
	}
		else{
	switch(rand()%4){
		case 0:
			f = new GiantBoar();
			break;
		case 1:
			f = new Goblin();
			break;
		case 2:
			f = new Orc();
			break;
		case 3:
			f = new JivinFunkyBadger();
			break;
	}
		}
	}
	output("do you remember your old companion, the " + f -> getName() + "'s name(y/n)?", false);
	char choose;
	std::string nickname;
	std::cin >> choose;
	std::cin.ignore(500, '\n');
	switch(choose){
		case 'y':
			outputflush("Tell us your companions name ('r' for a random name): ", false);
			getline(std::cin, nickname);
			if(nickname == "r"){
				nickname = generateName();
				nickname.at(0) = toupper(nickname.at(0));
			}
			Weapon = Monstertamed(nickname, *f);
		break;
		default:
			Weapon = Monstertamed(/*name + "'s " + */f -> getName(), *f);	
	}
} 

void MonsterTamer::gainLVL(){
	const int ghp = getValInRange(3, 6), gspd = getValInRange(1, 4), gatk = getValInRange(2, 5), gdef = getValInRange(1, 3);
	output(getType() + " " + name + " has gained a level!", false);
	displayBonuses(ghp, gspd, gatk, gdef);
	++lvl;
	max_hp +=ghp;
	hp = max_hp;
	spd += gspd;
	atk += gatk;
	def += gdef;
// 	lvlUP *= 2.15/2;
	displayStats();
	continueRequest();
}

Item* MonsterTamer::Monstertamed(std::string nickname, Character &tamed){
	return new TamedMonster(nickname, tamed);
}

bool MonsterTamer::tameMonster(Character &tamee){
	double chance = ((1- (1.0 * tamee.getHP())/tamee.getMHP())/3.0 + ((1.0 * lvl)/tamee.getLVL())/3.0) * 100;
	if(tamee.getDef() >0){
		chance +=((1.0 *atk)/tamee.getDef())/3.0;
	}
	else{
		chance+=atk/6.0;
	}
	if(tamee.getType() == "Special"){
		chance/=2;
	}
	if(tamee.getType() == "Boss"){
		chance/=10;
	}
	//std::cout << chance << std::endl;
	if(rand()%100<chance){
		gainEXP(tamee);
		return true;
	}
	return false;
}

void MonsterTamer::attack(Character & defense, int numAtk){
	if(hasWeapon()){
		Weapon->getMon() ->attack(defense, numAtk);
		return;
	}
	Character::attack(defense, numAtk);
}

Item* MonsterTamer::equipWeapon(Item *nWeapon){
	int cClass = type;
	int wClass = nWeapon -> iType();
	if(cClass == wClass&&nWeapon -> getMon() ->isAlive()){
		Item *temp = unequipWeapon();
		Weapon = nWeapon;
		return temp;
	}
	if(cClass != wClass)
		output("Unable to equip weapon, improper type.", false);
	else if(!nWeapon -> getMon() -> isAlive())
		output("Unable to send friend out, they're unconcious.", false);
	return nullptr;
}