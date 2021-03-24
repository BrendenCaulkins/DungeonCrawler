#include "includeItems.h"

// bool Item::operator!=(Item& rhs){
// 	if(isMon()){
// 		return true;
// 	}
// 	if(this -> name != rhs.name){
// 		return true;
// 	}
// 	if(isPotion()){
// 		return false;
// 	}
// 	if(getRare() == "Unique"){
// 		return true;
// 	}
// 	return false;
// }

bool Item::operator ==(Item& rhs){
	if(isMon()){
			return false;
		}
	if(this ->name == rhs.name&&isPotion()){
		return true;
		
	}
	if(getRare() == rhs.getRare() && getRare() != "Unique" && this -> name == rhs.name){
			return true;
	}
	return false;
}

bool Item::operator <(Item& rhs){
// 	std::cout << "comparing" << std::endl;
	if(isBook()){
		return true;
	}
	if(isPotion()){
		if(rhs.isPotion()){
			if(getCompVal() < rhs.getCompVal()){
				return true;
			}
			return false;
		}
		return true;
	}
	else if(isMon()){
		if(rhs.isPotion())
			return false;
		if(rhs.isMon()){
			if(name <= rhs.name){
			return true;
		}
		return false;
		}
		return true;
	}
	else if(isIngredient()){
		if(rhs.isPotion() || rhs.isMon())
			return false;
		if(rhs.isIngredient()){
			if(name <= rhs.name){
				return true;
			}
			return false;
		}
		return true;
	}
	else{
		if(rhs.isPotion() || rhs.isMon() || rhs.isIngredient())
			return false;
		if(name <= rhs.name){
			return true;
		}
		return false;
	}
// 	if(isPotion() && rhs.isPotion()){
// 		if(getCompVal() < rhs.getCompVal()){
// 			return true;
// 		}
// 		return false;
// 	}
// 	if(isPotion() && !rhs.isPotion())
// 		return true;
// 	if(!isPotion() && rhs.isPotion())
// 		return false;
// 	if(isMon() && rhs.isMon() && name <= rhs.getName())
// 		return true;
// 	if(isMon() && !rhs.isMon())
// 		return true;
// 	if(!isMon() && rhs.isMon())
// 		return false;
// 	if(isIngredient() && !rhs.isIngredient())
// 		return false;
// 	if(!isIngredient() && rhs.isIngredient())
// 		return true;
// 	if(isIngredient() && rhs.isIngredient()){
// 		if(name <= rhs.getName())
// 			return true;
// 		return false;
// 	}
// 	if(name <= rhs.getName())
// 		return true;
// 	return false;
}

bool Item::isPair(Item& comp){
	if(pairCode == comp.pairCode){
		return true;
	}
	return false;
}

Item* Item::grabFromStack(){
	if(getNum() == 1){
		return grabFromStack(0);
	}
	else if(getNum() < 1){
		return nullptr;
	}
	output("Please select the corresponding number for the Item you would like to grab", false);
	output(name, false);
	std::string headers = "  Levels: ";
	if(stuff == wep)
		headers += "|  Atk: "; 
	else
		headers += "| Def: ";
	output(headers, false);
	std::string body;
	for(unsigned i = 0; i < statStack.size(); ++i){
		if(i < 10)
			body+= "    ";
		else
			body += "   ";
		body += std::to_string(i) + " - " + std::to_string(statStack.lvlat(i)) + " | " + std::to_string(statStack.statat(i)) + '\n';
	}
	output(body, false);
	int num; std::cin >> num; 
	if(std::cin.fail()){
		std::cin.clear();
		std::cin.ignore(500, '\n');
	}
	return grabFromStack(num);
}

void Item::displayItem() {
	output(name, false);
	output("  Class: " + getType(), false);
	if(getNum() > 1){
		std::string header ="  Levels: ";
		if(stuff == wep)
			header += "|  Atk: ";
		else
			header += "|  Def: ";
		output(header, false);
		for(unsigned i = 0; i < statStack.size(); ++i){
			output("\t" + std::to_string(statStack.lvlat(i)) + " | " + std::to_string(statStack.statat(i)), false);
		}
		output("  Rarity: " + getRare(), false);
		output("Number Stacked: " + std::to_string(getNum()), false);
	}
	else{
		output("  Level: " + std::to_string(statStack.lvlat(0)), false);
		std::string s;
		if(stuff == wep)
			s = "Atk: ";
		else if(stuff == shi)
			s = "Def: ";
		output(s + std::to_string(statStack.statat(0)), false);
	}
}

