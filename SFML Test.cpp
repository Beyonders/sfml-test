// SFML Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <iostream>

sf::CircleShape shape(100.f);
sf::Texture texture;
sf::Sprite sprite;
sf::Sprite portraitSprite;
sf::Sprite shipSprite;
sf::Font font;
sf::Text text;
sf::Shader shader;

//const std::string fragmentShader = \
	"uniform sampler2D texture;" \
	"void main(void)" \
	"{" \
	"	vec4 pixel = gl_Color;" \
	"	if (pixel.r != pixel.g)" \
	"	{" \
	"		pixel.r = 40" \
	"		pixel.g = 200" \
	"		pixel.b = 150" \
	"	}" \
	"	gl_FragColor = pixel;" \
	"}";

const std::string fragmentShader = \
	"uniform sampler2D texture;" \
	"void main(void)" \
	"{" \
	"	vec4 pixel = gl_Color;" \
	"		pixel.r = 40" \
	"		pixel.g = 200" \
	"		pixel.b = 150" \
	"	gl_FragColor = pixel;" \
	"}";

void UpdateGame(sf::Time* elapsed, sf::RenderWindow* window);

int _tmain(int argc, _TCHAR* argv[])
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Test");
	
	shape.setFillColor(sf::Color::Green);
	if (!texture.loadFromFile("C:\\temp\\SFML Test\\x64\\Debug\\humans.png"))
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

	if (!font.loadFromFile("C:\\temp\\SFML Test\\x64\\Debug\\JLSSpaceGothicR.ttf"))
	{
		return 1;
	}

	text.setFont(font);
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