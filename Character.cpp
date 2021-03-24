#include "Character.h"

//constructor inlined

void Character::attack(Character& defense, int numAtk){
	bool atkd = false;
	for(unsigned i = 0; i < numAtk; ++i){
		if(defense.isTamer()&&defense.hasWeapon()){
			attack(*defense.getWeapon()->getMon(), numAtk);
			return;
		}
		if(!defense.isAlive()){
// 			return;
// 			std::cout << "Unable to attack " << defense.getName() << " is unconcious." << std::endl;
			return;
		}
		if(rand()%100 < getAccuracy() && rand()%100 > defense.getEvasion()){
			if(!atkd){
				atkd = true;
				std::string atkout;
				if(hasWeapon()){
					outputflush(name, false);
                    Weapon -> attackOutput(defense.getName());
				}
				else{
					attackOutput(defense);
				}
// 			output(atkout, false);
			}
			int dmg = calcDamage(defense);
			defense.damage(victoryOutput(defense), dmg);
		}
		else
			output(name + " missed.", false);
	}
	
	if(!defense.isAlive())
		gainEXP(defense);
}

std::string Character::victoryOutput(Character& mon){
	std::string t = getType();
	if(isChaos()){
		t = "Chaos";
	}
	else if(isMon() && isTamed){
		t = "Tamer";
	}
	else if(isMon()){
		
	}
	std::ifstream ifs("./victoryOutput/" + t + "VictoryOutput.txt");
	if(!ifs.is_open()){
		return "mysteriously disappears.";
	}
	std::vector<std::string>v;
	std::string line;
	while(getline(ifs, line)){
			if(line == ""){
				break;
			}
			if(line.at(0) == '.'){
				if(line.size()>1 && line.at(1) == '.')
					v.push_back('\n' + line.substr(2, line.size()));
				else
					v.at(v.size() - 1) += '\n' + line.substr(1, line.size());
			}
			else{
				v.push_back(line);
			}
	}
	if(v.size()>0){
		std::string sentence = v.at(rand()%v.size());
		std::string mName = mon.getName();
			parseMonsterName(sentence, mName);
			parsePlayerName(sentence, getName());
			std::string wep;
				if(hasWeapon()){
					wep = getWeapon() -> getName();
				}
			parseItem(sentence, wep);
			parseChoice(sentence);
			parseFind(sentence);
			parseRand(sentence);
			std::vector<std::string> mType;
			mType.push_back(mon.getType());
			mType.push_back(mon.getCreature());
			parseIfElse(sentence, mType);
		return sentence;
	}
	return "vanishes.";
}

bool Character::isAlive() const {
	if(hp >0)
		return true;
	
	return false;
}

void Character::displayStats(){
	std::string displayScreen;
	int abonus = 0, dbonus = 0, pbonus = 0;
	if(hasWeapon()){
		abonus = Weapon -> getStat();
	}
	if(hasDefensive()){
		dbonus = Defensive -> getStat();
	}
	if(hasWeapon() && hasDefensive()){
		if(Weapon->isPair(*Defensive)){
			pbonus = Weapon -> getStat()/3;
		}
	}
	displayScreen += name + '\n';
	displayScreen += "Class: " + getType() + '\n';
	displayScreen += "LVL: " + std::to_string(lvl) + '\n';
	displayScreen += "HP: " + std::to_string(hp) + "/" + std::to_string(max_hp) + '\n';
	displayScreen += "Atk: " + std::to_string(atk) + " + " + std::to_string(abonus + pbonus) + '\n';
	displayScreen += "Def: " + std::to_string(def) + " + " + std::to_string(dbonus + pbonus) + '\n';
	displayScreen += "Spd: " + std::to_string(spd) + '\n';
	displayScreen += "Wallet: " + std::to_string(wallet) + '\n';
	displayScreen += "Exp: " + std::to_string(exp) + "/" + std::to_string(lvlUP) + '\n';
	displayScreen += "Weapon: ";
	if(hasWeapon()){
		displayScreen +=  Weapon -> getName() + '\n';
		if(isTamer())
			displayScreen += " Health: " + std::to_string(Weapon -> getMon() ->getHP()) + "/" + std::to_string(Weapon -> getMon()-> getMHP()) + '\n';
		displayScreen += " Atk: ";
		if(isTamer())
			displayScreen += std::to_string(Weapon -> getMon() -> getAtk()) + '\n';
		else
			displayScreen += std::to_string(Weapon -> getStat()) + '\n';
	}
	else{
        displayScreen += "none";
		displayScreen += '\n';
	}
	displayScreen += "Defensive: ";
	if(hasDefensive()){
		displayScreen += Defensive -> getName() + '\n';
		displayScreen += " Def: " + std::to_string(Defensive -> getStat()) + '\n';
	}
	else
		displayScreen += "none";
	
	output(displayScreen, false);
}

