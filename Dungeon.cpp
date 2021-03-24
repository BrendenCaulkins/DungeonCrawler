#include "Dungeon.h"

Dungeon::Dungeon() : tp(false), chestVis(false), invis(0) {
	newDungeon();
}

void Dungeon::newDungeon(){
	newMaze();
	pmap.found = false;
	key.found = false;
	hasShovel = false;
	Monsters.resize(0);
	Monsters.resize(/*getValInRange(25, 40)*/100);
	for(int i = 0; i < Monsters.size();++i){
		setCoords(Monsters.at(i).loc.x, Monsters.at(i).loc.y, i%4+1);
		setMonster(Monsters.at(i).loc.x, Monsters.at(i).loc.y, i);
		Monsters.at(i).encountered = false;
		if(i == 0)
			Monsters.at(i).type = createSpecialMonster();
		else
			Monsters.at(i).type = createRegularMonster();
	}
// 	for(int i = 0; i < Monsters.size(); ++i){
// 		std::cout << i << " " <<  Monsters.at(i).type -> getName() << std::endl;
// 	}
	giveMonShovel();
	summonBoss();
	setMap();
	displayMap();
	setKey();
	displayKey();
	setShop();
	setChest();
	displayShop();
}

void Dungeon::move(char dir){
// 	Coord p = pCoord;
	if(std::toupper(dir) == 'D'&& pCoord.x == numCol - 2 && !isWall(pCoord.x + 1, pCoord.y)){
		if(keyFound()){
			Maze::move(dir);
		
		}
	}
	else if(hasShovelCanMove(dir)){
		erasePosition(pCoord.x, pCoord.y);
		moveForward(pCoord.x, pCoord.y, dir);
	}
	else{
		Maze::move(dir);
		
	}
	if(!keyFound())
		tryForKey();
	if(!mapFound())
		tryForMap();
	if(invis <=0){
		invis = 0;
		moveMonsters();
	}
	else{
		--invis;
		moveMonstersPInvis();
	}
	setEveryone();
}

void Dungeon::tryForMap(){
	if(pmap.loc.x == pCoord.x && pmap.loc.y == pCoord.y){
		output("Map located, press 'm' to display it.", false);
		pmap.found = true;
	}
}

void Dungeon::tryForKey(){
	if(key.loc.x == pCoord.x && key.loc.y == pCoord.y){
		output("The key has been found, the exit to the dungeon is now open.", false);
		key.found = true;
	}
}

void Dungeon::setEveryone(){
	if(!keyFound()){
		displayKey();
	}
	if(!mapFound()){
		displayMap();
	}
	if(chestVisible() && !chestFound()){
		displayChest();
	}
	displayShop();
	for(int i = 0; i < Monsters.size(); ++i){
		setMonster(Monsters.at(i).loc.x, Monsters.at(i).loc.y, i);
	}
	setPosition(pCoord.x, pCoord.y);
}

void Dungeon::moveMonsters(){
	for(int i = 0; i < Monsters.size(); ++i){
		erasePositionMaze(Monsters.at(i).loc.x, Monsters.at(i).loc.y);
		moveMonster(Monsters.at(i).loc.x, Monsters.at(i).loc.y);
		setMonster(Monsters.at(i).loc.x, Monsters.at(i).loc.y, i);
		
	}
}

void Dungeon::moveMonstersPInvis(){
	for(int i = 0; i < Monsters.size(); ++i){
		erasePositionMaze(Monsters.at(i).loc.x, Monsters.at(i).loc.y);
		Coord p;
		p.x= Monsters.at(i).loc.x;
		p.y = Monsters.at(i).loc.y;
		char m;
		do{
			switch(rand()%4){
				case 0:
					m = 'W';
					break;
				case 1:
					m = 'A';
					break;
				case 2:
					m = 'S';
					break;
				case 3:
					m = 'D';
					break;
			}
			if(canMoveForward(Monsters.at(i).loc.x, Monsters.at(i).loc.y, m)){
				moveForward(Monsters.at(i).loc.x, Monsters.at(i).loc.y, m);
			}
		}while(p.x == Monsters.at(i).loc.x && p.y == Monsters.at(i).loc.y);
		setMonster(Monsters.at(i).loc.x, Monsters.at(i).loc.y, i);
	}
}

void Dungeon::moveMonster(int &x, int &y){
	int chance = rand()%100;
	if(chance < 70){
	char p = findShortestPath(x, y);
		if(canMoveForward(x, y, p)&&!checkForMonster(x, y, p)){
			moveForward(x, y, p);
		}
	}
	else{
		Coord p;
		p.x= x;
		p.y = y;
		char m;
		do{
			switch(rand()%4){
				case 0:
					m = 'W';
					break;
				case 1:
					m = 'A';
					break;
				case 2:
					m = 'S';
					break;
				case 3:
					m = 'D';
					break;
			}
			if(canMoveForward(x, y, m)){
				moveForward(x, y, m);
			}
		}while(p.x == x && p.y == y);
	}
}

