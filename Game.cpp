#include "Game.h"
#include "GameSL.h"

Game::Game(char choice, std::string name){
	switch(choice){
		case 'w':
			player = new Wizard(name);
			pClass = "wizard";
			break;
		case 'p':
			player = new Paladin(name);
			pClass = "paladin";
			break;
		case 'a':
			player = new Archer(name);
			pClass = "archer";
			break;
		case 'i':
			player = new Intern(name);
			pClass = "intern";
			break;
		case 'd':
			player = new Android(name);
			pClass = "android";
			break;
		case 't':
			player = new MonsterTamer(name);
			pClass = "monsterTamer";
			break;
		case 'f':
			player = new Fighter(name);
			pClass = "fighter";
			break;
		case 'e':
			player = new Chaos(name);
			pClass = "chaos";
			break;
		default:
			switch(rand()%8){
				case 0:
					player = new Wizard(name);
					pClass = "wizard";
					break;
				case 1:
					player = new Paladin(name);
					pClass = "paladin";
					break;
				case 2:
					player = new Archer(name);
					pClass = "archer";
					break;
				case 3:
					player = new Intern(name);
					pClass = "intern";
					break;
				case 4:
					player = new Android(name);
					pClass = "android";
					break;	
				case 5:
					player = new MonsterTamer(name);
					pClass = "monsterTamer";
					break;
				case 6:
					player = new Fighter(name);
					pClass = "fighter";
				case 7:
					player = new Chaos(name);
					pClass = "chaos";
					break;
			}
			break;
	}
	bag.push_back(new SalubriousDecoction(5));
// 	bag.push_back(new RecipeBook());
	characterLore(pClass);
	if(chaosTime()){
		chaosLook();
		chaosGame();
	}
}

void Game::move(char dir){
	if(chaosTime()){
		chaosLook();
	}
	battleCheck();
	Dungeon::move(dir);
	if(!chestFound())
		tryForChest();
	battleCheck();
	if(dungeonClear()){
		boss -> lvlTO((player -> getLVL() - 2) + rand()%5);
		startBattle(boss);
	}
	atShop();
}

void Game::displayStats() {//called in main.cpp
	std::string options;
	char choice;
	do{
		options.resize(0);
	player -> displayStats();
		output("press i to interact with equipped items, any other button to return.", false);
	std::cin>>choice;
	switch(std::tolower(choice)){
		case 'i':
			player -> displayWeapon();
			output(" ", false);
			player -> displayDefensive();
			options += "interact with ";
			if(player -> getWeapon() -> isMon())
				options += "friend - f";
			else
				options +="weapon - w";
			options += '\n';
			options += "interact with defensive - d\n";
			options +="any other button to return";
			output(options, false);
			char c;
			std::cin >> c;
			switch(std::tolower(c)){
				case 'f':
				case 'w':
					{
					Item* temp = player -> getWeapon();
					interactWItem(player, temp, true);
					}
					break;
				case 'd':
					{
					Item* temp = player -> getDefensive();
					interactWItem(player, temp, true);
					}
					break;
			}
			choice = '~';
			output(" ", false);
			break;
		default:
			choice = 'b';
	}
	}while(choice == '~');
}

void Game::displayBag(){
	std::string choice;
	do{
		player -> displayStats();
		output(" ", false);
		if(keyFound() || canDig() || mapFound()){
			if(keyFound()){
				output("Key", false);
			}
			if(canDig()){
				output("Shovel", false);
			}
			if(mapFound()){
				output("Map - m", false );
			}
			output(" ", false);
		}
		if(player -> hasWeapon() || player -> hasDefensive()){
			if(player -> hasWeapon())
				output("Equipped Weapon - w ", false);
			if(player -> hasDefensive())
				output("Equipped Defensive - d", false);
			output(" ", false);
		}
		for(unsigned i = 0; i < bag.size(); ++i){
			output(std::to_string(i) + " - " + bag.at(i) -> showInBag(), false);
		}
		output("Press 'b' to return, press corresponding button to interact.", false);
		std::cin >> choice;
		if(choice == "m"|| choice == "M"){
				displayDungeon();
				requestReturn();
			choice = 'b';
		}
		if(choice == "b"){
			return;
		}
		else if((choice == "w" || choice == "W") && player -> hasWeapon()){
			Item* temp = player -> getWeapon();
			interactWItem(player, temp, true);
		}
		else if((choice == "d" || choice == "D") && player -> hasDefensive()){
			Item* temp = player -> getDefensive();
			interactWItem(player, temp, true);
		}
		else{
			int index = translate(choice);
			int num;
			if(index >= 0 && index < bag.size()){
					interactWItem(player, bag.at(index), false);
			}
		}
	}while(0==0);
}

