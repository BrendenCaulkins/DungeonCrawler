#include "extraFunctions.h"
#include <fstream>
using namespace std;

int main(){
	bool isTamed = true;
	srand(time(0));
	std::ifstream inFS("Attacks/CerberusAttacks.txt");
	if(!inFS.is_open()){
		std::cout << "Tim slaps you" << std::endl;
		return 0;
	}
	std::vector<std::string> attacks;
	std::string line;
	while(getline(inFS,line)){
		if(line == ""){
			break;
		}
		if(line.at(0) == '.'){
			attacks.at(attacks.size() - 1) += '\n' + line.substr(1, line.size());
		}
		else{
			attacks.push_back(line);
		}	
	}
	if(attacks.size() == 0){
		std::cout << "Tim slaps fred" << std::endl;
		inFS.close();
		return 0;
	}
	std::string sentence = attacks.at(rand()%attacks.size());
			parseMonsterName(sentence, "Tim");
			if(isTamed)
				parsePlayerName(sentence, "you");
			else
				parsePlayerName(sentence, "Fred");
			parseChoice(sentence);
			parseFind(sentence);
			parseRand(sentence);
			std::vector<std::string> stuff {"Tim", "Boss", "Cerberus"};
			parseIfElse(sentence, stuff);
	
	std::cout << sentence << std::endl;
	inFS.close();
}