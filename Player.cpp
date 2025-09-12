#include "Player.h"
#include <iostream>
#include "Math.h"


void Player::Initialize()
{
    
}

void Player::Load()
{
    if (texture.loadFromFile("D:\\rpg_game\\assets\\player\\textures\\spritesheet.png"))
    {
        std::cout << "player loaded" << std::endl;
        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(1550, 700));
        int Xindex = 0;
        int Yindex = 0;                         // position and width & height
        sprite.setTextureRect(sf::IntRect({ Xindex * 64, Yindex * 64 }, { 64, 64 }));
        sprite.scale(sf::Vector2f(2, 2)); // increase size of shown image by 3
    }
}

void Player::Update(Skeleton& skeleton)
{
    sf::Vector2f position = sprite.getPosition(); //get current position
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        sprite.setPosition(position + sf::Vector2f(speed, 0));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        sprite.setPosition(position + sf::Vector2f(0, -speed));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        sprite.setPosition(position + sf::Vector2f(-speed, 0));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        sprite.setPosition(position + sf::Vector2f(0, speed));

    //BULLET
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        bullets.push_back(sf::RectangleShape(sf::Vector2f(5, 3))); // add a bullet to list
        // set the first bullet's position of the last bullet the same as the player's
        int i = bullets.size() - 1;
        bullets[i].setPosition(sprite.getPosition());

    }

    // MOVE BULLET
    for (size_t i = 0; i < bullets.size(); i++)
    {
        sf::Vector2f bulletDirection = skeleton.sprite.getPosition() - bullets[i].getPosition(); // destination point
        bulletDirection = Math::NormalizeVector(bulletDirection); // make x and y to the destination point very small 
        bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed); //fire, change position every frame
    }
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);

    //DRAW BULLET
    for (size_t i = 0; i < bullets.size(); i++)
    {
        window.draw(bullets[i]);
    }

}
