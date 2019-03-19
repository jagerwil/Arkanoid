#pragma once
#include "Datatypes/BasicStructures.h"
#include <SFML/System/Clock.hpp>
#include <memory>
#include <vector>
using std::unique_ptr;
using std::shared_ptr;
using std::vector;
using sf::Clock;
using sf::Time;
using sf::Uint8;
using sf::Uint32;
using sf::Vector2i;
using sf::Vector2u;
using sf::Vector2f;

///GLOBAL VARIABLES!
const static Vector2i screenSize = {1366, 768};
const static float pi = 3.14159f;
const static float radian = 180.f / pi;
