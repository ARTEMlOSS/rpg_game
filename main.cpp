#include <SFML/Graphics.hpp>
#include <iostream>
#include "FrameRate.h"
#include "Player.h"
#include "Skeleton.h"

int main()
{
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8; // set anti-alias and creates the window
    sf::RenderWindow window(sf::VideoMode({ 1920, 1000 }), "My window", sf::Style::Default, sf::State::Windowed, settings);   
    //window.setVerticalSyncEnabled(true); //it makes frame rate stick to monitor's FPS
    window.setFramerateLimit(60);


    FrameRate frameRate;
    Player player;
    Skeleton skeleton;

    //--------------------------- INIT ---------------------------
    frameRate.Initialize();
    player.Initialize();
    skeleton.Initialize();
    //--------------------------- INIT ---------------------------


    //--------------------------- LOAD ---------------------------
    //LOAD FONTS

    frameRate.Load();
    player.Load();
    skeleton.Load();
    //--------------------------- LOAD ---------------------------
    
    sf::Clock clock;

    // MAIN GAME LOOP
    while (window.isOpen()) // run the program as long as the window is open
    {   
        // returns time between the loop started and restarted (time of 1 frame)
        //the slower the game is the bigger the value, so we can mustiply by it 
        // any update and keep game speed constant
        sf::Time deltaTimeTimer = clock.restart(); 
        float deltaTime = deltaTimeTimer.asMilliseconds();


        //--------------------------- UPDATE START ---------------------------
   
        // EVENT LOOP
        while (const std::optional event = window.pollEvent()) 
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // TO UPDATE OUTSIDE OF THE EVENT LOOF IS FASTER
        frameRate.Update(deltaTime);
        skeleton.Update(deltaTime);
        player.Update(deltaTime, skeleton);

        // --------------------------- UPDATE END ---------------------------

        //--------------------------- DRAW START ---------------------------
        window.clear(sf::Color::Black); // clear the window with black color

        skeleton.Draw(window);
        player.Draw(window);
        frameRate.Draw(window);


        window.display();
        //--------------------------- DRAW END ---------------------------
    }
}