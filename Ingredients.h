#ifndef INGREDIENTS_H
#define INGREDIENTS_H

class Ingredient : public Item {
	protected:
	int numStacked, stat, val;
	public:
	Ingredient(std::string name, int n, rarity rare) : Item(name, 0, 1, ingredient, rare, nei, "ING", false), stat(0), val(20) {if(n == 0) {numStacked = 1;}else{numStacked = n;}}
	void displayItem(){if(numStacked > 0){output(name +" - " + std::to_string(numStacked), false);}}
	std::string showInBag(){if(numStacked > 0){return name +" - " + std::to_string(numStacked);} return "error";}
	bool isIngredient() {return true;}
	int getStat(){return stat;}
	virtual Item* grabFromStack() = 0;
	virtual Item* grabFromStack(int n) = 0;
	int getNum(){return numStacked;}
	int getVal(int i){return val;}
	void addToStack(Item* p){numStacked += p -> getNum();}
	void addToStack(int lvl, int stat = 0) {numStacked += lvl;}
	virtual void toFile(std::ofstream& ofs){
		ofs << getNum() << std::endl;
	}
	virtual bool isEquippable(){return false;}
};

struct DistilledDarkness : public Ingredient {
	DistilledDarkness(int n = 0) : Ingredient("Distilled Darkness", n, common) {};
	virtual Item* grabFromStack(){--numStacked; return new DistilledDarkness();}
	virtual Item* grabFromStack(int n){numStacked -= n; return new DistilledDarkness(n);}
};

struct SweetnessStipule : public Ingredient {
	SweetnessStipule(int n = 0) : Ingredient("Sweetness Stipule", n, common) {};
	virtual Item* grabFromStack(){--numStacked; return new SweetnessStipule();}
	virtual Item* grabFromStack(int n){numStacked -= n; return new SweetnessStipule(n);}
};

struct SouredPome : public Ingredient {
	SouredPome(int n = 0) : Ingredient("Soured Pome", n, uncommon) {};
	virtual Item* grabFromStack(){--numStacked; return new SouredPome();}
	virtual Item* grabFromStack(int n){numStacked -= n; return new SouredPome(n);}
};

struct FermentedFunkyFungus : public Ingredient {
	FermentedFunkyFungus(int n = 0) : Ingredient("Fermented Funky Fungus", n, uncommon) {};
	virtual Item* grabFromStack(){--numStacked; return new FermentedFunkyFungus();}
	virtual Item* grabFromStack(int n){numStacked -= n; return new FermentedFunkyFungus(n);}
};

struct TitillatingToothfruit : public Ingredient {
	TitillatingToothfruit(int n = 0) : Ingredient("Titillating Toothfruit", n, rare) {};
	virtual Item* grabFromStack(){--numStacked; return new TitillatingToothfruit();}
	virtual Item* grabFromStack(int n){numStacked -= n; return new TitillatingToothfruit(n);}
};

struct DissolvedPearl : public Ingredient {
	DissolvedPearl(int n = 0) : Ingredient("Dissolved Pearl", n, rare) {};
	virtual Item* grabFromStack(){--numStacked; return new DissolvedPearl();}
	virtual Item* grabFromStack(int n){numStacked -= n; return new DissolvedPearl(n);}
};

struct IrateInchwormsIntestines : public Ingredient {
	IrateInchwormsIntestines(int n = 0) : Ingredient("Irate Inchworm's Intestines", n, uncommon) {};
	virtual Item* grabFromStack(){--numStacked; return new IrateInchwormsIntestines();}
	virtual Item* grabFromStack(int n){numStacked -= n; return new IrateInchwormsIntestines(n);}
};

struct BloatedBlossomsNectar : public Ingredient {
	BloatedBlossomsNectar(int n = 0) : Ingredient("Bloated Blossom's Nectar", n, rare) {};
	virtual Item* grabFromStack(){--numStacked; return new BloatedBlossomsNectar();}
	virtual Item* grabFromStack(int n){numStacked -= n; return new BloatedBlossomsNectar(n);}
};

