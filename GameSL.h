
Game::Game(std::ifstream& ifs){
	std::string name, type;
	int lvl, hp, mhp, atk, def, spd, wallet, exp, lvlup;
	Item *W, *D;
	getline(ifs, name);
	getline(ifs, type);
	ifs >> lvl >> hp >> mhp >> atk >> def >> spd >> wallet >> exp >> lvlup;	
	ifs.ignore(500, '\n');//ifs ignore here if it causes problems
// 	std::cout << "equipping weapon" << std::endl;
	W = createItems(ifs);
	D = createItems(ifs);	
	if(type == "Paladin"){
		player = new Paladin(name, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, W, D);
		pClass = "paladin";
	}
	else if(type=="Archer"){
		player = new Archer(name, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, W, D);
		pClass = "archer";
	}
	else if(type == "Wizard"){
		player = new Wizard(name, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, W, D);
		pClass = "wizard";
	}
	else if(type == "Intern"){
		player = new Intern(name, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, W, D);
		pClass = "intern";
	}
	else if(type == "Android"){
		player = new Android(name, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, W, D);
		pClass = "android";
	}
	else if(type == "Tamer"){
		player = new MonsterTamer(name, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, W, D);
		pClass = "monsterTamer";
	}
	else if(type == "Fighter"){
		player = new Fighter(name, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, W, D);
		pClass = "fighter";
	}
	else{
		player = new Chaos(name, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, W, D);
		pClass = "chaos";
	}
	while(!ifs.eof()){
		bag.push_back(createItems(ifs));
		if(bag.at(bag.size() - 1) == nullptr){
			bag.pop_back();
		}
	}
	ifs.close();
	if(chaosTime()){
		chaosLook();
		chaosGame();
	}
	sortBag();
}

Item* Game::createItems(std::ifstream& ifs){	
// 	ifs.ignore(500, '\n');
	Item* c;
	int num, lvl, stat;
	std::string name;
	getline(ifs, name);
// 	std::cout << name << std::endl;
	if(isBook(name)){
		std::string list;
		getline(ifs, list);
		c = newBook(name, list);
		if(c == nullptr){
			std::cout << "ERR: GAME LOADING NEEDS TO BE UPDATED: ~" << name << "~ PRoperly" << std::endl;
			return nullptr;
		}
		return c;
	}
	if(isPotion(name)){
		ifs >> num;
		ifs.ignore(500, '\n');//heres an ifs ignore if they cause issues
		name = name.substr(6, name.size() - 12);
		c = newPotion(name, num);
		if(c == nullptr){
			std::cout << "ERR: GAME LOADING NEEDS TO BE UPDATED TO RECOGNIZE: ~" << name << "~ PROPERLY, POTION CANNOT BE USED FURTHER" << std::endl;
			return nullptr;
		}
		return c;
		
	}
	if(isIngredient(name)){
		ifs >> num;
		ifs.ignore(500, '\n');//ifs ignore here if it causes problems
		name = name.substr(10, name.size()-20);
		c = newIngredient(name, num);
		if(c == nullptr){
			std::cout << "ERR: GAME LOADING NEEDS TO BE UPDATED TO RECOGNIZE: ~" << name << "~ PROPERLY, INGREDIENT CANNOT BE USED FURTHER" << std::endl;
			return nullptr;
		}
		return c;
	}
	if(isItem(name)){
		name = name.substr(4, name.size() - 8);
		c = newItem(ifs, name);
		if(c == nullptr){
			std::cout << "ERR: GAME LOADING NEEDS TO BE UPDATED TO RECOGNIZE: ~" << name << "~ PROPERLY, ITEM CANNOT BE USED FURTHER" << std::endl; 
			ifs >>num;
			return nullptr;
		}
		ifs >> num;
		ifs.ignore(500, '\n');//ifs ignore here if it causes problems
		if(num > 1)
			for(unsigned i = 1; i < num; ++i){
				ifs >> stat;
				ifs >> lvl;
				ifs.ignore(500, '\n');//ifs ignore here if it causes problems

				c -> addToStack(lvl, stat);
			}
		return c;
	}
	else if(isMonster(name)){
		name = name.substr(7, name.size() - 14);

		c = newMon(ifs, name);
		if(c == nullptr){
			std::cout << "ERR: GAME LOADING NEEDS TO BE UPDATED TO RECOGNIZE: " << name << " PROPERLY, MONSTER CANNOT BE USED FURTHER" << std::endl;
			return nullptr;
		}
		return c;
	}
	else{
		return nullptr;
	}
}

