#include "Monster.h"
void Monster::displayStats(){
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
	displayScreen += "Species: " + cret + '\n';
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
		displayScreen += "none\n";
	}
	displayScreen += "Defensive: ";
	if(hasDefensive()){
		displayScreen += Defensive -> getName() + '\n';
		displayScreen += " Def: " +  std::to_string(Defensive -> getStat()) + '\n';
	}
	else
		displayScreen += "none";
	
	output(displayScreen, false);
}

void Monster::lvlTO(int lvl){
	while(lvl > this -> lvl){
		gainLVL();
	}
	Item *W = soleDrop(), *D = soleDrop2();
	if(lvl >= 10 && lvl >= W->getLVL()){
		Item *temp = equipItem(W);
		delete temp;
	}
	if(lvl >= 10 && lvl >= D -> getLVL()){
		Item *temp = equipItem(D);
		delete temp;
	}
}

std::string Monster::getType(){
	switch(monster){
		case 0:
			return "Regular";
			break;
		case 1:
			return "Special";
			break;
		case 2:
			return "Boss";
			break;
		case 3:
			return "Unique";
	}
return "ERROR";
}

int Monster::expCalc(int pLVL){
	if(lvl < 5){
		return iExp();
	}
	return (lvl/2)*iExp() * lvl/pLVL*1.0;
}

std::vector<Item*> Monster::dropItems(int& money){
	std::vector <Item*> drop;
		int numDrop = getValInRange(1, 5);
		if(monster == regular){
			money = 5 + rand()%11;
			regDrop(drop, numDrop);
		}
		if(monster == special){
			money = 10 + rand()%21;
			specDrop(drop, numDrop);
		}
		if(monster== boss){
			money = 30 + rand()%21;
			bossDrop(drop, numDrop);
		}
	if(hasWeapon()){
		if(rand()%100 < 20){
			drop.push_back(soleDrop());
		}
	}
	if(hasDefensive()){
		if(rand()%100 < 20){
			drop.push_back(soleDrop2());
		}
	}
	for(unsigned i = 0; i < drop.size(); ++i){
		if(drop.at(i) == nullptr){
// 			std::cout << "unknown item?????" << std::endl;
			drop.erase(drop.begin() + i);
		}
	}
	outputDrop(drop, money);
	return drop;
}

void Monster::outputDrop(const std::vector<Item*> &drop, int money){
	output("Gained " + std::to_string(money) + " coins.", false);
	for(int i = 0; i < drop.size(); ++i){
		output(drop.at(i) -> showInBag(), false);
	}
	continueRequest();
}
	
void Monster::regDrop(std::vector<Item*> &drop, int numDrop){//regular monsters common, uncommon, unique, uniquely very rare
	for(int i = 0; i < numDrop; ++i){
		int chance = getValInRange(1, 100);//val from 1 to 1000
		if(chance <= 57){//common - 57%
			switch(getValInRange(0, 2)){
				case 0:
					drop.push_back(commonDrop());
					break;
				case 1:
					drop.push_back(new DistilledDarkness());
					break;
				case 2:
					drop.push_back(new SweetnessStipule());
					break;
			}
		}
		else if(chance <= 79){//uncommon - 22%
				switch(getValInRange(0, 5)){
					case 0:
						drop.push_back(uncommonDrop());
						break;
					case 1:
						drop.push_back(new SouredPome());
						break;
					case 2:
						if(cret == "Jivin' Funky Badger"){
							drop.push_back(new FermentedFunkyFungus());
						}
						else{
							--i;
						}
						break;
					case 3:
						drop.push_back(new DistilledPaleness());
						break;
					case 4:
						drop.push_back(new CalmConcentrate());
						break;
					case 5:
						drop.push_back(new AstringentAdenoids());
						break;
				}
		}
		else if(chance <= 88){//rare - 9%
			switch(getValInRange(0, 3)){
				case 0:
					drop.push_back(rareDrop());
					break;
				case 1:
					drop.push_back(new DissolvedPearl());
					break;
				case 2:
					if(cret == "Orc"){
						drop.push_back(new OrcsBaculum());
					}
					else{
						--i;
					}
					break;
				case 3:
					drop.push_back(new FreshDrupe());
					break;
				
			}
		}
		else if(chance <= 94){//(uniquely) very rare - 6%
			switch(getValInRange(0, 1)){
				case 0:
					drop.push_back(uveryRareDrop());
					break;
				case 1:
					drop.push_back(new CrunchedCaneTubules());
					break;
			}
		}
		else if(chance <= 98){//legendary - 4%
			--i;
		}
		else{//unique - 2
			drop.push_back(uniqueDrop());
		}
	}
}