std::string Item::getRare() {
	switch(chance){
		case common:
			return "Common";
		case uncommon:
			return "Uncommon";
		case  rare:
			return "Rare";
		case veryrare:
			return "Very Rare";
		case legendary:
			return "Legendary";
		case unique:
			return "Unique";
	}
    return "Error";
}
	std::string Item::getType() {
		switch(type){
		case paladin:
			return "Paladin";
		case wizard:
			return "Wizard";
		case archer:
			return "Archer";
		case android:
			return "Android";
		case Tamed:
			return "Tamed";
		case potion:
			return "Potion";
		case ingredient:
			return "Ingredient";
	}
    return "ERROR";
	}

Item* dropWeapon(std::string name, int atk, int lvl){	
	switch(rand()%76){
		case 0:
			return new Axe(lvl);
		case 1:
			return new Mace(lvl);
		case 2:
			return new Spear(lvl);
		case 3:
			return new Whip(lvl);
		case 4:
			return new Knife(lvl);
		case 5:
			return new Club(lvl);
		case 6:
			return new Pretzel(lvl);
		case 7:
			return new Candycanesword(lvl);
		case 8:
			return new Scythe(lvl);
		case 9:
			return new Bayonet(lvl);
		case 10:
			return new Trident(lvl);
		case 11:
			return new Tinyhammer(lvl);
		case 12:
			return new Flipflop(lvl);
		case 13:
			return new Chainsaw(lvl);
		case 14:
			return new Treebranch(lvl);
		case 15:
			return new Arm(name, lvl);
		case 16:
			return new Excalibur(lvl);
		case 17:
			return new Smashingboard(lvl);
		case 18:
			return new Schlong(name, atk);
		case 19:
			return new Broom(lvl);
		case 20:
			return new Magicring(lvl);
		case 21:
			return new Magicdie(lvl);
		case 22:
			return new Wand(lvl);
		case 23:
			return new Randombook(lvl);
		case 24:
			return new Handkerchiefs(lvl);
		case 25:
			return new Pointyhat(lvl);
		case 26:
			return new Incantation(lvl);
		case 27:
			return new Oldstaff(lvl);
		case 28:
			return new Candle(lvl);
		case 29:
			return new Ancienttome(lvl);
		case 30:
			return new Magiccloak(lvl);
		case 31:
			return new Enchantedbrassknuckles(lvl);
		case 32:
			return new Ancientstaff(lvl);
		case 33:
			return new Killergarfieldsvoice(lvl);
		case 34:
			return new Humorous(name, lvl);
		case 35:
			return new Dragonsbreath(lvl);
		case 36:
			return new Banishingcrystal(lvl);
		case 37:
			return new Skull(name, atk);
		case 38:
			return new Boomerang(lvl);
		case 39:
			return new Stone(lvl);
		case 40:
			return new Slingshot(lvl);
		case 41:
			return new Playingcards(lvl);
		case 42:
			return new Throwingknives(lvl);
		case 43:
			return new Canoworms(lvl);
		case 44:
			return new Paperairplane(lvl);
		case 45:
			return new Harpoon(lvl);
		case 46:
			return new Crossbow(lvl);
		case 47:
			return new Needles(lvl);
		case 48:
			return new Lizard(lvl);
		case 49:
			return new Highqualitybow(lvl);
		case 50:
			return new Gun(lvl);
		case 51:
			return new Giantmetalfrisbee(lvl);
		case 52:
			return new Enchantedbow(lvl);
		case 53:
			return new Hand(name, lvl);
		case 54:
			return new Thunderbolt(lvl);
		case 55:
			return new Egg(lvl);
		case 56:
			return new Nuts(name, atk);
		case 57:
			return new Leek(lvl);
		case 58:
			return new Recorder(lvl);
		case 59:
			return new Tunafish(lvl);
		case 60:
			return new Popscicle(lvl);
		case 61:
			return new Sakebottle(lvl);
		case 62:
			return new Guitar(lvl);
		case 63:
			return new Lance(lvl);
		case 64:
			return new Micstand(lvl);
		case 65:
			return new Flipphone(lvl);
		case 66:
			return new Keytar(lvl);
		case 67:
			return new Keyboard(lvl);
		case 68:
			return new Roadroller(lvl);
		case 69:
			return new Microphone(lvl);
		case 70:
			return new Musicalkatana(lvl);
		case 71:
			return new Songofdeath(lvl);
		case 72:
			return new Hair(name, lvl);
		case 73:
			return new Shiteyanyoform(lvl);
		case 74:
			return new Squirtgun(lvl);
		case 75:
			return new Soul(name, atk);
	}
    return nullptr;
}
Item* dropDefensive(std::string name, int def, int lvl){
	switch(rand()%76){
		case 0:
			return new Smalllog(lvl);
		case 1:
			return new Gauntlet(lvl);
		case 2:
			return new Cartwheel(lvl);
		case 3:
			return new Fishnets(lvl);
		case 4:
			return new Knifeblock(lvl);
		case 5:
			return new Loincloth(lvl);
		case 6:
			return new Chip(lvl);
		case 7:
			return new Candycaneshield(lvl);
		case 8:
			return new Wheatstalk(lvl);
		case 9:
			return new Netobay(lvl);
		case 10:
			return new Largespoon(lvl);
		case 11:
			return new Hardhat(lvl);
		case 12:
			return new Largefoamfinger(lvl);
		case 13:
			return new Leafblower(lvl);
		case 14:
			return new Unusuallylargeleaf(lvl);
		case 15:
			return new Leg(name, lvl);
		case 16:
			return new Svalinn(lvl);
		case 17:
			return new Guardingrod(lvl);
		case 18:
			return new Schlort(name, def);
		case 19:
			return new Veilodust(lvl);
		case 20:
			return new Magicearrings(lvl);
		case 21:
			return new Magiccoins(lvl);
		case 22:
			return new Cloak(lvl);
		case 23:
			return new Popuplibrary(lvl);
		case 24:
			return new Daringdeceptivedistractiondoves(lvl);
		case 25:
			return new Redraggedyscarf(lvl);
		case 26:
			return new In_cant_ation(lvl);
		case 27:
			return new Moderatedefensespell(lvl);
		case 28:
			return new Giantsnuffer(lvl);
		case 29:
			return new Assortedenchantedpapers(lvl);
		case 30:
			return new Magiccensorbar(lvl);
		case 31:
			return new Enchantedgoldchain(lvl);
		case 32:
			return new Forcefield(lvl);
		case 33:
			return new Voidpouch(lvl);
		case 34:
			return new Femur(name, lvl);
		case 35:
			return new Dragonsvapepen(lvl);
		case 36:
			return new Summoningslime(lvl);
		case 37:
			return new Brain(name, def);
		case 38:
			return new Adventuringslouch(lvl);
		case 39:
			return new Blunt(lvl);
		case 40:
			return new Comicallylargecatchersmitt(lvl);
		case 41:
			return new Greentable(lvl);
		case 42:
			return new Sharpeningboulder(lvl);
		case 43:
			return new Gianttoyworms(lvl);
		case 44:
			return new Origamishield(lvl);
		case 45:
			return new Scubagear(lvl);
		case 46:
			return new Chainmail(lvl);
		case 47:
			return new Bandages(lvl);
		case 48:
			return new Lemur(lvl);
		case 49:
			return new Target(lvl);
		case 50:
			return new Bulletarmor(lvl);
		case 51:
			return new Giantmetalhammer(lvl);
		case 52:
			return new Enchantedshield(lvl);
		case 53:
			return new Foot(name, lvl);
		case 54:
			return new Cloud(lvl);
		case 55:
			return new Chicken(lvl);
		case 56:
			return new Ribs(name, def);
		case 57:
			return new Onion(lvl);
		case 58:
			return new Sheetmusic(lvl);
		case 59:
			return new Cuttingboard(lvl);
		case 60:
			return new Popscicledepressor(lvl);
		case 61:
			return new Giantshotglass(lvl);
		case 62:
			return new Amp(lvl);
		case 63:
			return new Horsearmor(lvl);
		case 64:
			return new Comedicwits(lvl);
		case 65:
			return new Antenna(lvl);
		case 66:
			return new Glockenspiel(lvl);
		case 67:
			return new Desk(lvl);
		case 68:
			return new Giantrock(lvl);
		case 69:
			return new Noisecancellingheadphones(lvl);
		case 70:
			return new Offkeyarmor(lvl);
		case 71:
			return new Songofsteadfastedness(lvl);
		case 72:
			return new Enlargedhairbrush(name, lvl);
		case 73:
			return new Dickbuttform(lvl);
		case 74:
			return new Umbrella(lvl);
		case 75:
			return new Body(name, def);
	}
    return nullptr;
}


void Item::lvlTo(int l, int baseStat /*int minRange, int maxRange*/){
	int finalStat = baseStat;
	for(int i = 1; i < l; ++i){
		switch(chance){
		case common:
			finalStat += getValInRange(1, 3);
				break;
		case uncommon:
			finalStat += getValInRange(1, 5);
				break;
		case  rare:
			finalStat+= getValInRange(2, 4);
				break;
		case veryrare:
			finalStat += getValInRange(3, 5);
				break;
		case legendary:
			finalStat += getValInRange(4, 6);
				break;
		case unique:
				break;
			
	}
// 		int n1 = getValInRange(minRange, maxRange), n2 = getValInRange(minRange, maxRange);
// 		if(minRange/10 != 0){
// 			minRange += minRange/5;
// 			maxRange += minRange/5;
// 		}
// 		else{
// 			minRange += 2;
// 			maxRange +=2;
// 		}
	}
	statStack.push_back(finalStat, l);
}