Item* Game::newPotion(std::string name, int num){
	if(name == "NULL")
		return nullptr;
	if(name == "Salubrious Decoction")
		return new SalubriousDecoction(num);
	if(name == "Tonic For Eupepsia")
		return new TonicForEupepsia(num);
	if(name == "Lustiness Tincture")
		return new LustinessTincture(num);
	if(name == "Brew of Stamina")
		return new BrewofStamina(num);
	if(name == "Draught of Vigor")
		return new DraughtofVigor(num);
	if(name == "Dragon's Breath Libation")
		return new DragonsBreathLibation(num);
	if(name == "Vitality Concoction")
		return new VitalityConcoction(num);
	if(name == "Vial of Fortitude")
		return new VialofFortitude(num);
	if(name == "Potion of Robust Resistance")
		return new PotionofRobustResistance(num);
	if(name == "Aegis Aggregate")
		return new AegisAggregate(num);
	if(name == "Alacrity Potation")
		return new AlacrityPotation(num);
	if(name == "Elixir of Invisibility")
		return new ElixirofInvisibility(num);
	if(name == "Flask of Erudition")
		return new FlaskofErudition(num);
	if(name == "Corybantic Conveying Philter")
		return new CorybanticConveyingPhilter(num);
	return nullptr;
}

Item* Game::newBook(std::string name, std::string list){
	if(name == "NULL")
		return nullptr;
	Item* p =  new RecipeBook();
	if(list.find("Salubrious Decoction Recipe") != std::string::npos){
		recipe* r = new SalubriousDecoctionRecipe();
		p -> addRecipe(r);
	}
	if(list.find("Tonic For Eupepsia Recipe") != std::string::npos){
		recipe* r = new TonicForEupepsiaRecipe();
		p -> addRecipe(r);
	}
	if(list.find("Lustiness Tincture Recipe") != std::string::npos){
		recipe* r = new LustinessTinctureRecipe();
		p -> addRecipe(r);
	}
	if(list.find("Brew of Stamina Recipe") != std::string::npos){
		recipe* r = new BrewofStaminaRecipe();
		p -> addRecipe(r);
	}
	if(list.find("Draught of Vigor Recipe") != std::string::npos){
		recipe* r = new DraughtofVigorRecipe();
		p -> addRecipe(r);
	}
	if(list.find("Dragon's Breath Libation Recipe") != std::string::npos){
		recipe* r = new DragonsBreathLibationRecipe();
		p -> addRecipe(r);
	}
	if(list.find("Vitality Concoction Recipe") != std::string::npos){
		recipe* r = new VitalityConcoctionRecipe();
		p -> addRecipe(r);
	}
	if(list.find("Vial of Fortitude Recipe") != std::string::npos){
		recipe* r = new VialofFortitudeRecipe();
		p -> addRecipe(r);
	}
	if(list.find("Potion of Robust Resistance Recipe") != std::string::npos){
		recipe* r = new PotionofRobustResistanceRecipe();
		p -> addRecipe(r);
	}
	if(list.find("Aegis Aggregate Recipe") != std::string::npos){
		recipe* r = new AegisAggregateRecipe();
		p -> addRecipe(r);
	}
	if(list.find("Alacrity Potation Recipe") != std::string::npos){
		recipe* r = new AlacrityPotationRecipe();
		p -> addRecipe(r);
	}
	if(list.find("Elixir of Invisibility Recipe") != std::string::npos){
		recipe* r = new ElixirofInvisibilityRecipe();
		p -> addRecipe(r);
	}
	if(list.find("Flask of Erudition Recipe") != std::string::npos){
		recipe* r = new FlaskofEruditionRecipe();
		p -> addRecipe(r);
	}
	if(list.find("Corybantic Conveying Philter Recipe") != std::string::npos){
		recipe* r = new CorybanticConveyingPhilterRecipe();
		p -> addRecipe(r);
	}
	return p;
}

