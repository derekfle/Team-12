/**
* Declaration of AvatarSerializer class.
* Singleton class for saving and loading of avatar data.
*/

#pragma once

#include <string>
#include "Avatar.h"

class AvatarSerializer
{
public:
	~AvatarSerializer();

	/**
	* Returns the AvatarSerializer instance.
	*
	* @return the instance of the AvatarSerializer. 
	*/
	static AvatarSerializer &GetInstance();

	/**
	* A member functions for saving Avatar data.
	* 
	* @param avatar - a constant reference to an Avatar object
	*/
	void SaveAvatar(const Avatar &avatar);

	/**
	* A member functions for loading Avatar data.
	*
	* @param avatarName - a constant string that represents the Avatar's name
	* @return a boolean value indicating success
	*/
	bool LoadAvatar(const std::string &avatarName);

	/**
	* Returns the current player Avatar loaded.
	* 
	* @return the loaded player Avatar
	*/
	Avatar *GetPlayer() const;

private:
	/** Private constructor for the AvatarSerializer class. */
	AvatarSerializer();
	/** Delete the copy constructor so that it won't be used. */
	AvatarSerializer(AvatarSerializer const&) = delete;
	/** Delete the assignment operator so that it won't be used. */
	void operator=(AvatarSerializer const&) = delete;

	/** A pointer to the current player Avatar. */
	Avatar *_currentPlayer;
};

