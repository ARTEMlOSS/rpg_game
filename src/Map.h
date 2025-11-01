#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include "Tile.h"
#include "MapLoader.h"
#include "MapData.h"

class Map
{;
private:
	sf::Texture tileSheetTexture;
	//we don't create an array cause we cannot reassign it later on
	//we create a pointer to the array which is situated in Map.cpp on the heap
	Tile* tiles; // <- it's the whole numered table of tiles 

	MapLoader mapLoader;
	MapData md;

	int totalTiles;

	int totalTilesX;
	int totalTilesY;

	sf::Sprite* mapSprites;//it's a pointer because we don't know the size now
public:
	Map();
	~Map();

	void Initialize();// <- called once per app start
	void Load(std::string filename); // <- called once per app start
	void Update(float deltaTime); // <- once per frame
	void Draw(sf::RenderWindow& window);// <- once per frame
};

