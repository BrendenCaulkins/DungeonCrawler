# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/c/Users/brend/Desktop/Jupyterlab/Personal stuff/DungeonCrawler"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/brend/Desktop/JupyterLab/Personal stuff/DungeonCrawler"

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start "/mnt/c/Users/brend/Desktop/JupyterLab/Personal stuff/DungeonCrawler/CMakeFiles" "/mnt/c/Users/brend/Desktop/JupyterLab/Personal stuff/DungeonCrawler/CMakeFiles/progress.marks"
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start "/mnt/c/Users/brend/Desktop/JupyterLab/Personal stuff/DungeonCrawler/CMakeFiles" 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named DungeonCrawler

# Build rule for target.
DungeonCrawler: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 DungeonCrawler
.PHONY : DungeonCrawler

# fast build rule for target.
DungeonCrawler/fast:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/build
.PHONY : DungeonCrawler/fast

Android.o: Android.cpp.o

.PHONY : Android.o

# target to build an object file
Android.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Android.cpp.o
.PHONY : Android.cpp.o

Android.i: Android.cpp.i

.PHONY : Android.i

# target to preprocess a source file
Android.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Android.cpp.i
.PHONY : Android.cpp.i

Android.s: Android.cpp.s

.PHONY : Android.s

# target to generate assembly for a file
Android.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Android.cpp.s
.PHONY : Android.cpp.s

Archer.o: Archer.cpp.o

.PHONY : Archer.o

# target to build an object file
Archer.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Archer.cpp.o
.PHONY : Archer.cpp.o

Archer.i: Archer.cpp.i

.PHONY : Archer.i

# target to preprocess a source file
Archer.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Archer.cpp.i
.PHONY : Archer.cpp.i

Archer.s: Archer.cpp.s

.PHONY : Archer.s

# target to generate assembly for a file
Archer.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Archer.cpp.s
.PHONY : Archer.cpp.s

BigChungus.o: BigChungus.cpp.o

.PHONY : BigChungus.o

# target to build an object file
BigChungus.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/BigChungus.cpp.o
.PHONY : BigChungus.cpp.o

BigChungus.i: BigChungus.cpp.i

.PHONY : BigChungus.i

# target to preprocess a source file
BigChungus.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/BigChungus.cpp.i
.PHONY : BigChungus.cpp.i

BigChungus.s: BigChungus.cpp.s

.PHONY : BigChungus.s

# target to generate assembly for a file
BigChungus.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/BigChungus.cpp.s
.PHONY : BigChungus.cpp.s

Cerberus.o: Cerberus.cpp.o

.PHONY : Cerberus.o

# target to build an object file
Cerberus.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Cerberus.cpp.o
.PHONY : Cerberus.cpp.o

Cerberus.i: Cerberus.cpp.i

.PHONY : Cerberus.i

# target to preprocess a source file
Cerberus.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Cerberus.cpp.i
.PHONY : Cerberus.cpp.i

Cerberus.s: Cerberus.cpp.s

.PHONY : Cerberus.s

# target to generate assembly for a file
Cerberus.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Cerberus.cpp.s
.PHONY : Cerberus.cpp.s

Chaos.o: Chaos.cpp.o

.PHONY : Chaos.o

# target to build an object file
Chaos.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Chaos.cpp.o
.PHONY : Chaos.cpp.o

Chaos.i: Chaos.cpp.i

.PHONY : Chaos.i

# target to preprocess a source file
Chaos.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Chaos.cpp.i
.PHONY : Chaos.cpp.i

Chaos.s: Chaos.cpp.s

.PHONY : Chaos.s

# target to generate assembly for a file
Chaos.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Chaos.cpp.s
.PHONY : Chaos.cpp.s

Character.o: Character.cpp.o

.PHONY : Character.o

# target to build an object file
Character.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Character.cpp.o
.PHONY : Character.cpp.o

Character.i: Character.cpp.i

.PHONY : Character.i

# target to preprocess a source file
Character.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Character.cpp.i
.PHONY : Character.cpp.i

Character.s: Character.cpp.s

.PHONY : Character.s

# target to generate assembly for a file
Character.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Character.cpp.s
.PHONY : Character.cpp.s

Dragon.o: Dragon.cpp.o

.PHONY : Dragon.o