void Monster::specDrop(std::vector<Item*> &drop, int numDrop){//special monsters uncommon, rare, very rare
	for(int i = 0; i < numDrop; ++i){
		int chance = getValInRange(1, 100);//val from 1 to 1000
		if(chance <= 57){//common - 57%
			--i;
		}
		else if(chance <= 79){//uncommon - 28.9%
				switch(getValInRange(0, 5)){
					case 0:
						drop.push_back(uncommonDrop());
						break;
					case 1:
						drop.push_back(new CalmConcentrate());
						break;
					case 2:
						drop.push_back(new AstringentAdenoids());
						break;
				}
		}
		else if(chance <= 88){//rare - 10%
			switch(getValInRange(0, 5)){
				case 0:
					drop.push_back(rareDrop());
					break;
				case 1:
					drop.push_back(new TitillatingToothfruit());
					break;
				case 2:
					drop.push_back(new DissolvedPearl());
					break;
				case 3:
					drop.push_back(new BloatedBlossomsNectar());
					break;
				case 4:
					drop.push_back(new FreshDrupe());
					break;
				case 5:
					if(cret == "Thug Cactus"){
						drop.push_back(new PiquantPear());
					}
					else{
						--i;
					}
					break;
			}
		}
		else if(chance <= 94){//(uniquely) very rare - 6%
			switch(getValInRange(0, 4)){
				case 0:
					drop.push_back(veryRareDrop());
					break;
				case 1:
					drop.push_back(uveryRareDrop());
					break;
				case 2:
					drop.push_back(veryRareDrop());
					break;
				case 3:
					drop.push_back(new CactalSpindles());
					break;
				case 4:
					drop.push_back(new BubbledGoblinJelly());
					break;
			}
		}
		else if(chance <= 98){//legendary - 4%
			--i;
		}
		else{
			drop.push_back(uniqueDrop());
		}
	}
}
void Monster::bossDrop(std::vector<Item*> &drop, int numDrop){//boss all
	for(int i = 0; i < numDrop; ++i){
		int chance = getValInRange(1, 100);//val from 1 to 1000
		if(chance <= 57){//common - 57%
			drop.push_back(commonDrop());
		}
		else if(chance <= 79){//uncommon - 28.9%
				switch(getValInRange(0, 3)){
					case 0:
						drop.push_back(uncommonDrop());
						break;
					case 1:
						drop.push_back(new IrateInchwormsIntestines());
						break;
					case 2:
						drop.push_back(new CalmConcentrate());
						break;
					case 3:
						drop.push_back(new AstringentAdenoids());
						break;
				}
		}
		else if(chance <= 88){//rare - 9%
			switch(getValInRange(0, 3)){
				case 0:
					drop.push_back(rareDrop());
					break;
				case 1:
					drop.push_back(new DissolvedPearl());
					break;
				case 2:
					drop.push_back(new BloatedBlossomsNectar());
					break;
				case 3:
					drop.push_back(new FreshDrupe());
					break;
			}
		}
		else if(chance <= 94){//(uniquely) very rare - 6%
			switch(getValInRange(0, 2)){
				case 0:
					drop.push_back(veryRareDrop());
					break;
				case 1:
					drop.push_back(uveryRareDrop());
					break;
				case 2:
					if(cret == "Werewolf"){
						drop.push_back(new PowderedWerewolfClaw());
					}
					else{
						--i;
					}
					break;
			}
		}
		else if(chance <= 98){//legendary - 4%
			switch(getValInRange(0,1)){
				case 0:
					drop.push_back(legendaryDrop());
					break;
				case 1:
					if(cret == "Dragon"){
						drop.push_back(new SirensBud());
					}
					else{
						--i;
					}
			}
		}
		else{
			drop.push_back(uniqueDrop());
		}
	}
}
Item* Monster::commonDrop(){
	switch(rand()%40){
		case 0:
			return new Axe(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 1:
			return new Mace(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 2:
			return new Spear(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 3:
			return new Whip(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 4:
			return new Knife(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 5:
			return new Broom(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 6:
			return new Magicring(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 7:
			return new Magicdie(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 8:
			return new Wand(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 9:
			return new Randombook(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 10:
			return new Boomerang(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 11:
			return new Stone(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 12:
			return new Slingshot(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 13:
			return new Playingcards(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 14:
			return new Throwingknives(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 15:
			return new Leek(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 16:
			return new Recorder(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 17:
			return new Tunafish(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 18:
			return new Popscicle(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 19:
			return new Sakebottle(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 20:
			return new Smalllog(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 21:
			return new Gauntlet(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 22:
			return new Cartwheel(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 23:
			return new Fishnets(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 24:
			return new Knifeblock(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 25:
			return new Veilodust(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 26:
			return new Magicearrings(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 27:
			return new Magiccoins(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 28:
			return new Cloak(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 29:
			return new Popuplibrary(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 30:
			return new Adventuringslouch(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 31:
			return new Blunt(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 32:
			return new Comicallylargecatchersmitt(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 33:
			return new Greentable(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 34:
			return new Sharpeningboulder(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 35:
			return new Onion(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 36:
			return new Sheetmusic(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 37:
			return new Cuttingboard(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 38:
			return new Popscicledepressor(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 39:
			return new Giantshotglass(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
	}
    return nullptr;
}

Item* Monster::uncommonDrop(){
	switch(rand()%25){
		case 0:
			return new Pretzel(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 1:
			return new Candycanesword(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 2:
			return new Scythe(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 3:
			return new Handkerchiefs(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 4:
			return new Incantation(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 5:
			return new Oldstaff(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 6:
			return new Canoworms(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 7:
			return new Paperairplane(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 8:
			return new Harpoon(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 9:
			return new Guitar(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 10:
			return new Lance(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 11:
			return new Micstand(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 12:
			return new Gianttoyworms(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 13:
			return new Origamishield(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 14:
			return new Scubagear(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 15:
			return new Chip(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 16:
			return new Candycaneshield(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 17:
			return new Wheatstalk(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 18:
			return new Daringdeceptivedistractiondoves(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 19:
			return new In_cant_ation(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 20:
			return new Moderatedefensespell(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 21:
			return new Amp(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 22:
			return new Horsearmor(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 23:
			return new Comedicwits(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 24:
			return addUncommonDrop();
			break;
	}
    return nullptr;
}

Item* Monster::rareDrop(){
	switch(rand()%9){
		case 0:
			return new Trident(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 1:
			return new Ancienttome(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 2:
			return new Highqualitybow(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 3:
			return new Roadroller(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 4:
			return new Target(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 5:
			return new Largespoon(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 6:
			return new Assortedenchantedpapers(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 7:
			return new Giantrock(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 8:
			return addrareDrop();
			break;
	}
    return nullptr;
}

Item* Monster::veryRareDrop(){
	switch(rand()%9){
		case 0:
			return new Treebranch(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 1:
			return new Ancientstaff(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 2:
			return new Giantmetalfrisbee(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 3:
			return new Songofdeath(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 4:
			return new Giantmetalhammer(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 5:
			return new Unusuallylargeleaf(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 6:
			return new Forcefield(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 7:
			return new Songofsteadfastedness(getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 8:
			return addVeryRareDrop();
			break;
	}
    return nullptr;
}
	
Item* Monster::uveryRareDrop(){
	switch(rand()%7){
			case 0:
			return new Arm(name, getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 1:
			return new Humorous(name, getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 2:
			return new Hand(name, getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
		case 3:
			return new Hair(name, getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
			break;
			return new Enlargedhairbrush(name, getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 4:
			return new Foot(name, getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 5:
			return new Femur(name, getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
		case 6:
			return new Leg(name, getValInRange(std::max(1, lvl-2), std::min(100, lvl+2)));
	}
    return nullptr;
}

Item* Monster::uniqueDrop(){
	switch(rand()%8){
		case 0:
			return new Schlong(name, atk);
			break;
		case 1:
			return new Skull(name, atk);
			break;
		case 2:
			return new Nuts(name, atk);
			break;
		case 3:
			return new Soul(name, atk);
			break;
		case 4:
			return new Ribs(name, def);
		case 5:
			return new Schlort(name, def);
		case 6:
			return new Brain(name, def);
		case 7:
			return new Body(name, def);
	}
    return nullptr;
}

void Monster::interactOutput(){
	char interact;
// 	std::cout<<"you lightly pat "<< name << " on the head, they appear to appreciate it." << std::endl;
// 	return;
	do{
		std::string menu;
		menu = "What would you like to do?\n";
		menu +="\tf - Feed\n";
// 		menu +="\tp - Pet\n";
		menu +="\tb - Bathe\n";
		menu +="\ty - Play\n";
		menu +="\tn - Nap\n";
		menu +="\tPress any button to return\n";
		output(menu, false);
		std::cin.get(interact);
		std::cin.ignore(555,'\n');
		switch(interact){
			case 'f':
				feedOutput();
				break;
			case 'p':
				petOutput();
				break;
			case 'b':
				batheOutput();
				break;
			case 'y':
				playOutput();
				break;
			case 'n':
				napOutput();
				break;
			default:
				return;
		}
	}while(0==0);
}

void Monster::feedOutput(){
	int error = loadAndUseOutputs("FEED");
	if(error == -1){
		output("Unable to feed " + name + ", you're out of food.", false);
	}
}

void Monster::petOutput(){
	int error = loadAndUseOutputs("PET");
	if(error == -1){
		output("Unable to pet " + name + ", they don't seem to trust you enough.", false);
	}
}

void Monster::batheOutput(){
	int error = loadAndUseOutputs("BATHE");
	if(error == -1){
		output("Unable to bathe " + name + " refuses to be washed", false);
	}
}
void Monster::playOutput(){
	int error = loadAndUseOutputs("PLAY");
	if(error == -1){
		output("Unable to play with " + name + ", they don't feel like it.", false);
	}
}
void Monster::napOutput(){
	int error = loadAndUseOutputs("NAP");
	if(error == -1){
		output("Unable to nap with " + name + ", they aren't tired.", false);
	}
}

void Monster::attackOutput(Character &defense){
	std::string creat = cret;
	for(unsigned i = 0; i < creat.size(); ++i){
		if(creat.at(i) == ' '){
			creat.at(i) = '_';
		}
	}
	std::ifstream inFS("Attacks/" + creat + "Attacks.txt");
	if(!inFS.is_open()){
		if(!defense.isMon())
			output(name + " slaps you.", false);
		else
			output(name + " slaps " + defense.getName(), false);
		return;
	}
	std::vector<std::string> attacks;
	std::string line;
	while(getline(inFS,line)){
		if(line == ""){
// 			break;
		}
// 		if(line.at(0) == '.'){
// 			attacks.at(attacks.size() - 1) += '\n' + line.substr(1, line.size());
// 		}
		else{
			attacks.push_back(line);
		}	
	}
	if(attacks.size() == 0){
		if(!defense.isMon())
			output(name + " slaps you.", false);
		else
			output(name + " slaps " + defense.getName(), false);
		inFS.close();
		return;
	}
	std::string sentence = attacks.at(rand()%attacks.size());
			parseMonsterName(sentence, getName());
			if(!defense.isMon())
				parsePlayerName(sentence, "you");
			else
				parsePlayerName(sentence, defense.getName());
			parseChoice(sentence);
			parseFind(sentence);
			parseRand(sentence);
			std::vector<std::string> stuff {getName(), defense.getType(), defense.getCreature()};
// 			if(cret == "Dragon"){
// 				switch(getValInRange(0, 10)){
// 					case 0:
// 						stuff.push_back("Lightning");
// 						break;
// 					case 1:
// 						stuff.push_back("Earth");
// 						break;
// 					case 2:
// 				}
// 				stuff.push_back()
// 			}
			parseIfElse(sentence, stuff);
	
	output(sentence, 60, true);
	inFS.close();
}

void Monster::encounterOutput(){
	std::string creat = cret;
	for(unsigned i = 0; i < creat.size(); ++i){
		if(creat.at(i) == ' '){
			creat.at(i) = '_';
		}
	}
	std::ifstream inFS("Encounters/" + creat + "Encounters.txt");
	if(!inFS.is_open()){
		output(name + " appears suddenly out of the dark. ", false);
		return;
	}
	std::vector<std::string> encounters;
	std::string line;
	while(getline(inFS,line)){
		if(line == ""){
// 			break;
		}
// 		if(line.at(0) == '.'){
// 			encounters.at(encounters.size() - 1) += '\n' + line.substr(1, line.size());
// 		}
		else{
			encounters.push_back(line);
		}	
	}
	if(encounters.size() == 0){
		output(name + " appears suddenly out of the dark. ", false);
		inFS.close();
		return;
	}
	std::string sentence = encounters.at(rand()%encounters.size());
			parseMonsterName(sentence, getName());
			parseChoice(sentence);
			parseFind(sentence);
			parseRand(sentence);
			std::vector<std::string> stuff {getName(), getType(), getCreature()};
			parseIfElse(sentence, stuff);
	
	output(sentence, 60, true);
	inFS.close();
}

int Monster::loadAndUseOutputs(std::string type){
	std::string creat = cret;
	for(unsigned i = 0; i < creat.size(); ++i){
		if(creat.at(i) == ' '){
			creat.at(i) = '_';
		}
	}
	std::ifstream inFS("Interactions/" + creat + "Interactions.txt");
	if(!inFS.is_open()){
		return - 1;
	}
	std::vector<std::string> feeds;
	std::string food, f;
	while(getline(inFS,food)){
		if(food == type){
			while(getline(inFS, f)){
				if(f == ""){
					break;
				}
// 				if(f.at(0) == '.'){
// 					feeds.at(feeds.size() - 1) += '\n' + f.substr(1, f.size());
// 				}
				else{
					feeds.push_back(f);
				}
			}
			break;
		}
	}
	if(feeds.size() == 0){
		return -1;
	}
	std::string sentence = feeds.at(rand()%feeds.size());
			parseMonsterName(sentence, getName());
			parseChoice(sentence);
			parseFind(sentence);
			parseRand(sentence);
			std::vector<std::string> stuff {getType(), getCreature()};
			parseIfElse(sentence, stuff);
	
	output(sentence, 60, true);
	inFS.close();
	return 0;
}

void Monster::chaosCast(int& HP, int& SPD, int& ATK, int& DEF,const int pool){
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