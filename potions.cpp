#include "potions.h"//implementation file for usePotion

void Potion::usePotion(Character*& p, int& invis, bool& tp, bool& chest) {
	if(numStacked > 0 && !p -> fullHP()){
			--numStacked;
			p -> gainHP(stat);
			return;
		}
		if(p -> fullHP()){
			output("Unable to use " + name + ", health is full.", false);
			return;
		}
	output("Unable to use " + name + ", none remain", false);
}

void DragonsBreathLibation::usePotion(Character*& p, int& invis, bool& tp, bool& chest) {
	if(numStacked > 0 && !p -> fullHP()){
			--numStacked;
			p -> gainHP(p->getMHP());
			p->gainMaxHP(std::ceil(p->getMHP()/3.0));
			p -> gainAtk(std::ceil(p->getAtk()/3.0));
			p-> gainDef(std::ceil(p->getDef()/3.0));
			p->gainSpd(std::ceil(p->getSpd()/3.0));
			return;
		}
		if(p -> fullHP()){
			output("Unable to use " + name + ", health is full.", false);
			return;
		}
	output("Unable to use " + name + ", none remain", false);
}

void VitalityConcoction::usePotion(Character*& p, int& invis, bool& tp, bool& chest) {
	if(numStacked > 0){
			--numStacked;
		stat = getValInRange(std::ceil(6 * p -> getLVL()/2.0), std::ceil(7*p->getLVL()/2.0));
			p -> gainAtk(stat);
			return;
		}
	output("Unable to use " + name + ", none remain", false);
}

void VitalityConcoction::unUsePotion(Character*& p){
	p -> gainAtk(-stat);
}

void VialofFortitude::usePotion(Character*& p, int& invis, bool& tp, bool& chest) {
	if(numStacked > 0){
			--numStacked;
			p -> gainAtk(getValInRange(std::ceil(2 * p->getLVL()/3.0), std::ceil(3*p->getLVL()/3.0)));
			return;
		}
	output("Unable to use " + name + ", none remain", false);
}

void PotionofRobustResistance::usePotion(Character*& p, int& invis, bool& tp, bool& chest) {
	if(numStacked > 0){
			--numStacked;
			stat = getValInRange(std::ceil(6 * p-> getLVL()/2.0), std::ceil(7*p-> getLVL()/2.0));
			p -> gainDef(stat);
			return;
		}
	output("Unable to use " + name + ", none remain", false);
}

void PotionofRobustResistance::unUsePotion(Character*& p){
	p -> gainDef(-stat);
}

void AegisAggregate::usePotion(Character*& p, int& invis, bool& tp, bool& chest) {
	if(numStacked > 0){
			--numStacked;
			p -> gainDef(getValInRange(std::ceil(2 * p->getLVL()/3.0), std::ceil(3*p->getLVL()/3.0)));
			return;
		}
	output("Unable to use " + name + ", none remain", false);
}

void AlacrityPotation::usePotion(Character*& p, int& invis, bool& tp, bool& chest) {
	if(numStacked > 0){
			--numStacked;
		stat = getValInRange(4 * p ->getLVL(), 5 * p -> getLVL());
		if(getValInRange(1, 10)==1 && stat/2 < p->getSpd()){
			stat -= stat;
		}
			p -> gainSpd(stat);
			return;
		}
	output("Unable to use " + name + ", none remain", false);
}

void AlacrityPotation::unUsePotion(Character*& p){
	p -> gainSpd(-stat);
}

void ElixirofInvisibility::usePotion(Character*& p, int& invis, bool& tp, bool& chest) {
	if(numStacked > 0){
			--numStacked;
			invis = getValInRange(20, 30);
			p-> gainHP(-(p->getHP()/4.0));
			return;
		}
	output("Unable to use " + name + ", none remain", false);
}

void FlaskofErudition::usePotion(Character*& p, int& invis, bool& tp, bool& chest) {
	if(numStacked > 0){
			--numStacked;
			chest = true;
			return;
		}	
	output("Unable to use " + name + ", none remain", false);
}

void CorybanticConveyingPhilter::usePotion(Character*& p, int& invis, bool& tp, bool& chest) {
	if(numStacked > 0){
		--numStacked;
		tp = true;
		return;
		}
	output("Unable to use " + name + ", none remain", false);
}