bool Dungeon::checkForMonster(int x, int y, char facing){
	switch(std::toupper(facing)){
		case 'W':
			return isMonster(x, y-1);
			break;
		case 'A':
			return isMonster(x-1, y);
			break;
		case 'S':
			return isMonster(x, y+1);
			break;
		case 'D':
			return isMonster(x+1, y);
	}
return true;
}

char Dungeon::findShortestPath(int x, int y){
	if(x == pCoord.x && y == pCoord.y){
		return 'q';
	}
	std::deque<pathFind> path;
	std::vector<std::vector<bool>> been(numRow, std::vector<bool>(numCol));
	for(int i = 0; i < numRow; ++i){
        for(int j = 0; j < numCol; ++j){
            been.at(i).at(j) = false;
		}
    }
	if(canMoveForward(x, y, 'W')){
		path.push_back(pathFind(x, y-1, 'W'));
		been.at(y-1).at(x) = true;
	}
	if(canMoveForward(x, y, 'A')){
		path.push_back(pathFind(x-1, y, 'A'));
		been.at(y).at(x-1) = true;
	}
	if(canMoveForward(x, y, 'S')){
		path.push_back(pathFind(x, y+1, 'S'));
		been.at(y+1).at(x) = true;
	}
	if(canMoveForward(x, y, 'D')){
		path.push_back(pathFind(x+1, y, 'D'));
		been.at(y).at(x+1) = true;
	}
	while(!path.empty()){
		path.front();
		if(path.front().currCoord.x == pCoord.x && path.front().currCoord.y == pCoord.y){
			break;
		}
		if(path.front().lastMove != 'S' && canMoveForward(path.front().currCoord.x, path.front().currCoord.y, 'W') && !been.at(path.front().currCoord.y-1).at(path.front().currCoord.x)){
			been.at(path.front().currCoord.y-1).at(path.front().currCoord.x) = true;
			path.push_back(pathFind(path.front().currCoord.x, path.front().currCoord.y-1, path.front().firstMove, 'W'));
		}
		if(path.front().lastMove != 'D' && canMoveForward(path.front().currCoord.x, path.front().currCoord.y, 'A') && !been.at(path.front().currCoord.y).at(path.front().currCoord.x-1)){
			been.at(path.front().currCoord.y).at(path.front().currCoord.x-1) = true;
			path.push_back(pathFind(path.front().currCoord.x-1, path.front().currCoord.y, path.front().firstMove, 'A'));
		}
		if(path.front().lastMove != 'W' && canMoveForward(path.front().currCoord.x, path.front().currCoord.y, 'S') && !been.at(path.front().currCoord.y+1).at(path.front().currCoord.x)){
			been.at(path.front().currCoord.y+1).at(path.front().currCoord.x) = true;
			path.push_back(pathFind(path.front().currCoord.x, path.front().currCoord.y+1, path.front().firstMove, 'S'));
		}
		if(path.front().lastMove != 'A' && canMoveForward(path.front().currCoord.x, path.front().currCoord.y, 'D') && !been.at(path.front().currCoord.y).at(path.front().currCoord.x+1)){
			been.at(path.front().currCoord.y-1).at(path.front().currCoord.x) = true;
			path.push_back(pathFind(path.front().currCoord.x+1, path.front().currCoord.y, path.front().firstMove, 'D'));
		}
		path.pop_front();
	}
	return path.front().firstMove;
}


void Dungeon::setCoords(int &x, int &y, int quadrant){//quadrants are 1-4
	do{
		switch(quadrant){
			case 1:
				x = 1+rand()%((numCol-1)/2);
				y = 1+rand()%((numRow-1)/2);
				break;
			case 2:
				x = (1+(numCol-2)/2)+rand()%((numCol-1)/2);
				y = 1+rand()%((numRow-1)/2);
				break;
			case 3:
				x = 1+rand()%((numCol-1)/2);
				y = (1+(numRow-2)/2)+rand()%((numRow-1)/2);				
				break;
			case 4:
				x = (1+(numCol-2)/2)+rand()%((numCol-1)/2);
				y = (1+(numRow-2)/2)+rand()%((numRow-1)/2);
				break;
			default:
				x = (1+(numCol-2)/2)+rand()%((numCol-1)/2);
				y = (1+(numRow-2)/2)+rand()%((numRow-1)/2);
				break;
		}
	}while(!isSpace(x, y)/*|| !canMove(x, y)*/);
}

void Dungeon::setMonster(int x, int y, int indx){
	maze.at(y).at(x) = Monsters.at(indx).look;
}

void Dungeon::setMap(){
	findSpace(pmap.loc.x, pmap.loc.y);
}

void Dungeon::displayMap(){
	maze.at(pmap.loc.y).at(pmap.loc.x) = pmap.look;
}

