#include "Shop.h"


void Shop::enterShop(Character& player, std::vector <Item*>& bag){
	bookCheck(bag);
	if(!enteredBefore){
		enteredBefore = true;
		
		Item* book;
		for(unsigned i = 0; i < bag.size(); ++i){
		if(bag.at(i) -> isBook()){
			book = bag.at(i);
			break;
		}
	}
		fillShop(player.getLVL(), *book);
	}
// 	output("under construction, come back later" << std::endl;
// 	requestReturn();
// 	return;
	do{
		system("clear");
		//output(inventory.size() << std::endl;
	std::string greeting = "Welcome, what would you like to do today dear?";
	std::string menu = "\tb - buy\n\ts - sell\n\tc - craft\n\tl - leave";
		output(greeting, false);
		output(menu, false);
	char choice;
	std::cin >> choice;
	switch(choice){
		case 'b':
			player.buy(buyItem(player.getWallet(), bag));
			break;
		case 's':
			sortBag(bag);
			player.sold(sellItems(bag));
			break;
		case 'c':
			enterCrafting(bag);
			break;
		case 'l':
			sortBag(bag);
			return;
			break;
	}
	sortBag(bag);
	
	}while(0==0);
}

void Shop::displayItems(){
	std::string query =  "What items would you like to buy today hun?";
	std::string options;
	output(query, false);
	for(unsigned i = 0; i < recipeInventory.size(); ++i){
		options +=  i + " - " + recipeInventory.at(i) ->showInBag() + '\n';
	}
	for(unsigned i = 0; i < inventory.size(); ++i){
		options += std::to_string(i + recipeInventory.size()) + " - " + inventory.at(i) -> showInBag() + '\n';
	}
	output(options, false);
}
int Shop::buyItem(int wallet, std::vector<Item*>&bag){
	int spent = 0;
	do{
		system("clear");
		displayItems();
		std::string prompt = "Press the corresponding button to buy or any other button to return.";
		output(prompt, false);
		int bought;
		std::cin >> bought;
		if(std::cin.fail()){
			std::cin.clear();
			std::cin.ignore(5000, '\n');
			return spent;
		}
		if(bought < 0||bought >= (recipeInventory.size() + inventory.size())){
			std::string query =  "Do you need help selecting an item my child? Or do you need a pair of glasses, I'm sure I've got an extra pair around here somewhere.";
			output(query, true);
		}
		else{
			std::string query = "What would you like to do with that item dearie?";
			output(query, false);
			std::string result;
			if(bought >= recipeInventory.size()){
				inventory.at(bought - recipeInventory.size()) -> displayItem();
				result =  " Value: " + std::to_string(inventory.at(bought - recipeInventory.size()) -> getVal());
			}
			else{
				recipeInventory.at(bought) -> displayItem();
				 result = " Value: " + std::to_string(recipeInventory.at(bought) -> getVal());
			}
			output(result, false);
			std::string walchoice;
		walchoice =  "Wallet: " + std::to_string((wallet - spent)) + '\n';
		char choose;
			walchoice += "Press 'b' to buy or any other button to return to my inventory.";
			output(walchoice, false);
		std::cin >> choose;
			int itemVal = 0;
			char bb;
			switch(choose){
			case 'b':
				if(bought >= recipeInventory.size()){
					itemVal = inventory.at(bought - recipeInventory.size()) -> getVal();
				}
				else{
					itemVal = recipeInventory.at(bought) -> getVal();
				}
					if(itemVal < (wallet - spent)){
						spent += itemVal;
						if(bought >= recipeInventory.size()){
							addToBag(bag, inventory.at(bought - recipeInventory.size()));
							inventory.erase(inventory.begin() + (bought - recipeInventory.size()));
						}
						else{
							for(unsigned i = 0; i < bag.size(); ++i){
								if(bag.at(i) -> isBook()){
									bag.at(i) -> addRecipe(recipeInventory.at(bought));
								}
							}
							recipeInventory.erase(recipeInventory.begin() + bought);
						}
					}
					else{
						std::string letdown =  "Sorry dearie, you don't have enough money left for that.";
						output(letdown, false);
						std::cin.get(bb);
					}
				break;
			default:
				break;
			}
		}
	}while(0==0);
	return spent;
}
int Shop::sellItems(std::vector <Item*>&bag){
	int gain = 0;
	do{
		system("clear");
		std::string options;
		for(unsigned i = 0; i < bag.size(); ++i){
			options +=std::to_string(i) + " - " + bag.at(i) -> showInBag();
		}
		
		options+= "\nPress the corresponding button to sell or any other button to return.";
		output(options, false);
		int selling;
		std::cin >> selling;
		if(std::cin.fail()){
			std::cin.clear();
			std::cin.ignore(5000, '\n');
			return gain;
		}
		std::string queryresult;
		if(selling < 0||selling >= bag.size()){
			queryresult =  "Do you need help selecting an item my child? Or do you need a pair of glasses, I'm sure I've got an extra pair around here somewhere.";
			output(queryresult, true);
		}
		else{
			if(bag.at(selling) -> getNum() <= 0){
				queryresult = "I'm sorry dearie, there seems to be an error in the space time continuum, let me handle that for you";
				output(queryresult, true);
				bag.erase(bag.begin() + selling);
			}
			else if(bag.at(selling) -> isPotion() || bag.at(selling) -> isIngredient()){
				bag.at(selling) -> displayItem();
				queryresult =  "Val: " + std::to_string(bag.at(selling) -> getVal()) + "\nHow many would you like to sell?";
				output(queryresult, false);
				int num;
				std::cin >> num;
				if(num > bag.at(selling) -> getNum()){
					num = bag.at(selling) -> getNum();
				}
				else if(num < 0){
					num = 0;
				}
				
				queryresult = "Are you sure you'd like to sell " + std::to_string(num) + " " + bag.at(selling) -> getName() + "'s ?\n";
				queryresult = "y - yes\nn - no";
				output(queryresult, false);
				char yesno;
				do{
					std::cin >> yesno;
					if(std::tolower(yesno) == 'y'){
						gain += (bag.at(selling) -> getVal() * num);
						bag.at(selling) -> grabFromStack(num);
						if(bag.at(selling)->getNum() <= 0){
							bag.erase(bag.begin() + selling);
						}
// 						output("sold" << std::endl;
						break;
					}
					else if(std::tolower(yesno) == 'n'){
						break;
					}
					else{
						output("\x1b[A   \r \x1b[A",false);
					}
				}while(0==0);
			}
			else if(bag.at(selling) -> getNum() == 1){
				bag.at(selling) -> displayItem();
				queryresult = "Val: " + std::to_string(bag.at(selling) -> getVal()) + "\nAre you sure you'd like to sell this item?" + "\ny - yes\nn - no";
				output(queryresult, false);
				char yesno;
				do{
					std::cin >> yesno;
					if(std::tolower(yesno) == 'y'){
						gain += bag.at(selling) -> getVal();
						bag.erase(bag.begin() + selling);
						break;
					}
					else if(std::tolower(yesno) == 'n'){
						break;
					}
					else{
						output("\x1b[A   \r\x1b[A", false);
					}
				}while(0==0);
			}
			else{
				Item* n = bag.at(selling) -> grabFromStack();
				n-> displayItem();
				queryresult = "Val: " + std::to_string(n -> getVal()) + "\nAre you sure you'd like to sell this item?" + "\ny - yes\nn - no";
				output(queryresult, false);
				char yesno;
				do{
					std::cin >> yesno;
					if(std::tolower(yesno) == 'y'){
						gain += n -> getVal();
						delete n;
						break;
					}
					else if(std::tolower(yesno) == 'n'){
						bag.at(selling) -> addToStack(n);
						break;
					}
					else{
						output("\x1b[A   \r\x1b[A", false);
					}
				}while(0==0);
			}
			
		}
	}while(0==0);
	return gain;
}

