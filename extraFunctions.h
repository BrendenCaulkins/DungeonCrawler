#ifndef EXTRAFUNCTIONS_H
#define EXTRAFUNCTIONS_H

#include "parsingTools.h"
#include <iostream>
#include<fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

inline int getValInRange(int l, int h){int high = std::max(std::max(l, h), 0), low = std::max(0, std::min(l, h));high -= low; return (low + rand()%(high+1));}
inline char continueRequest();
inline void requestReturn();

inline std::string generateName();
inline std::string portman(const std::vector<std::string>& dict);
inline std::string portman(std::string& name, const std::vector<std::string>& dict, int bChance);
inline void output(std::string output, int width = 0, bool needsAdjustment = false);
inline void outputflush(std::string output, int width = 0, bool needsAdjustment = false);

template <typename T>
inline void Quicksort_midpoint(std::vector<T>&v, int i, int k);
template <typename T>
inline void sort(std::vector<T>& v){Quicksort_midpoint(v, 0, v.size()-1);}
template <typename T>
inline int Partition(std::vector<T>&v, int i, int k);//ised bu quicksort_midpoint

const std::string filename = "dictionarylist.txt";

char continueRequest(){
	char back;
	output("\nPress any button to continue", false);
// 	do{
		std::cin.get(back);
	outputflush("\x1b[A\x1b[A                                                       \r", false);

// 	}while(back != 'b');
	return back;
}

void requestReturn(){
	char back;
	output("Press 'b' to return.", false);
	do{
		std::cin>>back;
	}while(back != 'b');
	return;
}

std::string generateName(){
	std::vector<std::string> dict;
	std::string name;
	std::ifstream ifs(filename);
	if(!ifs.is_open()){
		output("ERR: FILENOTFOUND", false);
		return "WASDIGUESS";
	}
	while(ifs >> name){
		dict.push_back(name);
	}
	ifs.close();
	return portman(dict);
}

std::string portman(const std::vector<std::string>& dict){
	std::string name;
	portman(name, dict, 100);
	name.at(0) = std::toupper(name.at(0));
	return name;
}

std::string portman(std::string& name, const std::vector<std::string>& dict, int bChance){
	//cout << bChance << endl;
	if(rand()%100 > bChance){
		return name;
	}
	if(name.size() == 0){
// 		char startLetter = 97 + rand()%(122-97);
		name = dict.at((rand()*rand()*rand())%dict.size());
		return portman(name, dict, bChance);
	}
	else{
		std::vector<std::string> names;
		std::string subname = name;
		int ind = getValInRange(1, name.size()-2);
		char c = name.at(ind);
		int val = rand(); // number used to determine index of letter checking
		for(unsigned i = 0; i < dict.size(); ++i){
			if(c == dict.at(i).at(val%(dict.at(i).size() -1))){
				//cout << dict.at(i) << " ";
				names.push_back(dict.at(i));
				break;
			}
		}
		if(names.size()==0){
			return portman(name, dict, bChance);
		}
		int chosenName = getValInRange(0, names.size()-1);
		name = name.substr(0, ind) + names.at(chosenName).substr(val%(names.at(chosenName).size() - 1), names.at(chosenName).size());
		//cout << c << endl;
		if(subname == name){
			return portman(name, dict, bChance);
		}
		else{
			return portman(name, dict, 3*bChance/4);
		}
		
	}
}


void output(std::string line, int width, bool needsAdjustment){
	if(!needsAdjustment){
		std::cout << line << std::endl;
		return;
	}
	if(width == 0){
		width = 40;
	}
// 	std::cout << line.size() << std::endl;
	if(line.size()>width){
		for(unsigned i = width; i < line.size(); i+=width){
			if(line.at(i) == ' '){
				line.at(i) = '\n';
			}
			else{
				for(unsigned j = i; j < line.size(); --j){
					if(line.at(j) == ' '){
						line.at(j) = '\n';
						i = j;
						break;
					}
					else if(line.at(j) == '\n'){
						for(unsigned k = i; k < line.size(); ++k){
							if(line.at(k) == ' '){
								line.at(k) = '\n';
								i = k;
								break;
							}
						}
						break;
					}
				}
			}
		}
	}
		std::cout << line << std::endl;
}

void outputflush(std::string line, int width, bool needsAdjustment){
	if(!needsAdjustment){
		std::cout << line << std::flush;
		return;
	}
	if(width == 0){
		width = 40;
	}
// 	std::cout << line.size() << std::endl;
	if(line.size()>width){
		for(unsigned i = width; i < line.size(); i*=2){
			if(line.at(i) == ' '){
				line.at(i) = '\n';
			}
			else{
				for(unsigned j = i; j < line.size(); --j){
					if(line.at(j) == ' '){
						line.at(j) = '\n';
						i = j;
						break;
					}
					else if(line.at(j) == '\n'){
						for(unsigned k = i; k < line.size(); ++k){
							if(line.at(k) == ' '){
								line.at(k) = '\n';
								i = k;
								break;
							}
						}
						break;
					}
				}
			}
		}
	}
		std::cout << line << std::flush;
}


template <typename T>
void Quicksort_midpoint(std::vector<T>&v, int i, int k){
	int j = 0;
   
   // Base case: If there are 1 or zero elements to sort,
   // partition is already sorted
   if (i >= k) {
      return;
   }
   
   // Partition the data within the array. Value j returned
   // from partitioning is location of last element in low partition.
   j = Partition(v, i, k);
   
   // Recursively sort low partition (i to j) and
   // high partition (j + 1 to k)
   Quicksort_midpoint(v, i, j);
   Quicksort_midpoint(v, j + 1, k);
}

template <typename T>
int Partition(std::vector<T>&v, int i, int k) {
   int l = 0;
   int h = 0;
   int midpoint = 0;
   T pivot;
   T temp;
   bool done = false;
   
   // Pick middle element as pivot
   midpoint = i + (k - i) / 2;
   pivot = v.at(midpoint);
   
   l = i;
   h = k;
   
   while (!done) {
      
      // Increment l while numbers[l] < pivot
      while (v.at(l) < pivot) {
         ++l;
      }
      
      // Decrement h while pivot < numbers[h]
      while (pivot < v.at(h)) {
         --h;
      }
      
      // If there are zero or one elements remaining,
      // all numbers are partitioned. Return h
      if (l >= h) {
         done = true;
      }
      else {
         // Swap numbers[l] and numbers[h],
         // update l and h
         temp = v.at(l);
         v.at(l) = v.at(h);
         v.at(h) = temp;
         
         ++l;
         --h;
      }
   }
   
   return h;
}

#endif