int Character::calcDamage(Character & defense){
	int dmg=0;
	int patk=0, mdef=0;
	if(hasWeapon() && hasDefensive()){
		if(Weapon -> isPair(*Defensive)){
			patk = Weapon ->getStat()/3;
		}
	}
	if(defense.hasWeapon() && defense.hasDefensive()){
		if(defense.getWeapon()-> isPair(*defense.getDefensive())){
			mdef = defense.getWeapon() -> getStat()/3;
		}
	}
	if(hasWeapon()){
		patk += atk + Weapon -> getStat();
	}
	else{
		patk += atk;
	}
	if(defense.hasDefensive()){
		mdef += defense.getDef() + defense.getDefensive() -> getStat();
	}
	else{
		mdef += defense.getDef();
	}
	if(patk - mdef <=0){
			dmg = 1 + rand()%3;
		}
		else{
			dmg = rand()%4 + patk - mdef;
		}
	if(defense.getType() == "Fighter"){
		dmg = 0;
		if(rand()%100 < getCritChance()){
			output("Critical Hit!!!", true);
			dmg = 1;
		}
	}
	else
		if(rand()%100 < getCritChance()){
			output("Critical Hit!!!", true);
			dmg *= getCritMultiplier();
		}
	return dmg;
}

void Character::damage(std::string victoryOutput, int dmg){
	std::string out;
	if(dmg >= hp){
		if(!isMon())
			out = "you take " + std::to_string(hp) + " point(s) of damage and " + victoryOutput;
		else
			out = name + " takes " + std::to_string(hp) + " point(s) of damage and " + victoryOutput;
		output(out, true);
		hp -= hp;
		continueRequest();
		return;
	}
	std::string dmgoutput;
	if(!isMon())
		dmgoutput =  "You take " + std::to_string(dmg) + " point(s) of damage.";
	else
		dmgoutput = name + " takes " + std::to_string(dmg) + " point(s) of damage.";
	output(dmgoutput, true);
	hp -= dmg;
}

std::string Character::getType(){
	switch(type){
		case PALADIN:
			return "Paladin";
			break;
		case WIZARD:
			return "Wizard";
			break;
		case ARCHER:
			return "Archer";
			break;
		case INTERN:
			return "Intern";
			break;
		case ANDROID:
			return "Android";
		case TAMER:
			return "Tamer";
		case MONSTER:
			return "Monster";
		case FIGHTER:
			return "Fighter";
	}
return "ERROR";
}

void Character::gainHP(int gain){
	if(gain >= max_hp - hp){
		gain = max_hp - hp;
		hp = max_hp;
	}
	else{
			hp += gain;
	}
	std::string gainz = name + " gained " + std::to_string(gain) + " hp.";
	output(gainz, false);
}

void Character::gainMaxHP(int gain){
	max_hp += gain;
	hp += gain;
}

void Character::gainAtk(int gain){
	atk += gain;
}

void Character::gainDef(int gain){
	def += gain;
}

void Character::gainSpd(int gain){
	spd += gain;
}

