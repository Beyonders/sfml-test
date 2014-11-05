#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

bool _initialized = false;

std::map<std::string, sf::Sprite> ParentSprites; //To reduce the memory usage
std::map<std::string, sf::Sprite> Sprites;

bool Initialize(std::string path)
{
	if (_initialized) //already initalized
	{
		return true;
	}

	string line;
	ifstream spriteListFile (path);
	if (spriteListFile.is_open())
	{
		while (getline(spriteListFile,line))
		{
			if (line.length() == 0)
			{
				continue;
			}
		}
		spriteListFile.close();
		_initialized = true;
		return true;
	}
	return false;
}

sf::Sprite GetSprite(std::string name)
{
	if (Sprites.find(name) == Sprites.end())
	{
		return sf::Sprite();
	}
	return Sprites[name];
}