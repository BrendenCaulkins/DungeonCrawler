#ifndef PARSINGTOOLS_H
#define PARSERTOOLS_H

#include <string>
#include<vector>
#include <iostream>

struct statementHelp;

inline bool isVowel(char v){ v = tolower(v);if(v == 'a'||v == 'e'||v == 'i'||v == 'o'||v == 'u'/*||v == 'y'*/){return true;}return false;}
inline void parseMonsterName(std::string& line, const std::string& name);
inline void parsePlayerName(std::string& line, const std::string& name);
inline void parseItem(std::string& line, const std::string& wep = "", const std::string& shi = "");
inline void parseChoice(std::string& line);
inline void parseIfElse(std::string& line, std::vector <std::string> tVal = {});//wip
inline void ifElseHelp(std::string& line, std::vector<statementHelp>&v, std::string lookFor);
inline void parseFind(std::string& line);
inline void parseRand(std::string& line);
inline bool passes(std::vector<std::string> v, std::vector<std::string> test);
inline bool contains(std::vector<std::string> v, std::string l);
// inline void parseType(std::string )
			
void parseMonsterName(std::string& line, const std::string& name){//call any order looks for ~M~
	while(line.find("~M~") != std::string::npos){
		int spot = line.find("~M~");
		line = line.substr(0, spot) + name + line.substr(spot + 3, line.size());
	}
}

void parsePlayerName(std::string& line, const std::string& name){//call any order looks for NAME
	while(line.find("NAME") != std::string::npos){
		int spot = line.find("NAME");
		line = line.substr(0, spot) + name + line.substr(spot + 4, line.size());
	}
}

void parseItem(std::string& line, const std::string& wep, const std::string& shi){//call any order looks for ITEM
	std::string w = wep, s = shi;
	while(line.find("ITEM") != std::string::npos){
		int spot = line.find("ITEM");
		if(wep.size() == 0 && shi.size() == 0){
			line = line.substr(0, spot) + "nothing" + line.substr(spot + 4, line.size());
		}
		else if(wep.size() > 0 && shi.size() > 0){
			if(isVowel(wep.at(0))){
					w = "an " + wep;
				}
				else{
					w = "a " + wep;
				}
// 			if(isVowel(shi.at(0))){
// 				s = "an " + shi;
// 			}
// 			else{
// 				s = "a " + shi;
// 			}
			line = line.substr(0, spot) + w + " and " + s + line.substr(spot + 4, line.size());
		}
		else{
			if(wep.size() > 0){
				if(isVowel(wep.at(0))){
					w = "an " + wep;
				}
				else{
					w = "a " + wep;
				}
			}
			if(shi.size() > 0){
				if(isVowel(shi.at(0))){
					s = "an " + shi;
				}
				else{
					s = "a " + shi;
				}
			}
			line = line.substr(0, spot) + w  + s + line.substr(spot + 4, line.size());

		}
	}
}

void parseChoice(std::string& line){//call any order looks for CHOICE
	while(line.find("CHOICE") != std::string::npos){
		int start = line.find("CHOICE"), end;
		int countlp = 0, countrp = 0;
		for(unsigned i = start + 6; i < line.size(); ++i){
			if(line.at(i) == '('){
				++countlp;
			}
			if(line.at(i) == ')'){
				++countrp;
			}
			if(countlp == countrp && countlp > 0){
				end = i;
				break;
			}
		}
		std::vector<std::string> v;
		std::string c;
		for(unsigned i = start+7; i < end; ++i){
			if(line.at(i) == '/'){
				int j = 0, count = 0, close = 0;
				while(c.find("CHOICE(", j) != std::string::npos){
					j = c.find("CHOICE", j+6);
					++count;
				}
				j = 0;
				while(c.find(')', j) != std::string::npos){
					j = c.find(')', j + 1);
					++close;
				}
				if(count == close){
					v.push_back(c);
					c.resize(0);
				}
				else{
					c += line.at(i);
				}
			}
			else{
				
				c += line.at(i);
			}
		}
		v.push_back(c);
// 			std::cout << "CHOICE: " << std::endl;
// 		for(unsigned i = 0; i < v.size(); ++i){
// 			std::cout << v.at(i) << std::endl;
// 		}
		if(v.size() == 0){
			std::cout << "ERROR: CHOICE" << std::endl;
			return;
		}
		line = line.substr(0, start) + v.at(rand()%v.size()) + line.substr(end + 1, line.size());

	}
}

struct statementHelp {
	int start, end, contentStart, contentEnd;
	std::vector<std::string> boolean;
	std::string contents;
	statementHelp(int s) : start(s) {};
	void parseBool(std::string line){
		int p=0;
		for(unsigned i = 0; i < line.size(); ++i){
			if(i > 0 && line.at(i) == '|' && line.at(i-1) == '|'){
				boolean.push_back(line.substr(p, i-2-p));
				p = i+2;
			}
		}
		boolean.push_back(line.substr(p, line.size()));
// 		std::cout << "HERE IT IS " << std::endl;
// 		for(unsigned i = 0; i < boolean.size(); ++i){
// 			std::cout << "~" << boolean.at(i) << "~" << std::endl;
// 		}
	}
};

