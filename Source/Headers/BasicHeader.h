#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Time.hpp>
#include <vector>
using std::vector;
using sf::Time;
using sf::Vector2i;
using sf::Vector2u;
using sf::Vector2f;
using sf::Uint8;
using sf::Uint32;


enum class GameState
{
    START_GAME,
    PLAYING,
    END_GAME
};

enum class BallSize : Uint8
{
    SMALL = 10,
    LARGE = 20
};

struct BallData
{
    Vector2f coords;
    Uint8 radius;

    BallData(Vector2f coords, Uint8 radius):
        coords {coords},
        radius {radius}
    {
    }

    BallData operator=(BallData& other)
    {
        this->coords = other.coords;
        this->radius = other.radius;
        return *this;
    }
};
