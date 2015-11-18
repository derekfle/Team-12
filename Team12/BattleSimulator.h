/**
* BattleSimulator declaration. 
* This class initiates the game and contains the game loop.
*/

#pragma once

class BattleSimulator
{
public:
	/** The constructor for the BattleSimulator class. */
	BattleSimulator();
	/** The deconstructor for the BattleSimulator class. */
	~BattleSimulator();
	
	/** 
	* This method is the entrance to the game. It contains the game loop. 
	*/
	void Play();
};

