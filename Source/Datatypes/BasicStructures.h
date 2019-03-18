#pragma once
#include <SFML/Config.hpp>
#include <SFML/System/Vector2.hpp>
using sf::Uint8;
using sf::Vector2f;


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

enum class BallType
{
    COMMON,
    FIRE
};

struct BallData
{
    BallSize size;
    BallType type;
    Vector2f coords;
};

enum class UpgradeType : Uint8
{
    EXPAND,
    NARROW,
    DIVIDE,
    INCREASE,
    DECREASE,
    SLOW,
    FAST,
    CATCH,
    EXTRA_LIFE
};

enum class CollisionSide
{
    LEFT,
    RIGHT,
    TOP,
    BOTTOM
};
