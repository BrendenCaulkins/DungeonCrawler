#include "Maze.h"

Maze::Maze() : numRow(25), numCol(100), maze(numRow, std::vector<std::string>(numCol)), visited(numRow, std::vector<bool>(numCol, false)), endpointx(0), endpointy(0), mazeComplete(false), playerSymbol("\u263B"), wallMaterial("\u2591"), emptySpace(" ") {	 
	newMaze();
	 }

void Maze::newMaze(){
	map = maze;
	fillMaze();
	int x = 0, y = 0;
	endpointx = numCol - 1;
	endpointy = 1 + rand()%(numRow - 2);
	makeMaze(endpointx, endpointy);
	while(!mazeComplete){
		findSpace(x, y);
		makeMaze(x, y);
	}
	mazeComplete = false;
	startpointy = findMazeStart();
	pCoord.y = startpointy;
	pCoord.x = 0;
	resetMap();
	setPosition(pCoord.x, pCoord.y);
}

void Maze::displayMaze(){
	std::string mazeinfo;
    for(int i = 0; i < numRow; ++i){
		mazeinfo.resize(0);
        for(int j = 0; j < numCol; ++j){
            mazeinfo += maze.at(i).at(j);
        }
             output(mazeinfo, false);
	}
}

void Maze::displayMasked(){
// 	for(int i = 0; i < numRow; ++i){
//         for(int j = 0; j < numCol; ++j){
//             std::cout << map.at(i).at(j);
//         }
//              std::cout << std::endl;
// 	}
	std::string maskedline;
	for(int i = 0; i < numRow; ++i){
		maskedline.resize(0);
		for(int j = 0; j < numCol; ++j){
			if( visited.at(i).at(j)){
				if(!isSpace(j, i) && !isWall(j, i))
					if(inSight(j, i))
						maskedline += maze.at(i).at(j);
					else
						maskedline += emptySpace;
				else
					maskedline += maze.at(i).at(j);
			}
			else{
				maskedline += wallMaterial;
			}
		}
		output(maskedline, false);
	}
}

bool Maze::mazeSolved(){
	//return mazeComplete;
	if(pCoord.x == numCol - 1){
		return true;
	}
	return false;
}

void Maze::move(char dir){
	if(canMove(dir)){
		switch(dir){
		case 'D':
		case 'd':
			erasePosition(pCoord.x, pCoord.y);
			setPosition(++pCoord.x, pCoord.y);
			break;
		case 'A':
		case 'a':
			erasePosition(pCoord.x, pCoord.y);
			setPosition(--pCoord.x, pCoord.y);
			break;
		case 'W':
		case 'w':
			erasePosition(pCoord.x, pCoord.y);
			setPosition(pCoord.x, --pCoord.y);
			break;
		case 'S':
		case 's':
			erasePosition(pCoord.x, pCoord.y);
			setPosition(pCoord.x, ++pCoord.y);
			break;
		default:
			break;
	}
		
		return;
	}
	output("Unable to move, please choose a different direction.", false);
}

void Maze::updateVisited(int x, int y){
	visited.at(y).at(x) = true;
	if(x >= 1){
		visited.at(y).at(x - 1) = true;
		
		if(x >= 2){
			if(!isWall(x - 1, y))
				visited.at(y).at(x - 2) = true;
		}
		
		if(y >=1){	
			if(!isWall(x - 1, y)&&!isWall(x,y-1))
				visited.at(y - 1).at(x - 1) = true;
		}
	}
	
	if(x <= numCol - 2){
		visited.at(y).at(x + 1) = true;
		
		if(x <= numCol - 3){
			if(!isWall(x + 1, y))
				visited.at(y).at(x + 2) = true;
		}
		
		if(y <= numRow - 2){
			if(!isWall(x + 1, y)&&!isWall(x,y+1))
				visited.at(y + 1).at(x + 1) = true;
		}
	}
	
	if(y >= 1){
		visited.at(y - 1).at(x) = true;
		
		if(y >= 2){
			if(!isWall(x, y -1))
				visited.at(y - 2).at(x) = true;
		}
		
		if(x <= numCol - 2){
			if(!isWall(x + 1, y)&&!isWall(x,y-1))
				visited.at(y - 1).at(x + 1) = true;
		}
	}
	
	if(y <= numRow - 2){
		visited.at(y + 1).at(x) = true;
		
		if(y <= numRow - 3){
			if(!isWall(x, y+1))
				visited.at(y + 2).at(x) = true;
		}
		
		if(x >= 1){
			if(!isWall(x - 1, y)&&!isWall(x,y+1))
				visited.at(y + 1).at(x - 1) = true;
		}
	}
}

