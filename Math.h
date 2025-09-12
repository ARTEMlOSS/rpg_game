#pragma once
#include <SFML/Graphics.hpp>

class Math
{
public:
	static sf::Vector2f NormalizeVector(sf::Vector2f vector);
	//static allows to use the function directly from the Class with "::" without creating an object
};  // but now we all the objects cannot create such a function - they share one which is in Class

