/**
PlayerFile.h
Purpose: Declares the functions and variables governing the playable character

@author Josh Holgate
@version 1.0 9/4/18
*/

#include "stdafx.h"
#include <string>
#include "EntityFile.h"
using namespace std;
#pragma once

class player : public entity
{
private:
	string action;
	int potions;
	int turns;
	int member1;
public:
	/**
	Retrieves the player's chosen action in the overworld and combat

	@return The player's "action" variable
	*/
	string get_action(void);
	/**
	Stores the player's chosen action in the overworld and combat

	@param ac The choice the player inputs to the terminal
	*/
	void set_action(string ac);
	/**
	End's the player's turn in the overworld and combat
	*/
	void end_turn(void);

	/**
	Retrieves the player's stock of potions

	@return The player's "potions" variable
	*/
	int get_potions(void);
	/**
	Consumes a potion to restore the player's health

	@param h The amount of health restored
	*/
	void drink(int h);

	/**
	Prints a string with a small delay between each character

	@param message The string to be printed
	*/
	void bannertext(string message);

	/**
	Ends the game when the player exits the dungeon
	*/
	void end_game(void);

	player();
};