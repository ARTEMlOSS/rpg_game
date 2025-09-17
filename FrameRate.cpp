#include "FrameRate.h"
#include <iostream>

FrameRate::FrameRate() :
    frameRateText(font), frameRateCount(0)
{
}

FrameRate::~FrameRate()
{
}

void FrameRate::Initialize()
{
}

void FrameRate::Load()
{
    if (font.openFromFile("assets/fonts/arial.ttf"))
    {
        std::cout << "Font arial.ttf loaded" << std::endl;
        frameRateText.setFont(font);// if font is loaded so set it
    }
    else
    {
        std::cout << "Font arial.ttf Failed to load" << std::endl;
    }
}

void FrameRate::Update(float& deltaTime)
{
    float fps = 1000.f / deltaTime;

    if (frameRateCount++ % 10 == 0) // to display and calculate FPS every 10 frames 
    {
        frameRateText.setString("FPS: " + std::to_string((int)fps) + 
            " frameTime: " + std::to_string((int)deltaTime)); // to display FPS on the screen
    }
    if (frameRateCount > 500) // to avoid overflow of the variable
        frameRateCount = 0;
}

void FrameRate::Draw(sf::RenderWindow& window)
{
    window.draw(frameRateText);

}
