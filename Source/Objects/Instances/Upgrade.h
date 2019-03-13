#pragma once
#include "Objects/Object.h"


class Upgrade : public Object
{
protected:
    UpgradeType type;

public:
    Upgrade(Vector2f coords, UpgradeType type);
};