void Shop::enterCrafting(std::vector<Item*>& bag){
	bookCheck(bag);
	Item* book;
	for(unsigned i = 0; i < bag.size(); ++i){
		if(bag.at(i) -> isBook()){
			book = bag.at(i);
			break;
		}
	}
		do{
			std::string query = "What recipe would you like to follow (press 'b' to return)?";
			output(query, false);
			std::string options;
	for(unsigned i = 0; i < book->numPages(); ++i){
		options += std::to_string(i) + " - " + book->page(i) -> showInBag();
	}
			output(options, false);
	int rec;
	std::cin >> rec;
	if(std::cin.fail()){
			std::cin.clear();
			std::cin.ignore(5000, '\n');
			return;
	}
		std::string recipe = book->page(rec)->showInBag();
		output(recipe + '\n', false);
		std::vector<std::string> ing, alting;
		ing = book -> page(rec)->getIngredientList();
		alting = book -> page(rec)->getAltIngredientList();
		if(alting.size() > 0){
			outputCraft(ing, bag, true);
			outputCraft(alting, bag, true);
			if(craftable(ing, bag) && craftable(alting, bag)){
				std::string query = "Would you like to craft this potion?\ny - yes\nn - no";
				output(query, false);
			char yesno;
				do{
				std::cin >> yesno;
				if(tolower(yesno) == 'y'){
					std::string options = "Which recipe would you like to follow?\n0 - ";
					for(unsigned i = 0; i < ing.size(); ++i){
						if(i + 1 < ing.size())
							options += ing.at(i) + ", ";
						else
							options += "and " + ing.at(i);
					}
					options += "\n\n1 - ";
					for(unsigned i = 0; i < alting.size(); ++i){
						if(i + 1 < alting.size())
							options += alting.at(i) + ", ";
						else
							options += "and " + alting.at(i);
					}
					output(options + "\n\n", false);
					char oi;
					std::cin >> oi;
					if(std::tolower(oi) == '0'){
						craftPotion(ing, book -> page(rec), bag);
					}
					else if(std::tolower(oi) == '1'){
						craftPotion(alting, book -> page(rec), bag);
					}
					break;
				}
				else if(tolower(yesno) == 'n')
					break;
				}while(0==0);
			}
			else if(craftable(ing, bag)){
				std::string query = "Would you like to craft this potion?\ny - yes\nn - no";
				output(query, false);
			char yesno;
				do{
				std::cin >> yesno;
				if(tolower(yesno) == 'y'){
					craftPotion(ing, book -> page(rec), bag);
					break;
				}
				else if(tolower(yesno) == 'n')
					break;
				}while(0==0);
			}
			else if(craftable(alting, bag)){
				std::string query = "Would you like to craft this potion?\ny - yes\nn - no";
				output(query, false);
			char yesno;
				do{
				std::cin >> yesno;
				if(tolower(yesno) == 'y'){
					craftPotion(alting, book -> page(rec), bag);
					break;
				}
				else if(tolower(yesno) == 'n')
					break;
				}while(0==0);
			}
			else{
				std::cin.ignore(500,'\n');
				continueRequest();
			}
		}
		else{
			outputCraft(ing, bag, false);
			if(craftable(ing, bag)){
 			std::string query = "Would you like to craft this potion?\ny - yes\nn - no";
				output(query, false);
			char yesno;
				do{
				std::cin >> yesno;
				if(tolower(yesno) == 'y'){
					craftPotion(ing, book -> page(rec), bag);
					break;
				}
				else if(tolower(yesno) == 'n')
					break;
				}while(0==0);
			}
			else{
				std::cin.ignore(500,'\n');
				continueRequest();
			}
		}
		}while(0==0);
}

