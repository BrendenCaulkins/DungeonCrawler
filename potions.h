#ifndef POTIONS_H
#define POTIONS_H

#include "Items.h"
#include "Character.h"
#include "Ingredients.h"
#include <cmath>

class Potion : public Item {
	protected:
	int numStacked, stat, val;
	public:
	Potion(std::string name, int stat, int val, int n) : Item(name, stat, 1, potion, common, nei, "POT", false), val(val), stat(stat) {if(n == 0){numStacked = 1;}else{numStacked=n;}}
	void displayItem(){if(numStacked > 0){output(name + " heals: " + std::to_string(stat) + " hp - " + std::to_string(numStacked), false);}}
	std::string showInBag(){if(numStacked > 0){return name +" heals: " + std::to_string(stat) + " hp - " + std::to_string(numStacked);} return "ERROR";}
	bool isPotion() {return true;}
	virtual void usePotion(Character*& p, int& invis, bool& tp, bool& chest);
	virtual void unUsePotion(Character*& p) {};
	virtual int getCompVal() = 0;
	int getStat(){return stat;}
	virtual Item* grabFromStack() = 0;
	virtual Item* grabFromStack(int n) = 0;
	int getNum(){return numStacked;}
	int getVal(int i){return val;}
	void addToStack(Item* p){numStacked += p -> getNum();}
	void addToStack(int lvl, int stat = 0) {numStacked += lvl;}
	virtual void toFile(std::ofstream& ofs){ofs << getNum() << std::endl;}
	virtual bool isEquippable(){return false;}
};


struct SalubriousDecoction : public Potion {
	SalubriousDecoction(int n = 0) : Potion("Salubrious Decoction", 30, 20, n){};
	int getCompVal() {return 0;}
	virtual Item* grabFromStack(){--numStacked; return new SalubriousDecoction();}
	virtual Item* grabFromStack(int n) {numStacked -= n; return new SalubriousDecoction(n);}
};

struct TonicForEupepsia : public Potion {
	TonicForEupepsia(int n = 0) : Potion("Tonic For Eupepsia", 70, 50, n) {};
	int getCompVal() {return 1;}
	virtual Item* grabFromStack(){--numStacked; return new TonicForEupepsia();}
	virtual Item* grabFromStack(int n) {numStacked -= n; return new TonicForEupepsia(n);}
};

struct LustinessTincture : public Potion {
	LustinessTincture(int n = 0) : Potion("Lustiness Tincture", 150, 90, n) {};
	int getCompVal() {return 2;}
	virtual Item* grabFromStack(){--numStacked; return new LustinessTincture();}
	virtual Item* grabFromStack(int n) {numStacked -= n; return new LustinessTincture(n);}
};

struct BrewofStamina : public Potion {
	BrewofStamina(int n = 0) : Potion("Brew of Stamina", 200, 150, n) {};
	int getCompVal() {return 3;}
	virtual Item* grabFromStack(){--numStacked; return new BrewofStamina();}
	virtual Item* grabFromStack(int n) {numStacked -= n; return new BrewofStamina(n);}
};

struct DraughtofVigor : public Potion {
	DraughtofVigor(int n = 0) : Potion("Draught of Vigor", 250, 200, n) {}; 
	int getCompVal() {return 4;}
	virtual Item* grabFromStack(){--numStacked; return new DraughtofVigor();}
	virtual Item* grabFromStack(int n) {numStacked -= n; return new DraughtofVigor(n);}
};

struct DragonsBreathLibation : public Potion {
	DragonsBreathLibation(int n = 0) : Potion("Dragon's Breath Libation", 2, 1000, n){};
	void usePotion(Character*& p, int& invis, bool& tp, bool& chest);
	int getCompVal() {return 5;}
	virtual Item* grabFromStack(){--numStacked; return new DragonsBreathLibation();}
	virtual Item* grabFromStack(int n) {numStacked -= n; return new DragonsBreathLibation(n);}
};

struct VitalityConcoction : public Potion {
	VitalityConcoction(int n = 0, int s = 0) : Potion("Vitality Concoction", s, 100, n) {};
	void displayItem(){if(numStacked > 0){output(name +" - " + std::to_string(numStacked) + "\nStop holding back with the adrenaline rush gained from drinking a sweet concoction of random stuff.", false);}}
	std::string showInBag(){if(numStacked > 0){return name + "  - " + std::to_string(numStacked);}return "ERROR";}
	void usePotion(Character*& p, int& invis, bool& tp, bool& chest);
	void unUsePotion(Character*& p);
	int getCompVal() {return 6;}
	virtual Item* grabFromStack(){--numStacked; return new VitalityConcoction(1, stat);}
	virtual Item* grabFromStack(int n) {numStacked -= n; return new VitalityConcoction(n, stat);}
};

struct VialofFortitude : public Potion {
	VialofFortitude(int n = 0) : Potion("Vial of Fortitude", 0, 100, n) {};
	void displayItem(){if(numStacked > 0){output(name +" - " + std::to_string(numStacked) +  "\nGo from twink to twunk with just one swig.", false);}}
	std::string showInBag(){if(numStacked > 0){return name + " - " + std::to_string(numStacked);}return "ERROR";}
	void usePotion(Character*& p, int& invis, bool& tp, bool& chest);
	int getCompVal() {return 7;}
		virtual Item* grabFromStack(){--numStacked; return new VialofFortitude();}
	virtual Item* grabFromStack(int n) {numStacked -= n; return new VialofFortitude(n);}
};

