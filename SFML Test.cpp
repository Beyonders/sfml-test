// SFML Test.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"

#include <SFML/Graphics.hpp>
#include <iostream>
//#include <atlstr.h>
//#include <atlconv.h>

sf::CircleShape shape(100.f);
sf::Texture texture;
sf::Sprite sprite;
sf::Sprite portraitSprite;
sf::Sprite shipSprite;
sf::Font font;
sf::Text text;
sf::Shader shader;

const std::string fragmentShader = \
	"uniform sampler2D texture;" \
	"uniform vec3 ReplaceColor1;" \
	"uniform vec3 ReplaceColor2;" \
	"uniform vec3 ReplaceColor3;" \
	"uniform vec3 EmpireColor;" \
	"void main(void)" \
	"{" \
	"	vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);" \
	"	vec3 eps = vec3(0.009, 0.009, 0.009);" \
	"	if (all(greaterThanEqual(pixel, vec4(ReplaceColor1 - eps, 1.0))) && all(lessThanEqual(pixel, vec4(ReplaceColor1 + eps, 1.0))))" \
	"	{" \
	"		pixel = vec4(EmpireColor, 1.0);" \
	"	}" \
	"	if (all(greaterThanEqual(pixel, vec4(ReplaceColor2 - eps, 1.0))) && all(lessThanEqual(pixel, vec4(ReplaceColor2 + eps, 1.0))))" \
	"	{" \
	"		pixel = vec4(EmpireColor * 0.8, 1.0);" \
	"	}" \
	"	if (all(greaterThanEqual(pixel, vec4(ReplaceColor3 - eps, 1.0))) && all(lessThanEqual(pixel, vec4(ReplaceColor3 + eps, 1.0))))" \
	"	{" \
	"		pixel = vec4(EmpireColor * 0.55, 1.0);" \
	"	}" \
	"	gl_FragColor = pixel;" \
	"}";

void UpdateGame(sf::Time* elapsed, sf::RenderWindow* window);

/*
std::string ExePath()
{
	LPWSTR buffer = L"";
	GetModuleFileName(NULL, buffer, _MAX_PATH);
	return CW2A(buffer);
}
*/

int main(int argc, char* argv[])
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Test");

	if (!Initialize("sprites.txt"))
	{
		//Couldn't load sprites, close
		return -1;
	}
	GameMain gameMain = GameMain(800, 600);

	shape.setFillColor(sf::Color::Green);
	if (!texture.loadFromFile("graphics\\humans.png"))
	{
		return 1;
	}
	sprite.setTexture(texture);

	portraitSprite.setTexture(texture);
	portraitSprite.setTextureRect(sf::IntRect(0, 481, 300, 300));
	//portraitSprite.setColor(sf::Color(0, 0, 255));
	portraitSprite.setPosition(300,300);
	portraitSprite.setOrigin(150,150);
	portraitSprite.setRotation(45);

	shipSprite.setTexture(texture);
	shipSprite.setTextureRect(sf::IntRect(0, 320, 160, 160));
	shipSprite.setPosition(400, 10);

	if (!font.loadFromFile("JLSSpaceGothicR.ttf"))
	{
		return 1;
	}

	text.setFont(font);
	//std::string path = ExePath();
	text.setString("Version 0.59");
	text.setCharacterSize(14);
	text.setColor(sf::Color::Yellow);
	//text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.setPosition(0, 500);

	if (!sf::Shader::isAvailable())
	{
		return 2;
	}
	if (!shader.loadFromMemory(fragmentShader, sf::Shader::Fragment))
	{
		//return 3;
	}
	shader.setParameter("ReplaceColor1", 1.f, (165.0f/255.0f), (99.0f/255.0f));
	shader.setParameter("ReplaceColor2", (244.0f/255.0f), (74.0f/255.0f), (52.0f/255.0f));
	shader.setParameter("ReplaceColor3", (181.0f/255.0f), (13.0f/255.0f), (13.0f/255.0f));
	shader.setParameter("EmpireColor", 0.f, 0.f, 1.f);

	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				{
					window.close();
				} break;
			case sf::Event::Resized:
				{
					std::cout << "New width: " << event.size.width << std::endl;
					std::cout << "New height: " << event.size.height << std::endl;
				} break;
			case sf::Event::LostFocus:
				{
					std::cout << "Lost focus!" << std::endl;
				} break;
			case sf::Event::GainedFocus:
				{
					std::cout << "Regained focus!" << std::endl;
				} break;
			case sf::Event::TextEntered:
				{
					//Text typing code goes here
					if (event.text.unicode < 128)
					{
						std::cout << static_cast<char>(event.text.unicode);
					}
				} break;
			case sf::Event::KeyPressed:
				{
					//Keydown event that is repeated at OS-defined interval if the key is held down
					if (event.key.code == sf::Keyboard::Escape)
					{
						window.close();
					}
				} break;
			case sf::Event::KeyReleased:
				{
					//Keyup event
					if (event.key.code == sf::Keyboard::Space)
					{
						window.close();
					}
				} break;
			case sf::Event::MouseWheelMoved:
				{
					std::cout << "Wheel Movement: " << event.mouseWheel.delta << std::endl;
					std::cout << "Mouse X: " << event.mouseWheel.x << std::endl;
					std::cout << "Mouse Y: " << event.mouseWheel.y << std::endl;
				} break;
			case sf::Event::MouseButtonPressed:
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						std::cout << "Left Button Pressed" << std::endl;
					}
					else if (event.mouseButton.button == sf::Mouse::Right)
					{
						std::cout << "Right Button Pressed" << std::endl;
					}
					std::cout << "Mouse X: " << event.mouseButton.x << std::endl;
					std::cout << "Mouse Y: " << event.mouseButton.y << std::endl;
				} break;
			case sf::Event::MouseButtonReleased:
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						std::cout << "Left Button Released" << std::endl;
					}
					else if (event.mouseButton.button == sf::Mouse::Right)
					{
						std::cout << "Right Button Released" << std::endl;
					}
					std::cout << "Mouse X: " << event.mouseButton.x << std::endl;
					std::cout << "Mouse Y: " << event.mouseButton.y << std::endl;
				} break;
			case sf::Event::MouseMoved:
				{
					//std::cout << "Mouse Moved X: " << event.mouseMove.x << std::endl;
					//std::cout << "Mouse Moved Y: " << event.mouseMove.y << std::endl;
				} break;
			default:
				break;
			}
		}

		sf::Time elapsed = clock.restart();
		UpdateGame(&elapsed, &window);
	}

	return 0;
}

void UpdateGame(sf::Time* elapsed, sf::RenderWindow* window)
{
	window->clear();
	window->draw(shape);
	//window->draw(sprite);
	window->draw(portraitSprite);
	window->draw(text);
	//shader.setParameter("blink_alpha", 0.5f + std::cos(elapsed->asSeconds() * 3) * 0.25f);
	window->draw(shipSprite, &shader);
	window->display();
}