# target to build an object file
Dragon.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Dragon.cpp.o
.PHONY : Dragon.cpp.o

Dragon.i: Dragon.cpp.i

.PHONY : Dragon.i

# target to preprocess a source file
Dragon.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Dragon.cpp.i
.PHONY : Dragon.cpp.i

Dragon.s: Dragon.cpp.s

.PHONY : Dragon.s

# target to generate assembly for a file
Dragon.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Dragon.cpp.s
.PHONY : Dragon.cpp.s

Dungeon.o: Dungeon.cpp.o

.PHONY : Dungeon.o

# target to build an object file
Dungeon.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Dungeon.cpp.o
.PHONY : Dungeon.cpp.o

Dungeon.i: Dungeon.cpp.i

.PHONY : Dungeon.i

# target to preprocess a source file
Dungeon.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Dungeon.cpp.i
.PHONY : Dungeon.cpp.i

Dungeon.s: Dungeon.cpp.s

.PHONY : Dungeon.s

# target to generate assembly for a file
Dungeon.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Dungeon.cpp.s
.PHONY : Dungeon.cpp.s

Fighter.o: Fighter.cpp.o

.PHONY : Fighter.o

# target to build an object file
Fighter.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Fighter.cpp.o
.PHONY : Fighter.cpp.o

Fighter.i: Fighter.cpp.i

.PHONY : Fighter.i

# target to preprocess a source file
Fighter.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Fighter.cpp.i
.PHONY : Fighter.cpp.i

Fighter.s: Fighter.cpp.s

.PHONY : Fighter.s

# target to generate assembly for a file
Fighter.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Fighter.cpp.s
.PHONY : Fighter.cpp.s

Fish.o: Fish.cpp.o

.PHONY : Fish.o

# target to build an object file
Fish.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Fish.cpp.o
.PHONY : Fish.cpp.o

Fish.i: Fish.cpp.i

.PHONY : Fish.i

# target to preprocess a source file
Fish.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Fish.cpp.i
.PHONY : Fish.cpp.i

Fish.s: Fish.cpp.s

.PHONY : Fish.s

# target to generate assembly for a file
Fish.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Fish.cpp.s
.PHONY : Fish.cpp.s

Game.o: Game.cpp.o

.PHONY : Game.o

# target to build an object file
Game.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Game.cpp.o
.PHONY : Game.cpp.o

Game.i: Game.cpp.i

.PHONY : Game.i

# target to preprocess a source file
Game.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Game.cpp.i
.PHONY : Game.cpp.i

Game.s: Game.cpp.s

.PHONY : Game.s

# target to generate assembly for a file
Game.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Game.cpp.s
.PHONY : Game.cpp.s

GiantBoar.o: GiantBoar.cpp.o

.PHONY : GiantBoar.o

# target to build an object file
GiantBoar.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/GiantBoar.cpp.o
.PHONY : GiantBoar.cpp.o

GiantBoar.i: GiantBoar.cpp.i

.PHONY : GiantBoar.i

# target to preprocess a source file
GiantBoar.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/GiantBoar.cpp.i
.PHONY : GiantBoar.cpp.i

GiantBoar.s: GiantBoar.cpp.s

.PHONY : GiantBoar.s

# target to generate assembly for a file
GiantBoar.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/GiantBoar.cpp.s
.PHONY : GiantBoar.cpp.s

Goblin.o: Goblin.cpp.o

.PHONY : Goblin.o

# target to build an object file
Goblin.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Goblin.cpp.o
.PHONY : Goblin.cpp.o

Goblin.i: Goblin.cpp.i

.PHONY : Goblin.i

# target to preprocess a source file
Goblin.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Goblin.cpp.i
.PHONY : Goblin.cpp.i

Goblin.s: Goblin.cpp.s

.PHONY : Goblin.s

# target to generate assembly for a file
Goblin.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Goblin.cpp.s
.PHONY : Goblin.cpp.s

Golem.o: Golem.cpp.o

.PHONY : Golem.o

# target to build an object file
Golem.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Golem.cpp.o
.PHONY : Golem.cpp.o

Golem.i: Golem.cpp.i

.PHONY : Golem.i

# target to preprocess a source file
Golem.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Golem.cpp.i
.PHONY : Golem.cpp.i

Golem.s: Golem.cpp.s

.PHONY : Golem.s