bool Shop::craftable(const std::vector<std::string>& ing, const std::vector<Item*>& bag) const{
	if(ing.size() == 0){
		return false;
	}
	for(unsigned i = 0; i < ing.size(); ++i){
			if(!contains(ing.at(i), bag)){
				return false;
			}
		}
	return true;
}

void Shop::outputCraft(const std::vector<std::string>& ing, const std::vector<Item*>& bag, const bool hasAlt){
	std::string info;
		if(craftable(ing, bag)){
			info = "Can craft by combining: \n";
			for(unsigned i = 0; i < ing.size(); ++i){
				if(i + 1 < ing.size())
					info += ing.at(i) + ", ";
				else
					info += "and " + ing.at(i) + '\n';
			}
			info += "Can make " + std::to_string(calcCraftable(ing, bag));
			if(hasAlt == true)
				info += " by this method.\n\n";
		}
		else{
			for(unsigned i = 0; i < ing.size(); ++i){
				if(i + 1 < ing.size())
					info += ing.at(i) + ", ";
				else
					info += "and " + ing.at(i) + '\n';
			}
			info += '\n';
			if(hasAlt == false)
				info += "Can't craft, still missing: \n";
			else
				info += "Can't craft by this method, still missing: \n";
			for(unsigned i = 0; i < ing.size(); ++i){
				if(!contains(ing.at(i), bag)){
					info += ing.at(i) + '\n';
				}
			}
		}
			output(info, false);
}

