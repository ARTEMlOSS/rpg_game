#include "Math.h"

sf::Vector2f Math::NormalizeVector(sf::Vector2f vector)
{
    float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y); // vector length
    sf::Vector2f normalizedVector; // just a var to store values
    normalizedVector.x = vector.x / magnitude; // here we make vector very short
    normalizedVector.y = vector.y / magnitude; // so that it moves a little every frame
    return normalizedVector;
}



bool Math::DidRectCollide(sf::FloatRect rect1, sf::FloatRect rect2)
{
    if (rect1.intersects(rect2))
        return true;
    return false;
}

/*rect1.left + rect1.width > rect2.left &&
        rect2.left + rect2.width > rect1.left &&
        rect2.top + rect2.height > rect1.top &&
        rect1.top + rect1.height > rect2.top  */