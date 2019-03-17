#pragma once
#include "Headers/GraphicsHeader.h"

class Bitmap
{
protected:
    bool** bitmapArray;
    Vector2u size;

public:
    Bitmap();
    void initialize(Image& image);
    ///~Bitmap();

    friend vector<Vector2u> getCollisionPoints(Bitmap& bitmap1, Bitmap& bitmap2);

protected:
    bool getPixel(Uint32 x, Uint32 y);
    Vector2u getSize();
};

