#pragma once
#include <SFML/Graphics.hpp>
#include "Skeleton.h"

class Player
{
private:
	sf::Texture texture;

	//BULLET 1
	std::vector < sf::RectangleShape> bullets; // list of bullets
	float bulletSpeed = 0.4f;
	//BULLET 2
public:
	sf::Sprite sprite;
	float speed = 0.3f;
	// constructor is needed because "sprite" needs a argument
	Player() : sprite(texture) {}; 

public:

	void Initialize();// <- called once per app start
	void Load(); // <- called once per app start

	void Update(Skeleton& skeleton); // <- once per frame
	void Draw(sf::RenderWindow& window);// <- once per frame
};


