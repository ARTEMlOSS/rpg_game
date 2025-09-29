#include "Map.h"
#include <iostream>


Map::Map() :
   tileWidth(16), tileHeight(16), totalTilesX(0), totalTilesY(0)
{

}

Map::~Map()
{
}

void Map::Initialize()
{

}

void Map::Load()
{

    if (tileSheetTexture.loadFromFile("D:\\rpg_game\\assets\\world\\prison\\tilesheet.png"))
    {
        totalTilesX = tileSheetTexture.getSize().x / tileWidth;
        totalTilesY = tileSheetTexture.getSize().y / tileHeight;

        std::cout << "Loaded World prison tileSheet" << std::endl;

       for (int i = 0; i < 10; i++)
        {
            sprites[i].setTexture(tileSheetTexture);
            sprites[i].setTextureRect(sf::IntRect({ i * tileWidth, 0 * tileHeight }, { tileWidth, tileHeight })); // position and width & height
            sprites[i].setScale(sf::Vector2f(4, 4));
            sprites[i].setPosition(sf::Vector2f(0 + i * tileWidth * 4, 0));
        }

    }
    else
    {
        std::cout << "Failed to load World prison tileSheet" << std::endl;
    }
}

void Map::Update(float deltaTime)
{
}

void Map::Draw(sf::RenderWindow& window)
{
    for (size_t i = 0; i < 10; i++)
    {
        window.draw(sprites[i]);
    }
    
}