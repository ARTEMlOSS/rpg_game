#pragma once
#include <SFML/Graphics.hpp>

class FrameRate
{
private:
    sf::Font font;
    sf::Text frameRateText;
    int frameRateCount;
public:
    FrameRate(); 	// constructor is needed because "frameRateText" needs a argument
    ~FrameRate(); // desctuctor

    void Initialize();
    void Load(); 
    void Update(float& deltaTime);
    void Draw(sf::RenderWindow& window);
};

