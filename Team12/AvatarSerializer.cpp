/*
* Implementation of AvatarSerializer class
* MADE FOR WINDOWS OS ONLY
*/

#include "AvatarSerializer.h"
#include <fstream>
#include <iostream>
#include <Windows.h>

AvatarSerializer &AvatarSerializer::GetInstance()
{
	static AvatarSerializer instance;
	return instance;
}

void AvatarSerializer::SaveAvatarData(const AvatarData &data)
{
	wchar_t *dirName = L"Save";

	if (CreateDirectory(dirName, NULL) ||
		ERROR_ALREADY_EXISTS == GetLastError())
	{
		std::ofstream outfile("Save/" + data.name + ".dat", std::ios::out | std::ios::binary);
		if (outfile.is_open())
		{
			outfile.write((char*)&data, sizeof(data));
			outfile.close();
		}
		else
		{
			std::cerr << "Unable to open file for saving.\n";
		}
	}
	else
	{
		std::cerr << "Failed creating save directory.\n";
	}
}

AvatarData AvatarSerializer::LoadAvatarData(const std::string &avatarName)
{
	AvatarData data;
	std::ifstream infile("Save/" + avatarName + ".dat", std::ios::in | std::ios::binary);

	if (infile.is_open())
	{
		infile.read((char*)&data, sizeof(data));
		infile.close();
	}
	else
	{
		std::cerr << "Unable to open file for loading.\n";
	}

	return data;
}