#include "Skeleton.h"
#include <iostream>

Skeleton::Skeleton() :
    speed(0), health(100)
{
}

void Skeleton::ChangeHealth(int hp)
{
    health += hp;
    healthText.setString(std::to_string(health));

}

void Skeleton::Initialize()
{
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Blue);
    boundingRectangle.setOutlineThickness(1);

    size = sf::Vector2i(64, 64);
}

void Skeleton::Load()
{
    // load font for health writing
    if (font.loadFromFile("assets/fonts/arial.ttf"))
    {
        std::cout << "Loaded Font arial.ttf" << std::endl;
        healthText.setFont(font);// if font is loaded so set it
        healthText.setString(std::to_string(health)); // set initial hp value
    }
    else
    {
        std::cout << "Failed to load Font arial.ttf" << std::endl;
    }

    if (texture.loadFromFile("D:\\rpg_game\\assets\\skeleton\\textures\\spritesheet.png"))
    {
        std::cout << "Loaded skeleton" << std::endl;
        sprite.setTexture(texture);
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
    if (health > 0)
    {
        healthText.setPosition(sprite.getPosition());
        boundingRectangle.setPosition(sprite.getPosition());
    }
}

void Skeleton::Draw(sf::RenderWindow& window)
{
    if (health > 0)
    {
        window.draw(healthText);
        window.draw(sprite);
        window.draw(boundingRectangle);
    }
}