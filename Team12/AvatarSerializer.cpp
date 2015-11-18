/*
* Implementation of AvatarSerializer class
*/

#include "AvatarSerializer.h"
#include "Avatar.pb.h"

#include <fstream>
#include <iostream>

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

/**
* This method saves data using Google Protocol Buffers. 
*/
void AvatarSerializer::SaveAvatar(const Avatar &data)
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;

	proto::Avatar avatar;

	avatar.set_level(data.GetLevel());
	avatar.set_name(data.GetName());
	switch (data.GetClass().GetClassType())
	{
	case ClassType::Warrior:
		avatar.set_type(proto::Avatar::ClassType::Avatar_ClassType_WARRIOR);
		break;
	case ClassType::Rogue:
		avatar.set_type(proto::Avatar::ClassType::Avatar_ClassType_ROGUE);
		break;
	case ClassType::Mage:
		avatar.set_type(proto::Avatar::ClassType::Avatar_ClassType_MAGE);
		break;
	default:
		break;
	}

	// Write the avatar back to disk.
	std::fstream output(data.GetName() + ".dat", std::ios::out | std::ios::trunc | std::ios::binary);
	if (!avatar.SerializeToOstream(&output))
	{
		std::cerr << "Failed to write cache to disk." << std::endl;
		return;
	}
}


/**
* Loads data using Google Protocol Buffers.
*/
bool AvatarSerializer::LoadAvatar(const std::string &avatarName)
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;

	proto::Avatar avatar;

	// Read the existing cache
	std::fstream input(avatarName + ".dat", std::ios::in | std::ios::binary);
	if (!input)
	{
		return false;
	}
	else if (!avatar.ParseFromIstream(&input))
	{
		std::cerr << "Failed to parse file." << std::endl;
		return false;
	}

	ClassType type;
	switch (avatar.type())
	{
	case proto::Avatar::ClassType::Avatar_ClassType_WARRIOR:
		type = ClassType::Warrior;
		break;
	case proto::Avatar::ClassType::Avatar_ClassType_ROGUE:
		type = ClassType::Rogue;
		break;
	case proto::Avatar::ClassType::Avatar_ClassType_MAGE:
		type = ClassType::Mage;
		break;
	default:
		break;
	}

	if (_currentPlayer) delete _currentPlayer;
	_currentPlayer = new Avatar(avatar.name(), avatar.level(), type);
	return true;
}

Avatar *AvatarSerializer::GetPlayer() const
{
	return _currentPlayer;
}