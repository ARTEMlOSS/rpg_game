#include "Skeleton.h"
#include <iostream>

void Skeleton::Initialize()
{
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Blue);
    boundingRectangle.setOutlineThickness(1);

    size = sf::Vector2i(64, 64);
}

void Skeleton::Load()
{
    if (texture.loadFromFile("D:\\rpg_game\\assets\\skeleton\\textures\\spritesheet.png"))
    {
        std::cout << "skeleton loaded" << std::endl;
        sprite.setPosition(sf::Vector2f(400, 700));
        int Xindex = 0;
        int Yindex = 2;                         // position and width & height
        sprite.setTextureRect(sf::IntRect({ Xindex * size.x, Yindex * size.x }, { size.x, size.y }));
        sprite.scale(sf::Vector2f(2, 2)); // increase size of shown image by 2
        boundingRectangle.setSize( // box size = player size * player scale
            sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y)
        );
    }
}

void Skeleton::Update(float deltaTime)
{
    boundingRectangle.setPosition(sprite.getPosition());

}

void Skeleton::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    window.draw(boundingRectangle);

}