bool Shop::contains(const std::string& ing, const std::vector<Item*>& bag) const{
	for(unsigned i = 0; i < bag.size(); ++i){
		if(bag.at(i) -> getName() == ing){
			return true;
		}
	}
	return false;
}

int Shop::calcCraftable(const std::vector<std::string>& ing, const std::vector<Item*>& bag) const{
	if(!craftable(ing, bag)){
		return 0;
	}
	int num = 20000000;
	for(unsigned i = 0; i < ing.size(); ++i){
		for(unsigned j = 0; j < bag.size(); ++j){
			if(ing.at(i) == bag.at(j) -> getName()){
				num = std::min(num, bag.at(j)->getNum());
			}
		}
	}
	return num;
}


void Shop::emptyShop(){inventory.resize(0);}

void Shop::fillShop(const int lvl, const Item& book){
	recipe* rec;
	if(!book.isFull()){
		do{
			rec = allRecipes();
		}while(book.has(rec));
		recipeInventory.push_back(rec);
	}
	for(unsigned i = (recipeInventory.size() + inventory.size()); i < 10; ++i){
		int chance = getValInRange(1, 100);
		if(chance <= 50){
			inventory.push_back(commonItem(getValInRange(lvl - 2, std::min(lvl + 2, 100))));
		}
		else if(chance <= 75){
			inventory.push_back(uncommonItem(getValInRange(lvl - 2, std::min(lvl + 2, 100))));
		}
		else if(chance <= 85){
			inventory.push_back(rareItem(getValInRange(lvl - 2, std::min(lvl + 2, 100))));
		}
		else if(chance <=90){
			inventory.push_back(veryRareItem(getValInRange(lvl - 2, std::min(lvl + 2, 100))));
		}
		else{
			recipeInventory.push_back(allRecipes());
		}
	}
	sortBag(recipeInventory);
	
	sortBag(inventory);
}

void Shop::bookCheck(std::vector<Item*>& bag){
	system("clear");
	for(unsigned i = 0; i < bag.size(); ++i){
		if(bag.at(i)->isBook()){
			return;
		}
	}
	std::string exclamation = "It looks like it's your first time in a shop dearie, have a complimentary book";
	exclamation += "\nObtained 1 Recipe Book!";
	output(exclamation, true);
	continueRequest();
	Item* book = new RecipeBook();
	book -> addRecipe(allRecipes());
	bag.push_back(book);
	sortBag(bag);
	continueRequest();
}

void Shop::addToBag(std::vector<Item*>& bag, Item*& thing){
	for(unsigned i = 0; i < bag.size(); ++i){
		if(*bag.at(i) == *thing){
			bag.at(i)->addToStack(thing);
			return;
		}
	}
// 	output("pushing" << std::endl;
	bag.push_back(thing);
	sortBag(bag);
}

void Shop::sortBag(std::vector<Item*>& bag){
	for(unsigned i = 0; i < bag.size(); ++i){
		if(bag.at(i) == nullptr){
			bag.erase(bag.begin() + i);
		}
		else if(bag.at(i) -> getNum() <= 0){
			bag.erase(bag.begin()+i);
		}
	}
	int jindx;
	for(unsigned i = 0; i < bag.size(); ++i){
		jindx = i;
		for(unsigned j = i+1; j < bag.size(); ++j){
			if(*bag.at(j) < *bag.at(jindx)){
				jindx = j;
			}
		}
		std::swap(bag.at(jindx), bag.at(i));
	}
}

