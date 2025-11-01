#include "Player.h"
#include <iostream>
#include "Math.h"

Player::Player() :
     speed(1.0f), maxFireRate(250), fireRateTimer(0) // 1000 milliseconds
{
}

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
        std::cout << "Loaded player" << std::endl;
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

void Player::Update(float deltaTime, Skeleton& skeleton, sf::Vector2f& mousePosition, const sf::Vector2f& windowSize)
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
    fireRateTimer += deltaTime; // we add frame time untill it's 1000 (1 second)
    // so we can shoot only once a second

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && fireRateTimer >= maxFireRate)
    {
        bullets.push_back(Bullet()); // add a bullet to list
        // set the first bullet's position of the last bullet the same as the player's
        int i = bullets.size() - 1; // last bullet that was pushed
        bullets[i].Initialize(sprite.getPosition(), mousePosition, 0.5f);
        fireRateTimer = 0; // reset timer after shooting
    }

    // MOVE BULLET
    for (size_t i = 0; i < bullets.size(); i++)
    {
        bullets[i].Update(deltaTime);
        if (skeleton.health > 0)
        { // detect collision
            if (Math::DidRectCollide(bullets[i].GetGlobalBounds(), skeleton.sprite.getGlobalBounds()))
            {
                skeleton.ChangeHealth(-10); // reduce hp only when collides 
                bullets.erase(bullets.begin() + i); // delete bullet
                std::cout << "Skeleton health: " << skeleton.health << std::endl;
            }
        }
        // if bullet is out of the screen
        if ((bullets[i].GetPosition().x > windowSize.x || bullets[i].GetPosition().x < 0) ||
            ((bullets[i].GetPosition().y > windowSize.y || bullets[i].GetPosition().y < 0)))
        {
            bullets.erase(bullets.begin() + i); // delete bullet
            std::cout << "Bullet destroyed, " << bullets.size() << " bullets left" << std::endl;
        }
    }

    // make bounder follow the player
    boundingRectangle.setPosition(sprite.getPosition());

    
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    window.draw(boundingRectangle);

    //DRAW BULLET
    for (size_t i = 0; i < bullets.size(); i++)
       bullets[i].Draw(window);
}