bool Maze::inSight(int x, int y){
	if(std::abs(pCoord.x - x) > 2 || std::abs(pCoord.y - y) > 2)
		return false;
	if((pCoord.x != x && std::abs(pCoord.y - y) > 1) || (pCoord.y != y && std::abs(pCoord.x - x) > 1))
		return false;
	if(pCoord.x != x && pCoord.y != y && isWall(pCoord.x, y) && isWall(x, pCoord.y))
		return false;
	if(isWall((x - pCoord.x)/2 + pCoord.x, (y - pCoord.y)/2 + pCoord.y))
		return false;
	return true;
}

void Maze::makeMaze(int x, int y){
	maze.at(y).at(x) = emptySpace;

	if(!canMove(x, y)){
		return;
	}
	if(makeBranch()){
	
		makeMaze(x, y);
		
		makeBranch(x, y);
	}
	else{
		move(x,y);
		makeMaze(x,y);
	}
}
bool Maze::makeBranch(){
	int chance = rand()%100;
	if(chance < 50){
		return true;
	}
	return false;
}

void Maze::makeBranch(int &x, int &y){
	makeMaze(x, y);
}

bool Maze::canMove(const int x, const int y){
	if(canMoveNorth(x, y) || canMoveSouth(x, y) || canMoveEast(x, y) || canMoveWest(x, y)){
		return true;
	}
	return false;
}

void Maze::move(int &x, int &y){
	bool moved = false;
	if(canMove(x, y)){
		do{
			switch(rand()%4){
				case 0:
					if(canMoveNorth(x, y)){
						--y;
						moved = true;
					}
					break;
				case 1:
					if(canMoveSouth(x, y)){
						++y;
						moved = true;
					}
					break;
				case 2:
					if(canMoveEast(x, y)){
						++x;
						moved = true;
					}
					break;
				case 3:
					if(canMoveWest(x, y)){
						--x;
						moved = true;
					}
					break;
			}
		}while(!moved);
	}
}

bool Maze::isSpace(const int x, const int y){
    if(maze.at(y).at(x) == emptySpace){
        return true;
    }
    return false;
}

void Maze::fillMaze(){
	for(int i = 0; i < numRow; ++i){
        for(int j = 0; j < numCol; ++j){
            maze.at(i).at(j) = wallMaterial;
		}
    }
}
			   
bool Maze::canMoveNorth(const int x, const int y){
	if(x >= numCol - 1 || x <= 0){
		return false;
	}
	if(y <= 1){
		return false;
	}
	if(!isSpace(x, y - 2) && !isSpace(x-1, y-1) && !isSpace(x, y - 1) && !isSpace(x+1, y-1)){
		return true;
	}
	return false;
}
bool Maze::canMoveSouth(const int x, const int y){
	if(x >= numCol - 1 || x <= 0){
		return false;
	}
	if(y >= numRow - 2){
		return false;
	}
	if(!isSpace(x, y + 2) && !isSpace(x-1, y+1) && !isSpace(x+1, y+1)&&!isSpace(x, y + 1)){
		return true;
	}
	return false;
}
bool Maze::canMoveEast(const int x, const int y){
	if(x >= numCol - 2){
		return false;
	}
	if(!isSpace(x + 2, y) && !isSpace(x+1, y-1) && !isSpace(x+1, y+1)&&!isSpace(x + 1, y)){
		return true;
	}
	return false;
}
bool Maze::canMoveWest(const int x, const int y){
	if(x == 0){
		mazeComplete = true;
		return false;
	}
	if(x <= 1 && mazeComplete){
		return false;
	}
	else if(x <= 1 && !mazeComplete){
		return true;
	}
	if(!isSpace(x - 2, y) && !isSpace(x - 1, y - 1) && !isSpace(x - 1, y)&&!isSpace(x - 1, y + 1)){
		return true;
	}
	return false;
}
void Maze::findSpace(int& x, int& y){
	do{
		x = 1 + rand()%(numCol - 2);
		y = 1 + rand()%(numRow - 2);
	}while(!isSpace(x, y)/*|| !canMove(x, y)*/);
}

int Maze::findMazeStart(){
	for(int i = 0; i <maze.size();++i){
		if(isSpace(0, i)){ 
			return i;
		}
	}
return 0;
}

void Maze::resetMap(){
	for(int i = 0; i < numRow; ++i){
        for(int j = 0; j < numCol; ++j){
            map.at(i).at(j) = wallMaterial;
			visited.at(i).at(j) = false;
		}
    }
}

