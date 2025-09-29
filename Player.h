#pragma once
#include <SFML/Graphics.hpp>
#include "Skeleton.h"
#include "Bullet.h"

class Player
{
private:
	sf::Texture texture;

	std::vector <Bullet> bullets; // list of bullets

	float maxFireRate;
	float fireRateTimer;

	float speed;

	sf::RectangleShape boundingRectangle; // rect to see collision
	sf::Vector2i size; // size of bounding box

public:
	sf::Sprite sprite;
public:

	Player(); 	// constructor is needed because "sprite" needs a argument
	void Initialize();// <- called once per app start
	void Load(); // <- called once per app start
	void Update(float deltaTime, Skeleton& skeleton, sf::Vector2f& mousePosition, const sf::Vector2f& windowSize); // <- once per frame
	void Draw(sf::RenderWindow& window);// <- once per frame
};


