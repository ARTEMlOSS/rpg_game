#pragma once
#include <SFML/Graphics.hpp>


class Bullet
{
public:

private:
	sf::RectangleShape rectangleShape;
	sf::Vector2f direction;
	float speed;

public:
	Bullet();
	~Bullet();

	void Initialize(const sf::Vector2f& position, const sf::Vector2f& target, float speed);
	void Load();
	void Update(float deltaTime); 
	void Draw(sf::RenderWindow& window);

	// we create this method to leave "rectangleShape" private and get it's bounds
	// "inline" allows not to call the function but to paste it's content where it's "called" 
	// it saves on perfomance if there's only single line of code in the function
	inline const sf::FloatRect& GetGlobalBounds() { return rectangleShape.getGlobalBounds(); }
	inline const sf::Vector2f& GetPosition() { return rectangleShape.getPosition(); }
};

