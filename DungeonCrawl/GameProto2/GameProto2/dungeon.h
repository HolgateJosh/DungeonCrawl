/**
dungeon.h
Purpose: Declares the variables and highest-level functions that govern the main elements of gameplay

@author Josh Holgate
@version 1.0 9/4/18
*/

#include "stdafx.h"
#include <string>
#include "EntityFile.h"
#include "PlayerFile.h"
#include "foe.h"
using namespace std;
#pragma once

class game {
public:
	player hero;
	foe enemy;

	/**
	Allows the player to navigate the game world

	@param mx The horixontal size of the map
		   my The vertical size of the map
	@return True if the game ends with the player's exit, false on their defeat
	*/
	bool navigate(int mx, int my);

	/**
	Displays co-ordinates in an easily-interpretable manner

	@param num The integer that needs to be altered
		   scale The length of the axis measured by "num"
	*/
	void invert(int num, int scale);

	/**
	Displays the map with the position of both entities

	@param mx The horixontal size of the map
		   my The vertical size of the map
	*/
	void makemap(int mx, int my);

	/**
	Displays an entity's information in a styilised manner

	@param name The entity's name
		   hp The entity's current health
		   maxhp The entity's maximum health
	*/
	void nameplate(string name, int hp, int maxhp);

	/**
	Initiates combat between the two entities
	*/
	bool fight(void);
};