/**
PlayerFile.cpp
Purpose: Initialises the functions and variables governing the playable character

@author Josh Holgate
@version 1.0 9/4/18
*/

#include "PlayerFile.h"
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

string player::get_action(void) { return action; }
void player::set_action(string ac) { action = ac; }

void player::end_turn(void) { turns++; }

int player::get_potions(void) { return potions; }
void player::drink(int h)
{
	//		If the player has at least one potion
	if (potions > 0)
	{
		//			Heals the player
		heal(h);
		//			Removes one potion
		potions--;
		Sleep(400);
		//			Tells the player how many potions they have remaining
		if (potions != 1) { cout << potions << " potions left." << endl; }
		else { cout << potions << " potion left." << endl; }
	}
	//		If the player has no potions left, their turn ends
	else { cout << "Out of potions!" << endl; }
}

void player::bannertext(string message)
{
	Sleep(150);
	for (char& c : message) {
		Sleep(100);
		cout << c;
	}
	cout << endl;
}

void player::end_game(void) {
	bannertext("Your delve into the dungeon comes to an end!");
	//		As a method of tracking the player's progress, they are told their remaining HP,
	//		inventory of potions, gold collected and how many turns they took
	bannertext("You depart with:");
	cout << gold;
	bannertext(" GOLD");
	cout << potions;
	bannertext(" POTIONS");
	cout << turns;
	bannertext(" TURNS TAKEN");
	cout << hp << "/" << maxhp;
	bannertext(" HP REMAINING");
}

player::player()
{
	hp = 30;
	maxhp = 30;

	is_blocking = false;
	potions = 3;
	gold = 0;

	x = 7;
	y = 1;

	weapon_name = "sword";
	damage = 5;
	accuracy = 75;

	turns = 0;
}