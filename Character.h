#ifndef CHARACTER_H
#define CHARACTER_H

enum Type {PALADIN, WIZARD, ARCHER, ANDROID, TAMER, MONSTER, INTERN, FIGHTER};

#include "includeItems.h"
#include "extraFunctions.h"
#include <iostream>
#include <fstream>
#include <vector>

const int MAX_LVL = 100;
class Character {
protected:
	int hp, max_hp;
	int spd, atk, def;
	int lvl, exp, lvlUP;
	int critChance, accuracy, evasion;
	double critMultiplier;
	int wallet;
	std::string name;
	Type type;
	Item *Weapon, *Defensive;
	bool isTamed;
public:
	 Character(Type type, std::string name, int hp, int spd, int atk, int def, int critChance, double critMultiplier, int accuracy, int evasion) : type(type), name(name), max_hp(hp), hp(hp), spd(spd), atk(atk), def(def), lvl(1), exp(0), lvlUP(20), wallet(30), critChance(critChance), critMultiplier(critMultiplier), accuracy(accuracy), evasion(evasion), isTamed(false) {Weapon = nullptr; Defensive = nullptr;}
	 Character(Type type, std::string name, int hp, int mhp,int lvl,int spd, int atk,int def,int wallet,int exp,int lvlup, int critChance, double critMultiplier, int accuracy, int evasion, Item* W,Item* D): type(type), name(name), max_hp(mhp), hp(hp), lvl(lvl), spd(spd), atk(atk), def(def), exp(exp), lvlUP(lvlup), wallet(wallet), Weapon(W), Defensive(D), critChance(critChance), critMultiplier(critMultiplier), accuracy(accuracy), evasion(evasion), isTamed(false) {}
	~Character(){if(hasWeapon()){delete Weapon;}if(hasDefensive()){delete Defensive;}}
    bool isAlive() const;
    virtual void attack(Character &, int);
	virtual void displayStats();
	std::string getName() {return name;}
	virtual std::string getType();
	int getLVL() {return lvl;}
	int getHP() {return hp;}
	int getMHP() {return max_hp;}
	int getAtk() {return atk;}
	int getDef() {return def;}
	int getSpd() {return spd;}
	int getExp() {return exp;}
	int getLvLUp() {return lvlUP;}
	int getWallet() {return wallet;}
	virtual int getCritChance() {return critChance;}
	virtual double getCritMultiplier() {return critMultiplier;}
	virtual int getAccuracy() {return accuracy;}
	virtual int getEvasion() {return evasion;}
	Item* getWeapon() {return Weapon;}
	Item* getDefensive() {return Defensive;}
	void buy(int l = 0) {wallet -= l;}
	void sold(int g = 0) {wallet += g;}
	void gainHP(int gain);
	void gainMaxHP(int gain);
	void gainAtk(int gain);
	void gainDef(int gain);
	void gainSpd(int gain);
	bool fullHP();
	virtual void lvlTO(int lvl) {return;}
	virtual Item* equipItem(Item*temp);
	virtual std::vector <Item*> dropItems(int& money) {std::vector <Item*> k; return k;}
	void displayWeapon();
	void displayDefensive();
	Item* unequipDefensive();
	Item* unequipWeapon();
	virtual void encounterOutput() {return;}
	virtual bool isTamer() {return false;}
	virtual bool isChaos(){return false;}
	virtual bool tameMonster(Character&){return false;}
	virtual Item* Monstertamed(std::string, Character&){return nullptr;}
	virtual void changeName(std::string name) {return;}
	bool hasWeapon() {if(Weapon != nullptr){return true;}return false;}
	bool hasDefensive() {if(Defensive != nullptr){return true;}return false;}
	virtual std::string getCreature() {return"null";}
	virtual void interactOutput() {return;}
	bool run(Character&);
	void kill(){hp = 0;}
	void setHP(int j) {hp = j;}
	virtual Character* spawnMon() {return nullptr;}
	virtual bool isMon() {return false;}
	void tame(){isTamed = true;}

protected:
	void displayBonuses(int ghp, int gspd, int gatk, int gdef);
	virtual void attackOutput(Character &defense){output(name + " decks " + defense.getName(), true);}
	int calcDamage(Character & defense);
	void gainEXP(Character &corpse);
	virtual void gainLVL() = 0;
	virtual int expCalc(int pLVL) {return 0;}
	virtual Item* equipDefensive(Item *nDefensive);
	virtual Item* equipWeapon(Item*);
	void damage(std::string victoryOutput, int dmg);
	std::string victoryOutput(Character& mon);
};



#endif