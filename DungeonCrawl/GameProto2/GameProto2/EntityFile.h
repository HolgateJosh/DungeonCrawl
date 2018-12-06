/**
EntityFile.h
Purpose: Declares the functions and variables regarding both entities that operate within the game

@author Josh Holgate
@version 1.0 9/4/18
*/

#include "stdafx.h"
#include <string>
using namespace std;
#pragma once

class entity
{
private:
	bool is_alive = true;
protected:
	string name;
	int maxhp;
	int gold;

	int x;
	int y;

	bool is_blocking;
	int accuracy;
	string weapon_name;
	int damage;
public:
	int hp;

	/**
	Moves the associated entity to a random point on the map

	@param bound_x The maximum horizontal boundary the entity can be moved to
		   bound_y The maximum horizontal boundary the entity can be moved to
	*/
	void spawn(int bound_x, int bound_y);

	/**
	Retrieves the entity's name

	@return The entity's "name" variable
	*/
	string get_name(void);
	/**
	Changes the entity's name

	@param new_name The entity's new name
	*/
	void set_name(std::string new_name);

	/**
	Retrieves the entity's maximum health

	@return The entity's "maxhp" variable
	*/
	int get_maxhp(void);

	/**
	Increases the entity's health, capping at their maximum

	@param h The amount the entity is being healed by
	*/
	void heal(int h);

	/**
	Maximises the entity's health
	*/
	void fullheal();

	/**
	Reduces the entity's health

	@param d The damage dealt to the entity
	*/
	void take_damage(int d);

	/**
	Checks if the entity is blocking

	@return The entity's "is_blocking" variable
	*/
	bool get_is_blocking(void);
	/**
	Changes the entity's blocking state

	@param yn Whether or not the entity should now be blocking
	*/
	void set_is_blocking(bool yn);

	/**
	Determines an entity's chance to hit in combat

	@return True if the attack lands, false if it misses
	*/
	bool willhit();

	/**
	Retrieves the name of the entity's weapon

	@return The entity's "weapon_name" variable
	*/
	string get_weapon_name(void);
	/**
	Retrieves the damage dealt by the entity's weapon

	@return The entity's "damage" variable
	*/
	int get_damage(void);

	/**
	Attempts to attack another entity

	@param f The target of the entity's attack
	*/
	void attack(entity &f);

	/**
	Retrieves how much gold the entity possesses

	@return The entity's "gold" variable
	*/
	int get_gold(void);
	/**
	Increases the entity's amount of gold

	@param g The amount of gold the entity gains
	*/
	void loot(int g);

	/**
	Checks the entity's x co-ordinate

	@return The entity's "x" variable
	*/
	int get_x(void);
	/**
	Checks the entity's y co-ordinate

	@return The entity's "y" variable
	*/
	int get_y(void);
	/**
	Changes negative integers into their positive state

	@param n The integer to be converted
	@return The converted integer
	*/
	int isinv(int n);

	/**
	Controls the movement of all entities

	@param choice The direction the entity intends to move in
		   px The x co-ordinate of the other entity
		   py The y co-ordinate of the other entity
	*/
	void move(char choice, int px, int py);
};