# target to generate assembly for a file
Golem.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Golem.cpp.s
.PHONY : Golem.cpp.s

Intern.o: Intern.cpp.o

.PHONY : Intern.o

# target to build an object file
Intern.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Intern.cpp.o
.PHONY : Intern.cpp.o

Intern.i: Intern.cpp.i

.PHONY : Intern.i

# target to preprocess a source file
Intern.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Intern.cpp.i
.PHONY : Intern.cpp.i

Intern.s: Intern.cpp.s

.PHONY : Intern.s

# target to generate assembly for a file
Intern.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Intern.cpp.s
.PHONY : Intern.cpp.s

Items.o: Items.cpp.o

.PHONY : Items.o

# target to build an object file
Items.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Items.cpp.o
.PHONY : Items.cpp.o

Items.i: Items.cpp.i

.PHONY : Items.i

# target to preprocess a source file
Items.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Items.cpp.i
.PHONY : Items.cpp.i

Items.s: Items.cpp.s

.PHONY : Items.s

# target to generate assembly for a file
Items.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Items.cpp.s
.PHONY : Items.cpp.s

JivinFunkyBadger.o: JivinFunkyBadger.cpp.o

.PHONY : JivinFunkyBadger.o

# target to build an object file
JivinFunkyBadger.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/JivinFunkyBadger.cpp.o
.PHONY : JivinFunkyBadger.cpp.o

JivinFunkyBadger.i: JivinFunkyBadger.cpp.i

.PHONY : JivinFunkyBadger.i

# target to preprocess a source file
JivinFunkyBadger.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/JivinFunkyBadger.cpp.i
.PHONY : JivinFunkyBadger.cpp.i

JivinFunkyBadger.s: JivinFunkyBadger.cpp.s

.PHONY : JivinFunkyBadger.s

# target to generate assembly for a file
JivinFunkyBadger.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/JivinFunkyBadger.cpp.s
.PHONY : JivinFunkyBadger.cpp.s

KillerGarfield.o: KillerGarfield.cpp.o

.PHONY : KillerGarfield.o

# target to build an object file
KillerGarfield.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/KillerGarfield.cpp.o
.PHONY : KillerGarfield.cpp.o

KillerGarfield.i: KillerGarfield.cpp.i

.PHONY : KillerGarfield.i

# target to preprocess a source file
KillerGarfield.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/KillerGarfield.cpp.i
.PHONY : KillerGarfield.cpp.i

KillerGarfield.s: KillerGarfield.cpp.s

.PHONY : KillerGarfield.s

# target to generate assembly for a file
KillerGarfield.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/KillerGarfield.cpp.s
.PHONY : KillerGarfield.cpp.s

Kyle.o: Kyle.cpp.o

.PHONY : Kyle.o

# target to build an object file
Kyle.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Kyle.cpp.o
.PHONY : Kyle.cpp.o

Kyle.i: Kyle.cpp.i

.PHONY : Kyle.i

# target to preprocess a source file
Kyle.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Kyle.cpp.i
.PHONY : Kyle.cpp.i

Kyle.s: Kyle.cpp.s

.PHONY : Kyle.s

# target to generate assembly for a file
Kyle.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Kyle.cpp.s
.PHONY : Kyle.cpp.s

Maze.o: Maze.cpp.o

.PHONY : Maze.o

# target to build an object file
Maze.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Maze.cpp.o
.PHONY : Maze.cpp.o

Maze.i: Maze.cpp.i

.PHONY : Maze.i

# target to preprocess a source file
Maze.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Maze.cpp.i
.PHONY : Maze.cpp.i

Maze.s: Maze.cpp.s

.PHONY : Maze.s

# target to generate assembly for a file
Maze.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Maze.cpp.s
.PHONY : Maze.cpp.s

Minotaur.o: Minotaur.cpp.o

.PHONY : Minotaur.o

# target to build an object file
Minotaur.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Minotaur.cpp.o
.PHONY : Minotaur.cpp.o

Minotaur.i: Minotaur.cpp.i

.PHONY : Minotaur.i

# target to preprocess a source file
Minotaur.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Minotaur.cpp.i
.PHONY : Minotaur.cpp.i

Minotaur.s: Minotaur.cpp.s

.PHONY : Minotaur.s

# target to generate assembly for a file
Minotaur.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Minotaur.cpp.s
.PHONY : Minotaur.cpp.s

