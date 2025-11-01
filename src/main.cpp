#include <SFML/Graphics.hpp>
#include <iostream>

#include "FrameRate.h"
#include "Map.h"
#include "Player.h"
#include "Skeleton.h"

#include "MapLoader.h"

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8; // set anti-alias
    //window.setVerticalSyncEnabled(true); //it makes frame rate stick to monitor's FPS
    sf::RenderWindow window(sf::VideoMode(1920, 1000), "My window", sf::Style::Default);
    window.setFramerateLimit(60);
    sf::Vector2f windowSize = sf::Vector2f(window.getSize());

    FrameRate frameRate;
    Map map;
    Player player;
    Skeleton skeleton;
    MapLoader mapLoader;
    mapLoader.Load("assets/maps/level1.rmap");
    //--------------------------- INIT ---------------------------
    frameRate.Initialize();
    map.Initialize();
    player.Initialize();
    skeleton.Initialize();
    //--------------------------- INIT ---------------------------


    //--------------------------- LOAD ---------------------------
    std::cout << std::endl;
    frameRate.Load();
    map.Load();
    player.Load();
    skeleton.Load();
    std::cout << std::endl;
    //--------------------------- LOAD ---------------------------
    
    sf::Clock clock;
    sf::Event event;

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
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // TO UPDATE OUTSIDE OF THE EVENT LOOF IS FASTER
        // we pass "window" in "getPosition(window)" to calculate mouse relatevely window, not the screen
        sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window)); // we shouldn't call mouse in "updates"

        frameRate.Update(deltaTime);
        map.Update(deltaTime);
        skeleton.Update(deltaTime);
        player.Update(deltaTime, skeleton, mousePosition, windowSize);
        // --------------------------- UPDATE END ---------------------------

        //--------------------------- DRAW START ---------------------------
        window.clear(); // clear the window with black color

        map.Draw(window);
        skeleton.Draw(window);
        player.Draw(window);
        frameRate.Draw(window);

        window.display();
        //--------------------------- DRAW END ---------------------------
    }
}