void Game::nextDungeon(){
	newDungeon();
	if(chaosTime()){
		chaosGame();
	}
}

Item* Game::selectPotion(){
	int indx = 0, maxInd = 0;;
				for(unsigned i = 0; i < bag.size(); ++i){
					if(bag.at(i) -> isPotion()){
						output(std::to_string(i) + " - " + bag.at(i) -> showInBag(), false);
					}
					else
						maxInd = i - 1;
						break;
				}
				output("Which potion would you like to use? ('b' to return)", false);
				do{
				std::cin >> indx;
					if(std::cin.fail()){
						std::cin.ignore(500, '\n');
						std::cin.clear();
						break;
					}
					if(indx > maxInd||!bag.at(indx) ->isPotion()){
						output("Please select a potion", false);
					}
				}while(indx > maxInd||!bag.at(indx) ->isPotion());
	return bag.at(indx);
}

void Game::usePotion(Character *& healed, Item *& Potion){
	Potion -> usePotion(healed, invis, tp, chestVis);
	if(chestVis){
		makeChestVisible();
	}
	if(tp){
		teleportPlayer();
	}
}

void Game::interactWItem(Character*& p, Item *& selected, bool isEquipped){
	char choice;
	selected -> displayItem();
	output(" ", false);
	if(selected -> isBook()){
		output("Open - e", false);
	}
	if(isEquipped){
		output("Unequip - u", false);
	}
	else if(selected -> isEquippable()){
		output("Equip - e", false);
	}
	else if(selected -> isPotion()){
		output("Use - u", false);
	}
	if(selected -> isMon()){
		output("use Potion On - p", false);
		output("Interact - i", false);
		if(selected -> getMon() -> hasWeapon())
			output("Interact with Weapon - w", false);
		if(selected -> getMon() -> hasDefensive())
			output("Interact with Defensive - a", false);
		output("give Item - g", false);
	}
	if(!selected ->isBook()){
		output("Drop - d", false);
	}
		output("Back - b", false);
		std::cin >> choice;
		switch(std::tolower(choice)){
			case 'u':
				if(selected -> isPotion()){
					selected -> addToStack(1);
					Item* temp = selected -> grabFromStack();
					usedItems.itemUsed(temp);
					/*selected -> */usePotion(p, selected);
					sortBag();
				}
				else if(isEquipped){
					unequipItem(p, selected);
				}
				break;
			case 'e':
				if(selected -> isEquippable())
					equipItem(p, selected);
				if(selected -> isBook())
					selected -> enterBook();
				break;
			case 'p':
				if(selected -> isMon()){
					Item*  p = selectPotion();
					p -> addToStack(1);
					Item* temp = p->grabFromStack();
				usedItems.itemUsed(temp);
					Character *Mon = selected -> getMon();
					/*p ->*/ usePotion(Mon, p);
					sortBag();
				}
				break;
			case 'i':
				if(selected -> isMon()){
					selected -> getMon() -> interactOutput();
				}
				break;
			case 'w':
				if(selected -> isMon()){
				Character* temp = selected -> getMon();
				Item* t2 = temp -> getWeapon();
				interactWItem(temp, t2, true);
				}
				break;
			case 'a':
				if(selected -> isMon()){
				Character* temp = selected -> getMon();
				Item* t2 = temp -> getDefensive();
				interactWItem(temp, t2, true);
				}
				break;
			case 'g':
				if(selected -> isMon()){
					Item* temp = showEquippable(selected -> getMon() -> getLVL());
					Character* t2 = selected -> getMon();
					equipItem(t2, temp);
				}
				break;
			case 'd':
				if(!selected -> isBook()){
					if(isEquipped){
						unequipItem(p, selected);
						dropItem(selected);
					}
					else{
						dropItem(selected);
					}
				}
				break;
			default:
				return;
		}
}

