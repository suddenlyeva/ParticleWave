#pragma once
#include <map>
#include <SFML/Graphics.hpp>

using namespace std;

class TextureDictionary
{
private:
	map<string, sf::Texture> dictionary;
public:
	TextureDictionary(string);
	const sf::Texture& operator[](string);
};