#ifndef RECIPE_BOOK_H
#define RECIPE_BOOK_H

#include "Items.h"
#include "potions.h"

class recipe {
	private:
	std::string name;
	int val;
	std::vector<std::string> ingredients, altIngredients;
	public:
	std::string getName(){return name;}
	recipe(std::string name, int val, std::vector<std::string> v, std::vector<std::string> v2 = {}) : name(name), val(val), ingredients(v), altIngredients(v2) {}
	virtual Item* craft(int i = 0){return nullptr;}
	std::vector<std::string> getIngredientList() { return ingredients;}
	std::vector<std::string> getAltIngredientList() { return altIngredients;}
	virtual std::string showInBook() { return name ;}
	virtual std::string showInBag() {return showInBook();}
	virtual void displayItem(){output(showInBook(), false); }
	virtual int sortVal(){return 999;}
	int getVal(){return val;};
	virtual void displayRecipe();
	
	bool operator <(recipe& rhs){
		if(sortVal() < rhs.sortVal()){
			return true;
		}
		return false;
	}
	bool operator ==(recipe& rhs){
		if(name == rhs.name){
			return true;
		}
		return false;
	}
};

class RecipeBook : public Item {
	private:
	std::vector<recipe*> pages;
	public:
	RecipeBook() : Item("Potion Recipe Book", 0, 1, book, unique, nei, "BOOK", false) {};
	bool isBook(){return true;}
	void addRecipe(recipe* r);
	std::string showInBag() {return name;}
	
	void displayItem(){output(showInBag() +  std::to_string(pages.size()) + " out of 14 recipes found", false);}
	void enterBook();
	int numPages() const {return pages.size();}
	bool isFull() const {if(numPages() == 14){return true;}return false;}
	recipe* page(int i){return pages.at(i);}
	virtual bool isEquippable(){return false;}
	bool has(recipe* rec) const{
		for(unsigned i = 0; i < pages.size(); ++i){
			if(*pages.at(i) == *rec){
				return true;
			}
		}
		return false;
	}
	void toFile(std::ofstream& ofs){
		for(unsigned i = 0; i < pages.size(); ++i){
			ofs << pages.at(i)->getName() << " " << std::flush;
		}
		ofs << std::endl;
	}
};



class SalubriousDecoctionRecipe : public recipe { 	
	public: 	
	SalubriousDecoctionRecipe() : recipe("Salubrious Decoction Recipe", 250, {"Sweetness Stipule", "Distilled Darkness"}) {};
	virtual int sortVal(){return 1;}
	virtual Item* craft(int i = 0);
};

class TonicForEupepsiaRecipe : public recipe { 	
	public: 	
	TonicForEupepsiaRecipe() : recipe("Tonic For Eupepsia Recipe", 750, {"Fermented Funky Fungus", "Distilled Darkness"}, {"Soured Pome", "Distilled Darkness"}){};
	virtual int sortVal(){return 2;}
	virtual Item* craft(int i = 0);
};

class LustinessTinctureRecipe : public recipe { 	
	public: 	
	LustinessTinctureRecipe() : recipe("Lustiness Tincture Recipe", 1500, {"Sweetness Stipule", "Titillating Toothfruit", "Fermented Funky Fungus"}){};
	virtual int sortVal(){return 3;}
	virtual Item* craft(int i = 0);
};

class BrewofStaminaRecipe : public recipe { 	
	public: 	
	BrewofStaminaRecipe() : recipe("Brew of Stamina Recipe", 2500, {"Distilled Darkness", "Dissolved Pearl", "Irate Inchworm's Intestines"}, {"Distilled Paleness", "Dissolved Pearl", "Irate Inchworm's Intestines"}){};
	virtual int sortVal(){return 4;}
	virtual Item* craft(int i = 0);
};

class DraughtofVigorRecipe : public recipe { 	
	public: 	
	DraughtofVigorRecipe() : recipe("Draught of Vigor Recipe", 4000, {"Cactal Spindles", "Distilled Darkness", "Bloated Blossom's Nectar"}) {};
	virtual int sortVal(){return 5;}
	virtual Item* craft(int i = 0);
};

class DragonsBreathLibationRecipe : public recipe { 	
	public: 	
	DragonsBreathLibationRecipe() : recipe("Dragon's Breath Libation Recipe", 5000, {"Siren's Bud", "Soured Pome", "Orc's Baculum"}) {};
	virtual int sortVal(){return 6;}
	virtual Item* craft(int i = 0);
};

class VitalityConcoctionRecipe : public recipe { 	
	public: 	
	VitalityConcoctionRecipe() : recipe("Vitality Concoction Recipe", 250, {"Sweetness Stipule", "Distilled Paleness", "Bloated Blossom's Nectar"}){};
	virtual int sortVal(){return 7;}
	virtual Item* craft(int i = 0);
};

class VialofFortitudeRecipe : public recipe { 	
	public: 	
	VialofFortitudeRecipe() : recipe("Vial of Fortitude Recipe", 500, {"Sweetness Stipule", "Distilled Paleness", "Soured Pome"}){}; 
	virtual int sortVal(){return 8;}
	virtual Item* craft(int i = 0);
};

class PotionofRobustResistanceRecipe : public recipe { 
	public: 
	PotionofRobustResistanceRecipe() : recipe("Potion of Robust Resistance Recipe", 250, {"Sweetness Stipule", "Calm Concentrate", "Bloated Blossom's Nectar"}){}; 
	virtual int sortVal(){return 9;}
	virtual Item* craft(int i = 0);
};

class AegisAggregateRecipe : public recipe { 	
	public: 	
	AegisAggregateRecipe() : recipe("Aegis Aggregate Recipe", 500, {"Sweetness Stipule", "Calm Concentrate", "Soured Pome"}){}; 
	virtual int sortVal(){return 10;}
	virtual Item* craft(int i = 0);
};

class AlacrityPotationRecipe : public recipe { 	
	public: 	
	AlacrityPotationRecipe() : recipe("Alacrity Potation Recipe", 1500, {"Sweetness Stipule", "Astringent Adenoids", "Fermented Funky Fungus"}){};
	virtual int sortVal(){return 11;}
	virtual Item* craft(int i = 0);
};

class ElixirofInvisibilityRecipe : public recipe { 	
	public: 
	ElixirofInvisibilityRecipe() : recipe("Elixir of Invisibility Recipe", 2500, {"Powdered Werewolf Claw", "Dissolved Pearl", "Bubbled Goblin Jelly"}){};
	virtual int sortVal(){return 12;}
	virtual Item* craft(int i = 0);
};

class FlaskofEruditionRecipe : public recipe {
	public:
	FlaskofEruditionRecipe() : recipe("Flask of Erudition Recipe", 3000, {"Fresh Drupe", "Piquant Pear", "Distilled Paleness"}){};
	virtual int sortVal(){return 13;}
	virtual Item* craft(int i = 0);
};

class CorybanticConveyingPhilterRecipe : public recipe {
	public:
	CorybanticConveyingPhilterRecipe() : recipe("Corybantic Conveying Philter Recipe", 3500, {"Piquant Pear", "Titillating Toothfruit", "Crunched Cane Tubules"}){};
	virtual int sortVal(){return 14;}
	virtual Item* craft(int i = 0);
};

#endif