#include "TextureDictionary.h"
#include <filesystem>
#include <iostream>

using namespace std;

TextureDictionary::TextureDictionary(string folderPath)
{
	dictionary = map<string, sf::Texture>();
	for (const auto & entry : filesystem::directory_iterator(folderPath)) {

		sf::Texture texture;

		string path = entry.path().string();
		string stem = entry.path().stem().string();
		string extension = entry.path().extension().string();

		if (!texture.loadFromFile(path)) {
			cerr << "Failed to load " << stem << extension << endl;
		}

		dictionary[stem] = texture;
	}
}

const sf::Texture & TextureDictionary::operator[](string key)
{
	return dictionary[key];
}
