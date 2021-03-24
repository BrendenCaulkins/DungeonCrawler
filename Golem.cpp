#include "Golem.h"

void Golem::gainLVL(){
	const int ghp = getValInRange(7, 8), gspd = getValInRange(2, 3), gatk = getValInRange(1, 2), gdef = getValInRange(3, 5);
	++lvl;
	max_hp +=ghp;
	hp = max_hp;
	spd += gspd;
	atk += gatk;
	def += gdef;
// 	lvlUP *= 2.15/2;
}

Item* Golem::addLegendaryDrop(){
	switch(rand()%2){
		case 0:
			return new Smashingboard(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 1:
			return new Guardingrod(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
	}
    return nullptr;
}

void Golem::displayStats(){
	std::string uwu;
	if(name != "Gowem"){
		Monster::displayStats();
		return;
	}
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
	uwu += name + '\n';
	uwu += "Cwass: " + getType() + '\n';
	uwu += "Species: Gowem" + '\n';
	uwu += "WVW: " + std::to_string(lvl) + '\n';
	uwu += "HP: " + std::to_string(hp) + "/" + std::to_string(max_hp) + '\n';
	uwu += "Atk: " + std::to_string(atk) + " + " + std::to_string(abonus + pbonus) + '\n';
	uwu += "Def: " + std::to_string(def) + " + " + std::to_string(dbonus + pbonus) + '\n';
	uwu += "Spd: " + std::to_string(spd) + '\n';
	uwu += "Wawwet: " + std::to_string(wallet) + '\n';
	uwu += "Exp: " + std::to_string(exp) + "/" + std::to_string(lvlUP) + '\n';
	uwu += "Weapon: ";
	if(hasWeapon()){
		std::string wep = Weapon -> getName();
		for(unsigned i = 0; i < wep.size(); ++i){
			if(std::tolower(wep.at(i)) == 'l' || std::tolower(wep.at(i) == 'r')){
				wep.at(i) = 'w';
				
			}
		}
		wep.at(0) = std::toupper(wep.at(0));
		uwu +=  wep + '\n';
		uwu += " Atk: ";
			uwu += std::to_string(Weapon -> getStat());
	}
	else{
		uwu += "UWU";
	}
	uwu += "Defensive: ";
	if(hasDefensive()){
		std::string def = Defensive -> getName();
		for(unsigned i = 0; i < def.size(); ++i){
			if(std::tolower(def.at(i)) == 'l' || std::tolower(def.at(i) == 'r')){
				def.at(i) = 'w';
				
			}
		}
		def.at(0) = std::toupper(def.at(0));
		uwu += def + '\n';
		uwu += " Def: " + std::to_string(Defensive -> getStat());
	}
	else
		uwu += "UWU";
}