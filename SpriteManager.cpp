#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

bool _initialized = false;

std::map<std::string, sf::Sprite> ParentSprites; //To reduce the memory usage
std::map<std::string, sf::Sprite> Sprites;



float BBSprite::GetNextFrameLength()
{
	if (_baseSprite.FrameLength[_currentFrame].size() == 1)
	{
		return _baseSprite.FrameLength[_currentFrame][0] / 1000.0f;
	}
	else if (_baseSprite.FrameLength[_currentFrame].size() == 2)
	{
		int min = _baseSprite.FrameLength[_currentFrame][0];
		int max = _baseSprite.FrameLength[_currentFrame][1];

		return (rand() % max + min) / 1000.0f;
	}
	return 0;
}

BBSprite::BBSprite(BaseSprite& baseSprite)
{
		_baseSprite = baseSprite;
		_currentFrame = 0;
		_animated = _baseSprite.Frames.size() > 1;
		if (_animated)
		{
			_frameTimer = GetNextFrameLength();
		}
}

void BBSprite::Update(float time)
{
	if (!_animated)
	{
		return;
	}
	_frameTimer -= time;
	if (_frameTimer <= 0)
	{
		//Advance to next frame
		_currentFrame++;
		if (_currentFrame >= _baseSprite.Frames.size())
		{
			_currentFrame = 0;
		}
		_frameTimer = GetNextFrameLength();
	}
}

void BBSprite::Draw(float x, float y)
{
	sf::Color color = sf::Color(255,255,255,255);
	Draw(x, y, 1, 1, color, 0.0f);
}

void BBSprite::Draw(float x, float y, float scale)
{
	sf::Color color = sf::Color(255,255,255,255);
	Draw(x, y, scale, scale, color, 0.0f);
}

void BBSprite::Draw(float x, float y, float scaleX, float scaleY)
{
	sf::Color color = sf::Color(255,255,255,255);
	Draw(x, y, scaleX, scaleY, color, 0.0f);
}

void BBSprite::Draw(float x, float y, float scaleX, float scaleY, char alpha)
{
	sf::Color color = sf::Color(255,255,255,alpha);
	Draw(x, y, 1, 1, color, 0.0f);
}

void BBSprite::Draw(float x, float y, float scaleX, float scaleY, sf::Color& color)
{
	Draw(x, y, 1, 1, color, 0.0f);
}

void BBSprite::Draw(float x, float y, float scaleX, float scaleY, sf::Color& color, float angle)
{
	sf::Sprite frame = _baseSprite.Frames[_currentFrame];
	frame.setRotation(angle);
	frame.setPosition(x, y);
	frame.setScale(scaleX, scaleY);
	frame.setColor(color);
	//frame->draw();
}

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