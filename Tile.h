#pragma once
#include <SFML/Graphics.hpp>

//struct is the same thing as Class
//the only difference is that everything in a struct is public by default
//but the unspoken rule is that in a struct we use only date - no functions
struct Tile
{
	int id = -1;
	sf::Vector2i position;
};