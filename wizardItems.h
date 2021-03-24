#ifndef WIZARDITEMS_H
#define WIZARDITEMS_H

#include "Items.h"

struct RandomStick : public Item {
	RandomStick() : Item("Random Stick", 3, 1,wizard, common, wep, "RSWDS", false){}
	void attackOutput(std::string Mname){output(" fires a weak bolt", true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new RandomStick();}
};

struct Broom : public Item {
	Broom(int lvl) : Item("Broom", getValInRange(1, 7), lvl,  wizard, common, wep, "BVOD", true) {}
Broom(int stat, int lvl) : Item("Broom", stat, lvl, wizard, common, wep, "BVOD", false){}
	void attackOutput(std::string Mname){output(" flies at " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Broom(stat, lvl);}
};

struct Magicring : public Item {
	Magicring(int lvl) : Item("Magic Ring", getValInRange(1, 7), lvl,  wizard, common, wep, "MRME", true) {}
Magicring(int stat, int lvl) : Item("Magic Ring", stat, lvl, wizard, common, wep, "MRME", false){}
	void attackOutput(std::string Mname){output(" adjusts the ring and smacks " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Magicring(stat, lvl);}
};

struct Magicdie : public Item {
	Magicdie(int lvl) : Item("Magic Die", getValInRange(1, 7), lvl,  wizard, common, wep, "MDMC", true) {}
Magicdie(int stat, int lvl) : Item("Magic Die", stat, lvl, wizard, common, wep, "MDMC", false){}
	void attackOutput(std::string Mname){output(" rolls the " + name + ", which then emits " + std::to_string(getValInRange(1, 6)) + " beam(s) of light, damaging " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Magicdie(stat, lvl);}
};

struct Wand : public Item {
	Wand(int lvl) : Item("Wand", getValInRange(1, 7), lvl,  wizard, common, wep, "WC", true) {}
Wand(int stat, int lvl) : Item("Wand", stat, lvl, wizard, common, wep, "WC", false){}
	void attackOutput(std::string Mname){output(" summons doves to peck at " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Wand(stat, lvl);}
};

struct Randombook : public Item {
	Randombook(int lvl) : Item("Random Book", getValInRange(1, 7), lvl,  wizard, common, wep, "RBPUL", true) {}
Randombook(int stat, int lvl) : Item("Random Book", stat, lvl, wizard, common, wep, "RBPUL", false){}
	void attackOutput(std::string Mname){output(" determines the book is useless and thumps " + Mname + " with it", true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Randombook(stat, lvl);}
};

struct Handkerchiefs : public Item {
	Handkerchiefs(int lvl) : Item("Handkerchiefs", getValInRange(3, 9), lvl,  wizard, uncommon, wep, "HDDDD", true) {}
Handkerchiefs(int stat, int lvl) : Item("Handkerchiefs", stat, lvl, wizard, uncommon, wep, "HDDDD", false){}
	void attackOutput(std::string Mname){output(" tosses "+ name + " at "+ Mname + " and strangles them", true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Handkerchiefs(stat, lvl);}
};

struct Pointyhat : public Item {
	Pointyhat(int lvl) : Item("Pointy Hat", getValInRange(3, 9), lvl,  wizard, uncommon, wep, "PHRRS", true) {}
Pointyhat(int stat, int lvl) : Item("Pointy Hat", stat, lvl, wizard, uncommon, wep, "PHRRS", false){}
	void attackOutput(std::string Mname){output(" judges " + Mname + " and puts it in a house ", true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Pointyhat(stat, lvl);}
};

struct Incantation : public Item {
	Incantation(int lvl) : Item("Incantation", getValInRange(3, 9), lvl,  wizard, uncommon, wep, "IICA", true) {}
Incantation(int stat, int lvl) : Item("Incantation", stat, lvl, wizard, uncommon, wep, "IICA", false){}
	void attackOutput(std::string Mname){output(" shouts the incantation and punches " + Mname + " while they're distracted", true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Incantation(stat, lvl);}
};

struct Oldstaff : public Item {
	Oldstaff(int lvl) : Item("Old Staff", getValInRange(3, 9), lvl,  wizard, uncommon, wep, "OSMDS", true) {}
Oldstaff(int stat, int lvl) : Item("Old Staff", stat, lvl, wizard, uncommon, wep, "OSMDS", false){}
	void attackOutput(std::string Mname){output(" slams the " + name + " and summons a blast of light, burning " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Oldstaff(stat, lvl);}
};

struct Candle : public Item {
	Candle(int lvl) : Item("Candle", getValInRange(5, 11), lvl,  wizard, rare, wep, "CGS", true) {}
Candle(int stat, int lvl) : Item("Candle", stat, lvl, wizard, rare, wep, "CGS", false){}
	void attackOutput(std::string Mname){output(" launches fiery wax spikes at " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Candle(stat, lvl);}
};

struct Ancienttome : public Item {
	Ancienttome(int lvl) : Item("Ancient Tome", getValInRange(5, 11), lvl,  wizard, rare, wep, "ATAEP", true) {}
Ancienttome(int stat, int lvl) : Item("Ancient Tome", stat, lvl, wizard, rare, wep, "ATAEP", false){}
	void attackOutput(std::string Mname){output(" speaks an ancient spell and explodes " + Mname + "'s face ", true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Ancienttome(stat, lvl);}
};

struct Magiccloak : public Item {
	Magiccloak(int lvl) : Item("Magic Cloak", getValInRange(5, 11), lvl,  wizard, rare, wep, "MCMCB", true) {}
Magiccloak(int stat, int lvl) : Item("Magic Cloak", stat, lvl, wizard, rare, wep, "MCMCB", false){}
	void attackOutput(std::string Mname){output(" opens the " + name + " and flashes " + Mname + ", using the distraction to blast " + Mname + " with light", true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Magiccloak(stat, lvl);}
};

struct Enchantedbrassknuckles : public Item {
	Enchantedbrassknuckles(int lvl) : Item("Enchanted Brass Knuckles", getValInRange(5, 11), lvl,  wizard, rare, wep, "EBKEGC", true) {}
Enchantedbrassknuckles(int stat, int lvl) : Item("Enchanted Brass Knuckles", stat, lvl, wizard, rare, wep, "EBKEGC", false){}
	void attackOutput(std::string Mname){output(" pummels " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Enchantedbrassknuckles(stat, lvl);}
};

struct Ancientstaff : public Item {
	Ancientstaff(int lvl) : Item("Ancient Staff", getValInRange(7, 13), lvl,  wizard, veryrare, wep, "ASFF", true) {}
Ancientstaff(int stat, int lvl) : Item("Ancient Staff", stat, lvl, wizard, veryrare, wep, "ASFF", false){}
	void attackOutput(std::string Mname){output(" opens the heavens to fire a holy beam at " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Ancientstaff(stat, lvl);}
};

struct Killergarfieldsvoice : public Item {
	Killergarfieldsvoice(int lvl) : Item("Killer Garfield's Voice", getValInRange(7, 13), lvl,  wizard, veryrare, wep, "KGVVP", true) {}
Killergarfieldsvoice(int stat, int lvl) : Item("Killer Garfield's Voice", stat, lvl, wizard, veryrare, wep, "KGVVP", false){}
	void attackOutput(std::string Mname){output(" mimics " + name + " and makes "+ Mname + "’s ears bleed", true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Killergarfieldsvoice(stat, lvl);}
};

struct Humorous : public Item {
	Humorous(std::string name, int lvl) : Item(name +  "'s Humorous", getValInRange(7, 13), lvl, wizard, veryrare, wep, "HF2", true){}
	Humorous(std::string name, int stat, int lvl) : Item(name +  "'s Humorous",stat , lvl, wizard, veryrare, wep, "HF2", false){}
	void attackOutput(std::string Mname){output(" humors " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Humorous(name.substr(0, name.find("'s Humorous")), stat, lvl);}
};

struct Dragonsbreath : public Item {
	Dragonsbreath(int lvl) : Item("Dragon's Breath", getValInRange(9, 15), lvl,  wizard, legendary, wep, "DBDVP", true) {}
Dragonsbreath(int stat, int lvl) : Item("Dragon's Breath", stat, lvl, wizard, legendary, wep, "DBDVP", false){}
	void attackOutput(std::string Mname){output(" summons a mighty fireball using " + name, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Dragonsbreath(stat, lvl);}
};

struct Banishingcrystal : public Item {
	Banishingcrystal(int lvl) : Item("Banishing Crystal", getValInRange(9, 15), lvl,  wizard, legendary, wep, "BCSS", true) {}
Banishingcrystal(int stat, int lvl) : Item("Banishing Crystal", stat, lvl, wizard, legendary, wep, "BCSS", false){}
	void attackOutput(std::string Mname){output(" clouts "+ Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Banishingcrystal(stat, lvl);}
};

struct Skull : public Item {
	Skull(std::string name, int atk) : Item(name +  "'s Skull", atk, 1, wizard, unique, wep, "SB2", false){}
	void attackOutput(std::string Mname){output(" quotes shakespeare at " + Mname + ", they groan", true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Skull(name.substr(0, name.find("'s Skull")), stat);}
};

struct Weakdefensespell : public Item {
	Weakdefensespell() : Item("Weak Defense Spell", 3, 1,wizard, common, shi, "RSWDS", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Weakdefensespell();}
};

struct Veilodust : public Item {
	Veilodust(int lvl) : Item("Veil o' Dust", getValInRange(1, 7), lvl,  wizard, common, shi, "BVOD", true) {}
Veilodust(int stat, int lvl) : Item("Veil o' Dust", stat, lvl, wizard, common, shi, "BVOD", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Veilodust(stat, lvl);}
};

struct Magicearrings : public Item {
	Magicearrings(int lvl) : Item("Magic Earrings", getValInRange(1, 7), lvl,  wizard, common, shi, "MRME", true) {}
Magicearrings(int stat, int lvl) : Item("Magic Earrings", stat, lvl, wizard, common, shi, "MRME", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Magicearrings(stat, lvl);}
};

struct Magiccoins : public Item {
	Magiccoins(int lvl) : Item("Magic Coins", getValInRange(1, 7), lvl,  wizard, common, shi, "MDMC", true) {}
Magiccoins(int stat, int lvl) : Item("Magic Coins", stat, lvl, wizard, common, shi, "MDMC", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Magiccoins(stat, lvl);}
};

struct Cloak : public Item {
	Cloak(int lvl) : Item("Cloak", getValInRange(1, 7), lvl,  wizard, common, shi, "WC", true) {}
Cloak(int stat, int lvl) : Item("Cloak", stat, lvl, wizard, common, shi, "WC", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Cloak(stat, lvl);}
};

struct Popuplibrary : public Item {
	Popuplibrary(int lvl) : Item("Pop-up Library", getValInRange(1, 7), lvl,  wizard, common, shi, "RBPUL", true) {}
Popuplibrary(int stat, int lvl) : Item("Pop-up Library" , stat, lvl, wizard, common, shi, "RBPUL", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Popuplibrary(stat, lvl);}
};

struct Daringdeceptivedistractiondoves : public Item {
	Daringdeceptivedistractiondoves(int lvl) : Item("Daring Deceptive Distraction Doves", getValInRange(3, 9), lvl,  wizard, uncommon, shi, "HDDDD", true) {}
Daringdeceptivedistractiondoves(int stat, int lvl) : Item("Daring Deceptive Distraction Doves", stat, lvl, wizard, uncommon, shi, "HDDDD", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Daringdeceptivedistractiondoves(stat, lvl);}
};

struct Redraggedyscarf : public Item {
	Redraggedyscarf(int lvl) : Item("Red Raggedy Scarf", getValInRange(3, 9), lvl,  wizard, uncommon, shi, "PHRRS", true) {}
Redraggedyscarf(int stat, int lvl) : Item("Red Raggedy Scarf", stat, lvl, wizard, uncommon, shi, "PHRRS", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Redraggedyscarf(stat, lvl);}
};

struct In_cant_ation : public Item {
	In_cant_ation(int lvl) : Item("In-can't-ation", getValInRange(3, 9), lvl,  wizard, uncommon, shi, "IICA", true) {}
In_cant_ation(int stat, int lvl) : Item("In-can't-ation", stat, lvl, wizard, uncommon, shi, "IICA", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new In_cant_ation(stat, lvl);}
};

struct Moderatedefensespell : public Item {
	Moderatedefensespell(int lvl) : Item("Moderate Defense Spell", getValInRange(3, 9), lvl,  wizard, uncommon, shi, "OSMDS", true) {}
Moderatedefensespell(int stat, int lvl) : Item("Moderate Defense Spell", stat, lvl, wizard, uncommon, shi, "OSMDS", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Moderatedefensespell(stat, lvl);}
};

struct Giantsnuffer : public Item {
	Giantsnuffer(int lvl) : Item("Giant Snuffer", getValInRange(5, 11), lvl,  wizard, rare, shi, "CGS", true) {}
Giantsnuffer(int stat, int lvl) : Item("Giant Snuffer", stat, lvl, wizard, rare, shi, "CGS", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Giantsnuffer(stat, lvl);}
};

struct Assortedenchantedpapers : public Item {
	Assortedenchantedpapers(int lvl) : Item("Assorted Enchanted Papers", getValInRange(5, 11), lvl,  wizard, rare, shi, "ATAEP", true) {}
Assortedenchantedpapers(int stat, int lvl) : Item("Assorted Enchanted Papers", stat, lvl, wizard, rare, shi, "ATAEP", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Assortedenchantedpapers(stat, lvl);}
};

struct Magiccensorbar : public Item {
	Magiccensorbar(int lvl) : Item("Magic Censor Bar", getValInRange(5, 11), lvl,  wizard, rare, shi, "MCMCB", true) {}
Magiccensorbar(int stat, int lvl) : Item("Magic Censor Bar", stat, lvl, wizard, rare, shi, "MCMCB", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Magiccensorbar(stat, lvl);}
};

struct Enchantedgoldchain : public Item {
	Enchantedgoldchain(int lvl) : Item("Enchanted Gold Chain", getValInRange(5, 11), lvl,  wizard, rare, shi, "EBKEGC", true) {}
Enchantedgoldchain(int stat, int lvl) : Item("Enchanted Gold Chain", stat, lvl, wizard, rare, shi, "EBKEGC", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Enchantedgoldchain(stat, lvl);}
};

struct Forcefield : public Item {
	Forcefield(int lvl) : Item("Forcefield", getValInRange(7, 13), lvl,  wizard, veryrare, shi, "ASFF", true) {}
Forcefield(int stat, int lvl) : Item("Forcefield", stat, lvl, wizard, veryrare, shi, "ASFF", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Forcefield(stat, lvl);}
};

struct Voidpouch : public Item {
	Voidpouch(int lvl) : Item("Void Pouch", getValInRange(7, 13), lvl,  wizard, veryrare, shi, "KGVVP", true) {}
Voidpouch(int stat, int lvl) : Item("Void Pouch", stat, lvl, wizard, veryrare, shi, "KGVVP", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Voidpouch(stat, lvl);}
};

struct Femur : public Item {
	Femur(std::string name, int lvl) : Item(name +  "'s Femur", getValInRange(7, 13), lvl, wizard, veryrare, wep, "HF2", true){}
	Femur(std::string name, int stat, int lvl) : Item(name +  "'s Femur",stat , lvl, wizard, veryrare, wep, "HF2", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Femur(name.substr(0, name.find("'s Femur")), stat, lvl);}
};

struct Dragonsvapepen : public Item {
	Dragonsvapepen(int lvl) : Item("Dragon's Vape Pen", getValInRange(9, 15), lvl,  wizard, legendary, shi, "DBDVP", true) {}
Dragonsvapepen(int stat, int lvl) : Item("Dragon's Vape Pen", stat, lvl, wizard, legendary, shi, "DBDVP", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Dragonsvapepen(stat, lvl);}
};

struct Summoningslime : public Item {
	Summoningslime(int lvl) : Item("Summoning Slime", getValInRange(9, 15), lvl,  wizard, legendary, shi, "BCSS", true) {}
Summoningslime(int stat, int lvl) : Item("Summoning Slime", stat, lvl, wizard, legendary, shi, "BCSS", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Summoningslime(stat, lvl);}
};

struct Brain : public Item {
	Brain(std::string name, int atk) : Item(name +  "'s Brain", atk, 1, wizard, unique, shi, "SB2", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Brain(name.substr(0, name.find("'s Brain")), stat);}
};

#endif