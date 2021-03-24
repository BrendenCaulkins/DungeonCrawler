#ifndef ANDROIDITEMS_H
#define ANDROIDITEMS_H

#include "Items.h"

struct Glowstick : public Item {
	Glowstick() : Item("Glow Stick", 3, 1, android, common, wep, "GSAC", false){}
	void attackOutput(std::string Mname){output(" whacks " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Glowstick();}
};

struct Leek : public Item {
	Leek(int lvl) : Item("Leek", getValInRange(1,7), lvl, android, common, wep, "LO", true) {}
	Leek(int stat, int lvl) : Item("Leek",stat, lvl , android, common, wep, "LO", false){}
	void attackOutput(std::string Mname){output(" Miku Miku's " + Mname + ", they cannot stop dancing", true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Leek(stat, lvl);}
};

struct Recorder : public Item {
	Recorder(int lvl) : Item("Recorder", getValInRange(1,7), lvl, android, common, wep, "RSM",true){}
 Recorder(int stat, int lvl) : Item("Recorder",stat,lvl , android, common, wep, "RSM", false){}
	void attackOutput(std::string Mname){output(" plays an off-key tune which annoys " + Mname + ", distracting them long enough to kick", true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Recorder(stat, lvl);}
};

struct Tunafish : public Item {
	Tunafish(int lvl) : Item("Tuna Fish", getValInRange(1,7), lvl, android, common, wep, "TFCB", true) {}
 Tunafish(int stat, int lvl) : Item("Tuna Fish",stat, lvl , android, common, wep, "TFCB", false){}
	void attackOutput(std::string Mname){output(" slaps " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Tunafish(stat, lvl);}
};

struct Popscicle : public Item {
	Popscicle(int lvl) : Item("Popscicle", getValInRange(1,7), lvl, android, common, wep, "PPD", true) {}
 Popscicle(int stat, int lvl) : Item("Popscicle",stat, lvl , android, common, wep, "PPD", false){}
	void attackOutput(std::string Mname){output(" jabs " + Mname + " in the eye", true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Popscicle(stat, lvl);}
};

struct Sakebottle : public Item {
	Sakebottle(int lvl) : Item("Sake Bottle", getValInRange(1,7), lvl, android, common, wep, "SBGSG", true) {}
 Sakebottle(int stat, int lvl) : Item("Sake Bottle", stat, lvl , android, common, wep, "SBGSG", false){}
	void attackOutput(std::string Mname){output(" smashes the " + name + " over " +  Mname + "'s' head", true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Sakebottle(stat, lvl);}
};

struct Guitar : public Item {
	Guitar(int lvl) : Item("Guitar", getValInRange(3,9), lvl, android, uncommon, wep, "GA", true) {}
 Guitar(int stat, int lvl) : Item("Guitar", stat, lvl , android, uncommon, wep, "GA", false){}
	void attackOutput(std::string Mname){output(" bashes " + name + " into " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Guitar(stat, lvl);}
};

struct Lance : public Item {
	Lance(int lvl) : Item("Lance", getValInRange(3,9), lvl, android, uncommon, wep, "LHA", true) {}
 Lance(int stat, int lvl) : Item("Lance", stat, lvl, android, uncommon, wep, "LHA", false){}
	void attackOutput(std::string Mname){output(" impales " + Mname + ", poking them in the eye", true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Lance(stat, lvl);}
};

struct Micstand : public Item {
	Micstand(int lvl) : Item("Mic Stand", getValInRange(3,9), lvl, android, uncommon, wep, "MSCW", true) {}
 Micstand(int stat, int lvl) : Item("Mic Stand", stat, lvl, android, uncommon, wep, "MSCW", false){}
	void attackOutput(std::string Mname){output(" konks " + Mname + " on the head", true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Micstand(stat, lvl);}
};

struct Flipphone : public Item {
	Flipphone(int lvl) : Item("Flip Phone", getValInRange(3,9), lvl, android, uncommon, wep, "FPA", true) {}
 Flipphone(int stat, int lvl) : Item("Flip Phone", stat, lvl, android, uncommon, wep, "FPA", false){}
	void attackOutput(std::string Mname){output(" makes a call and a trained lethal assassin attacks "+ Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Flipphone(stat, lvl);}
};

struct Keytar : public Item {
	Keytar(int lvl) : Item("Keytar", getValInRange(5,11), lvl, android, rare, wep, "KG", true) {}
 Keytar(int stat, int lvl) : Item("Keytar", stat, lvl, android, rare, wep, "KG", false){}
	void attackOutput(std::string Mname){output(" keys " + Mname + " in the face", true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Keytar(stat, lvl);}
};

struct Keyboard : public Item {
	Keyboard(int lvl) : Item("Keyboard", getValInRange(5,11), lvl, android, rare, wep, "KD", true) {}
 Keyboard(int stat, int lvl) : Item("Keyboard", stat, lvl, android, rare, wep, "KD", false){}
	void attackOutput(std::string Mname){output(" makes a scalding callout post about " + Mname + ", hurting their self-esteem", true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Keyboard(stat, lvl);}
};

struct Roadroller : public Item {
	Roadroller(int lvl) : Item("Road Roller", getValInRange(5,11), lvl, android, rare, wep, "RRGR", true) {}
 Roadroller(int stat, int lvl) : Item("Road Roller", stat, lvl, android, rare, wep, "RRGR", false){}
	void attackOutput(std::string Mname){output(" runs over " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Roadroller(stat, lvl);}
};

struct Microphone : public Item {
	Microphone(int lvl) : Item("Microphone", getValInRange(5,11), lvl, android, rare, wep, "MNCH", true) {}
 Microphone(int stat, int lvl) : Item("Microphone", stat, lvl, android, rare, wep, "MNCH", false){}
	void attackOutput(std::string Mname){output(" sings and makes " + Mname + "'s ears bleed", true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Microphone(stat, lvl);}
};

struct Musicalkatana : public Item {
	Musicalkatana(int lvl) : Item("Musical Katana", getValInRange(7,13), lvl, android, veryrare, wep, "MKOKA", true) {}
 Musicalkatana(int stat, int lvl) : Item("Musical Katana", stat, lvl, android, veryrare, wep, "MKOKA", false){}
	void attackOutput(std::string Mname){output(" slashes " + Mname + " and creates a beautiful melody", true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Musicalkatana(stat, lvl);}
};

struct Songofdeath : public Item {
	Songofdeath(int lvl) : Item("Song of Death", getValInRange(7,13), lvl, android, veryrare, wep, "SODSOS", true) {}
 Songofdeath(int stat, int lvl) : Item("Song of Death", stat, lvl, android, veryrare, wep, "SODSOS", false){}
	void attackOutput(std::string Mname){output(" recites the " + name + ", causing " + Mname + "to falter and trip out of fear", true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Songofdeath(stat, lvl);}
};

struct Hair : public Item {
	Hair(std::string name, int lvl) : Item(name + "'s Hair", getValInRange(7,13), lvl, android, veryrare, wep, "HEH", true){}
	Hair(std::string name, int stat, int lvl) : Item(name + "'s Hair", stat, lvl, android, veryrare, wep, "HEH", false) {}
	void attackOutput(std::string Mname){output(" strangles " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Hair(name.substr(0, name.find("'s Hair")), stat, lvl);}
};

struct Shiteyanyoform : public Item {
	Shiteyanyoform(int lvl) : Item("Shiteyanyo Form", getValInRange(9,15), lvl, android, legendary, wep, "SFDF", true) {}
 Shiteyanyoform(int stat, int lvl) : Item("Shiteyanyo Form", stat, lvl, android, legendary, wep, "SFDF", false){}
	void attackOutput(std::string Mname){output(" charges " + Mname + ", kicking them and causing psychological damage simultaneously", true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Shiteyanyoform(stat, lvl);}
};

struct Squirtgun : public Item {
	Squirtgun(int lvl) : Item("Squirt Gun", getValInRange(9,15), lvl, android, legendary, wep, "SGU", true) {}
 Squirtgun(int stat, int lvl) : Item("Squirt Gun", stat, lvl, android, legendary, wep, "SGU", false){}
	void attackOutput(std::string Mname){output(" squirts " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Squirtgun(stat, lvl);}
};

struct Soul : public Item {
	Soul(std::string name, int atk) : Item(name + "'s Soul", atk ,1, android, unique, wep, "SB3", false){}
	void attackOutput(std::string Mname){output(" puts some soul into a song about " + Mname, true);}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Soul(name.substr(0, name.find("'s Soul")), stat);}
};

struct Asslesschaps : public Item {
	Asslesschaps() : Item("Assless Chaps", 3, 1, android, common, shi, "GSAC", true){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Asslesschaps();}
};

struct Onion : public Item {
	Onion(int lvl) : Item("Onion", getValInRange(1, 7), lvl, android, common, shi, "LO", true) {}
 Onion(int stat, int lvl) : Item("Onion", stat, lvl, android, common, shi, "LO", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Onion(stat, lvl);}
};

struct Sheetmusic : public Item {
	Sheetmusic(int lvl) : Item("Sheet Music", getValInRange(1, 7), lvl, android, common, shi, "RSM", true) {}
 Sheetmusic(int stat, int lvl) : Item("Sheet Music",stat , lvl, android, common, shi, "RSM", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Sheetmusic(stat, lvl);}
};

struct Cuttingboard : public Item {
	Cuttingboard(int lvl) : Item("Cutting Board", getValInRange(1, 7), lvl, android, common, shi, "TFCB", true) {}
 Cuttingboard(int stat, int lvl) : Item("Cutting Board", stat, lvl, android, common, shi, "TFCB", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Cuttingboard(stat, lvl);}
};

struct Popscicledepressor : public Item {
	Popscicledepressor(int lvl) : Item("Popscicle Depressor", getValInRange(1, 7), lvl, android, common, shi, "PPD", true) {}
 Popscicledepressor(int stat, int lvl) : Item("Popscicle Depressor", stat, lvl, android, common, shi, "PPD", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Popscicledepressor(stat, lvl);}
};

struct Giantshotglass : public Item {
	Giantshotglass(int lvl) : Item("Giant Shot Glass", getValInRange(1, 7), lvl, android, common, shi, "SBGSG", true) {}
 Giantshotglass(int stat, int lvl) : Item("Giant Shot Glass",stat,lvl , android, common, shi, "SBGSG", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Giantshotglass(stat, lvl);}
};

struct Amp : public Item {
	Amp(int lvl) : Item("Amp", getValInRange(3, 9), lvl, android, uncommon, shi, "GA", true) {}
 Amp(int stat, int lvl) : Item("Amp", stat, lvl, android, uncommon, shi, "GA", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Amp(stat, lvl);}
};

struct Horsearmor : public Item {
	Horsearmor(int lvl) : Item("Horse Armor", getValInRange(3, 9), lvl, android, uncommon, shi, "LHA", true) {}
 Horsearmor(int stat, int lvl) : Item("Horse Armor", stat, lvl , android, uncommon, shi, "LHA", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Horsearmor(stat, lvl);}
};

struct Comedicwits : public Item {
	Comedicwits(int lvl) : Item("Comedic Wits", getValInRange(3, 9), lvl, android, uncommon, shi, "MSCW", true) {}
 Comedicwits(int stat, int lvl) : Item("Comedic Wits", stat, lvl, android, uncommon, shi, "MSCW", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Comedicwits(stat, lvl);}
};

struct Antenna : public Item {
	Antenna(int lvl) : Item("Antenna", getValInRange(3, 9), lvl, android, uncommon, shi, "FPA", true) {}
 Antenna(int stat, int lvl) : Item("Antenna",stat ,lvl , android, uncommon, shi, "FPA", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Antenna(stat, lvl);}
};

struct Glockenspiel : public Item {
	Glockenspiel(int lvl) : Item("Glockenspiel", getValInRange(5, 11), lvl, android, rare, shi, "KG", true) {}
 Glockenspiel(int stat, int lvl) : Item("Glockenspiel", stat, lvl, android, rare, shi, "KG", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Glockenspiel(stat, lvl);}
};

struct Desk : public Item {
	Desk(int lvl) : Item("Desk", getValInRange(5, 11), lvl, android, rare, shi, "KD", true) {}
 Desk(int stat, int lvl) : Item("Desk", stat, lvl, android, rare, shi, "KD", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Desk(stat, lvl);}
};

struct Giantrock : public Item {
	Giantrock(int lvl) : Item("Giant Rock", getValInRange(5, 11), lvl, android, rare, shi, "RRGR", true) {}
 Giantrock(int stat, int lvl) : Item("Giant Rock", stat, lvl, android, rare, shi, "RRGR", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Giantrock(stat, lvl);}
};

struct Noisecancellingheadphones : public Item {
	Noisecancellingheadphones(int lvl) : Item("Noise-Cancelling Headphones", getValInRange(5, 11), lvl, android, rare, shi, "MNCH", true) {}
 Noisecancellingheadphones(int stat, int lvl) : Item("Noise-Cancelling Headphones", stat, lvl, android, rare, shi, "MNCH", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Noisecancellingheadphones(stat, lvl);}
};

struct Offkeyarmor : public Item {
	Offkeyarmor(int lvl) : Item("Off-Key Armor", getValInRange(7, 13), lvl, android, veryrare, shi, "MKOKA", true) {}
 Offkeyarmor(int stat, int lvl) : Item("Off-Key Armor", stat, lvl, android, veryrare, shi, "MKOKA", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Offkeyarmor(stat, lvl);}
};

struct Songofsteadfastedness : public Item {
	Songofsteadfastedness(int lvl) : Item("Song of Steadfastedness", getValInRange(7, 13), lvl, android, veryrare, shi, "SODSOS", true) {}
 Songofsteadfastedness(int stat, int lvl) : Item("Song of Steadfastedness",stat , lvl, android, veryrare, shi, "SODSOS", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Songofsteadfastedness(stat, lvl);}
};

struct Enlargedhairbrush : public Item {
	Enlargedhairbrush(std::string name, int lvl) : Item(name + "'s Enlarged Hairbrush", getValInRange(7, 13), lvl, android, veryrare, shi, "HEH", true){}
	Enlargedhairbrush(std::string name, int stat, int lvl) : Item(name + "'s Enlarged Hairbrush",stat , lvl, android, veryrare, shi, "HEH", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Enlargedhairbrush(name.substr(0, name.find("'s Enlarged Hairbrush")), stat, lvl);}
};

struct Dickbuttform : public Item {
	Dickbuttform(int lvl) : Item("Dickbutt Form", getValInRange(9, 15), lvl, android, legendary, shi, "SFDF", true) {}
 Dickbuttform(int stat, int lvl) : Item("Dickbutt Form", stat, lvl, android, legendary, shi, "SFDF", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Dickbuttform(stat, lvl);}
};

struct Umbrella : public Item {
	Umbrella(int lvl) : Item("Umbrella", getValInRange(9, 15), lvl, android, legendary, shi, "SGU", true) {}
 Umbrella(int stat, int lvl) : Item("Umbrella", stat, lvl, android, legendary, shi, "SGU", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Umbrella(stat, lvl);}
};

struct Body : public Item {
	Body(std::string name, int atk) : Item(name + "'s Body", atk,1, android, unique, shi, "SB3", false){}
	virtual Item* grabFromStack(int i){int stat = statStack.statat(i), lvl = statStack.lvlat(i); if(statStack.deleteat(i)<0){return nullptr;}return new Body(name.substr(0, name.find("'s Body")), stat);}
};

#endif