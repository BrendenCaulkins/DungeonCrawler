#ifndef ARCHERITEMS_H
#define ARCHERITEMS_H

#include "Items.h"

struct OldBow : public Item {
	OldBow() : Item("Old Bow", 3, 1, archer, common, wep, "OBTLC", false){}
	void attackOutput(std::string Mname){output(" fires an arrow at " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new OldBow();}
};

struct Boomerang : public Item {
	Boomerang(int lvl) : Item("Boomerang", getValInRange(1, 7), lvl, archer, common, wep, "BMAS", true) {}
Boomerang(int stat, int lvl) : Item("Boomerang",stat , lvl, archer, common, wep, "BMAS", false){}
	void attackOutput(std::string Mname){output(" thumps " + Mname + " with " + name, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Boomerang(stat, lvl);}
};

struct Stone : public Item {
	Stone(int lvl) : Item("Stone", getValInRange(1, 7), lvl, archer, common, wep, "SB1", true) {}
Stone(int stat, int lvl) : Item("Stone", stat, lvl, archer, common, wep, "SB1", false){}
	void attackOutput(std::string Mname){output(" stones " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Stone(stat, lvl);}
};

struct Slingshot : public Item {
	Slingshot(int lvl) : Item("Slingshot", getValInRange(1, 7), lvl, archer, common, wep, "SSCLCM", true) {}
Slingshot(int stat, int lvl) : Item("Slingshot", stat, lvl, archer, common, wep, "SSCLCM", false){}
	void attackOutput(std::string Mname){output(" slings a stone at " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Slingshot(stat, lvl);}
};

struct Playingcards : public Item {
	Playingcards(int lvl) : Item("Playing Cards", getValInRange(1, 7), lvl, archer, common, wep, "PCGT", true) {}
Playingcards(int stat, int lvl) : Item("Playing Cards", stat, lvl, archer, common, wep, "PCGT", false){}
	void attackOutput(std::string Mname){output(" plays " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Playingcards(stat, lvl);}
};

struct Throwingknives : public Item {
	Throwingknives(int lvl) : Item("Throwing Knives", getValInRange(1, 7), lvl, archer, common, wep, "TKSB", true) {}
Throwingknives(int stat, int lvl) : Item("Throwing Knives", stat, lvl, archer, common, wep, "TKSB", false){}
	void attackOutput(std::string Mname){output(" sticks " + Mname + " with " + name, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Throwingknives(stat, lvl);}
};

struct Canoworms : public Item {
	Canoworms(int lvl) : Item("Can O' Worms", getValInRange(3, 9), lvl, archer, uncommon, wep, "COWGTW", true) {}
Canoworms(int stat, int lvl) : Item("Can O' Worms", stat, lvl, archer, uncommon, wep, "COWGTW", false){}
	void attackOutput(std::string Mname){output(" opens " + name + ", causing monster worms to bite at " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Canoworms(stat, lvl);}
};

struct Paperairplane : public Item {
	Paperairplane(int lvl) : Item("Paper Airplane", getValInRange(3, 9), lvl, archer, uncommon, wep, "PAOS", true) {}
Paperairplane(int stat, int lvl) : Item("Paper Airplane", stat, lvl, archer, uncommon, wep, "PAOS", false){}
	void attackOutput(std::string Mname){output(" tosses " + name + " at " + Mname + ", poking them in the eye", true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Paperairplane(stat, lvl);}
};

struct Harpoon : public Item {
	Harpoon(int lvl) : Item("Harpoon", getValInRange(3, 9), lvl, archer, uncommon, wep, "HSG", true) {}
Harpoon(int stat, int lvl) : Item("Harpoon", stat, lvl, archer, uncommon, wep, "HSG", false){}
	void attackOutput(std::string Mname){output(" shoots " + name + " at " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Harpoon(stat, lvl);}
};

struct Crossbow : public Item {
	Crossbow(int lvl) : Item("Crossbow", getValInRange(3, 9), lvl, archer, uncommon, wep, "CC", true) {}
Crossbow(int stat, int lvl) : Item("Crossbow", stat, lvl, archer, uncommon, wep, "CC", false){}
	void attackOutput(std::string Mname){output(" bolts "+ Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Crossbow(stat, lvl);}
};

struct Needles : public Item {
	Needles(int lvl) : Item("Needles", getValInRange(5, 11), lvl, archer, rare, wep, "NB", true) {}
Needles(int stat, int lvl) : Item("Needles", stat, lvl, archer, rare, wep, "NB", false){}
	void attackOutput(std::string Mname){output(" spikes " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Needles(stat, lvl);}
};

struct Lizard : public Item {
	Lizard(int lvl) : Item("Lizard", getValInRange(5, 11), lvl, archer, rare, wep, "LL", true) {}
Lizard(int stat, int lvl) : Item("Lizard", stat, lvl, archer, rare, wep, "LL", false){}
	void attackOutput(std::string Mname){output(" tosses the " + name + " at " + Mname + ", they freak out", true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Lizard(stat, lvl);}
};

struct Highqualitybow : public Item {
	Highqualitybow(int lvl) : Item("High Quality Bow", getValInRange(5, 11), lvl, archer, rare, wep, "HQBT", true) {}
Highqualitybow(int stat, int lvl) : Item("High Quality Bow", stat, lvl , archer, rare, wep, "HQBT", false){}
	void attackOutput(std::string Mname){output(" fires a mighty arrow at " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Highqualitybow(stat, lvl);}
};

struct Gun : public Item {
	Gun(int lvl) : Item("Gun", getValInRange(5, 11), lvl, archer, rare, wep, "GBA", true) {}
Gun(int stat, int lvl) : Item("Gun", stat, lvl, archer, rare, wep, "GBA", false){}
	void attackOutput(std::string Mname){output(" shoots " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Gun(stat, lvl);}
};

struct Giantmetalfrisbee : public Item {
	Giantmetalfrisbee(int lvl) : Item("Giant Metal Frisbee", getValInRange(7, 13), lvl, archer, veryrare, wep, "GMFGMH", true) {}
Giantmetalfrisbee(int stat, int lvl) : Item("Giant Metal Frisbee", stat, lvl, archer, veryrare, wep, "GMFGMH", false){}
	void attackOutput(std::string Mname){output(" tosses the " + name + " at " + Mname + ", bludgeoning them", true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Giantmetalfrisbee(stat, lvl);}
};

struct Enchantedbow : public Item {
	Enchantedbow(int lvl) : Item("Enchanted Bow", getValInRange(7, 13), lvl, archer, veryrare, wep, "EBES", true) {}
Enchantedbow(int stat, int lvl) : Item("Enchanted Bow", stat, lvl, archer, veryrare, wep, "EBES", false){}
	void attackOutput(std::string Mname){output(" fires a magic bolt at " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Enchantedbow(stat, lvl);}
};

struct Hand : public Item {
	Hand(std::string name, int lvl) : Item(name + "'s Hand",getValInRange(7, 13), lvl, archer, veryrare, wep, "HF1", true){}
	Hand(std::string name, int stat, int lvl) : Item(name + "'s Hand", stat, lvl, archer, veryrare, wep, "HF1", false) {}
	void attackOutput(std::string Mname){output(" gives " + Mname + " a " + name, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Hand(name.substr(0, name.find("'s Hand")), stat, lvl);}
};

struct Thunderbolt : public Item {
	Thunderbolt(int lvl) : Item("Thunderbolt", getValInRange(9, 15), lvl, archer, legendary, wep, "TC", true) {}
Thunderbolt(int stat, int lvl) : Item("Thunderbolt", stat, lvl, archer, legendary, wep, "TC", false){}
	void attackOutput(std::string Mname){output(" lightnings " + Mname + " to thunderous applause", true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Thunderbolt(stat, lvl);}
};

struct Egg : public Item {
	Egg(int lvl) : Item("Egg", getValInRange(9, 15), lvl, archer, legendary, wep, "EC", true) {}
Egg(int stat, int lvl) : Item("Egg", stat, lvl, archer, legendary, wep, "EC", false){}
	void attackOutput(std::string Mname){output(" offers " + Mname + " an " + name + " in these trying times", true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Egg(stat, lvl);}
};

struct Nuts : public Item {
	Nuts(std::string name, int atk) : Item(name + "'s Nuts", atk,1, archer, unique, wep, "NR", false){}
	void attackOutput(std::string Mname){output(" teabags " + Mname + " with " + name, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Nuts(name.substr(0, name.find("'s Nuts")), stat);}
};

struct Thiccleathershirt : public Item {
	Thiccleathershirt() : Item("Thicc Leather Shirt", 3, 1, archer, common, shi, "OBTLC", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Thiccleathershirt();}
};

struct Adventuringslouch : public Item {
	Adventuringslouch(int lvl) : Item("Adventuring Slouch", getValInRange(1, 7), lvl, archer, common, shi, "BMAS", true) {}
Adventuringslouch(int stat, int lvl) : Item("Adventuring Slouch", stat, lvl, archer, common, shi, "BMAS", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Adventuringslouch(stat, lvl);}
};

struct Blunt : public Item {
	Blunt(int lvl) : Item("Blunt", getValInRange(1, 7), lvl, archer, common, shi, "SB1", true) {}
Blunt(int stat, int lvl) : Item("Blunt", stat, lvl, archer, common, shi, "SB1", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Blunt(stat, lvl);}
};

struct Comicallylargecatchersmitt : public Item {
	Comicallylargecatchersmitt(int lvl) : Item("Comically Large Catchers Mitt", getValInRange(1, 7), lvl, archer, common, shi, "SSCLCM", true) {}
Comicallylargecatchersmitt(int stat, int lvl) : Item("Comically Large Catchers Mitt", stat, lvl, archer, common, shi, "SSCLCM", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Comicallylargecatchersmitt(stat, lvl);}
};

struct Greentable : public Item {
	Greentable(int lvl) : Item("Green Table", getValInRange(1, 7), lvl, archer, common, shi, "PCGT", true) {}
Greentable(int stat, int lvl) : Item("Green Table", stat, lvl, archer, common, shi, "PCGT", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Greentable(stat, lvl);}
};

struct Sharpeningboulder : public Item {
	Sharpeningboulder(int lvl) : Item("Sharpening Boulder",getValInRange(1, 7), lvl, archer, common, shi, "TKSB", true) {}
Sharpeningboulder(int stat, int lvl) : Item("Sharpening Boulder", stat, lvl, archer, common, shi, "TKSB", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Sharpeningboulder(stat, lvl);}
};

struct Gianttoyworms : public Item {
	Gianttoyworms(int lvl) : Item("Giant Toy Worms", getValInRange(3, 9), lvl, archer, uncommon, shi, "COWGTW", true) {}
Gianttoyworms(int stat, int lvl) : Item("Giant Toy Worms", stat, lvl, archer, uncommon, shi, "COWGTW", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Gianttoyworms(stat, lvl);}
};

struct Origamishield : public Item {
	Origamishield(int lvl) : Item("Origami Shield", getValInRange(3, 9), lvl, archer, uncommon, shi, "PAOS", true) {}
Origamishield(int stat, int lvl) : Item("Origami Shield", stat, lvl, archer, uncommon, shi, "PAOS", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Origamishield(stat, lvl);}
};

struct Scubagear : public Item {
	Scubagear(int lvl) : Item("Scuba Gear", getValInRange(3, 9), lvl, archer, uncommon, shi, "HSG", true) {}
Scubagear(int stat, int lvl) : Item("Scuba Gear", stat, lvl, archer, uncommon, shi, "HSG", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Scubagear(stat, lvl);}
};

struct Chainmail : public Item {
	Chainmail(int lvl) : Item("Chainmail", getValInRange(3, 9), lvl, archer, uncommon, shi, "CC", true) {}
Chainmail(int stat, int lvl) : Item("Chainmail", stat, lvl, archer, uncommon, shi, "CC", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Chainmail(stat, lvl);}
};

struct Bandages : public Item {
	Bandages(int lvl) : Item("Bandages", getValInRange(5, 11), lvl, archer, rare, shi, "NB", true) {}
Bandages(int stat, int lvl) : Item("Bandages", stat, lvl, archer, rare, shi, "NB", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Bandages(stat, lvl);}
};

struct Lemur : public Item {
	Lemur(int lvl) : Item("Lemur", getValInRange(5, 11), lvl, archer, rare, shi, "LL", true) {}
Lemur(int stat, int lvl) : Item("Lemur", stat, lvl, archer, rare, shi, "LL", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Lemur(stat, lvl);}
};

struct Target : public Item {
	Target(int lvl) : Item("Target", getValInRange(5, 11), lvl, archer, rare, shi, "HQBT", true) {}
Target(int stat, int lvl) : Item("Target", stat, lvl, archer, rare, shi, "HQBT", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Target(stat, lvl);}
};

struct Bulletarmor : public Item {
	Bulletarmor(int lvl) : Item("Bullet Armor", getValInRange(5, 11), lvl, archer, rare, shi, "GBA", true) {}
Bulletarmor(int stat, int lvl) : Item("Bullet Armor", stat, lvl, archer, rare, shi, "GBA", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Bulletarmor(stat, lvl);}
};

struct Giantmetalhammer : public Item {
	Giantmetalhammer(int lvl) : Item("Giant Metal Hammer", getValInRange(7, 13), lvl, archer, veryrare, shi, "GMFGMH", true) {}
Giantmetalhammer(int stat, int lvl) : Item("Giant Metal Hammer", stat, lvl, archer, veryrare, shi, "GMFGMH", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Giantmetalhammer(stat, lvl);}
};

struct Enchantedshield : public Item {
	Enchantedshield(int lvl) : Item("Enchanted Shield", getValInRange(7, 13), lvl, archer, veryrare, shi, "EBES", true) {}
Enchantedshield(int stat, int lvl) : Item("Enchanted Shield", stat, lvl, archer, veryrare, shi, "EBES", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Enchantedshield(stat, lvl);}
};

struct Foot : public Item {
	Foot(std::string name, int lvl) : Item(name + "'s Foot", getValInRange(7, 13), lvl, archer, veryrare, shi, "HF1", true){}
	Foot(std::string name, int stat, int lvl) : Item(name + "'s Enlarged Hairbrush",stat , lvl, archer, veryrare, shi, "HF1", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Foot(name.substr(0, name.find("'s Foot")), stat, lvl);}
};

struct Cloud : public Item {
	Cloud(int lvl) : Item("Cloud", getValInRange(9, 15), lvl, archer, legendary, shi, "TC", true) {}
Cloud(int stat, int lvl) : Item("Cloud", stat, lvl, archer, legendary, shi, "TC", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Cloud(stat, lvl);}
};

struct Chicken : public Item {
	Chicken(int lvl) : Item("Chicken", getValInRange(9, 15), lvl, archer, legendary, shi, "EC", true) {}
Chicken(int stat, int lvl) : Item("Chicken", stat, lvl, archer, legendary, shi, "EC", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Chicken(stat, lvl);}
};

struct Ribs : public Item {
	Ribs(std::string name, int atk) : Item(name + "'s Ribs", atk,1, archer, unique, shi, "NR", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Ribs(name.substr(0, name.find("'s Ribs")), stat);}
};


#endif