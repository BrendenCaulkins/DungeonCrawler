#include "recipeBook.h"

void recipe::displayRecipe() {
	std::string ing;
		for(unsigned i = 0; i < ingredients.size(); ++i){
			ing += ingredients.at(i); 
			if(i + 1 < ingredients.size())
				ing += ", ";
		}
		output(ing, false);
		ing.resize(0);
		if(altIngredients.size()>0){
			output("or", false);
		}
		for(unsigned i = 0; i < altIngredients.size(); ++i){
			ing += altIngredients.at(i);
			if(i + 1 < altIngredients.size())
				ing +=", ";
		}
	output(ing, false);
	}

void RecipeBook::addRecipe(recipe* r){
		for(unsigned i = 0; i < pages.size(); ++i){
			if(pages.at(i) -> sortVal() == r -> sortVal()){
				return;
			}
		}
		pages.push_back(r);
		int jindx;
		for(unsigned i = 0; i < pages.size(); ++i){
			jindx = i;
			for(unsigned j = i+1; j < pages.size(); ++j){
				if(*pages.at(j) < *pages.at(jindx)){
					jindx = j;
				}
			}
			std::swap(pages.at(jindx), pages.at(i));
		}
	}

void RecipeBook::enterBook(){
		do{	
			output("Which recipe would you like to examine?", false);
			std::string rec;
			for(unsigned i = 0; i < pages.size(); ++i){
				rec += std::to_string(i) + " - " + pages.at(i)->showInBook() + '\n';
			}
			rec += "b - return";
			output(rec, false);
			int p;
			do{
				std::cin >> p;
				if(std::cin.fail()){
					std::cin.clear();
					std::cin.ignore(500, '\n');
					return;
				}
			}while(p >= pages.size());
			pages.at(p) -> displayRecipe();
			continueRequest();
		}while(0==0);
	}
	 
Item* SalubriousDecoctionRecipe::craft(int i  ) {return new SalubriousDecoction(i);}

	  Item* TonicForEupepsiaRecipe::craft(int i  ){return new TonicForEupepsia(i);}

	  Item* LustinessTinctureRecipe::craft(int i  ){return new LustinessTincture(i);}

	  Item* BrewofStaminaRecipe::craft(int i  ){return new BrewofStamina(i);}

	  Item* DraughtofVigorRecipe::craft(int i  ){return new DraughtofVigor(i);}

	  Item* DragonsBreathLibationRecipe::craft(int i  ){return new DragonsBreathLibation(i);}

	  Item* VitalityConcoctionRecipe::craft(int i  ){return new VitalityConcoction(i);}

	  Item* VialofFortitudeRecipe::craft(int i  ){return new VialofFortitude(i);}

	  Item* PotionofRobustResistanceRecipe::craft(int i  ){return new PotionofRobustResistance(i);}

	  Item* AegisAggregateRecipe::craft(int i  ){return new AegisAggregate(i);}

	  Item* AlacrityPotationRecipe::craft(int i  ){return new AlacrityPotation(i);}

	  Item* ElixirofInvisibilityRecipe::craft(int i  ){return new ElixirofInvisibility(i);}

	  Item* FlaskofEruditionRecipe::craft(int i  ){return new FlaskofErudition(i);}

	  Item* CorybanticConveyingPhilterRecipe::craft(int i  ){return new CorybanticConveyingPhilter(i);}
