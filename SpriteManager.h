#include <SFML/Graphics.hpp>
#include <map>

extern bool _initialized;

extern std::map<std::string, sf::Sprite> ParentSprites; //To reduce the memory usage
extern std::map<std::string, sf::Sprite> Sprites;

bool Initialize(std::string path);
sf::Sprite GetSprite(std::string name);