#include "Math.h"

sf::Vector2f Math::NormalizeVector(sf::Vector2f vector)
{
    float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y); // vector length
    sf::Vector2f normalizedVector; // just a var to store values
    normalizedVector.x = vector.x / magnitude; // here we make vector very short
    normalizedVector.y = vector.y / magnitude; // so that it moves a little every frame
    return normalizedVector;
}