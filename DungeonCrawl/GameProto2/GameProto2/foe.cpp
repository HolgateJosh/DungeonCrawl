/**
foe.cpp
Purpose: Initialises the functions and variables governing the AI-controlled enemy

@author Josh Holgate
@version 1.0 9/4/18
*/

#include "foe.h"
#include "EntityFile.h"
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

void foe::scavenge(void)
{
	srand((unsigned)time(0));
	gold = rand() % 5;
}

void foe::take_damage(int hp, int d)
{
	hp -= d;
	cout << d << " damage!" << endl;
}

foe::foe()
{
	hp = 12;
	maxhp = 12;

	x = 0;
	y = 6;

	name = "GOBLIN";
	weapon_name = "club";
	damage = 3;
	accuracy = 50;

	gold = 5;
}