void Shop::sortBag(std::vector<recipe*>& bag){
// for(unsigned i = 0; i < bag.size(); ++i){
// 		if(bag.at(i) -> getNum() <= 0){
// 			bag.erase(bag.begin()+i);
// 		}
// 	}
	int jindx;
	for(unsigned i = 0; i < bag.size(); ++i){
		jindx = i;
		for(unsigned j = i+1; j < bag.size(); ++j){
			if(*bag.at(j) < *bag.at(jindx)){
				jindx = j;
			}
		}
		std::swap(bag.at(jindx), bag.at(i));
	}
}
// Item* Shop::extraItems(){
// 	switch(){
// 		case 0:
			
// 	}
// }

void Shop::craftPotion(const std::vector<std::string>& ing, recipe* currRec, std::vector<Item*>& bag){
	int max = calcCraftable(ing, bag), num;
	std::string name = currRec->getName().substr(0, currRec->getName().size() - 7);
	std::string query =  "How many " + name + "'s would you like to craft? (max " + std::to_string(max) + ")";
	output(query, false);
	do{
		if(std::cin.fail()){
			std::cin.clear();
			std::cin.ignore(500, '\n');
		}
		std::cin >> num;
	}while(std::cin.fail());
	if(num <= 0){
		return;
	}
	if(num > max){
		num = max;
	}
	
	for(unsigned i = 0; i < ing.size(); ++i){
		for(unsigned j = 0; j < bag.size(); ++j){
			if(ing.at(i) == bag.at(j) -> getName()){
				bag.at(j) -> grabFromStack(num);
			}
		}
	}
	Item* pot = currRec -> craft(num);
	addToBag(bag, pot);
}

recipe* Shop::allRecipes(){
	switch(getValInRange(0, 13)){
		case 0:
			return new SalubriousDecoctionRecipe();
			break;
		case 1:
			return new TonicForEupepsiaRecipe();
			break;
		case 2:
			return new LustinessTinctureRecipe();
			break;
		case 3:
			return new BrewofStaminaRecipe();
			break;
		case 4:
			return new DraughtofVigorRecipe();
			break;
		case 5:
			return new DragonsBreathLibationRecipe();
			break;
		case 6:
			return new VitalityConcoctionRecipe();
			break;
		case 7:
			return new VialofFortitudeRecipe();
			break;
		case 8:
			return new PotionofRobustResistanceRecipe();
			break;
		case 9:
			return new AegisAggregateRecipe();
			break;
		case 10:
			return new AlacrityPotationRecipe();
			break;
		case 11:
			return new ElixirofInvisibilityRecipe();
			break;
		case 12:
			return new FlaskofEruditionRecipe();
			break;
		case 13:
			return new CorybanticConveyingPhilterRecipe();
			break;
	}
    return nullptr;
}

