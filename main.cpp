#include <SFML/Graphics.hpp>

int main()
{
    
    //--------------------------- INITIALIZATION ---------------------------
    // set anti-alias and creates the window
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "My window", sf::Style::Default, sf::State::Windowed, settings);

    sf::CircleShape shape(50.f, 3);
    shape.setFillColor(sf::Color(100, 250, 50));
    shape.setPosition(sf::Vector2f(100, 100));
    shape.setOutlineThickness(10);
    shape.setOutlineColor(sf::Color::Blue);

    sf::RectangleShape rectangle({ 100.f, 3.f });
    rectangle.setPosition(sf::Vector2f(500, 100));
    rectangle.setFillColor(sf::Color::Red);
    // sets pivot point to the center instead of top left
    rectangle.setOrigin(rectangle.getSize() / 2.f);
    rectangle.setRotation(sf::degrees(45));
    //--------------------------- INITIALIZATION ---------------------------
     
    // run the program as long as the window is open
    while (window.isOpen())
    {
        //--------------------------- UPDATE ---------------------------
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        //--------------------------- UPDATE ---------------------------
        
        //--------------------------- DRAW ---------------------------
        // clear the window with black color
        window.clear(sf::Color::Black);
        window.draw(shape);
        window.draw(rectangle);
        window.display();
        //--------------------------- DRAW ---------------------------
    }
}