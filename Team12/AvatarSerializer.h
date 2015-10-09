/*
* Declaration of AvatarSerializer class
* Singleton class for saving and loading of avatar data
* MADE FOR WINDOWS OS ONLY
*/

#pragma once
#include <string>

/*
* Relevant avatar data to be saved
*/
struct AvatarData
{
	std::string name;
	unsigned level;

	AvatarData() : name(""), level(0) {};
};

class AvatarSerializer
{
public:
	~AvatarSerializer() {};

	/*
	* Returns the AvatarSerializer instance
	*/
	static AvatarSerializer &GetInstance();

	/*
	* The member functions for saving and loading avatar data
	*/
	void SaveAvatarData(const AvatarData &data);
	AvatarData LoadAvatarData(const std::string &avatarName);

private:
	AvatarSerializer() {};
	AvatarSerializer(AvatarSerializer const&) = delete;
	void operator=(AvatarSerializer const&) = delete;
};