Item* Game::newIngredient(std::string name, int num){
	if(name == "NULL")
		return nullptr;
	if(name == "Distilled Darkness")
		return new DistilledDarkness(num);
	if(name == "Sweetness Stipule")
		return new SweetnessStipule(num);
	if(name == "Soured Pome")
		return new SouredPome(num);
	if(name == "Fermented Funky Fungus")
		return new FermentedFunkyFungus(num);
	if(name == "Titillating Toothfruit")
		return new TitillatingToothfruit(num);
	if(name == "Dissolved Pearl")
		return new DissolvedPearl(num);
	if(name == "Irate Inchworm's Intestines")
		return new IrateInchwormsIntestines(num);
	if(name == "Bloated Blossoms' Nectar")
		return new BloatedBlossomsNectar(num);
	if(name == "Cactal Spindles")
		return new CactalSpindles(num);
	if(name == "Siren's Bud")
		return new SirensBud(num);
	if(name == "Orc's Baculum")
		return new OrcsBaculum(num);
	if(name == "Distilled Paleness")
		return new DistilledPaleness(num);
	if(name == "Calm Concentrate")
		return new CalmConcentrate(num);
	if(name == "Astringent Adenoids")
		return new AstringentAdenoids(num);
	if(name == "Powdered Werewolf Claw")
		return new PowderedWerewolfClaw(num);
	if(name == "Bubbled Goblin Jelly")
		return new BubbledGoblinJelly(num);
	if(name == "Fresh Drupe")
		return new FreshDrupe(num);
	if(name == "Piquant Pear")
		return new PiquantPear(num);
	if(name == "Crunched Cane Tubules")
		return new CrunchedCaneTubules(num);
	return nullptr;
}