void Maze::updateMap(int x, int y){
	
	map.at(y).at(x) = maze.at(y).at(x);
	
	if(x >= 1){
		map.at(y).at(x - 1) = maze.at(y).at(x - 1);
		
		if(x >= 2){
			if(!isWall(x - 1, y))
				map.at(y).at(x - 2) = maze.at(y).at(x - 2);
		}
		
		if(y >=1){	
			if(!isWall(x - 1, y)&&!isWall(x,y-1))
				map.at(y - 1).at(x - 1) = maze.at(y - 1).at(x - 1);
		}
	}
	
	if(x <= numCol - 2){
		map.at(y).at(x + 1) = maze.at(y).at(x + 1);
		
		if(x <= numCol - 3){
			if(!isWall(x + 1, y))
				map.at(y).at(x + 2) = maze.at(y).at(x + 2);
		}
		
		if(y <= numRow - 2){
			if(!isWall(x + 1, y)&&!isWall(x,y+1))
				map.at(y + 1).at(x + 1) = maze.at(y + 1).at(x + 1);
		}
	}
	
	if(y >= 1){
		map.at(y - 1).at(x) = maze.at(y - 1).at(x);
		
		if(y >= 2){
			if(!isWall(x, y -1))
				map.at(y - 2).at(x) = maze.at(y - 2).at(x);
		}
		
		if(x <= numCol - 2){
			if(!isWall(x + 1, y)&&!isWall(x,y-1))
				map.at(y - 1).at(x + 1) = maze.at(y - 1).at(x + 1);
		}
	}
	
	if(y <= numRow - 2){
		map.at(y + 1).at(x) = maze.at(y + 1).at(x);
		
		if(y <= numRow - 3){
			if(!isWall(x, y+1))
				map.at(y + 2).at(x) = maze.at(y + 2).at(x);
		}
		
		if(x >= 1){
			if(!isWall(x - 1, y)&&!isWall(x,y+1))
				map.at(y + 1).at(x - 1) = maze.at(y + 1).at(x - 1);
		}
	}
}

void Maze::setPosition(int x, int y){
	maze.at(y).at(x) = playerSymbol;
// 	updateMap(x, y);
	updateVisited(x, y);
}

void Maze::erasePosition(int x, int y){
	erasePositionMap(x, y);
	erasePositionMaze(x, y);
}

void Maze::erasePositionMaze(int x, int y){
	maze.at(y).at(x) = emptySpace;
}

void Maze::erasePositionMap(int x, int y){
	map.at(y).at(x) = emptySpace;
}

bool Maze::canMove(char dir){
	switch(std::toupper(dir)){
		case 'D':
			return !isWall(pCoord.x + 1, pCoord.y);
			break;
		case 'A':
			if(pCoord.x == 0){
				return false;
			}
			return !isWall(pCoord.x - 1, pCoord.y);
			break;
		case 'W':
			return !isWall(pCoord.x, pCoord.y - 1);
			break;
		case 'S':
			return !isWall(pCoord.x, pCoord.y + 1);
			break;
	}
return false;
}

void Maze::solveMaze(){
	pCoord.x = 0;
	pCoord.y = startpointy;
	while(!mazeSolved()){
		char move;
		switch(rand()%4){
			case 0:
				move = 'W';
				break;
			case 1:
				move = 'S';
				break;
			case 2:
				move = 'D';
				break;
			case 3:
				move = 'A';
				break;
				
		}
		sMove(move);
	}
}

void Maze::sMove(char move){
	if(sCanMove(move)){
		switch(move){
			case 'D':
				if(isPlayerSymbol(pCoord.x + 1, pCoord.y)){
					erasePosition(pCoord.x, pCoord.y);
				}
				setPosition(++pCoord.x, pCoord.y);
				break;
			case 'A':
				if(isPlayerSymbol(pCoord.x - 1, pCoord.y)){
					erasePosition(pCoord.x, pCoord.y);
				}
				setPosition(--pCoord.x, pCoord.y);
				break;
			case 'W':
				if(isPlayerSymbol(pCoord.x, pCoord.y - 1)){
					erasePosition(pCoord.x, pCoord.y);
				}
				setPosition(pCoord.x, --pCoord.y);
				break;
			case 'S':
				if(isPlayerSymbol(pCoord.x, pCoord.y + 1)){
					erasePosition(pCoord.x, pCoord.y);
				}
				setPosition(pCoord.x, ++pCoord.y);
				break;
		}
	}
}

bool Maze::sCanMove(char move){
	switch(move){
		case 'D':
			if(!isWall(pCoord.x + 1, pCoord.y)){
				return true;
			}
			break;
		case 'A':
			if(pCoord.x >=1){
			if(!isWall(pCoord.x - 1, pCoord.y)){
				return true;
			}
			}
			break;
		case 'W':
			if(!isWall(pCoord.x, pCoord.y - 1)){
				return true;
			}
			break;
		case 'S':
			if(!isWall(pCoord.x, pCoord.y + 1)){
				return true;
			}
			break;
	}
	return false;
}

bool Maze::isPlayerSymbol(int x, int y){
	if(maze.at(y).at(x) == playerSymbol){
        return true;
    }
    return false;
}

bool Maze::isWall(int x, int y){
	if(maze.at(y).at(x) == wallMaterial){
		return true;
	}
	return false;
}