void Dungeon::setKey(){
	findSpace(key.loc.x, key.loc.y);
}

void Dungeon::setShop(){
// 	Store.store.refillInventory();
	findSpace(Store.loc.x, Store.loc.y);
// 	Store.loc.x = 1;
}

void Dungeon::setChest(){
	treasure.visible = false;
	treasure.found = false;
	while(!treasure.contents.empty()){
		Item* temp = treasure.contents.at(treasure.contents.size()-1);
		treasure.contents.pop_back();
		delete temp;
	}
	for(unsigned i = 0; i < rand()%4 + 1; ++i){
		switch(rand()%2){
			case 0:
				treasure.contents.push_back(dropWeapon("Mimic", getValInRange(1, 300), getValInRange(1, 100)));
				break;
			case 1:
				treasure.contents.push_back(dropDefensive("Mimic", getValInRange(1, 300), getValInRange(1, 100)));
				break;
		}
	}
	findSpace(treasure.loc.x, treasure.loc.y);
}

void Dungeon::displayKey(){
	maze.at(key.loc.y).at(key.loc.x) = key.look;
}

void Dungeon::displayShop(){
	maze.at(Store.loc.y).at(Store.loc.x) = Store.look;
}

void Dungeon::displayChest(){
	if(chestVisible())
		maze.at(treasure.loc.y).at(treasure.loc.x) = treasure.look;
}

void Dungeon::teleportPlayer(){
	erasePosition(pCoord.x, pCoord.y);
	findSpace(pCoord.x, pCoord.y);
	setPosition(pCoord.x, pCoord.y);
}

bool Dungeon::hasShovelCanMove(char dir){
	if(!canDig()){
		return false;
	}
	switch(std::toupper(dir)){
		case 'D':
			if(pCoord.x != numCol - 2){
				return true;
			}
			if(isWall(pCoord.x + 1, pCoord.y)){
				return false;
			}
			if(!keyFound()){
				return false;
			}
			return true;
			break;
		case 'A':
			if(pCoord.x == 0){
				return false;
			}
			if(pCoord.x == 1 &&isWall(pCoord.x - 1, pCoord.y)){
				return false;
			}
			return true;
			break;
		case 'W':
			 if(pCoord.y == 1||pCoord.x == 0){
				 return false;
			 }
			return true;
			break;
		case 'S':
			if(pCoord.y == numRow - 2||pCoord.x == 0){
				return false;
			}
			return true;
			break;
	}
output("ERROR", false);
    return false;
}

Character* Dungeon::createRegularMonster(){
	switch(rand()%4){
		case 0:
			return new Goblin(generateName());
			break;
		case 1:
			return new Orc(generateName());
			break;
		case 2:
			return new GiantBoar(generateName());
			break;
		case 3:
			return new JivinFunkyBadger(generateName());
			break;
	}
	return new GiantBoar(generateName());
}

Character* Dungeon::createSpecialMonster(){
	if(rand()%100 == 69){
			return new Kyle(generateName());
		}
		switch(rand()%4){
			case 0:
				return new ThugCactus(generateName());
				break;
			case 1:
				return new BigChungus(generateName());
				break;
			case 2:
				return new KillerGarfield(generateName());
				break;
			case 3:
				return new Saintan(generateName());
				break;
		}
		return new ThugCactus(generateName());
}

void Dungeon::summonBoss(){
	switch(rand()%8){
		case 0:
			boss = new Cerberus(generateName());
			break;
		case 1:
			boss = new Minotaur(generateName()); 
			break;
		case 2:
			boss = new Dragon(generateName()); 
			break;
		case 3:
			boss = new Werewolf(generateName()); 
			break;
		case 4:
			boss = new Golem(generateName());
			break;
		case 5:
			boss = new Fish(generateName());
			break;
		case 6:
			boss = new SuperSoakingSquirter(generateName());
			break;
		case 7:
			boss = new SentientTrebuchet(generateName());
			break;
	}
}

void Dungeon::moveForward(int& x,int& y,char facing){
	switch(std::toupper(facing)){
		case 'A':
			--x;
			return;
		case 'D':
			++x;
			return;
		case 'S':
			++y;
			return;
		case 'W':
			--y;
			return;
	}
}
	
bool Dungeon::canMoveForward(int x,int y, char facing){
	switch(std::toupper(facing)){
		case 'A':
			if(x < 1){
				return false;
			}
			return !isWall(x - 1, y);
			break;
		case 'D':
			if(x >= numCol - 1){
				return false;
			}
			return !isWall(x+1, y);
			break;
		case 'S':
			if(y >= numRow - 1){
				return false;
			}
			return !isWall(x, y + 1);
			break;
		case 'W':
			if(y < 1){
				return false;
			}
			return !isWall(x, y - 1);
			break;
	}
	return false;
}
