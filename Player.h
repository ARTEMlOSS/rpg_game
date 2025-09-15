#pragma once
#include <SFML/Graphics.hpp>
#include "Skeleton.h"

class Player
{
private:
	sf::Texture texture;

	std::vector < sf::RectangleShape> bullets; // list of bullets
	float bulletSpeed = 2.0f;

	float speed = 1.0f;

	sf::RectangleShape boundingRectangle; // rect to see collision
	sf::Vector2i size; // size of bounding box

public:
	sf::Sprite sprite;
	Player() : sprite(texture) {}; 	// constructor is needed because "sprite" needs a argument

public:

	void Initialize();// <- called once per app start
	void Load(); // <- called once per app start

	void Update(float deltaTime, Skeleton& skeleton); // <- once per frame
	void Draw(sf::RenderWindow& window);// <- once per frame
};


