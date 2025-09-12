#include "Skeleton.h"
#include <iostream>

void Skeleton::Initialize()
{

}

void Skeleton::Load()
{
    if (texture.loadFromFile("D:\\rpg_game\\assets\\skeleton\\textures\\spritesheet.png"))
    {
        std::cout << "skeleton loaded" << std::endl;
        sprite.setPosition(sf::Vector2f(400, 700));
        int Xindex = 0;
        int Yindex = 2;                         // position and width & height
        sprite.setTextureRect(sf::IntRect({ Xindex * 64, Yindex * 64 }, { 64, 64 }));
        sprite.scale(sf::Vector2f(2, 2)); // increase size of shown image by 3
    }
}

void Skeleton::Update()
{

}

void Skeleton::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}