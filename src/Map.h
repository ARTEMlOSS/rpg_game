#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include "Tile.h"

class Map
{;
private:
	sf::Texture tileSheetTexture;
	//we don't create an array cause we cannot reassign it later on
	//we create a pointer to the array which is situated in Map.cpp on the heap
	Tile* tiles; // <- it's the whole numered table of tiles 

	int totalTiles;

	int tileWidth;
	int tileHeight;

	int totalTilesX;
	int totalTilesY;

	static const int mapSize = 6;
	int mapWidth;
	int mapHeight;

	int mapNumbers[mapSize] = {120, 121, 122, 144, 145, 146}; // <- it's the actual map to draw, bunch of indexes

	sf::Sprite mapSprites[mapSize];
public:
	Map();
	~Map();

	void Initialize();// <- called once per app start
	void Load(); // <- called once per app start
	void Update(float deltaTime); // <- once per frame
	void Draw(sf::RenderWindow& window);// <- once per frame
};