bool Character::fullHP(){
	if(hp == max_hp){
		return true;
	}
	return false;
}

void Character::gainEXP(Character & corpse){
	if(lvl >= MAX_LVL){
		exp = lvlUP = 0;
		return;
	}
	int gain = corpse.expCalc(lvl); 
	exp+= gain;
	std::string expgainz = name + " gained " + std::to_string(gain) + " exp points.";
	output(expgainz, false);
	while(exp >= lvlUP){
		exp -= lvlUP;
		gainLVL();
		lvlUP += lvlUP/4;
	}
	if(isTamer()&&hasWeapon()){
		Weapon ->getMon() -> gainEXP(corpse);
	}
}

void Character::displayBonuses(int ghp, int gspd, int gatk, int gdef){
	std::string displayScreen;
	displayScreen += name + '\n';
	displayScreen += "Class: " + getType() + '\n';
	displayScreen += "LVL: " + std::to_string(lvl) + " + 1" + '\n';
	displayScreen += "HP: " + std::to_string(hp) + "/" + std::to_string(max_hp) + " + " + std::to_string(ghp) + '\n';
	displayScreen += "Atk: " + std::to_string(atk) + " + " + std::to_string(gatk) + '\n';
	displayScreen += "Def: " + std::to_string(def) + " + " + std::to_string(gdef) + '\n';
	displayScreen += "Spd: " + std::to_string(spd) + " + " + std::to_string(gspd) + '\n';
	displayScreen += "Wallet: " + std::to_string(wallet) + '\n';
	if(getType() != "Monster")
		displayScreen += "Exp: " + std::to_string(exp) + "/" + std::to_string(lvlUP) + '\n';
	output(displayScreen, false);
	continueRequest();
}

Item* Character::equipItem(Item*temp){
	if(temp -> wType() == wep){
		return equipWeapon(temp);
	}
	else if(temp -> wType() == shi){
		return equipDefensive(temp);
	}
    return nullptr;
}

Item* Character::equipWeapon(Item *nWeapon){
	int cClass = type;
	int wClass = nWeapon -> iType();
	if(cClass == wClass&& lvl >= nWeapon -> getLVL()||type == MONSTER || type == INTERN){
		Item *temp = unequipWeapon();
		Weapon = nWeapon;
		return temp;
	}
	if(cClass != wClass)
		output("Unable to equip item, improper type.", false);
	else if(lvl < nWeapon -> getLVL())
		output("Unable to equip item, you're too weak.", false);
	return nWeapon;
}
Item*Character::equipDefensive(Item *nDefensive){
	int cClass = type;
	int wClass = nDefensive -> iType();
	if(cClass == wClass&& lvl >= nDefensive -> getLVL()||type == MONSTER || type == INTERN){
		Item *temp = unequipDefensive();
		Defensive = nDefensive;
		return temp;
	}
	if(cClass != wClass)
		output("Unable to equip item, improper type.", false);
	else if(lvl < nDefensive -> getLVL())
		output("Unable to equip item, you're too weak.", false);
	return nDefensive;
}

void Character::displayWeapon(){
	if(hasWeapon()){
		Weapon -> displayItem();
	}
	else
		output("Weapon: none", false);
}

void Character::displayDefensive() {
	if(hasDefensive())
		Defensive -> displayItem();
	else
		output("Defensive: none", false);
}

Item* Character::unequipWeapon(){
	Item *temp = Weapon;
	Weapon = nullptr;
	return temp;
}

Item* Character::unequipDefensive(){
	Item *temp = Defensive;
	Defensive = nullptr;
	return temp;
}

bool Character::run(Character& defense){
	double chance = (spd * lvl * 1.0)/(defense.getLVL() *defense.getSpd()) * 100;
	//std::cout << chance << std::endl;
	if(rand()%100 < chance){
		output("You fled.", false);
		return true;
	}
	output("You tried to run but couldn't get away.", true);
	return false;
}