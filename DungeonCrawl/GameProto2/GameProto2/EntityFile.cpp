/**
EntityFile.cpp
Purpose: Initialises the functions and variables regarding both entities that operate within the game

@author Josh Holgate
@version 1.0 9/4/18
*/

#include "EntityFile.h"
#include "stdafx.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib> 
#include <ctime>
using namespace std;


void entity::spawn(int bound_x, int bound_y)
{
	srand((unsigned)time(0));
	x = rand() % bound_x;
	srand((unsigned)time(0));
	y = rand() % bound_y;
}

string entity::get_name(void) { return name; }

void entity::set_name(string new_name) { name = new_name; }

int entity::get_maxhp(void) { return maxhp; }

void entity::heal(int h)
{
	if (hp + h > maxhp)
	{
		cout << (maxhp - hp) << " health restored!" << endl;
		hp = maxhp;
	}
	else
	{
		cout << h << " health restored!" << endl;
		hp += h;
	}
}

void entity::fullheal()
{
	hp = maxhp;
}

void entity::take_damage(int d)
{
	hp -= d;
	cout << d << " damage!" << endl;
}

bool entity::get_is_blocking(void) { return is_blocking; }

void entity::set_is_blocking(bool yn) { is_blocking = yn; }

bool entity::willhit()
{
	srand((unsigned)time(0));
	int chance = rand() % 100;

	if (chance <= accuracy) { return true; }
	else { return false; }
}

string entity::get_weapon_name(void) { return weapon_name; }
int entity::get_damage(void) { return damage; }

//	-----------------------------------------------------------------------
//	Called whenever an entity declares an attack
//	Uses the targeted entity as input
void entity::attack(entity &f)
{
	//		Will only occur if a hit lands
	if (willhit() == true)
	{
		//			Dealt damage is random within a range of the attacker's weapon's damage
		int dam_high = (damage * 1.25);
		int dam_low = (damage * 0.75);
		int true_dam = rand() % dam_high + dam_low;

		//			Damage dealt is halved if the target is blocking
		if (f.is_blocking == true)
		{
			f.take_damage((true_dam / 2));
		}
		else
		{
			f.take_damage(true_dam);
		}
		Sleep(400);

		//			If the target entity's HP reaches 0, they are declared dead
		if (f.hp <= 0)
		{
			cout << f.get_name() << " falls!" << endl;
			Sleep(250);
		}
	}
	//		If the hit misses
	else
	{
		cout << get_name() << " misses!" << endl;
		Sleep(400);
	}
}

//---------------------------
// Reads and increments an entity's gold
int entity::get_gold(void) { return gold; }
void entity::loot(int g) { gold += g; }
//	-----------------------------------------------------------------------
//	Reads an entity's x and y co-ordinates
int entity::get_x(void) { return x; }
int entity::get_y(void) { return y; }
int entity::isinv(int n)
{
	if (n >= 0) { return n; }
	else { return (n * -1); }
}
//	-----------------------------------------------------------------------
//	Controls the movement of all entities


void entity::move(char choice, int px, int py)
{
	//		This input will only occur if the entity being moved is an enemy
	//		Movement will be randomly determined
	if (choice == 'r')
	{
		srand((unsigned)time(0));
		int choice = rand() % 4;

		if (choice == 0 && (y - 1 >= 0)) { y--; }
		else if (choice == 1 && (y + 1 <= 7)) { y++; }
		else if (choice == 2 && (x + 1 <= 7)) { x++; }
		else if (choice == 3 && (x - 1 >= 0)) { x--; }
	}
	else if (choice == 'c')
	{
		int xd = isinv(x - px);
		int yd = isinv(y - py);

		if (xd <= 3 || yd <= 3)
		{
			if (xd >= yd)
			{
				if ((x - px) <= 0) { move('e', 0, 0); }
				else { move('w', 0, 0); }
			}
			else
			{
				if ((y - py) <= 0) { move('s', 0, 0); }
				else { move('n', 0, 0); }
			}
		}
		else { move('r', 0, 0); }
	}

	//		These inputs are only possible from the player
	//		The player moves in a direction of their choice - if they try to pass through a wall, they will be pushed back
	else if (choice == 'n') {
		if (y - 1 >= 0) { y--; }
	}
	else if (choice == 's') {
		if (y + 1 <= 7) { y++; }
	}
	else if (choice == 'e') {
		if (x + 1 <= 7) { x++; }
	}
	else if (choice == 'w') {
		if (x - 1 >= 0) { x--; }
	}
}

//	Class "entity" ends
//	=======================================================================