Item* Game::newItem(std::ifstream& ifs, std::string name){
	int stat, lvl;
	ifs >> stat >> lvl;
	ifs.ignore(500, '\n');//ifs ignore here if it causes problems
if(name == "NULL")
	return nullptr;	
if(name == "Rusty Sword")
    return new RustySword();

if(name == "Axe")
    return new Axe(stat, lvl);

if(name == "Mace")
        return new Mace(stat, lvl);

if(name == "Spear")
    return new Spear(stat, lvl);

if(name == "Whip")
    return new Whip(stat, lvl);

if(name == "Knife")
    return new Knife(stat, lvl);

if(name == "Club")
    return new Club(stat, lvl);

if(name == "Pretzel")
    return new Pretzel(stat, lvl);

if(name == "Candy Cane Sword")
    return new Candycanesword(stat, lvl);

if(name == "Scythe")
    return new Scythe(stat, lvl);

if(name == "Bayonet")
    return new Bayonet(stat, lvl);

if(name == "Trident")
    return new Trident(stat, lvl);

if(name == "Tiny Hammer")
    return new Tinyhammer(stat, lvl);

if(name == "Flip Flop")
    return new Flipflop(stat, lvl);

if(name == "Chainsaw")
    return new Chainsaw(stat, lvl);

if(name == "Tree Branch")
    return new Treebranch(stat, lvl);

if(name.find("'s Arm")!=std::string::npos){
	name = name.substr(0, name.find("'s Arm"));
    return new Arm(name, stat, lvl);
}
if(name == "Excalibur")
    return new Excalibur(stat, lvl);

if(name == "Smashing Board")
    return new Smashingboard(stat, lvl);

if(name.find("'s Schlong") != std::string::npos){
	name = name.substr(0, name.find("'s Schlong"));
    return new Schlong(name, stat);
}
if(name == "Random Stick")
    return new RandomStick();

if(name == "Broom")
    return new Broom(stat, lvl);

if(name == "Magic Ring")
    return new Magicring(stat, lvl);

if(name == "Magic Die")
    return new Magicdie(stat, lvl);

if(name == "Wand")
    return new Wand(stat, lvl);

if(name == "Random Book")
    return new Randombook(stat, lvl);

if(name == "Handkerchiefs")
    return new Handkerchiefs(stat, lvl);

if(name == "Pointy Hat")
    return new Pointyhat(stat, lvl);

if(name == "Incantation")
    return new Incantation(stat, lvl);

if(name == "Old Staff")
    return new Oldstaff(stat, lvl);

if(name == "Candle")
    return new Candle(stat, lvl);

if(name == "Ancient Tome")
    return new Ancienttome(stat, lvl);

if(name == "Magic Cloak")
    return new Magiccloak(stat, lvl);

if(name == "Enchanted Brass Knuckles")
    return new Enchantedbrassknuckles(stat, lvl);

if(name == "Ancient Staff")
    return new Ancientstaff(stat, lvl);

if(name == "Killer Garfield's Voice")
    return new Killergarfieldsvoice(stat, lvl);

if(name.find("'s Humorous") != std::string::npos){
	name = name.substr(0, name.find("'s Humorous"));
    return new Humorous(name, stat, lvl);
}

if(name == "Dragon's Breath")
    return new Dragonsbreath(stat, lvl);

if(name == "Banishing Crystal")
    return new Banishingcrystal(stat, lvl);

if(name.find("'s Skull") != std::string::npos){
	name = name.substr(0, name.find("'s Skull"));
    return new Skull(name, stat);
}

if(name == "Old Bow")
    return new OldBow();

if(name == "Boomerang")
    return new Boomerang(stat, lvl);

if(name == "Stone")
    return new Stone(stat, lvl);

if(name == "Slingshot")
    return new Slingshot(stat, lvl);

if(name == "Playing Cards")
    return new Playingcards(stat, lvl);

if(name == "Throwing Knives")
    return new Throwingknives(stat, lvl);

if(name == "Can O' Worms")
    return new Canoworms(stat, lvl);

if(name == "Paper Airplane")
    return new Paperairplane(stat, lvl);

if(name == "Harpoon")
    return new Harpoon(stat, lvl);

if(name == "Crossbow")
    return new Crossbow(stat, lvl);

if(name == "Needles")
    return new Needles(stat, lvl);

if(name == "Lizard")
    return new Lizard(stat, lvl);

if(name == "High Quality Bow")
    return new Highqualitybow(stat, lvl);

if(name == "Gun")
    return new Gun(stat, lvl);

if(name == "Giant Metal Frisbee")
    return new Giantmetalfrisbee(stat, lvl);

if(name == "Enchanted Bow")
    return new Enchantedbow(stat, lvl);

if(name.find("'s Hand") != std::string::npos){
	name = name.substr(0, name.find("'s Hand"));
    return new Hand(name, stat, lvl);
}

if(name == "Thunderbolt")
    return new Thunderbolt(stat, lvl);

if(name == "Egg")
    return new Egg(stat, lvl);

if(name.find("'s Nuts") != std::string::npos){
	name = name.substr(0, name.find("'s Nuts"));
    return new Nuts(name, stat);
}

if(name == "Glow Stick")
    return new Glowstick();

if(name == "Leek")
    return new Leek(stat, lvl);

if(name == "Recorder")
    return new Recorder(stat, lvl);

if(name == "Tuna Fish")
    return new Tunafish(stat, lvl);

if(name == "Popscicle")
    return new Popscicle(stat, lvl);

if(name == "Sake Bottle")
    return new Sakebottle(stat, lvl);

if(name == "Guitar")
    return new Guitar(stat, lvl);

if(name == "Lance")
    return new Lance(stat, lvl);

if(name == "Mic Stand")
    return new Micstand(stat, lvl);

if(name == "Flip Phone")
    return new Flipphone(stat, lvl);

if(name == "Keytar")
    return new Keytar(stat, lvl);

if(name == "Keyboard")
    return new Keyboard(stat, lvl);

if(name == "Road Roller")
    return new Roadroller(stat, lvl);

if(name == "Microphone")
    return new Microphone(stat, lvl);

if(name == "Musical Katana")
    return new Musicalkatana(stat, lvl);

if(name == "Song of Death")
    return new Songofdeath(stat, lvl);

if(name.find("'s Hair") != std::string::npos){
	name = name.substr(0, name.find("'s Hair"));
    return new Hair(name, stat, lvl);
}
if(name == "Shiteyanyo Form")
    return new Shiteyanyoform(stat, lvl);

if(name == "Squirt Gun")
    return new Squirtgun(stat, lvl);

if(name.find("'s Soul") != std::string::npos){
	name = name.substr(0, name.find("'s Soul"));
    return new Soul(name, stat);
}
if(name == "Rusty Shield")
    return new RustyShield();

if(name == "Small Log")
    return new Smalllog(stat, lvl);

if(name == "Gauntlet")
    return new Gauntlet(stat, lvl);

if(name == "Cart Wheel")
    return new Cartwheel(stat, lvl);

if(name == "Fishnets")
    return new Fishnets(stat, lvl);

if(name == "Knife Block")
    return new Knifeblock(stat, lvl);

if(name == "Loincloth")
    return new Loincloth(stat, lvl);

if(name == "Chip")
    return new Chip(stat, lvl);

if(name == "Candy Cane Shield")
    return new Candycaneshield(stat, lvl);

if(name == "Wheat Stalk")
    return new Wheatstalk(stat, lvl);

if(name == "Net-o'-bay")
    return new Netobay(stat, lvl);

if(name == "Large Spoon")
    return new Largespoon(stat, lvl);

if(name == "Hard Hat")
    return new Hardhat(stat, lvl);

if(name == "Large Foam Finger")
    return new Largefoamfinger(stat, lvl);

if(name == "Leaf Blower")
    return new Leafblower(stat, lvl);

if(name == "Unusually Large Leaf")
    return new Unusuallylargeleaf(stat, lvl);

if(name.find("'s Leg") != std::string::npos){
	name = name.substr(0, name.find("'s Leg"));
    return new Leg(name, stat, lvl);
}

if(name == "Svalinn")
    return new Svalinn(stat, lvl);

if(name == "Guarding Rod")
    return new Guardingrod(stat, lvl);

if(name.find("'s Schlort") != std::string::npos){
	name = name.substr(0, name.find("'s Schlort"));
    return new Schlort(name, stat);
}

if(name == "Weak Defense Spell")
    return new Weakdefensespell();

if(name == "Veil o' Dust")
    return new Veilodust(stat, lvl);

if(name == "Magic Earrings")
    return new Magicearrings(stat, lvl);

if(name == "Magic Coins")
    return new Magiccoins(stat, lvl);

if(name == "Cloak")
    return new Cloak(stat, lvl);

if(name == "Pop-up Library")
    return new Popuplibrary(stat, lvl);

if(name == "Daring Deceptive Distratcion Doves")
    return new Daringdeceptivedistractiondoves(stat, lvl);

if(name == "Red Raggedy Scarf")
    return new Redraggedyscarf(stat, lvl);

if(name == "In-can't-ation")
    return new In_cant_ation(stat, lvl);

if(name == "Moderate Defense Spell")
    return new Moderatedefensespell(stat, lvl);

if(name == "Giant Snuffer")
    return new Giantsnuffer(stat, lvl);

if(name == "Assorted Enchanted Papers")
    return new Assortedenchantedpapers(stat, lvl);

if(name == "Magic Censor Bar")
    return new Magiccensorbar(stat, lvl);

if(name == "Enchanted Gold Chain")
    return new Enchantedgoldchain(stat, lvl);

if(name == "Forcefield")
    return new Forcefield(stat, lvl);

if(name == "Void Pouch")
    return new Voidpouch(stat, lvl);

if(name.find("'s Femur") != std::string::npos){
	name = name.substr(0, name.find("'s Femur"));
    return new Femur(name, stat, lvl);
}

if(name == "Dragon's Vape Pen")
    return new Dragonsvapepen(stat, lvl);

if(name == "Summoning Slime")
    return new Summoningslime(stat, lvl);

if(name.find("'s Brain") != std::string::npos){
	name = name.substr(0, name.find("'s Brain"));
    return new Brain(name, stat);
}
if(name == "Thicc Leather Shirt")
    return new Thiccleathershirt();

if(name == "Adventuring Slouch")
    return new Adventuringslouch(stat, lvl);

if(name == "Blunt")
    return new Blunt(stat, lvl);

if(name == "Comically Large Catchers Mitt")
    return new Comicallylargecatchersmitt(stat, lvl);

if(name == "Green Table")
    return new Greentable(stat, lvl);

if(name == "Sharpening Boulder")
    return new Sharpeningboulder(stat, lvl);

if(name == "Giant Toy Worms")
    return new Gianttoyworms(stat, lvl);

if(name == "Origami Shield")
    return new Origamishield(stat, lvl);

if(name == "Scuba Gear")
    return new Scubagear(stat, lvl);

if(name == "Chainmail")
    return new Chainmail(stat, lvl);

if(name == "Bandages")
    return new Bandages(stat, lvl);

if(name == "Lemur")
    return new Lemur(stat, lvl);

if(name == "Target")
    return new Target(stat, lvl);

if(name == "Bullet Armor")
    return new Bulletarmor(stat, lvl);

if(name == "Giant Metal Hammer")
    return new Giantmetalhammer(stat, lvl);

if(name == "Enchanted Shield")
    return new Enchantedshield(stat, lvl);

if(name.find("'s Foot") != std::string::npos){
	name = name.substr(0, name.find("'s Foot"));
    return new Foot(name, stat, lvl);
}
if(name == "Cloud")
    return new Cloud(stat, lvl);

if(name == "Chicken")
    return new Chicken(stat, lvl);

if(name.find("'s Ribs") != std::string::npos){
	name = name.substr(0, name.find("'s Ribs"));
    return new Ribs(name, stat);
}

if(name == "Assless Chaps")
    return new Asslesschaps();

if(name == "Onion")
    return new Onion(stat, lvl);

if(name == "Sheet Music")
    return new Sheetmusic(stat, lvl);

if(name == "Cutting Board")
    return new Cuttingboard(stat, lvl);

if(name == "Popscicle Depressor")
    return new Popscicledepressor(stat, lvl);

if(name == "Giant Shot Glass")
    return new Giantshotglass(stat, lvl);

if(name == "Amp")
    return new Amp(stat, lvl);

if(name == "Horse Armor")
    return new Horsearmor(stat, lvl);

if(name == "Comedic Wits")
    return new Comedicwits(stat, lvl);

if(name == "Antenna")
    return new Antenna(stat, lvl);

if(name == "Glockenspiel")
    return new Glockenspiel(stat, lvl);

if(name == "Desk")
    return new Desk(stat, lvl);

if(name == "Giant Rock")
    return new Giantrock(stat, lvl);

if(name == "Noise Cancelling Headphones")
    return new Noisecancellingheadphones(stat, lvl);

if(name == "Off-key Armor")
    return new Offkeyarmor(stat, lvl);

if(name == "Song of Steadfastedness")
    return new Songofsteadfastedness(stat, lvl);

if(name.find("'s Enlarged Hairbrush")!= std::string::npos){
	name = name.substr(0, name.find("'s Enlarged Hairbrush"));
    return new Enlargedhairbrush(name, stat, lvl);
}
if(name == "Dickbutt Form")
    return new Dickbuttform(stat, lvl);

if(name == "Umbrella")
    return new Umbrella(stat, lvl);

if(name.find("'s Body") != std::string::npos){
	name = name.substr(0, name.find("'s Body"));
	return new Body(name, stat);
	}
	return nullptr;
}

