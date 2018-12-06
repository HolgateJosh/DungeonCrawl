/**
dungeon.cpp
Purpose: Initialises the highest-level functions that govern the main elements of gameplay

@author Josh Holgate
@version 1.0 9/4/18
*/

#include "stdafx.h"
#include <string>
#include "EntityFile.h"
#include "PlayerFile.h"
#include "foe.h"
#include "dungeon.h"
using namespace std;

void game::invert(int num, int scale)
{
	cout << (scale - num);
}

void game::nameplate(string name, int hp, int maxhp)
{
	cout << "---------------" << endl;
	Sleep(100);
	cout << name << endl;
	Sleep(100);
	cout << hp << "/" << maxhp << endl;
	Sleep(100);
}

void game::makemap(int mx, int my)
{
	cout << "GOLD:" << hero.get_gold() << endl;
	cout << "POTIONS:" << hero.get_potions() << endl;
	//	Creating the northern wall of the dungeon
	cout << "==========" << endl;
	for (int i = 0; i < my; i++)
	{
		//	Creating the western wall of the dungeon
		cout << "|";
		//	Going through every map tile in sequence
		for (int j = 0; j < mx; j++)
		{
			//	If the player is present on the tile
			if (hero.get_x() == j && hero.get_y() == i)
			{
				cout << "X";
			}
			//	If an enemy is present on the tile
			else if (enemy.get_x() == j && enemy.get_y() == i)
			{
				cout << "x";
			}
			//	If the exit is present on the tile
			else if (j == (mx - 1) && i == 0)
			{
				cout << "#";
			}
			//	If nothing is present on the tile
			else
			{
				cout << "/";
			}
		}
		//	Creating the eastern wall of the dungeon
		cout << "|" << endl;
	}
	//	Creating the southern wall of the dungeon
	cout << "==========" << endl;

	//	Printing the player's co-ordinates
	cout << "(" << (hero.get_x() + 1) << ", ";
	// Since the map is created via a 2D array, the Y co-ordinate increases as the player moves further down the map instead of up
	// To prevent player confusion, their co-ordinates are diaplayed to them in the typical format
	invert((hero.get_y() + 1), (my + 1));
	cout << ")" << endl;
	cout << endl;
}

bool game::fight()
{
	cout << "===============" << endl;
	hero.bannertext("FIGHT");
	cout << "===============" << endl;
	Sleep(250);
	//	Loops as long as the player and enemy are both alive
	while (enemy.hp > 0 && hero.hp > 0)
	{
		//Prints player and enemy health
		nameplate(hero.get_name(), hero.hp, hero.get_maxhp());
		nameplate(enemy.get_name(), enemy.hp, enemy.get_maxhp());
		cout << "---------------" << endl;
		Sleep(750);
		cout << endl;

		//	Prompts player action
		string c;
		cout << "What will you do?" << endl;
		cin >> c;
		hero.set_action(c);

		Sleep(500);
		cout << endl;
		//		Attacking
		if (hero.get_action() == "attack" || hero.get_action() == "a")
		{
			//	Lowers the player's block when they attack
			if (hero.get_is_blocking() == true)
			{
				hero.set_is_blocking(false);
				cout << "You lower your guard." << endl;
			}
			Sleep(400);
			cout << "You strike the " << enemy.get_name() << " with your " << hero.get_weapon_name() << "!" << endl;
			Sleep(400);
			//	Attempts an attack using the player's weapon damage and accuracy
			hero.attack(enemy);
			Sleep(400);
		}
		//		Blocking
		else if (hero.get_action() == "block" || hero.get_action() == "b")
		{
			cout << "You take a defensive stance!" << endl;
			//	Sets the player to a blocking stance - damage is halved
			hero.set_is_blocking(true);
			Sleep(800);
		}
		//		Healing
		else if (hero.get_action() == "heal" || hero.get_action() == "h" || hero.get_action() == "drink" || hero.get_action() == "d")
		{
			//	Heals the player by 15HP, or to maximum
			//	The "heal" command does *not* lower the player's block, allowing them to defend themselves while healing
			hero.drink(15);
			Sleep(800);
		}
		else { cout << "Command unrecognised." << endl; }
		cout << endl;
		//		Enemy Attack
		if (enemy.hp <= 0) {
			hero.set_is_blocking(false);
			return true;
		}

		cout << "The " << enemy.get_name() << " takes a swipe with its " << enemy.get_weapon_name() << "!" << endl;
		Sleep(400);
		enemy.attack(hero);
		Sleep(250);
		//	Ends the loop if the player dies
		if (hero.hp <= 0) { return false; }
		cout << endl;
	}
	//	Ends the loop if the enemy dies
	return true;
}