Item* Game::showEquippable(int lvl){
	output("select an Item to equip:", false);
	do{
	for(unsigned i = 0; i < bag.size(); ++i){
		if(!bag.at(i) -> isPotion() && !bag.at(i) -> isMon()){
			output(std::to_string(i) + " - " + bag.at(i) -> showInBag(), false);
			for(unsigned j = 0; j < bag.at(i) ->getNum(); ++j){
				if(bag.at(i) ->lvlat(j) < lvl)
					output("Lvl: " + std::to_string(bag.at(i) ->lvlat(j)) + ", Stat: " + std::to_string(bag.at(i) ->statat(j)), false);
			}
		}
	}
		int j = 0;
		std::cin >> j;
		if( j > bag.size() - 1 || bag.at(j) -> isPotion() || bag.at(j) -> isMon()){
			output("Please select an equippable item", false); 
		}
		else{
			return bag.at(j) -> grabFromStack();
		}
	}while(0 == 0);
}

void Game::tryForChest(){
		if(treasure.loc.x == pCoord.x && treasure.loc.y == pCoord.y){
			output("You tripped over a chest, you obtained:", false);
			for(unsigned i = 0; i < treasure.contents.size(); ++i){
				output(treasure.contents.at(i) -> showInBag(), false);
			}
			Game::addToBag(treasure.contents);
			treasure.found = true;
			continueRequest();
		}
}

void Game::addToBag(std::vector <Item*> drop){
	for(unsigned i = 0; i < drop.size(); ++i){
		addToBag(drop.at(i));
	}
	sortBag();
}

void Game::addToBag(Item *& drop){
// 	std::cout << "adding to bag" << std::endl;
	for(unsigned i = 0; i < bag.size(); ++i){
		if(*bag.at(i) == *drop){
			bag.at(i)->addToStack(drop);
			return;
		}
	}
// 	std::cout << "pushing" << std::endl;
	bag.push_back(drop);
// 	std::cout << "sorting" << std::endl;
	sortBag();
}

void Game::sortBag(){
// 	std::cout << "SORTING" << std::endl;
// 	for(unsigned i = 0; i < bag.size(); ++i){
// 		std::cout << bag.at(i) -> getName() << std::endl;
// 	}
// 	std::cout << "starting sorte" << bag.size() << std::endl;
// 	std::cout << "removing" << std::endl;
	for(unsigned i = 0; i < bag.size(); ++i){
		if(bag.at(i) -> getNum() <= 0){
// 			Item* temp = bag.at(i);
			bag.erase(bag.begin()+i);
// 			delete temp;
		}
	}
// 	std::cout << "sorting remaining" << bag.size() << std::endl;
// 	sort(bag);
	int jindx;
	for(unsigned i = 0; i < bag.size(); ++i){
// // 		std::cout << "outerloop" << i << std::endl;
		jindx = i;
		for(unsigned j = i+1; j < bag.size(); ++j){
// // 		std::cout << "innerloop" << j<< std::endl;
			if(*bag.at(j) < *bag.at(jindx)){
				jindx = j;
			}
		}
// // 		std::cout << "swapping against" << jindx << std::endl;
		std::swap(bag.at(jindx), bag.at(i));
	}
}

void Game::equipItem(Character*& p, Item *&selected){
	Item *newWep = selected -> grabFromStack();
// 	selected -> removeOne();
	Item *temp = p -> equipItem(newWep);
	if(temp != nullptr){
		addToBag(temp);
	}
	sortBag();
}

void Game::unequipItem(Character*& p, Item*& selected){
	Item* temp = nullptr;
	if(selected -> isWeapon() || selected -> isMon())
		temp = p -> unequipWeapon();
	else if(selected -> isDefensive())
		temp = p -> unequipDefensive();
	if(temp != nullptr){
		addToBag(temp);
		sortBag();
	}
}

