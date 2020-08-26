#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextureDictionary.h"

using namespace std;

int main(void) {
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!", sf::Style::Fullscreen);
	
	TextureDictionary TEXTURES = TextureDictionary("assets/images/");

	sf::Sprite player;

	player.setTexture(TEXTURES["player"]);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(player);
		window.display();
	}

	return 0;
}