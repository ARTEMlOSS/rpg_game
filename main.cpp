#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>

sf::Vector2f NormalizeVector(sf::Vector2f vector)
{
    float magnitude = std::sqrt(vector.x* vector.x + vector.y * vector.y); // vector length
    sf::Vector2f normalizedVector; // just a var to store values
    normalizedVector.x = vector.x / magnitude; // here we make vector very short
    normalizedVector.y = vector.y / magnitude; // so that it moves a little every frame
    return normalizedVector;
}

int main()
{
     //--------------------------- INITIALIZATION ---------------------------
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8; // set anti-alias and creates the window
    sf::RenderWindow window(sf::VideoMode({ 1920, 1000 }), "My window", sf::Style::Default, sf::State::Windowed, settings);
    //--------------------------- INITIALIZATION ---------------------------

    //SKELETON
    sf::Texture skeletonTexture;
    sf::Sprite skeletonSprite(skeletonTexture); // apply the texture to the sprite
    if (skeletonTexture.loadFromFile("D:\\rpg_game\\assets\\skeleton\\textures\\spritesheet.png"))
    {
        std::cout << "skeleton loaded" << std::endl;
        skeletonSprite.setPosition(sf::Vector2f(400, 700));
        int Xindex = 0;
        int Yindex = 2;                         // position and width & height
        skeletonSprite.setTextureRect(sf::IntRect({ Xindex * 64, Yindex * 64 }, { 64, 64 }));
        skeletonSprite.scale(sf::Vector2f(2, 2)); // increase size of shown image by 3
    }

    //PLAYER
    sf::Texture playerTexture;
    float playerSpeed = 0.3f;
    sf::Sprite playerSprite(playerTexture); // apply the texture to the sprite
    if (playerTexture.loadFromFile("D:\\rpg_game\\assets\\player\\textures\\spritesheet.png"))
    {
        std::cout << "player loaded" << std::endl;
        playerSprite.setPosition(sf::Vector2f(1550, 700));
        int Xindex = 0;
        int Yindex = 0;                         // position and width & height
        playerSprite.setTextureRect(sf::IntRect({ Xindex * 64, Yindex * 64 }, { 64, 64 }));
        playerSprite.scale(sf::Vector2f(2, 2)); // increase size of shown image by 3
    }
    
    //BULLET
    std::vector < sf::RectangleShape> bullets; // list of bullets
    float bulletSpeed = 0.4f;



    // MAIN GAME LOOP
    while (window.isOpen()) // run the program as long as the window is open
    {
        //--------------------------- UPDATE ---------------------------
        // EVENT LOOP
        while (const std::optional event = window.pollEvent()) 
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        //OUTSIDE OF THE EVENT LOOF IS FASTER
         
        
        //MOVEMENT
        sf::Vector2f position = playerSprite.getPosition(); //get current position
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
             playerSprite.setPosition(position + sf::Vector2f(playerSpeed, 0));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            playerSprite.setPosition(position + sf::Vector2f(0, -playerSpeed));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            playerSprite.setPosition(position + sf::Vector2f(-playerSpeed, 0));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            playerSprite.setPosition(position + sf::Vector2f(0, playerSpeed));

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            bullets.push_back(sf::RectangleShape(sf::Vector2f(5, 3))); // add a bullet to list
            // set the first bullet's position of the last bullet the same as the player's
            int i = bullets.size() - 1;
            bullets[i].setPosition(playerSprite.getPosition());
      
        }

        // MOVE BULLET
        for (size_t i = 0; i < bullets.size(); i++)
        {
            sf::Vector2f bulletDirection = skeletonSprite.getPosition() - bullets[i].getPosition(); // destination point
            bulletDirection = NormalizeVector(bulletDirection); // make x and y to the destination point very small 
            bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed); //fire, change position every frame
        }


        // --------------------------- UPDATE---------------------------
                
        //--------------------------- DRAW ---------------------------
        window.clear(sf::Color::Black); // clear the window with black color

        window.draw(playerSprite);
        window.draw(skeletonSprite);
        for (size_t i = 0; i < bullets.size(); i++)
        {
            window.draw(bullets[i]);
        }

        window.display();
        //--------------------------- DRAW ---------------------------
    }
}