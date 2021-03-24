#ifndef MONSTERTAMER_H
#define MONSTERTAMER_H
#include "includeMonsters.h"
#include "Character.h"
#include "extraFunctions.h"
class TamedMonster : public Item {
	private:
	Character* tamed;
	public:
	TamedMonster(std::string nName, Character &newMon) : Item (nName, newMon.getAtk(), newMon.getLVL(), Tamed, unique, wep, "MONS", false) {tamed =&newMon; newMon.changeName(nName);newMon.tame();}
	~TamedMonster() {delete tamed;}
	void displayItem() {tamed -> displayStats();}
	std::string showInBag() {return tamed -> getName() + " Species: " + getType();}
	Character* getMon() {return tamed;}
	std::string getType() {return tamed -> getCreature();}
	bool isMon() {return true;}
	virtual Item* grabFromStack(){statStack.pop_back();return new TamedMonster(name, *tamed->spawnMon());}
};


class MonsterTamer : public Character {
public:
	MonsterTamer(std::string name);
	MonsterTamer(std::string name, int hp, int mhp,int lvl,int spd, int atk,int def,int wallet,int exp,int lvlup,Item* W,Item* D):Character(TAMER, name, hp, mhp, lvl, spd, atk, def, wallet, exp, lvlup, /*critChance*/ 2, /*critMultiplier*/ 2.5, /*accuracy*/ 80, /*evasion*/ 20,W, D){}
	void attack(Character& defense, int numAtk);
	bool tameMonster(Character&);
	Item* Monstertamed(std::string nickname, Character&);
	bool isTamer() {return true;}
	private:
	void gainLVL();
	Item* equipWeapon(Item *nWeapon);
	void attackOutput(Character& defense) {output(name + " flails arms at " + defense.getName(), false);}
};

#endif