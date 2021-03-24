#ifndef ITEMS_H
#define ITEMS_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "extraFunctions.h"
// #include "Character.h"
/*ANY CHANGES TO NAMES OR NEW ITEMS SHOULD BE ADDED TO MONSTER.CPP SHOP.CPP GAMESL.H(names & new items)*/
//each classes item's are stored in their own file for easier sorting and smaller files
enum classtype {paladin, wizard, archer, android, Tamed, potion, ingredient, book};

enum rarity {common, uncommon, rare, veryrare, legendary, unique};

enum wepshi {wep, shi, nei};

class Character;
class recipe;

struct lvlstat{
	int lvl, stat;
	lvlstat(int stat, int lvl) : lvl(lvl), stat(stat) {};
};

struct itemStack {
	private:
	std::vector<lvlstat> ls;
	public:
	int lvlat(int i){
		if(i > ls.size()){
			output("unable to complete action", false);
			return -1;
		}
		return ls.at(i).lvl;
	}
	int statat(int i){
		if(i > ls.size()){
			output("unable to complete action", false);
		}
		return ls.at(i).stat;
	}
	int size(){
		return ls.size();
	}
	lvlstat at(int i){
		if(i > ls.size()){
			output("unable to complete action", false);
			return lvlstat(-1, -1);
		}
		return ls.at(i);
	}
	void push_back(lvlstat i){
		ls.push_back(i);
		sort();
	}
	void push_back(int stat, int lvl){
		ls.push_back(lvlstat(stat, lvl));
		sort();
	}
	void push_back(itemStack j){
		for(unsigned i = 0; i < j.size(); ++i){
			ls.push_back(j.at(i));
		}
	}
	void pop_back(){
		ls.pop_back();
	}
	int deleteat(int i){
		if(i > ls.size()){
			output("unable to complete action", false);
			return -1;
		}
		ls.erase(ls.begin() + i);
		return 0;
	}
	
	void toFile(std::ofstream& ofs){
		for(unsigned i = 0; i < ls.size(); ++i){
			ofs << statat(i) << std::endl << lvlat(i) << std::endl;
		}
	}
	void toFile(std::ofstream& ofs, int i){
		ofs << statat(i) << std::endl << lvlat(i) << std::endl;
	}
	void sort(){
		int jindx;
	for(unsigned i = 0; i < ls.size(); ++i){
		jindx = i;
		for(unsigned j = i+1; j < ls.size(); ++j){
			if(ls.at(j).lvl < ls.at(jindx).lvl){
				jindx = j;
			}
		}
		std::swap(ls.at(jindx), ls.at(i));
	}
	}
};

class Item {
protected:
	std::string name;
	itemStack statStack;
// 	int lvl, stat, numStacked;
	classtype type;
	rarity chance;
	wepshi stuff;
	std::string pairCode;
public:
	Item(std::string name, int baseStat, int lvl, classtype type, rarity chance, wepshi stuff, std::string pairCode, bool needsToLvl) : name(name), type(type), chance(chance), stuff(stuff), pairCode(pairCode) {if(needsToLvl){lvlTo(lvl, baseStat);}else{statStack.push_back(baseStat, lvl);}};
// 	Item(std::string name, int stat, int lvl, classtype type, rarity chance, wepshi stuff, std::string pairCode) : name(name), type(type), chance(chance), stuff(stuff), pairCode(pairCode) {statStack.push_back(stat, lvl);};
	
	bool operator!=(Item& rhs);
	bool operator ==(Item& rhs);
	bool operator <(Item& rhs);
	bool isPair(Item&);
	
	virtual void displayItem();
	virtual std::string showInBag(){return (name + " Class: " + getType() + " - " + std::to_string(getNum()));}
	std::string getName() {return name;}
	virtual int getStat() {if(getNum() == 1){return statStack.statat(0);}output("should not be accessing stat here", false);return -1;}
	virtual int getVal(int i = 0) {return statStack.statat(i);}//returns stat for shop to be able to buy/sell at diff value since potions have diff value than stat
	int getLVL() {if(getNum() == 1){return statStack.lvlat(0);}output("should not be accessing lvl here", false);return -1;}
	virtual int getNum() {return statStack.size();}//number stacked
	virtual int getCompVal() {return 69;}//comparison for sorting
	classtype iType() { return type;}
	wepshi wType() {return stuff;}
	bool isWeapon() {if(stuff == wep){return true;}return false;}
	bool isDefensive() {if(stuff == shi){return true;}return false;}
	virtual bool isEquippable(){return true;}
	virtual Item* grabFromStack();
	virtual Item* grabFromStack(int i){ return nullptr;}
	virtual void attackOutput(std::string){output("", false);}
	std::string getRare();
	virtual std::string getType();
	virtual void addToStack(int lvl, int stat = 0) {statStack.push_back(stat, lvl);return;}
	itemStack getStack() {return statStack;}
	virtual void addToStack(Item* d) {statStack.push_back(d->getStack());}
// 	void removeOne() {std::cout << }
	virtual bool isPotion() {return false;}
	virtual bool isIngredient() {return false;}
	/*monster tamer*/
	virtual Character* getMon() {return nullptr;}
	virtual bool isMon() {return false;}
	virtual void usePotion(Character*& p, int& invis, bool& tp, bool& chest) {return;}
	virtual void unUsePotion(Character*& p) {return;}
	void lvlTo(int l, int baseStat/*int minRange, int maxRange*/);
	virtual void toFile(std::ofstream& ofs){
		statStack.toFile(ofs, 0);
		ofs << getNum() << std::endl;
		for(unsigned i = 1; i < getNum(); ++i){
			statStack.toFile(ofs, i);
		}
	}
	//recipe book stuff
	virtual void enterBook(){return;}
	virtual void addRecipe(recipe* r){return;}
	virtual bool isBook(){return false;}
	virtual bool isFull() const {return false;}
	virtual bool has(recipe* rec) const{return false;}
	virtual int numPages() const {return -1;}
	virtual recipe* page(int i){return nullptr;}
	
	int statat(int i){
		return statStack.statat(i);
	}
	int lvlat(int i){
		return statStack.lvlat(i);
	}
};

Item* dropWeapon(std::string name, int atk, int lvl);
Item* dropDefensive(std::string name, int def, int lvl);





#endif