#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    
    //--------------------------- INITIALIZATION ---------------------------
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8; // set anti-alias and creates the window
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "My window", sf::Style::Default, sf::State::Windowed, settings);
    //--------------------------- INITIALIZATION ---------------------------

     
    //--------------------------- LOAD ---------------------------
    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("D:\\rpg_game\\assets\\player\\textures\\spritesheet.png"))
    {
        std::cout << "player image failed to load" << std::endl;
        return -1;
    }
    
    sf::Sprite playerSprite(playerTexture); // apply the texture to the sprite

    int Xindex = 0;
    int Yindex = 0;                         // position and width & height
    playerSprite.setTextureRect(sf::IntRect({Xindex * 64, Yindex * 64 }, { 64, 64 }) );
    playerSprite.scale(sf::Vector2f(2,2)); // increase size of shown image by 3
    //--------------------------- LOAD ---------------------------
    
    
    
    
    // main game loop
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
             playerSprite.setPosition(position + sf::Vector2f(1, 0));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            playerSprite.setPosition(position + sf::Vector2f(0, -1));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            playerSprite.setPosition(position + sf::Vector2f(-1, 0));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            playerSprite.setPosition(position + sf::Vector2f(0, 1));

        // --------------------------- UPDATE---------------------------
                
        //--------------------------- DRAW ---------------------------
        window.clear(sf::Color::Black); // clear the window with black color
        window.draw(playerSprite);
        window.display();
        //--------------------------- DRAW ---------------------------
    }
}