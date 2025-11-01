#include "Map.h"
#include <iostream>


Map::Map() :
    totalTilesX(0), totalTilesY(0),
    totalTiles(0), tiles(nullptr), mapSprites(nullptr)
{

}

Map::~Map()
{
    delete[] mapSprites;
    delete[] tiles;
}

void Map::Initialize()
{

}

void Map::Load(std::string filename)
{//"assets/maps/level1.rmap"

    mapLoader.Load(filename, md);

    mapSprites = new sf::Sprite[md.dataSize];

    if (tileSheetTexture.loadFromFile(md.tilesheet))
    {
        totalTilesX = tileSheetTexture.getSize().x / md.tileWidth; // 24
        totalTilesY = tileSheetTexture.getSize().y / md.tileHeight; // 12

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
                tiles[i].position = sf::Vector2i(x * md.tileWidth, y * md.tileHeight);
            }
        }
    }
    else
    {
        std::cout << "Failed to load World prison tileSheet" << std::endl;
    }

    // CREATE THE MAP BY APPLYING TILE TEXTURES TO THE SPRITES IN THE SPRITE ARRAY
    for (int y = 0; y < md.mapHeight; y++)
    {
        for (int x = 0; x < md.mapWidth; x++)
        {
            int i = x + (y * md.mapWidth);
            int index = md.data[i]; // we go through the numbers which will be used as indexes
            mapSprites[i].setTexture(tileSheetTexture);
            mapSprites[i].setTextureRect(sf::IntRect(
                tiles[index].position.x,
                tiles[index].position.y,
                md.tileWidth,
                md.tileHeight)
            );
            mapSprites[i].setPosition(sf::Vector2f(x * md.tileWidth * md.scaleX,
                y * md.tileHeight * md.scaleY));
            mapSprites[i].setScale(sf::Vector2f(md.scaleX, md.scaleY));
        }
    }
}

void Map::Update(float deltaTime)
{
}

void Map::Draw(sf::RenderWindow& window)
{
     for (int i = 0; i < md.dataSize; i++)
    {
        window.draw(mapSprites[i]);
    }
    
}