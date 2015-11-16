/*
* Declaration of AvatarSerializer class
* Singleton class for saving and loading of avatar data
*/

#pragma once
#include <string>

#include "Avatar.h"



class AvatarSerializer
{
public:
	~AvatarSerializer();

	/*
	* Returns the AvatarSerializer instance
	*/
	static AvatarSerializer &GetInstance();

	/*
	* The member functions for saving and loading avatar data
	*/
	void SaveAvatar(const Avatar &avatar);
	bool LoadAvatar(const std::string &avatarName);

	/*
	* Returns the current player avatar loaded
	*/
	Avatar *GetPlayer() const;

private:
	AvatarSerializer();
	AvatarSerializer(AvatarSerializer const&) = delete;
	void operator=(AvatarSerializer const&) = delete;

	Avatar *_currentPlayer;
};