void Game::dropItem(Item *&selected){
	selected -> grabFromStack();
// 		std::cout << "How many " << selected -> getName() << "'s would you like to drop?" << std::endl;
// 		int num;
// 		std::cin >> num;
// 		for(int i = 0; i < num; ++i){
// 			selected -> removeOne();
			
// 		}
	sortBag();
// 	for(unsigned i = 0; i < bag.size(); ++i){
// 		if(bag.at(i) -> getNum() <= 0){
// 				bag.erase(bag.begin() + i);
// 			}
// 	}
		return;
}

void Game::battleCheck(){
		for(unsigned i = 0; i < Monsters.size(); ++i){
			if(Monsters.at(i).loc == pCoord){
				if(!Monsters.at(i).encountered){
					Monsters.at(i).encountered = true;
					Monsters.at(i).type -> lvlTO((player -> getLVL() - 2) + rand()%5);
				}
				startBattle(Monsters.at(i).type);
				if(!Monsters.at(i).type -> isAlive()){
					killMon();
				}
			}
		}
	usedItems.resetUsed(player);
}

void Game::startBattle(Character *& monster){//player and monster don't necessarily switch each turn, if a player/monster is fast enough, they can go twice in a row needs retooling
	usedItems.healthUsed = false;
	system("clear");
	monster ->encounterOutput();
	monster -> displayStats();
// 	std::cout << std::endl;
	//monster -> displayStats();
	std::vector<int> pattern;
	if(!player ->isTamer())
		pattern = generatePattern(player -> getSpd(), monster -> getSpd());
	else
		if(player ->hasWeapon())
			pattern = generatePattern(player->getWeapon() -> getMon() -> getSpd(), monster -> getSpd());
		else
			pattern = generatePattern(player -> getSpd(), monster -> getSpd());
		int i = 0;
	
	//battle loop
	while(player -> isAlive() && monster -> isAlive()){
// 		monster -> displayStats();
		if(pattern.at(i) == 0){
				output("a - attack", false);
			if(player -> isTamer())
				output("t - tame monster", false);
			output( "d - display enemy stats", false);
			output("b -  bag", false);
			output("r - run", false);
			char choice;
			std::cin >> choice;
			std::cin.ignore(500, '\n');
			switch(std::tolower(choice)){
				case 'a':
					player -> attack(*monster, 1);
					i=(++i)%pattern.size();
					break;
				case 'd':
					monster -> displayStats();
					continueRequest();
					break;
					case 't':
					if(player -> isTamer())
						if(player ->tameMonster(*monster)){
							Character* newMon = monster -> spawnMon();
							Item* tame;
							output("give a nickname to your new creature?\ny - yes\nn - no", false);
							char choose;
							std::string nickname;
							std::cin >> choose;
							switch(choose){
								case 'y':
									output("Nickname your new friend ('r' for a random name): ", false);
									std::cin.ignore(500, '\n');
									getline(std::cin, nickname);
									if(nickname == "r"){
// 										std::cout << "generating name "<< std::endl;
										nickname = generateName();
// 										std::cout << "name generated" << std::endl;
										nickname.at(0) = toupper(nickname.at(0));
									}
									tame = player -> Monstertamed(nickname, *newMon);
									break;
								default:
								tame = player->Monstertamed(/*player -> getName() + "'s " + */newMon -> getName(), *newMon);	
							}
							monster -> kill();
							if(!monster -> isAlive()){
								killMon();
							}
							addToBag(tame);
							return;
							break;
					}
					i=(++i)%pattern.size();
					break;
// 				case 'f':
// 					if(player -> isTamer())
// 						if(player ->hasWeapon()){
// 							Item* p = selectPotion();
// 							Character* m = player ->getWeapon() ->getMon();
// 							p ->usePotion(m);
// 							sortBag();
// 							i=(++i)%pattern.size();
// 						}
// 					break;
				case 'r':
					if(player -> run(*monster)){
						return;
					}
					i=(++i)%pattern.size();
					break;
				case 'b':
					displayBag();
					if(usedItems.healthUsed){
						usedItems.healthUsed = false;
						i = (++i)%pattern.size();
					}
					break;
			}
		}
		else{
			int numAtk = 0;
			do{
				++numAtk;
			i=(++i)%pattern.size();
			}while(pattern.at(i) != 0);
			monster -> attack(*player, numAtk);
			if(player -> isTamer())
			if(player -> hasWeapon())
				if(!player -> getWeapon() -> getMon() -> isAlive()){
					Item* dMon = player -> unequipWeapon();//monster died, puts in bag
					addToBag(dMon);
					output(dMon -> getName() + " has passed out, bring someone else out?", false);
					output("y - yes\nn - no", false);
					char c;
					std::cin >> c;
					switch(std::tolower(c)){
						case 'y':{
							output("please select the corresponding number: ", false);
							for(unsigned i = 0; i < bag.size(); ++i){
								if(bag.at(i) -> isMon() && bag.at(i) -> getMon() -> isAlive()){
									bag.at(i) -> showInBag();
								}
							}
							int j = 5000;
							do{
								if(std::cin.fail()){
									std::cin.clear();
									std::cin.ignore(500, '\n');
									j = 40000;
									break;
								}
								std::cin >> j;
								if(!bag.at(j) -> isMon() || !bag.at(j) -> getMon() ->isAlive()){
									output("please select a friend to send out", false);
								}
							}while(!bag.at(j) -> isMon() || !bag.at(j) -> getMon() -> isAlive());
							if(j < bag.size()){
								Item* m = bag.at(j) -> grabFromStack();
								player -> equipItem(m);
								sortBag();
							}
						}
							break;
						case 'n':
							break;
					}
				}
		}
		}
	if(!player -> isAlive()){
		output("GAME OVER", false);
		exit(0);
	}
	if(Monsters.size() == 0){
		output("congratulations on defeating all monsters in the current dungeon", false);
		continueRequest();
	}
	monsterDrop(monster);
}

