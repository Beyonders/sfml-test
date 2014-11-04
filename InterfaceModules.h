#include <SFML/Graphics.hpp>

class BaseInterface
{
protected:
	int _x, _y;
	int _width, _height;

public:
	BaseInterface(int x, int y, int width, int height);
};

enum StretchableImageType
{
	ThickBorder,
	MediumBorder,
	ThinBorderBG,
	ThinBorderFG,
	TinyButtonBG,
	TinyButtonFG,
	TextBox
};

class BBStretchableImage : BaseInterface
{
private:
	int _sectionWidth, _sectionHeight;
	int _horizontalStretchLength, _verticalStretchLength;
	sf::Sprite _sections[9];

public:
	BBStretchableImage(int x, int y, int width, int height, StretchableImageType type);
};

class BBToolTip : BaseInterface
{
private:
	const int MAXWIDTH = 260;
	int _actualWidth;
};

class BBButton : BaseInterface
{
};