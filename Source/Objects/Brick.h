#pragma once
#include "Headers/BasicHeader.h"
#include <SFML/Graphics/Transformable.hpp>
using sf::Transformable;


class Brick : public Transformable
{
protected:
    Vector2f coords;

public:
    Brick();
};