Item* Game::newMon(std::ifstream& ifs, std::string type){
	Character* mon;
	int lvl, hp, mhp, atk, def, spd, wallet, exp, lvlup;
	Item *W, *D;
	std::string name;
	getline(ifs, name);
	ifs >> lvl >> hp >> mhp >> atk >> def >> spd >> wallet >> exp >> lvlup;
	ifs.ignore(500, '\n');
	W = createItems(ifs);
	D = createItems(ifs);
if(type == "Goblin")
	mon = new Goblin(name, type, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, W, D);
else if(type == "Orc")
	mon = new Orc(name, type, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, W, D);

else if(type == "Giant Boar")
	mon = new GiantBoar(name, type, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, W, D);

else if(type == "Jivin' Funky Badger")
	mon = new JivinFunkyBadger(name, type, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, W, D);

else if(type == "Thug Cactus")
	mon = new ThugCactus(name, type, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, W, D);

else if(type == "Big Chungus")
	mon = new BigChungus(name, type, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, W, D);

else if(type == "Killer Garfield")
	mon = new KillerGarfield(name, type, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, W, D);

else if(type == "Saintan")
	mon = new Saintan(name, type, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, W, D);

else if(type == "Minotaur")
	mon = new Minotaur(name, type, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, W, D);

else if(type == "Dragon")
	mon = new Dragon(name, type, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, W, D);

else if(type == "Werewolf")
	mon = new Werewolf(name, type, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, W, D);

else if(type == "Golem")
	mon = new Golem(name, type, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, W, D);

else if(type == "Cerberus")
	mon = new Cerberus(name, type, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, W, D);

else if(type == "Sentient Trebuchet")
	mon = new SentientTrebuchet(name, type, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, W, D);

else if(type == "Super Soaking Squirter")
	mon = new SuperSoakingSquirter(name, type, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, W, D);

else if(type == "Fish")
	mon = new Fish(name, type, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, W, D);

else if(type == "Porcupine Lion")
	mon = new PorcupineLion(name, type, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, W, D);

else
	mon = new Kyle(name, type, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, W, D);

	return new TamedMonster(name, *mon);
}

