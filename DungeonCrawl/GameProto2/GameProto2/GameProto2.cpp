/**
dungeon.cpp
Purpose: Main file, calls the highest-level functions that start the game

@author Josh Holgate
@version 1.0 9/4/18
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib> 
#include <ctime>
#include "EntityFile.cpp"
#include "PlayerFile.cpp"
#include "foe.cpp"
#include "dungeon.cpp"
using namespace std;

int main()
{
	char replay;
	game dungeon;

	string new_name;
	cout << "What is your name, hero?" << endl;
	cin >> new_name;
	dungeon.hero.set_name(new_name);
	cout << dungeon.hero.get_name() << ", your adventure begins here!" << endl;

		if (dungeon.navigate(8, 8) == true)
		{
			dungeon.hero.end_game();
		}
}