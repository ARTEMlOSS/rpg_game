#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Skeleton.h"

int main()
{
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8; // set anti-alias and creates the window
    sf::RenderWindow window(sf::VideoMode({ 1920, 1000 }), "My window", sf::Style::Default, sf::State::Windowed, settings);   
    //window.setVerticalSyncEnabled(true); //it makes frame rate stick to monitor's FPS
    window.setFramerateLimit(500);

    Player player;
    Skeleton skeleton;

    //--------------------------- INIT ---------------------------
    player.Initialize();
    skeleton.Initialize();
    //--------------------------- INIT ---------------------------


    //--------------------------- LOAD ---------------------------
    player.Load();
    skeleton.Load();
    //--------------------------- LOAD ---------------------------
    
    sf::Clock clock;

    // MAIN GAME LOOP
    while (window.isOpen()) // run the program as long as the window is open
    {   

        sf::Time deltaTimeTimer = clock.restart();
        float deltaTime = deltaTimeTimer.asMilliseconds();
        std::cout << deltaTime << std::endl;
        //--------------------------- UPDATE 1 ---------------------------
   
        // EVENT LOOP
        while (const std::optional event = window.pollEvent()) 
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // TO UPDATE OUTSIDE OF THE EVENT LOOF IS FASTER
        // --------------------------- UPDATE 2 ---------------------------
        skeleton.Update(deltaTime);
        player.Update(deltaTime, skeleton);
        //--------------------------- DRAW 1 ---------------------------
        window.clear(sf::Color::Black); // clear the window with black color

        skeleton.Draw(window);
        player.Draw(window);

        window.display();
        //--------------------------- DRAW 2 ---------------------------
    }
}