bool Game::isPotion(std::string name){
	if(name == "NULL"){
		return false;
	}
	if(name.substr(0, 6) == "POTION" && name.substr(name.size() - 6, name.size()) == "POTION"){
		return true;
	}
	return false;
}

bool Game::isBook(std::string name){
	if(name == "NULL"){
		return false;
	}
	if(name.substr(0, 4) == "BOOK" && name.substr(name.size() - 4, name.size()) == "BOOK"){
		return true;
	}
	return false;
}

bool Game::isItem(std::string name){
	if(name == "NULL"){
		return false;
	}
	if(name.substr(0, 4) == "ITEM" && name.substr(name.size() - 4, name.size()) == "ITEM"){
		return true;
	}
	return false;
}

bool Game::isMonster(std::string name){
	if(name == "NULL"){
		return false;
	}
	if(name.substr(0, 7) == "MONSTER" && name.substr(name.size() - 7, name.size()) == "MONSTER"){
		return true;
	}
	return false;
}

bool Game::isIngredient(std::string name){
	if(name == "NULL"){
		return false;
	}
	if(name.substr(0, 10) == "INGREDIENT" && name.substr(name.size()-10, name.size()) == "INGREDIENT"){
		return true;
	}
	return false;
}

void Game::saveGame(std::ofstream& ofs){
	saveCharacter(ofs, player);
	for(unsigned i = 0; i < bag.size(); ++i){
		saveItem(ofs, bag.at(i));
	}
}

