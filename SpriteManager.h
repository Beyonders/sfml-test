#include <SFML/Graphics.hpp>
#include <map>

enum StretchMode { STRETCH, REPEAT };

class BaseSprite
{
private:
	StretchMode _stretchMode;

public:
	std::vector<sf::Sprite> Frames;
	std::vector<std::vector<int>> FrameLength;
	std::string Name;

	bool LoadSprite(sf::Sprite parentSprite, std::string name, int frames, std::string frameStrings[]);
};

class BBSprite
{
private:
	BaseSprite _baseSprite;
	int _currentFrame;
	float _frameTimer;
	bool _animated;
	float GetNextFrameLength();

public:
	float Width;
	float Height;

	BBSprite(BaseSprite& baseSprite);
	void Update(float time);
	void Draw(float x, float y);
	void Draw(float x, float y, float scale);
	void Draw(float x, float y, float scaleX, float scaleY);
	void Draw(float x, float y, float scaleX, float scaleY, char alpha);
	void Draw(float x, float y, float scaleX, float scaleY, sf::Color& color);
	void Draw(float x, float y, float scaleX, float scaleY, sf::Color& color, float angle);
};

extern bool _initialized;

extern std::map<std::string, sf::Sprite> ParentSprites; //To reduce the memory usage
extern std::map<std::string, sf::Sprite> Sprites;

bool Initialize(std::string path);
sf::Sprite GetSprite(std::string name);