#include "Game.h"
// #include "openGLFunctions.h"
#include <fstream>
#include <dirent.h>
#include "extraFunctions.h"
using namespace std;

void startProgram();
void newGame();
void loadGame();
void playGame(Game &maze, int floor, string filename);
void saveGame(Game& maze, int floor, string& filename);
void openingLore();
string chaosCl();
void pauseScreen(Game& maze, int floor, string& filename);
void infoScreen();
void symbolsLegend(const Game& maze);
bool exists(string s, const vector<string>& v){if(s.size() == 0){return true;}for(unsigned i = 0; i < v.size(); ++i){if(s == v.at(i)){return true;}}return false;}

int main(int argc, char** argv){
	srand(time(0));
	startProgram();
return 0;
}

void startProgram(){
	char choice;
	system("clear");
	do{
		string menu = "THE DUNGEON\nn - new Game\nl - load Game\ni - info\nq - quit";
	output(menu, false);
		cin >> choice;
	switch(choice){
		case 'n':
			newGame();
			break;
		case 'l':
			loadGame();
			break;
		case 'i':
			infoScreen();
			system("clear");
			break;
		case 'q':
			return;
			break;
	}
	}while(choice != 'q');
}

void newGame(){
	system("clear");
	char choice;
	string name;
	openingLore();
	system("clear");
	string classChoice = "Declare your class:\np - Paladin\na - Archer\nw - Wizard\nt - Monster Tamer\ni - Intern\nd - Android\nf - Fighter\nr - Random\ne - " + chaosCl();
	output(classChoice, false);
	cin >> choice;
	outputflush("\n\nPress 'r' for a random name\x1b[A\rname yourself: ", false);
	cin.ignore(500, '\n');
	getline(cin, name);
	if(name == "r"){
		name = generateName();
		name.at(0) = toupper(name.at(0));
	}
	system("clear");
	Game maze(choice, name);
	playGame(maze, 1, "");
}

void loadGame(){
// 	system("ls  SaveFiles");
// 	cout << "Please enter save file: " << flush;
	string savefile;
	int num;
// 	cin >> savefile;
// 	if(savefile.size() >= 4){
// 		if(savefile.substr(savefile.size() - 4, savefile.size()) != ".dat")
// 			savefile += ".dat";
// 	}
// 	else{
// 		savefile += ".dat";
// 	}
// 	std::cout << savefile << std::endl;
	DIR *dpdf;
    struct dirent *epdf;
	vector<string> tfiles, files;
	dpdf = opendir("./SaveFiles");
	if (dpdf != NULL) {
	   while (epdf = readdir(dpdf)) {
		  tfiles.push_back(std::string(epdf->d_name));
	   }
	}
	
	for(unsigned i = 0; i < tfiles.size(); ++i){
		if(tfiles.at(i).find(".dat") != std::string::npos)
			files.push_back(tfiles.at(i));
	}
	std::string prompt = "Enter the number associated with the file ('q' to quit): \n";
	for(unsigned i = 0; i < files.size(); ++i){
		prompt += std::to_string(i) + " - " + files.at(i) + '\n';
	}
	output(prompt, false);
	do{
		cin >> num;
		if(cin.fail()){
			cin.clear();
			cin.ignore(500, '\n');
			return;
		}
	}while(num > files.size());
	savefile = files.at(num);
	ifstream inFS("./SaveFiles/" + savefile);
	if(!inFS.is_open()){
// 		system("clear");
		output("unable to load file, quitting", false);
		return;
	}
	int floor;
	string test;
	inFS >> test;
	if(test != "DATAFILE"){
		system("clear");
		output("Wrong file, quitting", false);
		return;
	}
	inFS >> floor;
	//cout << floor << endl;
	inFS.ignore(500, '\n');
	Game maze(inFS);
	playGame(maze, floor, savefile);
}

void playGame(Game &maze, int floor, string filename){
	char choice, k;
// 	system("clear");
	do{
// 			system("clear");
// 			std::cout << floor << "F" << std::endl;
			maze.displayMasked();
// 			maze.displayDungeon();
		cin >> choice;
		switch(choice){
			case 'w':
			case 'a':
			case 's':
			case 'd':
				maze.move(choice);
				break;
			case 'e':
				maze.displayStats();
				//requestReturn();
				break;
			case 'b':
				maze.displayBag();
				break;
			case 'p':
				pauseScreen(maze, floor, filename);
				break;
			case 'm':
				if(maze.mapFound()){
// 					std::cout << floor << "F" << std::endl;
				maze.displayDungeon();
				requestReturn();
				}
				break;
// 			case 'l':
// 				maze.solveDungeon();
// 				maze.displayDungeon();
// 				cin >> k;
// 				break;
		}
// 		system("clear");
		if(maze.dungeonClear()&&floor < 100){
			++floor;
			maze.nextDungeon();
			saveGame(maze, floor, filename);
		}
		if(floor >= 100){
			output("CONGRATS");
			return;
		}
	}while(0==0);
}