void Game::monsterDrop(Character *& monster){
	//std::cin.ignore(500, '\n');
	int money = 0;
	addToBag(monster -> dropItems(money));
	player -> sold(money);
}

void Game::killMon(){
	for(int i = 0; i < Monsters.size(); ++i){
		if(!Monsters.at(i).type ->isAlive()){
			if(Monsters.at(i).hasShovel){
				output("The monster dropped a shovel, you pick it up.", false);
				hasShovel = true;
				std::cin.ignore();
			}
			erasePosition(Monsters.at(i).loc.x, Monsters.at(i).loc.y);
			setPosition(pCoord.x, pCoord.y);
// 			std::cout << "erasing" << std::endl;
// 			Monsters.erase(Monsters.begin()+i);
			Monsters.at(i) = Monsters.at(Monsters.size()-1);
			Monsters.pop_back();
// 			std::cout << "erased" << std::endl;
			return;
		}
	}
}

int Game::translate(std::string choice){
	int num = 0;
	int digitPlace = 1;
	for(int i = 0; i < choice.size(); ++i){
		num *= 10;
		switch(choice.at(i)){
			case '0':
				break;
			case '1':
				num += 1;
				break;
			case '2':
				num += 2;
				break;
			case '3':
				num += 3;
				break;
			case '4':
				num += 4;
				break;
			case '5':
				num += 5;
				break;
			case '6':
				num += 6;
				break;
			case '7':
				num += 7;
				break;
			case '8':
				num += 8;
				break;
			case '9':
				num += 9;
				break;
		}
	}
	return num;
}





void Game::chaosGame(){
	for(unsigned i = 0; i < Monsters.size(); ++i){
		Character* temp = Monsters.at(i).type;
		Monsters.at(i).type = new Kyle(generateName());
		delete temp;
	}
	delete boss;
	boss = new Kyle(generateName());
// 	giveMonShovel();
}