Monster.o: Monster.cpp.o

.PHONY : Monster.o

# target to build an object file
Monster.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Monster.cpp.o
.PHONY : Monster.cpp.o

Monster.i: Monster.cpp.i

.PHONY : Monster.i

# target to preprocess a source file
Monster.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Monster.cpp.i
.PHONY : Monster.cpp.i

Monster.s: Monster.cpp.s

.PHONY : Monster.s

# target to generate assembly for a file
Monster.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Monster.cpp.s
.PHONY : Monster.cpp.s

MonsterTamer.o: MonsterTamer.cpp.o

.PHONY : MonsterTamer.o

# target to build an object file
MonsterTamer.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/MonsterTamer.cpp.o
.PHONY : MonsterTamer.cpp.o

MonsterTamer.i: MonsterTamer.cpp.i

.PHONY : MonsterTamer.i

# target to preprocess a source file
MonsterTamer.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/MonsterTamer.cpp.i
.PHONY : MonsterTamer.cpp.i

MonsterTamer.s: MonsterTamer.cpp.s

.PHONY : MonsterTamer.s

# target to generate assembly for a file
MonsterTamer.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/MonsterTamer.cpp.s
.PHONY : MonsterTamer.cpp.s

Orc.o: Orc.cpp.o

.PHONY : Orc.o

# target to build an object file
Orc.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Orc.cpp.o
.PHONY : Orc.cpp.o

Orc.i: Orc.cpp.i

.PHONY : Orc.i

# target to preprocess a source file
Orc.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Orc.cpp.i
.PHONY : Orc.cpp.i

Orc.s: Orc.cpp.s

.PHONY : Orc.s

# target to generate assembly for a file
Orc.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Orc.cpp.s
.PHONY : Orc.cpp.s

Paladin.o: Paladin.cpp.o

.PHONY : Paladin.o

# target to build an object file
Paladin.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Paladin.cpp.o
.PHONY : Paladin.cpp.o

Paladin.i: Paladin.cpp.i

.PHONY : Paladin.i

# target to preprocess a source file
Paladin.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Paladin.cpp.i
.PHONY : Paladin.cpp.i

Paladin.s: Paladin.cpp.s

.PHONY : Paladin.s

# target to generate assembly for a file
Paladin.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Paladin.cpp.s
.PHONY : Paladin.cpp.s

PorcupineLion.o: PorcupineLion.cpp.o

.PHONY : PorcupineLion.o

# target to build an object file
PorcupineLion.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/PorcupineLion.cpp.o
.PHONY : PorcupineLion.cpp.o

PorcupineLion.i: PorcupineLion.cpp.i

.PHONY : PorcupineLion.i

# target to preprocess a source file
PorcupineLion.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/PorcupineLion.cpp.i
.PHONY : PorcupineLion.cpp.i

PorcupineLion.s: PorcupineLion.cpp.s

.PHONY : PorcupineLion.s

# target to generate assembly for a file
PorcupineLion.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/PorcupineLion.cpp.s
.PHONY : PorcupineLion.cpp.s

Saintan.o: Saintan.cpp.o

.PHONY : Saintan.o

# target to build an object file
Saintan.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Saintan.cpp.o
.PHONY : Saintan.cpp.o

Saintan.i: Saintan.cpp.i

.PHONY : Saintan.i

# target to preprocess a source file
Saintan.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Saintan.cpp.i
.PHONY : Saintan.cpp.i

Saintan.s: Saintan.cpp.s

.PHONY : Saintan.s

# target to generate assembly for a file
Saintan.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Saintan.cpp.s
.PHONY : Saintan.cpp.s

SentientTrebuchet.o: SentientTrebuchet.cpp.o

.PHONY : SentientTrebuchet.o

# target to build an object file
SentientTrebuchet.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/SentientTrebuchet.cpp.o
.PHONY : SentientTrebuchet.cpp.o

SentientTrebuchet.i: SentientTrebuchet.cpp.i

.PHONY : SentientTrebuchet.i

# target to preprocess a source file
SentientTrebuchet.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/SentientTrebuchet.cpp.i
.PHONY : SentientTrebuchet.cpp.i

SentientTrebuchet.s: SentientTrebuchet.cpp.s

.PHONY : SentientTrebuchet.s