Item* Shop::commonItem(const int lvl){
	switch(rand()%40){
		case 0:
			return new Axe(lvl);
			break;
		case 1:
			return new Mace(lvl);
			break;
		case 2:
			return new Spear(lvl);
			break;
		case 3:
			return new Whip(lvl);
			break;
		case 4:
			return new Knife(lvl);
			break;
		case 5:
			return new Broom(lvl);
			break;
		case 6:
			return new Magicring(lvl);
			break;
		case 7:
			return new Magicdie(lvl);
			break;
		case 8:
			return new Wand(lvl);
			break;
		case 9:
			return new Randombook(lvl);
			break;
		case 10:
			return new Boomerang(lvl);
			break;
		case 11:
			return new Stone(lvl);
			break;
		case 12:
			return new Slingshot(lvl);
			break;
		case 13:
			return new Playingcards(lvl);
			break;
		case 14:
			return new Throwingknives(lvl);
			break;
		case 15:
			return new Leek(lvl);
			break;
		case 16:
			return new Recorder(lvl);
			break;
		case 17:
			return new Tunafish(lvl);
			break;
		case 18:
			return new Popscicle(lvl);
			break;
		case 19:
			return new Sakebottle(lvl);
			break;
		case 20:
			return new Smalllog(lvl);
		case 21:
			return new Gauntlet(lvl);
		case 22:
			return new Cartwheel(lvl);
		case 23:
			return new Fishnets(lvl);
		case 24:
			return new Knifeblock(lvl);
		case 25:
			return new Veilodust(lvl);
		case 26:
			return new Magicearrings(lvl);
		case 27:
			return new Magiccoins(lvl);
		case 28:
			return new Cloak(lvl);
		case 29:
			return new Popuplibrary(lvl);
		case 30:
			return new Adventuringslouch(lvl);
		case 31:
			return new Blunt(lvl);
		case 32:
			return new Comicallylargecatchersmitt(lvl);
		case 33:
			return new Greentable(lvl);
		case 34:
			return new Sharpeningboulder(lvl);
		case 35:
			return new Onion(lvl);
		case 36:
			return new Sheetmusic(lvl);
		case 37:
			return new Cuttingboard(lvl);
		case 38:
			return new Popscicledepressor(lvl);
		case 39:
			return new Giantshotglass(lvl);
	}
    return nullptr;
}

Item* Shop::uncommonItem(const int lvl){
	switch(rand()%24){
		case 0:
			return new Pretzel(lvl);
			break;
		case 1:
			return new Candycanesword(lvl);
			break;
		case 2:
			return new Scythe(lvl);
			break;
		case 3:
			return new Handkerchiefs(lvl);
			break;
		case 4:
			return new Incantation(lvl);
			break;
		case 5:
			return new Oldstaff(lvl);
			break;
		case 6:
			return new Canoworms(lvl);
			break;
		case 7:
			return new Paperairplane(lvl);
			break;
		case 8:
			return new Harpoon(lvl);
			break;
		case 9:
			return new Guitar(lvl);
			break;
		case 10:
			return new Lance(lvl);
			break;
		case 11:
			return new Micstand(lvl);
			break;
		case 12:
			return new Gianttoyworms(lvl);
		case 13:
			return new Origamishield(lvl);
		case 14:
			return new Scubagear(lvl);
		case 15:
			return new Chip(lvl);
		case 16:
			return new Candycaneshield(lvl);
		case 17:
			return new Wheatstalk(lvl);
		case 18:
			return new Daringdeceptivedistractiondoves(lvl);
		case 19:
			return new In_cant_ation(lvl);
		case 20:
			return new Moderatedefensespell(lvl);
		case 21:
			return new Amp(lvl);
		case 22:
			return new Horsearmor(lvl);
		case 23:
			return new Comedicwits(lvl);
	}
        return nullptr;

}
		
Item* Shop::rareItem(const int lvl){
	switch(rand()%8){
		case 0:
			return new Trident(lvl);
			break;
		case 1:
			return new Ancienttome(lvl);
			break;
		case 2:
			return new Highqualitybow(lvl);
			break;
		case 3:
			return new Roadroller(lvl);
			break;
		case 4:
			return new Target(lvl);
		case 5:
			return new Largespoon(lvl);
		case 6:
			return new Assortedenchantedpapers(lvl);
		case 7:
			return new Giantrock(lvl);
	}
        return nullptr;

}

Item* Shop::veryRareItem(const int lvl){
	switch(rand()%8){
		case 0:
			return new Treebranch(lvl);
			break;
		case 1:
			return new Ancientstaff(lvl);
			break;
		case 2:
			return new Giantmetalfrisbee(lvl);
			break;
		case 3:
			return new Songofdeath(lvl);
			break;
		case 4:
			return new Giantmetalhammer(lvl);
		case 5:
			return new Unusuallylargeleaf(lvl);
		case 6:
			return new Forcefield(lvl);
		case 7:
			return new Songofsteadfastedness(lvl);

	}
    return nullptr;
}