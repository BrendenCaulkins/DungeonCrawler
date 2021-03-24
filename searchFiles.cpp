#include <fstream>
#include <dirent.h>
#include <iostream>
#include <vector>
using namespace std;

struct list {
	string name;
	int num;
	list(string n, int i) : name(n), num(i) {};
};

int main(){
	srand(time(0));
	vector<list> discovered;
	DIR *dpdf;
    struct dirent *epdf;
	vector<string> files;
	dpdf = opendir(".");
	if (dpdf != NULL) {
	   while (epdf = readdir(dpdf)) {
		  files.push_back(std::string(epdf->d_name));
	   }
	}
	for(unsigned i = 0; i < files.size(); ++i){
		ifstream ifs(files.at(i));
		if(!ifs.is_open()){
			cout << "ERROR OPENING FILE: " << files.at(i) << std::endl;
		}
		else{
			string line;
			bool found = false;
			int count = 0;
			while(getline(ifs, line)){
				if((line.find("template") != std::string::npos || line.find("template") != std::string::npos) && (line.find("//") == std::string::npos && line.find("/*")==std::string::npos && line.find("*/") == std::string::npos)){
					++count;
// 					break;
					found = true;
				}
			}
			if(found){
				discovered.push_back(list(files.at(i), count));
			}
		}
		ifs.close();
	}
// 	int jindx;
// 		for(unsigned i = 0; i < discovered.size(); ++i){
// 			jindx = i;
// 			for(unsigned j = i + 1; j < discovered.size(); ++j){
// 				if(discovered.at(jindx).num < discovered.at(j).num){
// 					jindx = j;
// 				}
// 			}
// 			swap(discovered.at(jindx), discovered.at(i));
// 		}
	int total = 0;
	for(unsigned i = 0; i < discovered.size(); ++i){
		cout << discovered.at(i).name << " - " << discovered.at(i).num << endl; 
		total += discovered.at(i).num;
	}
	cout << "Total files: " << discovered.size() << " \nTotal lines: " << total << endl;
	int ran = rand()%discovered.size();
	cout << "Work on: " << discovered.at(ran).name  << " - " << discovered.at(ran).num << endl;
	return 0;
}