void Game::chaosLook(){
	//playerlook
	switch(rand()%16){
		case 0:
			playerSymbol = "\u263A";//face w/mouth
			break;
		case 1:
			playerSymbol = "\u2687";//face no mouth
			break;
		case 2:
			playerSymbol = "\u263B";//filled face w/mouth(default)
			break;
		case 3:
			playerSymbol = "\u25A0";//filled white block
			break;
		case 4:
			playerSymbol = "\u058D";//circularthing
			break;
		case 5:
			playerSymbol = "\u17D9";//circle w/dot
			break;
		case 6:
			playerSymbol = "\u13EB";//no symbol thing
			break;
		case 7:
			playerSymbol = "\u1696";//diamond
			break;
		case 8:
			playerSymbol = "\u04C2";//boi 3-leg
			break;
		case 9:
			playerSymbol = "\u03E0";//odd line boi
			break;
		case 10:
			playerSymbol = "\u06E9";//coffin thing
			break;
		case 11:
			playerSymbol = "\u2658";//horse
			break;
		case 12:
			playerSymbol = "\u047C";
			break;
		case 13:
			playerSymbol = "\u07DC";
			break;
		case 14:
			playerSymbol = "\u07DC";
			break;
		case 15:
			playerSymbol = "\u0A0A";
			break;
	}
	std::string newWall;
	switch(rand()%9){
		case 0:
			newWall = "\u2591";//grainy wall(default)
			break;
		case 1:
			newWall = "@";
			break;
		case 2:
			newWall = "&";
			break;
		case 3:
			newWall = "%";
			break;
		case 4:
			newWall = "\u00A7";//logic symbol
			break;
		case 5:
			newWall = "\u00F7";//division symbol
			break;
		case 6:
			newWall = "\u0428";//blocky w
			break;
		case 7:
			newWall = "\u046C";//????
			break;
		case 8:
			newWall = "\u048A";//fancy N
			break;
// 		case 9:
// 			newWall = "\u0B87";
// 			break;
			
	}
	for(int i = 0; i < numRow; ++i){
        for(int j = 0; j < numCol; ++j){
            if(maze.at(i).at(j) == wallMaterial){
				maze.at(i).at(j) = newWall;
			}
		}
    }
	wallMaterial  = newWall;
}

void Game::characterLore(std::string cls){
	std::string sentence;
	std::ifstream inFS("Lore/" + cls + "Lore.txt");
	if(!inFS.is_open()){
		output("Your character has no past, good luck", false);
		return;
	}
	while(getline(inFS, sentence)){
		if(sentence.size() == 0){
			char k = continueRequest();
			if(k == 'q'){
				return;
			}
		}
		else{
			
			if(player -> isTamer()){
				parseMonsterName(sentence, player -> getWeapon() -> getMon() -> getName());
			}
			parsePlayerName(sentence, player -> getName());
			std::string wep, shi;
				if(player -> hasWeapon()){
					wep = player -> getWeapon() -> getName();
				}
				if(player -> hasDefensive()){
					shi = player -> getDefensive() -> getName();
				}
			parseItem(sentence, wep, shi);
			parseChoice(sentence);
			parseFind(sentence);
			parseRand(sentence);
			if(player -> isTamer()){
				std::vector<std::string> monsterStuff;
				Character* m = player -> getWeapon() -> getMon();
			monsterStuff.push_back(m -> getType());
			monsterStuff.push_back(m-> getCreature());
// 			monsterStuff.push_back("SPD: " + std::to_string(m -> getSpd()));
// 			monsterStuff.push_back("ATK: " + )
				parseIfElse(sentence, monsterStuff);
			}
			else
				parseIfElse(sentence);
			output(sentence, 75, true);
		}
	}
	continueRequest();
	inFS.close();
}

std::vector<int> Game::generatePattern(int spd1, int spd2){
		std::vector<int>pattern;
		do{
		if(spd1 >= spd2){
			spd1 -=spd2;
			pattern.push_back(0);
		}
		else if(spd2 > spd1){
			spd2 -=spd1;
			pattern.push_back(1);
		}
	}while(!contains(pattern, 0) || !contains(pattern, 1));
	return pattern;
	}