void parseIfElse(std::string& line, std::vector <std::string> tVal){//should be called either last or near last looks for if, else if, and else
	while(line.find("IF(") != std::string::npos){
		std::vector<statementHelp> v;
		ifElseHelp(line, v, "IF(");
		while(line.substr(v.at(v.size()-1).contentEnd + 1, 7) == "ELSEIF("){
			ifElseHelp(line, v, "ELSEIF(");

		}
		while(line.substr(v.at(v.size()-1).contentEnd+1, 5) == "ELSE{"){
			ifElseHelp(line, v, "ELSE");
		}
		for(unsigned i = 0; i < v.size(); ++i){
			if(contains(v.at(i).boolean, "True") || passes(tVal, v.at(i).boolean) || v.at(i).boolean.size() == 0){
	// 			std::cout << v.at(0).start << " " << (v.at(0).start-2) << std::endl;
	// 			std::cout << v.at(v.size()-1).contentEnd << " " << line.size() << " " << v.size() <<  std::endl;
				line = line.substr(0, (v.at(0).start-2)) + v.at(i).contents + line.substr(v.at(v.size()-1).contentEnd+1, line.size()); 
				break;
			}
		}
	}
}

void ifElseHelp(std::string& line, std::vector<statementHelp>&v, std::string lookFor){
	if(v.size() ==0){
		v.push_back(statementHelp(line.find(lookFor)+lookFor.size()-1));
	}
	else{
		v.push_back(statementHelp(line.find(lookFor, v.at(v.size()-1).contentEnd) + lookFor.size()-1));
	}
	if(lookFor.find('(') != std::string::npos){
		int countlp = 0, countrp = 0;
// 		std::cout << v.at(v.size()-1).start << std::endl;
		for(unsigned i = v.at(v.size()-1).start; i <  line.size(); ++i){
			if(line.at(i) == '('){
				++countlp;
			}
			if(line.at(i) == ')'){
				++countrp;
			}
			if(countlp == countrp && countlp > 0){
				v.at(v.size()-1).end = i;
				break;
			}
		}
		v.at(v.size()-1).parseBool(line.substr(v.at(v.size()-1).start+ 1, v.at(v.size()-1).end - (v.at(v.size()-1).start + 1)));
		v.at(v.size()-1).contentStart = v.at(v.size()-1).end + 2;
		}
		else{
			v.at(v.size()-1).end = v.at(v.size()-1).start+1;
			v.at(v.size()-1).contentStart = v.at(v.size()-1).start+2;
		}
		int countlb = 0, countrb = 0;
		for(unsigned i = v.at(v.size()-1).end; i < line.size(); ++i){
			if(line.at(i) == '{'){
				++countlb;
			}
			if(line.at(i) == '}'){
				++countrb;
			}
			if(countlb == countrb && countlb > 0){
// 				std::cout << i << std::endl;
				v.at(v.size()-1).contentEnd = i;
				break;
			}
		}
// 	std::cout << v.at(v.size()-1).contentEnd << std::endl;
		v.at(v.size()-1).contents = line.substr(v.at(v.size()-1).contentStart, v.at(v.size()-1).contentEnd - (v.at(v.size()-1).contentStart));
// 		std::cout << "BOOL: ~" << v.at(v.size()-1).boolean  <<"~"<< std::endl;
// 		std::cout << "C: ~" <<  v.at(v.size()-1).contents << "~" << v.at(v.size()-1).contentEnd << std::endl;
}

inline bool passes(std::vector<std::string> v, std::vector<std::string> test){
	for(unsigned i = 0; i < test.size(); ++i){
		if(contains(v, test.at(i))){
			return true;
		}
	}
	return false;
}

bool contains(std::vector<std::string> v, std::string l){
	for(unsigned i = 0; i < v.size(); ++i){
		if(v.at(i) == l){
			return true;
		}
	}
	return false;
}

void parseFind(std::string& line){//call any order looks for FIND, should be called before parseIfElse
	while(line.find("FIND") != std::string::npos){
		int spot = line.find("FIND"), start = line.find('(', spot) + 1, end = line.find(')', spot);
		std::string found = line.substr(start, end - start);
// 		std::cout << found << std::endl;
		if(line.find(found) != std::string::npos){
			if(line.find(found) < spot)
				line = line.substr(0, spot) + "True" + line.substr(end + 1, line.size());	
			else
				line = line.substr(0, spot) + "False" + line.substr(end + 1, line.size());	
		}
		else{
			line = line.substr(0, spot) + "False" + line.substr(end + 1, line.size());			
		}
	}
}

void parseRand(std::string& line){//all any order looks for RAND
	while(line.find("RAND") != std::string::npos){
		int spot = line.find("RAND");
		int end = line.find(')', spot);
		std::string k;
		std::vector<int> v;
		for(unsigned i = spot; i < end; ++i){
			if(isdigit(line.at(i))){
				k += line.at(i);
			}
			else{
				if(k.size() > 0){
					v.push_back(stoi(k));
					k.resize(0);
				}
			}
		}
		v.push_back(stoi(k));
		if(v.size() == 0){
			std::cout << "ERROR: RAND" << std::endl;
			return;
		}
		if(v.size() == 1){
			std::cout << "ERROR: TOO FEW ARGUMENTS, needs 2" << std::endl;
		}
// 		std::cout << v.size() << std::endl;
		line = line.substr(0, spot) + std::to_string(std::min(v.at(0), v.at(1)) + rand()%(std::max(v.at(0), v.at(1)) - std::min(v.at(0), v.at(1)) + 1)) + line.substr(end + 1, line.size());
	}
}

#endif