bool game::navigate(int mx, int my)
{
	char dir;
	bool canmove = true;
	//	Creates the map with the player and enemy locations
	makemap(mx, my);
	//	Selecting a specific player name skips the introductory dialogue, speeding up later testing stages
	if (hero.get_name() == "Barry") { cout << "QuickStart!" << endl; }
	else {
		Sleep(1000);
		cout << "You enter the dungeon through the north-eastern stairwell." << endl;
		Sleep(1000);
		cout << "You have come here with three goals in mind:" << endl;
		Sleep(750);
		cout << "- Kill ";
		hero.bannertext("GOBLINS");
		Sleep(750);
		cout << "- Get ";
		hero.bannertext("TREASURE");
		Sleep(750);
		cout << "- Pay ";
		hero.bannertext("RENT");
		Sleep(1000);
		cout << endl;
	}

	while (canmove)
	{
		//	If the player is on the same tile as an enemy, a fight initiates
		if (hero.get_x() == enemy.get_x() && hero.get_y() == enemy.get_y())
		{
			//	If the player loses the fight
			if (fight() == false)
			{
				//	Terminates the game
				cout << "Your journey ends here..." << endl;
				return false;
			}
			//	If the player wins the fight
			else
			{
				//	Continues the game
				Sleep(1000);
				//	The player is given a random amount of gold
				cout << "You acquire " << enemy.get_gold() << " gold from your foe's body." << endl;
				hero.loot(enemy.get_gold());
				Sleep(500);
				cout << "Your journey continues!" << endl;
				//	Moves the enemy to a random point on the map
				enemy.fullheal();
				enemy.spawn(mx, my);
				enemy.scavenge();
				makemap(mx, my);
			}
		}

		cout << "Where will you go?" << endl;

		//	Requesting player input
		cin >> dir;
		cout << endl;
		//	The player can drink a healing potion on the overworld instead of moving
		if (dir == 'h' || dir == 'd') { hero.drink(15); }
		else if (dir == 'n' || dir == 's' || dir == 'e' || dir == 'w') { hero.move(dir, 0, 0); }
		else { cout << "not supported" << endl; }
		cout << endl;

		//	If the player arrives at the exit
		if (hero.get_x() == 7 && hero.get_y() == 0)
		{
			char yn;
			cout << "You stand before the stairwell you used to enter the dungeon." << endl;
			cout << "Do you wish to leave with the treasure you have collected? (Y/N)" << endl;
			cin >> yn;
			while (yn != 'y' && yn != 'Y' && yn != 'n' && yn != 'N') { cin >> yn; }
			if (yn == 'y' || yn == 'Y')
			{
				cout << "You make your way out of the dungeon." << endl;
				cout << endl;
				hero.end_turn();
				return true;
			}
			else if (yn == 'n' || yn == 'N')
			{
				cout << "You change your mind and return to the dungeon floor." << endl;
				cout << endl;
				hero.move('s', 0, 0);
			}
			cout << endl;
		}

		enemy.move('c', hero.get_x(), hero.get_y());
		hero.end_turn();
		makemap(mx, my);
	}
}