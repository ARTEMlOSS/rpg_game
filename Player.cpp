#include "Player.h"
#include <iostream>
#include "Math.h"

void Player::Initialize()
{   
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Red);
    boundingRectangle.setOutlineThickness(1);

    size = sf::Vector2i(64, 64);
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
        sprite.setTextureRect(sf::IntRect({ Xindex * size.x, Yindex * size.x }, {size.x, size.y}));
        

        sprite.scale(sf::Vector2f(2, 2)); // increase size of shown image by 2
        boundingRectangle.setSize( // box size = player size * player scale
            sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y)
        );
    }
}

void Player::Update(float deltaTime, Skeleton& skeleton)
{
    sf::Vector2f position = sprite.getPosition(); //get current position
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        sprite.setPosition(position + sf::Vector2f(1, 0) * speed * deltaTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        sprite.setPosition(position + sf::Vector2f(0, -1) * speed * deltaTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        sprite.setPosition(position + sf::Vector2f(-1, 0) * speed * deltaTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        sprite.setPosition(position + sf::Vector2f(0, 1) * speed * deltaTime);

    //BULLET
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        bullets.push_back(sf::RectangleShape(sf::Vector2f(25, 15))); // add a bullet to list
        // set the first bullet's position of the last bullet the same as the player's
        int i = bullets.size() - 1;
        bullets[i].setPosition(sprite.getPosition());

    }

    // MOVE BULLET
    for (size_t i = 0; i < bullets.size(); i++)
    {
        sf::Vector2f bulletDirection = skeleton.sprite.getPosition() - bullets[i].getPosition(); // destination point
        bulletDirection = Math::NormalizeVector(bulletDirection); // make x and y to the destination point very small 
        bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed * deltaTime); //fire, change position every frame
    }

    // make bounder follow the player
    boundingRectangle.setPosition(sprite.getPosition());

    // detect collision
    if (Math::DidRectCollide(sprite.getGlobalBounds(), skeleton.sprite.getGlobalBounds()))
    {
        std::cout << "COLLISION" << std::endl;
    }
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    window.draw(boundingRectangle);

    //DRAW BULLET
    for (size_t i = 0; i < bullets.size(); i++)
    {
        window.draw(bullets[i]);
    }

}