# target to generate assembly for a file
SentientTrebuchet.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/SentientTrebuchet.cpp.s
.PHONY : SentientTrebuchet.cpp.s

Shop.o: Shop.cpp.o

.PHONY : Shop.o

# target to build an object file
Shop.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Shop.cpp.o
.PHONY : Shop.cpp.o

Shop.i: Shop.cpp.i

.PHONY : Shop.i

# target to preprocess a source file
Shop.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Shop.cpp.i
.PHONY : Shop.cpp.i

Shop.s: Shop.cpp.s

.PHONY : Shop.s

# target to generate assembly for a file
Shop.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Shop.cpp.s
.PHONY : Shop.cpp.s

SuperSoakingSquirter.o: SuperSoakingSquirter.cpp.o

.PHONY : SuperSoakingSquirter.o

# target to build an object file
SuperSoakingSquirter.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/SuperSoakingSquirter.cpp.o
.PHONY : SuperSoakingSquirter.cpp.o

SuperSoakingSquirter.i: SuperSoakingSquirter.cpp.i

.PHONY : SuperSoakingSquirter.i

# target to preprocess a source file
SuperSoakingSquirter.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/SuperSoakingSquirter.cpp.i
.PHONY : SuperSoakingSquirter.cpp.i

SuperSoakingSquirter.s: SuperSoakingSquirter.cpp.s

.PHONY : SuperSoakingSquirter.s

# target to generate assembly for a file
SuperSoakingSquirter.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/SuperSoakingSquirter.cpp.s
.PHONY : SuperSoakingSquirter.cpp.s

ThugCactus.o: ThugCactus.cpp.o

.PHONY : ThugCactus.o

# target to build an object file
ThugCactus.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/ThugCactus.cpp.o
.PHONY : ThugCactus.cpp.o

ThugCactus.i: ThugCactus.cpp.i

.PHONY : ThugCactus.i

# target to preprocess a source file
ThugCactus.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/ThugCactus.cpp.i
.PHONY : ThugCactus.cpp.i

ThugCactus.s: ThugCactus.cpp.s

.PHONY : ThugCactus.s

# target to generate assembly for a file
ThugCactus.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/ThugCactus.cpp.s
.PHONY : ThugCactus.cpp.s

Werewolf.o: Werewolf.cpp.o

.PHONY : Werewolf.o

# target to build an object file
Werewolf.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Werewolf.cpp.o
.PHONY : Werewolf.cpp.o

Werewolf.i: Werewolf.cpp.i

.PHONY : Werewolf.i

# target to preprocess a source file
Werewolf.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Werewolf.cpp.i
.PHONY : Werewolf.cpp.i

Werewolf.s: Werewolf.cpp.s

.PHONY : Werewolf.s

# target to generate assembly for a file
Werewolf.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Werewolf.cpp.s
.PHONY : Werewolf.cpp.s

Wizard.o: Wizard.cpp.o

.PHONY : Wizard.o

# target to build an object file
Wizard.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Wizard.cpp.o
.PHONY : Wizard.cpp.o

Wizard.i: Wizard.cpp.i

.PHONY : Wizard.i

# target to preprocess a source file
Wizard.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Wizard.cpp.i
.PHONY : Wizard.cpp.i

Wizard.s: Wizard.cpp.s

.PHONY : Wizard.s

# target to generate assembly for a file
Wizard.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/Wizard.cpp.s
.PHONY : Wizard.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/main.cpp.s
.PHONY : main.cpp.s

potions.o: potions.cpp.o

.PHONY : potions.o

# target to build an object file
potions.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/potions.cpp.o
.PHONY : potions.cpp.o

potions.i: potions.cpp.i

.PHONY : potions.i

# target to preprocess a source file
potions.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/potions.cpp.i
.PHONY : potions.cpp.i

potions.s: potions.cpp.s

.PHONY : potions.s

# target to generate assembly for a file
potions.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/potions.cpp.s
.PHONY : potions.cpp.s

recipeBook.o: recipeBook.cpp.o

.PHONY : recipeBook.o

# target to build an object file
recipeBook.cpp.o:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/recipeBook.cpp.o
.PHONY : recipeBook.cpp.o

recipeBook.i: recipeBook.cpp.i

.PHONY : recipeBook.i

