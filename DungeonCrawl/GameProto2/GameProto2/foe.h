/**
foe.h
Purpose: Declares the functions and variables governing the AI-controlled enemy

@author Josh Holgate
@version 1.0 9/4/18
*/

#include "stdafx.h"
#include <string>
#include "EntityFile.h"
using namespace std;
#pragma once

class foe : public entity
{
public:
	/**
	Sets the enemy's gold to a random amount
	*/
	void scavenge(void);
	/**
	Reduces the enemy's health
	This version of the function does not write to "hp"'s memory address,
		preventing it from presisting between fights
	@param hp The enemy's current health
		   d The damage dealt to the enemy
	*/
	void take_damage(int hp, int d);
	foe();
};