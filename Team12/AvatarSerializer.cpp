/*
* Implementation of AvatarSerializer class
* MADE FOR WINDOWS OS ONLY
*/

#include "AvatarSerializer.h"

AvatarSerializer::AvatarSerializer() :
	_currentPlayer(nullptr)
{}

AvatarSerializer::~AvatarSerializer()
{
	if (_currentPlayer) delete _currentPlayer;
}

AvatarSerializer &AvatarSerializer::GetInstance()
{
	static AvatarSerializer instance;
	return instance;
}

void AvatarSerializer::SaveAvatar(const Avatar &data)
{
	// Not yet
}

bool AvatarSerializer::LoadAvatar(const std::string &avatarName)
{
	if (_currentPlayer) delete _currentPlayer;
	_currentPlayer = new Avatar(avatarName, 1, AvatarClass::GetClassType(avatarName));
	return true;
}

Avatar *AvatarSerializer::GetPlayer() const
{
	return _currentPlayer;
}