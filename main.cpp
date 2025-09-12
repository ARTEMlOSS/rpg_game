#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Skeleton.h"

int main()
{
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8; // set anti-alias and creates the window
    sf::RenderWindow window(sf::VideoMode({ 1920, 1000 }), "My window", sf::Style::Default, sf::State::Windowed, settings);   

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
    
    // MAIN GAME LOOP
    while (window.isOpen()) // run the program as long as the window is open
    {
    //--------------------------- UPDATE 1 ---------------------------
   
        // EVENT LOOP
        while (const std::optional event = window.pollEvent()) 
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // TO UPDATE OUTSIDE OF THE EVENT LOOF IS FASTER
        skeleton.Update();
        player.Update(skeleton);

        // --------------------------- UPDATE 2 ---------------------------
                
        //--------------------------- DRAW 1 ---------------------------
        window.clear(sf::Color::Black); // clear the window with black color

        skeleton.Draw(window);
        player.Draw(window);

        window.display();
        //--------------------------- DRAW 2 ---------------------------
    }
}