# target to preprocess a source file
recipeBook.cpp.i:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/recipeBook.cpp.i
.PHONY : recipeBook.cpp.i

recipeBook.s: recipeBook.cpp.s

.PHONY : recipeBook.s

# target to generate assembly for a file
recipeBook.cpp.s:
	$(MAKE) -f CMakeFiles/DungeonCrawler.dir/build.make CMakeFiles/DungeonCrawler.dir/recipeBook.cpp.s
.PHONY : recipeBook.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... DungeonCrawler"
	@echo "... Android.o"
	@echo "... Android.i"
	@echo "... Android.s"
	@echo "... Archer.o"
	@echo "... Archer.i"
	@echo "... Archer.s"
	@echo "... BigChungus.o"
	@echo "... BigChungus.i"
	@echo "... BigChungus.s"
	@echo "... Cerberus.o"
	@echo "... Cerberus.i"
	@echo "... Cerberus.s"
	@echo "... Chaos.o"
	@echo "... Chaos.i"
	@echo "... Chaos.s"
	@echo "... Character.o"
	@echo "... Character.i"
	@echo "... Character.s"
	@echo "... Dragon.o"
	@echo "... Dragon.i"
	@echo "... Dragon.s"
	@echo "... Dungeon.o"
	@echo "... Dungeon.i"
	@echo "... Dungeon.s"
	@echo "... Fighter.o"
	@echo "... Fighter.i"
	@echo "... Fighter.s"
	@echo "... Fish.o"
	@echo "... Fish.i"
	@echo "... Fish.s"
	@echo "... Game.o"
	@echo "... Game.i"
	@echo "... Game.s"
	@echo "... GiantBoar.o"
	@echo "... GiantBoar.i"
	@echo "... GiantBoar.s"
	@echo "... Goblin.o"
	@echo "... Goblin.i"
	@echo "... Goblin.s"
	@echo "... Golem.o"
	@echo "... Golem.i"
	@echo "... Golem.s"
	@echo "... Intern.o"
	@echo "... Intern.i"
	@echo "... Intern.s"
	@echo "... Items.o"
	@echo "... Items.i"
	@echo "... Items.s"
	@echo "... JivinFunkyBadger.o"
	@echo "... JivinFunkyBadger.i"
	@echo "... JivinFunkyBadger.s"
	@echo "... KillerGarfield.o"
	@echo "... KillerGarfield.i"
	@echo "... KillerGarfield.s"
	@echo "... Kyle.o"
	@echo "... Kyle.i"
	@echo "... Kyle.s"
	@echo "... Maze.o"
	@echo "... Maze.i"
	@echo "... Maze.s"
	@echo "... Minotaur.o"
	@echo "... Minotaur.i"
	@echo "... Minotaur.s"
	@echo "... Monster.o"
	@echo "... Monster.i"
	@echo "... Monster.s"
	@echo "... MonsterTamer.o"
	@echo "... MonsterTamer.i"
	@echo "... MonsterTamer.s"
	@echo "... Orc.o"
	@echo "... Orc.i"
	@echo "... Orc.s"
	@echo "... Paladin.o"
	@echo "... Paladin.i"
	@echo "... Paladin.s"
	@echo "... PorcupineLion.o"
	@echo "... PorcupineLion.i"
	@echo "... PorcupineLion.s"
	@echo "... Saintan.o"
	@echo "... Saintan.i"
	@echo "... Saintan.s"
	@echo "... SentientTrebuchet.o"
	@echo "... SentientTrebuchet.i"
	@echo "... SentientTrebuchet.s"
	@echo "... Shop.o"
	@echo "... Shop.i"
	@echo "... Shop.s"
	@echo "... SuperSoakingSquirter.o"
	@echo "... SuperSoakingSquirter.i"
	@echo "... SuperSoakingSquirter.s"
	@echo "... ThugCactus.o"
	@echo "... ThugCactus.i"
	@echo "... ThugCactus.s"
	@echo "... Werewolf.o"
	@echo "... Werewolf.i"
	@echo "... Werewolf.s"
	@echo "... Wizard.o"
	@echo "... Wizard.i"
	@echo "... Wizard.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... potions.o"
	@echo "... potions.i"
	@echo "... potions.s"
	@echo "... recipeBook.o"
	@echo "... recipeBook.i"
	@echo "... recipeBook.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