struct CactalSpindles : public Ingredient {
	CactalSpindles(int n = 0) : Ingredient("Cactal Spindles", n, veryrare) {};
	virtual Item* grabFromStack(){--numStacked; return new CactalSpindles();}
	virtual Item* grabFromStack(int n){numStacked -= n; return new CactalSpindles(n);}
};

struct SirensBud : public Ingredient {
	SirensBud(int n = 0) : Ingredient("Siren's Bud", n, legendary) {};
	virtual Item* grabFromStack(){--numStacked; return new SirensBud();}
	virtual Item* grabFromStack(int n){numStacked -= n; return new SirensBud(n);}
};

struct OrcsBaculum : public Ingredient {
	OrcsBaculum(int n = 0) : Ingredient("Orc's Baculum", n, rare) {};
	virtual Item* grabFromStack(){--numStacked; return new OrcsBaculum();}
	virtual Item* grabFromStack(int n){numStacked -= n; return new OrcsBaculum(n);}
};

struct DistilledPaleness : public Ingredient {
	DistilledPaleness(int n = 0) : Ingredient("Distilled Paleness", n, uncommon) {};
	virtual Item* grabFromStack(){--numStacked; return new DistilledPaleness();}
	virtual Item* grabFromStack(int n){numStacked -= n; return new DistilledPaleness(n);}
};

struct CalmConcentrate : public Ingredient {
	CalmConcentrate(int n = 0) : Ingredient("Calm Concentrate", n, uncommon) {};
	virtual Item* grabFromStack(){--numStacked; return new CalmConcentrate();}
	virtual Item* grabFromStack(int n){numStacked -= n; return new CalmConcentrate(n);}
};

struct AstringentAdenoids : public Ingredient {
	AstringentAdenoids(int n = 0) : Ingredient("Astringent Adenoids", n, uncommon) {};
	virtual Item* grabFromStack(){--numStacked; return new AstringentAdenoids();}
	virtual Item* grabFromStack(int n){numStacked -= n; return new AstringentAdenoids(n);}
};

struct PowderedWerewolfClaw : public Ingredient {
	PowderedWerewolfClaw(int n = 0) : Ingredient("Powdered Werewolf Claw", n, veryrare) {};
	virtual Item* grabFromStack(){--numStacked; return new PowderedWerewolfClaw();}
	virtual Item* grabFromStack(int n){numStacked -= n; return new PowderedWerewolfClaw(n);}
};

struct BubbledGoblinJelly : public Ingredient {
	BubbledGoblinJelly(int n = 0) : Ingredient("Bubbled Goblin Jelly", n, veryrare) {};
	virtual Item* grabFromStack(){--numStacked; return new BubbledGoblinJelly();}
	virtual Item* grabFromStack(int n){numStacked -= n; return new BubbledGoblinJelly(n);}
};

struct FreshDrupe : public Ingredient {
	FreshDrupe(int n = 0) : Ingredient("Fresh Drupe", n, rare) {};
	virtual Item* grabFromStack(){--numStacked; return new FreshDrupe();}
	virtual Item* grabFromStack(int n){numStacked -= n; return new FreshDrupe(n);}
};

struct PiquantPear : public Ingredient {
	PiquantPear(int n = 0) : Ingredient("Piquant Pear", n, rare) {};
	virtual Item* grabFromStack(){--numStacked; return new PiquantPear();}
	virtual Item* grabFromStack(int n){numStacked -= n; return new PiquantPear(n);}
};

struct CrunchedCaneTubules : public Ingredient {
	CrunchedCaneTubules(int n = 0) : Ingredient("Crunched Cane Tubules", n, veryrare) {};
	virtual Item* grabFromStack(){--numStacked; return new CrunchedCaneTubules();}
	virtual Item* grabFromStack(int n){numStacked -= n; return new CrunchedCaneTubules(n);}
};



#endif