void saveGame(Game& maze, int floor, string& filename){
	if(filename.size() == 0){
		outputflush("Creating new save, please enter a name: ", false);
		DIR *dpdf;
		struct dirent *epdf;
		vector<string> tfiles, files;
		dpdf = opendir("./SaveFiles");
		if (dpdf != NULL) {
		   while (epdf = readdir(dpdf)) {
			  tfiles.push_back(std::string(epdf->d_name));
		   }
		}
		for(unsigned i = 0; i < tfiles.size(); ++i){
			if(tfiles.at(i).find(".dat") != std::string::npos)
				files.push_back(tfiles.at(i));
		}
		char c;
		do{
				cin.ignore(500, '\n');
		if(filename.size() == 0){
			getline(cin,filename);
			if(filename.find(".dat") == std::string::npos){
				filename += ".dat";
			}
		}
			if(exists(filename, files)){
				output("filename already exists:\noverwrite - o\nchange name - c\nadd (1) (or change (1) to (2) etc) to end of file - a", false);
				cin >> c;
				string t;
				switch(tolower(c)){
					case 'o':
						c = 'o';
						break;
					case 'c':
						filename.resize(0);
						break;
					case 'a':
						filename.resize(filename.size() - 4);
						for(unsigned i = 1; i < 100; ++i){
							t = "(" + to_string(i) + ")";
							if(filename.find(t) == std::string::npos){
								if(i == 1){
									filename += "(1).dat";
								}
								else{
									filename.resize(filename.size() - 3);
									filename += t + ".dat";									
								}
								break;
							}
						}
						break;
				}
			}
			if(c == 'o')
				break;
		}while(exists(filename, files) || filename.size() == 0);
	}
	ofstream ofs("SaveFiles/"+filename);
	ofs<< "DATAFILE" << endl;
	ofs << floor << endl;
	maze.saveGame(ofs);
}

void openingLore(){
	string sentence;
	ifstream inFS("./Lore/worldLore.txt");
	if(!inFS.is_open()){
		return;
	}
	while(getline(inFS, sentence)){
		if(sentence.size() == 0){
			char k = continueRequest();
			if(k == 'q'){
				return;
			}
			if(k != '\n')
				cin.ignore(500, '\n');
		}
		else{
			output(sentence, 75, true);
		}
// 		cout << sentence << endl;
	}
	continueRequest();
	inFS.close();
	
}

string chaosCl(){
	string name;
	char letter;
	int length = 6 + rand()%4;
	for(int i = 0; i < length; ++i){
		letter = 32 + rand()%95;
		name += letter;
	}
	return name;
}

void pauseScreen(Game& maze, int floor, string& filename){
	std::string screen;
	do{
		screen = "Pause\n";
		screen += "p - return\n";
		screen += "s - save\n";
		screen += "l - symbols legend\n";
		screen += "q - quit";
		output(screen, false);
		char choice;
		cin >> choice;
		switch(choice){
			case 'p':
				return;
			case 's':
				saveGame(maze, floor, filename);
				break;
			case 'l':
				symbolsLegend(maze);
				break;
			case 'q':
				exit(0);
				break;
		}
	}while(0==0);
}

void infoScreen(){
	std::string info = "Controls:\nW - up\nA - Left\nS - Down\nD - Right\n";
	info += "This game only saves player-specific data as well as autosaves at the beginning of each dungeon.\n";
	info += "Loading a game can cause the items that the Chaos class can equip to change.";
	output(info, false);
	requestReturn();
}

void symbolsLegend(const Game& maze){
	std::string symbols =  maze.getPSymbol() + " - player character\n";
	symbols += maze.getMSymbol() + " - monster\n";
	symbols += maze.getWSymbol() + " - wall block\n";
	symbols += maze.getMapSymbol() + " - map\n";
	symbols += maze.getKSymbol() + " - key\n";
	symbols += maze.getSSymbol() + " - shop";
	output(symbols, false);
	requestReturn();
}