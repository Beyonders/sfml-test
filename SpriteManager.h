#include <SFML/Graphics.hpp>
#include <map>

static class SpriteManager
{
private:
	bool _initalized;

public:
	std::map<char[16],sf::Sprite> Sprites;

	SpriteManager(char* path);

	sf::Sprite GetSprite(char[16] name);
};