#pragma once
#include <SFML/Graphics.hpp>

class Skeleton
{
private:
	sf::Texture texture;
public:
	sf::Sprite sprite;
	float speed = 0.3f;

	// constructor is needed because "sprite" needs a argument
	Skeleton() : sprite(texture) {};

public:

	void Initialize();// <- called once per app start
	void Load(); // <- called once per app start

	void Update(); // <- once per frame
	void Draw(sf::RenderWindow& window);// <- once per frame
};