void Game::saveCharacter(std::ofstream& ofs, Character* p){
	if(p -> isMon())
		ofs << "MONSTER" << p-> getCreature() << "MONSTER" << std::endl;
	ofs << p -> getName() << std::endl;
	if(!p -> isMon())
		ofs << p -> getType() << std::endl;
	ofs << p -> getLVL() << std::endl;
	ofs << p -> getHP() << std::endl;
	ofs << p -> getMHP() << std::endl;
	ofs << p -> getAtk() << std::endl;
	ofs << p -> getDef() << std::endl;
	ofs << p -> getSpd() << std::endl;
	ofs << p -> getWallet() << std::endl;
	ofs << p -> getExp() << std::endl;
	ofs << p -> getLvLUp() << std::endl;
	if(p -> hasWeapon()){
		saveItem(ofs, p -> getWeapon());
	}
	else
		ofs << "NULL" << std::endl;
	if(p -> hasDefensive()){
		saveItem(ofs, p -> getDefensive());
	}
	else
		ofs << "NULL" << std::endl;
}

void Game::saveItem(std::ofstream& ofs, Item* p){
	if(p -> isMon()){
		saveCharacter(ofs, p -> getMon());
	}
	else if(p -> isPotion()){
		ofs << "POTION" << p -> getName() << "POTION" << std::endl;
		p -> toFile(ofs);
	}
	else if(p -> isIngredient()){
		ofs << "INGREDIENT" << p -> getName() << "INGREDIENT" << std::endl;
		p -> toFile(ofs);
	}
	else if(p -> isBook()){
		ofs << "BOOK" << p -> getName() << "BOOK" << std::endl;
		p -> toFile(ofs);
	}
	else{
		ofs << "ITEM" << p -> getName() << "ITEM" << std::endl;
		p -> toFile(ofs);
	}
}