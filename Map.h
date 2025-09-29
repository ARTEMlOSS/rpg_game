#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>


class Map
{;
private:
	sf::Texture tileSheetTexture;
	sf::Sprite sprites[10];

	int tileWidth;
	int tileHeight;

	int totalTilesX;
	int totalTilesY;
public:
	Map();
	~Map();

	void Initialize();// <- called once per app start
	void Load(); // <- called once per app start
	void Update(float deltaTime); // <- once per frame
	void Draw(sf::RenderWindow& window);// <- once per frame
};

