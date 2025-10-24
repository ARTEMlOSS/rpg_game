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
        totalTilesX = tileSheetTexture.getSize().x / tileWidth; // 24
        totalTilesY = tileSheetTexture.getSize().y / tileHeight; // 12

        totalTiles = totalTilesX * totalTilesY;

        std::cout << "Loaded World prison tileSheet" << std::endl;

        // with "new" I allocate memory in the heap but I need to delete it manualy later on
        tiles = new Tile[totalTiles];//the pointer "tiles" referrs to instances of the Tile array 
       // std::cout << "totalTiles = " << totalTiles << std::endl;
        // CREATE THE ARRAY OF MAP TEXTURES SPLIT ON TILES
        for (int y = 0; y < totalTilesY; y++)
        {
            //std::cout << "entered y loop" << std::endl;
            for (int x = 0; x < totalTilesX; x++)
            {
                //std::cout << "entered x loop" << std::endl;
                // 1,2...24 + (0 * 24)  then  1,2...(1 * 24) + 24  then  1,2...24 + (2 * 24), it gives 0,1,2,...287 
                int i = x + (y * totalTilesX);   
                tiles[i].id = i;
                //std::cout << "i = " << i << std::endl;
                tiles[i].position = sf::Vector2i(x * tileWidth, y * tileHeight);
            }
        }
    }
    else
    {
        std::cout << "Failed to load World prison tileSheet" << std::endl;
    }

    // CREATE THE MAP BY APPLYING TILE TEXTURES TO THE SPRITES IN THE SPRITE ARRAY
    for (int y = 0; y < 2; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            int i = x + (y * 3);
            int index = mapNumbers[i]; // we go through the numbers which will be used as indexes
            mapSprites[i].setTexture(tileSheetTexture);
            mapSprites[i].setTextureRect(sf::IntRect(
                tiles[index].position.x,
                tiles[index].position.y,
                tileWidth,
                tileHeight)
            );
            mapSprites[i].setPosition(sf::Vector2f(x * 16 * 4, y * 16 * 4));
            mapSprites[i].setScale(sf::Vector2f(4, 4));
        }
    }
}

void Map::Update(float deltaTime)
{
}

void Map::Draw(sf::RenderWindow& window)
{
     for (int i = 0; i < 6; i++)
    {
        window.draw(mapSprites[i]);
    }
    
}