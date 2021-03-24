#ifndef SHOP_H
#define SHOP_H
#include "Character.h"
#include "includeItems.h"
#include "extraFunctions.h"
#include <vector>
class Shop {
	private:
	std::vector <Item*> inventory;
	std::vector<recipe*> recipeInventory;
	bool enteredBefore;
	public:
	Shop() {enteredBefore = false;}
	~Shop() {while(!inventory.empty()){Item* temp = inventory.at(inventory.size()-1); inventory.pop_back(); delete temp;}}
	void enterShop(Character&, std::vector <Item*> &bag);//displays menu
// 	void refillInventory(){emptyShop();fillShop();}
	private:
	void emptyShop();//empties Shop
	void fillShop(const int lvl, const Item& book);//fills inventory
	void displayItems();
	int buyItem(int wallet, std::vector<Item*>&bag);
	int sellItems(std::vector <Item*>&bag);
	void enterCrafting(std::vector<Item*>& bag);
	bool craftable(const std::vector<std::string>& ing, const std::vector<Item*>& bag) const;
	void outputCraft(const std::vector<std::string>& ing, const std::vector<Item*>& bag, const bool hasAlt);
	bool contains(const std::string& ing, const std::vector<Item*>& bag) const;
	int calcCraftable(const std::vector<std::string>& ing, const std::vector<Item*>& bag) const;
	void bookCheck(std::vector<Item*>& bag);
	void addToBag(std::vector<Item*>& bag, Item*& thing);
	void sortBag(std::vector<Item*>& bag);
	void sortBag(std::vector<recipe*>& bag);
// 	Item* extraItems();
	void craftPotion(const std::vector<std::string>& ing, recipe* currRec, std::vector<Item*>& bag);
	recipe* allRecipes();
	Item* commonItem(const int lvl);
	Item* uncommonItem(const int lvl);
	Item* rareItem(const int lvl);
	Item* veryRareItem(const int lvl);
	
};

#endif