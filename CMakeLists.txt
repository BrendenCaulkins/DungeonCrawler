CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
#source CMakeList
project(DungeonCrawler)

SET(CMAKE_CXX_STANDARD 11)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

set (CMAKE_EXE_LINKER_FLAGS -g)

ADD_EXECUTABLE(DungeonCrawler
	main.cpp
	
	#game directory
	Maze.cpp
	Game.cpp
	Dungeon.cpp
	
	#character
	Character.cpp

	#character/player directory
	Archer.cpp
	Paladin.cpp
	Wizard.cpp
	Intern.cpp
	Android.cpp
	MonsterTamer.cpp
	Fighter.cpp
	Chaos.cpp
	
	#character/monster
	Monster.cpp
	GiantBoar.cpp
	Goblin.cpp
	Cerberus.cpp 
	Orc.cpp
	ThugCactus.cpp
	BigChungus.cpp
	KillerGarfield.cpp
	Minotaur.cpp
	Dragon.cpp
	Werewolf.cpp
	Golem.cpp
	Fish.cpp
	Saintan.cpp
	JivinFunkyBadger.cpp
	SuperSoakingSquirter.cpp
	SentientTrebuchet.cpp
	Kyle.cpp
	PorcupineLion.cpp
	
	#itemshop
	Shop.cpp
	Items.cpp
	potions.cpp
	recipeBook.cpp
	
)


target_link_libraries(DungeonCrawler ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY})