struct PotionofRobustResistance : public Potion {
	PotionofRobustResistance(int n = 0, int s = 0) : Potion("Potion of Robust Resistance", s, 100, n) {};
	void displayItem(){if(numStacked > 0){output(name +" - " + std::to_string(numStacked) + "\nYou're gonna be able to take a couple extra hits in your next battle mate.", false);}}
	std::string showInBag(){if(numStacked > 0){return name +" - " + std::to_string(numStacked);}return "ERROR";}
	void usePotion(Character*& p, int& invis, bool& tp, bool& chest);
	void unUsePotion(Character*& p);
	int getCompVal() {return 8;}
	virtual Item* grabFromStack(){--numStacked; return new PotionofRobustResistance(1, stat);}
	virtual Item* grabFromStack(int n) {numStacked -= n; return new PotionofRobustResistance(n, stat);}
};

struct AegisAggregate : public Potion {
	AegisAggregate(int n = 0) : Potion("Aegis Aggregate", 0, 100, n) {}; 
	void displayItem(){if(numStacked > 0){output(name +" - " + std::to_string(numStacked)  + "\nHardens your skin a bit to defend against your foes.", false);}}
	std::string showInBag(){if(numStacked > 0){return name +" - " + std::to_string(numStacked);}return "ERROR";}
	void usePotion(Character*& p, int& invis, bool& tp, bool& chest);
	int getCompVal() {return 9;}
	virtual Item* grabFromStack(){--numStacked; return new AegisAggregate();}
	virtual Item* grabFromStack(int n) {numStacked -= n; return new AegisAggregate(n);}
};

struct AlacrityPotation : public Potion {
	AlacrityPotation(int n = 0, int s = 0) : Potion("Alacrity Potation", s, 100, n) {};
	void displayItem(){if(numStacked > 0){output(name +" - " + std::to_string(numStacked) + "\nYou're either gonna get faster or slower for a bit."/*"Gain or loss you shall soon discover. Faster or slower than the others. Pray for luck lest your changes cost you dearly."*/, false);}}
	std::string showInBag(){if(numStacked > 0){return name +" - " + std::to_string(numStacked);}return "ERROR";}
	void usePotion(Character*& p, int& invis, bool& tp, bool& chest);
	void unUsePotion(Character*& p);
	int getCompVal() {return 10;}
	virtual Item* grabFromStack(){--numStacked; return new AlacrityPotation(1, stat);}
	virtual Item* grabFromStack(int n) {numStacked -= n; return new AlacrityPotation(n, stat);}
};

struct ElixirofInvisibility : public Potion {
	ElixirofInvisibility(int n = 0) : Potion("Elixir of Invisibility", 0, 100, n) {}; 
	void displayItem(){if(numStacked > 0){output(name +" - " + std::to_string(numStacked) + "\nFrom monsters sight you shall be lost but beware, all things have a cost.", false);}}
	std::string showInBag(){if(numStacked > 0){return name + " - " + std::to_string(numStacked);}return "ERROR";}
	void usePotion(Character*& p, int& invis, bool& tp, bool& chest);
	int getCompVal() {return 11;}
	virtual Item* grabFromStack(){--numStacked; return new ElixirofInvisibility();}
	virtual Item* grabFromStack(int n) {numStacked -= n; return new ElixirofInvisibility(n);}
};

struct FlaskofErudition : public Potion {
	FlaskofErudition(int n = 0) : Potion("Flask of Erudition", 0, 100, n) {};
	void displayItem(){if(numStacked > 0){output(name +"  - " + std::to_string(numStacked)  + "\nThings previously lost from sight shall be shown but only if the path is already known.", false);}}
	std::string showInBag(){if(numStacked > 0){return name + " - " + std::to_string(numStacked);}return "ERROR";}
	void usePotion(Character*& p, int& invis, bool& tp, bool& chest);
	int getCompVal() {return 12;}
	virtual Item* grabFromStack(){--numStacked; return new FlaskofErudition();}
	virtual Item* grabFromStack(int n) {numStacked -= n; return new FlaskofErudition(n);}
};

struct CorybanticConveyingPhilter : public Potion {
	CorybanticConveyingPhilter(int n = 0) : Potion("Corybantic Conveying Philter", 0, 100, n) {};
	void displayItem(){if(numStacked > 0){output(name +" - " + std::to_string(numStacked) + "\nConveys you to a new place, but beware! monsters may surround you there too.", false);}}
	std::string showInBag(){if(numStacked > 0){return name +" - " + std::to_string(numStacked);}return "ERROR";}
	void usePotion(Character*& p, int& invis, bool& tp, bool& chest);
	int getCompVal() {return 13;}
	virtual Item* grabFromStack(){--numStacked; return new CorybanticConveyingPhilter();}
	virtual Item* grabFromStack(int n) {numStacked -= n; return new CorybanticConveyingPhilter(n);}
};

#endif