#ifndef PALADINITEMS_H
#define PALADINITEMS_H

#include "Items.h"

struct RustySword : public Item {
	RustySword() : Item("Rusty Sword", 3, 1,paladin, common, wep, "RSRS", false){}
	void attackOutput(std::string Mname){output( " swings at " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new RustySword();}
};

struct Axe : public Item {
	Axe(int lvl) : Item("Axe", getValInRange(1, 7), lvl,  paladin, common, wep, "ASl", true) {}
Axe(int stat, int lvl) : Item("Axe", stat, lvl, paladin, common, wep, "ASL", false){}
	void attackOutput(std::string Mname){output( " " + name + "s " + Mname + " a question", true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Axe(stat, lvl);}
};

struct Mace : public Item {
	Mace(int lvl) : Item("Mace", getValInRange(1, 7), lvl,  paladin, common, wep, "MG", true) {}
Mace(int stat, int lvl) : Item("Mace", stat, lvl, paladin, common, wep, "MG", false){}
	void attackOutput(std::string Mname){output( " blugeons " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Mace(stat, lvl);}
};

struct Spear : public Item {
	Spear(int lvl) : Item("Spear", getValInRange(1, 7), lvl,  paladin, common, wep, "SCW", true) {}
Spear(int stat, int lvl) : Item("Spear", stat, lvl, paladin, common, wep, "SCW", false){}
	void attackOutput(std::string Mname){output( " spears " + Mname + " through the chest", true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Spear(stat, lvl);}
};

struct Whip : public Item {
	Whip(int lvl) : Item("Whip", getValInRange(1, 7), lvl,  paladin, common, wep, "WF", true) {}
Whip(int stat, int lvl) : Item("Whip", stat, lvl, paladin, common, wep, "WF", false){}
	void attackOutput(std::string Mname){output( " flagellates " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Whip(stat, lvl);}
};

struct Knife : public Item {
	Knife(int lvl) : Item("Knife", getValInRange(1, 7), lvl,  paladin, common, wep, "KKB", true) {}
Knife(int stat, int lvl) : Item("Knife", stat, lvl, paladin, common, wep, "KKB", false){}
	void attackOutput(std::string Mname){output( " shanks " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Knife(stat, lvl);}
};

struct Club : public Item {
	Club(int lvl) : Item("Club", getValInRange(3, 9), lvl,  paladin, uncommon, wep, "CL", true) {}
Club(int stat, int lvl) : Item("Club", stat, lvl, paladin, uncommon, wep, "CL", false){}
	void attackOutput(std::string Mname){output( " goes clubbing with " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Club(stat, lvl);}
};

struct Pretzel : public Item {
	Pretzel(int lvl) : Item("Pretzel", getValInRange(3, 9), lvl,  paladin, uncommon, wep, "PC", true) {}
Pretzel(int stat, int lvl) : Item("Pretzel", stat, lvl, paladin, uncommon, wep, "PC", false){}
	void attackOutput(std::string Mname){output( " clubs " + Mname + " with " + name + " leaving them salty", true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Pretzel(stat, lvl);}
};

struct Candycanesword : public Item {
	Candycanesword(int lvl) : Item("Candy Cane Sword", getValInRange(3, 9), lvl,  paladin, uncommon, wep, "CCSCCS", true) {}
Candycanesword(int stat, int lvl) : Item("Candy Cane Sword", stat, lvl, paladin, uncommon, wep, "CCSCCS", false){}
	void attackOutput(std::string Mname){output( " licks " + Mname + " with " + name + ", leaving them in less than mint condition", true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Candycanesword(stat, lvl);}
};

struct Scythe : public Item {
	Scythe(int lvl) : Item("Scythe", getValInRange(3, 9), lvl,  paladin, uncommon, wep, "SWS", true) {}
Scythe(int stat, int lvl) : Item("Scythe", stat, lvl, paladin, uncommon, wep, "SWS", false){}
	void attackOutput(std::string Mname){output( " harvests " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Scythe(stat, lvl);}
};

struct Bayonet : public Item {
	Bayonet(int lvl) : Item("Bayonet", getValInRange(5, 11), lvl,  paladin, rare, wep, "BNOB", true) {}
Bayonet(int stat, int lvl) : Item("Bayonet",stat, lvl, paladin, rare, wep, "BNOB", false){}
	void attackOutput(std::string Mname){output( " eviscerates " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Bayonet(stat, lvl);}
};

struct Trident : public Item {
	Trident(int lvl) : Item("Trident", getValInRange(5, 11), lvl,  paladin, rare, wep, "TLS", true) {}
Trident(int stat, int lvl) : Item("Trident", stat, lvl, paladin, rare, wep, "TLS", false){}
	void attackOutput(std::string Mname){output( " sticks a giant fork in " + Mname + ", they’re done", true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Trident(stat, lvl);}
};

struct Tinyhammer : public Item {
	Tinyhammer(int lvl) : Item("Tiny Hammer", getValInRange(5, 11), lvl,  paladin, rare, wep, "THHH", true) {}
Tinyhammer(int stat, int lvl) : Item("Tiny Hammer", stat, lvl, paladin, rare, wep, "THHH", false){}
	void attackOutput(std::string Mname){output( " lightly hammers " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Tinyhammer(stat, lvl);}
};

struct Flipflop : public Item {
	Flipflop(int lvl) : Item("Flip Flop", getValInRange(5, 11), lvl,  paladin, rare, wep, "FFLFF", true) {}
Flipflop(int stat, int lvl) : Item("Flip Flop", stat, lvl, paladin, rare, wep, "FFLFF", false){}
	void attackOutput(std::string Mname){output( "flips " + Mname + ", they flop", true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Flipflop(stat, lvl);}
};

struct Chainsaw : public Item {
	Chainsaw(int lvl) : Item("Chainsaw", getValInRange(7, 13), lvl,  paladin, veryrare, wep, "CLB", true) {}
Chainsaw(int stat, int lvl) : Item("Chainsaw", stat, lvl, paladin, veryrare, wep, "CLB", false){}
	void attackOutput(std::string Mname){output( " saws through " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Chainsaw(stat, lvl);}
};

struct Treebranch : public Item {
	Treebranch(int lvl) : Item("Tree Branch", getValInRange(7, 13), lvl,  paladin, veryrare, wep, "TBULL", true) {}
Treebranch(int stat, int lvl) : Item("Tree Branch", stat, lvl, paladin, veryrare, wep, "TBULL", false){}
	void attackOutput(std::string Mname){output( " stops " + Mname + " from branching out", true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Treebranch(stat, lvl);}
};

struct Arm : public Item {
	Arm(std::string name, int lvl) : Item(name + "'s Arm", getValInRange(7, 13), lvl, paladin, veryrare, wep, "AL", true){}
	Arm(std::string name, int stat, int lvl) : Item(name + "'s Arm",stat , lvl, paladin, veryrare, wep, "AL", false){}
	void attackOutput(std::string Mname){output( " is very armed, it psychologically damages " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Arm(name.substr(0, name.find("'s Arm")), stat, lvl);}
};

struct Excalibur : public Item {
	Excalibur(int lvl) : Item("Excalibur", getValInRange(9, 15), lvl,  paladin, legendary, wep, "ES", true) {}
Excalibur(int stat, int lvl) : Item("Excalibur", stat, lvl, paladin, legendary, wep, "ES", false){}
	void attackOutput(std::string Mname){output( " burns " + Mname + " with a holy passion", true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Excalibur(stat, lvl);}
};

struct Smashingboard : public Item {
	Smashingboard(int lvl) : Item("Smashing Board", getValInRange(9, 15), lvl,  paladin, legendary, wep, "SBGR", true) {}
Smashingboard(int stat, int lvl) : Item("Smashing Board", stat, lvl, paladin, legendary, wep, "SBGR", false){}
	void attackOutput(std::string Mname){output( " smashes " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Smashingboard(stat, lvl);}
};

struct Schlong : public Item {
	Schlong(std::string name, int atk) : Item(name + "'s Schlong", atk,1, paladin, unique, wep, "SS", false){}
	void attackOutput(std::string Mname){output( " hobknocks " + Mname + " with " + name, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Schlong(name.substr(0, name.find("'s Schlong")), stat);}
};

struct RustyShield : public Item {
	RustyShield() : Item("Rusty Shield", 3, 1,paladin, common, shi, "RSRS", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new RustyShield();}
};

struct Smalllog : public Item {
	Smalllog(int lvl) : Item("Small Log", getValInRange(1, 7), lvl,  paladin, common, shi, "ASL", true) {}
Smalllog(int stat, int lvl) : Item("Small Log", stat, lvl,paladin, common, shi, "ASL", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Smalllog(stat, lvl);}
};

struct Gauntlet : public Item {
	Gauntlet(int lvl) : Item("Gauntlet", getValInRange(1, 7), lvl,  paladin, common, shi, "MG", true) {}
Gauntlet(int stat, int lvl) : Item("Gauntlet", stat, lvl,paladin, common, shi, "MG", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Gauntlet(stat, lvl);}
};

struct Cartwheel : public Item {
	Cartwheel(int lvl) : Item("Cart Wheel", getValInRange(1, 7), lvl,  paladin, common, shi, "SCW", true) {}
Cartwheel(int stat, int lvl) : Item("Cart Wheel", stat, lvl, paladin, common, shi, "SCW", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Cartwheel(stat, lvl);}
};

struct Fishnets : public Item {
	Fishnets(int lvl) : Item("Fishnets", getValInRange(1, 7), lvl,  paladin, common, shi, "WF", true) {}
Fishnets(int stat, int lvl) : Item("Fishnets", stat, lvl, paladin, common, shi, "WF", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Fishnets(stat, lvl);}
};

struct Knifeblock : public Item {
	Knifeblock(int lvl) : Item("Knife Block", getValInRange(1, 7), lvl,  paladin, common, shi, "KKB", true) {}
Knifeblock(int stat, int lvl) : Item("Knife Block", stat, lvl, paladin, common, shi, "KKB", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Knifeblock(stat, lvl);}
};

struct Loincloth : public Item {
	Loincloth(int lvl) : Item("Loincloth", getValInRange(3, 9), lvl,  paladin, uncommon, shi, "CL", true) {}
Loincloth(int stat, int lvl) : Item("Loincloth", stat, lvl, paladin, uncommon, shi, "CL", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Loincloth(stat, lvl);}
};

struct Chip : public Item {
	Chip(int lvl) : Item("Chip", getValInRange(3, 9), lvl,  paladin, uncommon, shi, "PC", true) {}
Chip(int stat, int lvl) : Item("Chip", stat, lvl, paladin, uncommon, shi, "PC", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Chip(stat, lvl);}
};

struct Candycaneshield : public Item {
	Candycaneshield(int lvl) : Item("Candy Cane Shield", getValInRange(3, 9), lvl,  paladin, uncommon, shi, "CCSCCS", true) {}
Candycaneshield(int stat, int lvl) : Item("Candy Cane Shield", stat, lvl, paladin, uncommon, shi, "CCSCCS", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Candycaneshield(stat, lvl);}
};

struct Wheatstalk : public Item {
	Wheatstalk(int lvl) : Item("Wheat Stalk", getValInRange(3, 9), lvl,  paladin, uncommon, shi, "SWS", true) {}
Wheatstalk(int stat, int lvl) : Item("Wheat Stalk", stat, lvl, paladin, uncommon, shi, "SWS", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Wheatstalk(stat, lvl);}
};

struct Netobay : public Item {
	Netobay(int lvl) : Item("Net-o'-bay", getValInRange(5, 11), lvl,  paladin, rare, shi, "BNOB", true) {}
Netobay(int stat, int lvl) : Item("Net-o'-bay", stat, lvl, paladin, rare, shi, "BNOB", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Netobay(stat, lvl);}
};

struct Largespoon : public Item {
	Largespoon(int lvl) : Item("Large Spoon", getValInRange(5, 11), lvl,  paladin, rare, shi, "TLS", true) {}
Largespoon(int stat, int lvl) : Item("Large Spoon", stat, lvl, paladin, rare, shi, "TLS", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Largespoon(stat, lvl);}
};

struct Hardhat : public Item {
	Hardhat(int lvl) : Item("Hard Hat", getValInRange(5, 11), lvl,  paladin, rare, shi, "THHH", true) {}
Hardhat(int stat, int lvl) : Item("Hard Hat", stat, lvl, paladin, rare, shi, "THHH", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Hardhat(stat, lvl);}
};

struct Largefoamfinger : public Item {
	Largefoamfinger(int lvl) : Item("Large Foam Finger", getValInRange(5, 11), lvl,  paladin, rare, shi, "FFLFF", true) {}
Largefoamfinger(int stat, int lvl) : Item("Large Foam Finger", stat, lvl, paladin, rare, shi, "FFLFF", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Largefoamfinger(stat, lvl);}
};

struct Leafblower : public Item {
	Leafblower(int lvl) : Item("Leaf Blower", getValInRange(7, 13), lvl,  paladin, veryrare, shi, "CLB", true) {}
Leafblower(int stat, int lvl) : Item("Leaf Blower", stat, lvl, paladin, veryrare, shi, "CLB", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Leafblower(stat, lvl);}
};

struct Unusuallylargeleaf : public Item {
	Unusuallylargeleaf(int lvl) : Item("Unusually Large Leaf", getValInRange(7, 13), lvl,  paladin, veryrare, shi, "TBULL", true) {}
Unusuallylargeleaf(int stat, int lvl) : Item("Unusually Large Leaf", stat, lvl, paladin, veryrare, shi, "TBULL", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Unusuallylargeleaf(stat, lvl);}
};

struct Leg : public Item {
	Leg(std::string name, int lvl) : Item(name + "'s Leg", getValInRange(7, 13), lvl, paladin, veryrare, shi, "AL", true){}
	Leg(std::string name, int stat, int lvl) : Item(name + "'s Leg",stat , lvl, paladin, veryrare, shi, "AL", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Leg(name.substr(0, name.find("'s Leg")), stat, lvl);}
};

struct Svalinn : public Item {
	Svalinn(int lvl) : Item("Svalinn", getValInRange(9, 15), lvl,  paladin, legendary, shi, "ES", true) {}
Svalinn(int stat, int lvl) : Item("Svalinn", stat, lvl, paladin, legendary, shi, "ES", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Svalinn(stat, lvl);}
};

struct Guardingrod : public Item {
	Guardingrod(int lvl) : Item("Guarding Rod", getValInRange(9, 15), lvl,  paladin, legendary, shi, "SBGR", true) {}
Guardingrod(int stat, int lvl) : Item("Guarding Rod", stat, lvl, paladin, legendary, shi, "SBGR", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Guardingrod(stat, lvl);}
};

struct Schlort : public Item {
	Schlort(std::string name, int atk) : Item(name + "'s Schlort", atk,1, paladin, unique, shi, "SS", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Schlort(name.substr(0, name.find("'s Schlort")), stat);}
};

#endif