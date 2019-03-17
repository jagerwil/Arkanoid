#pragma once
#include "Headers/GraphicsHeader.h"

class Bitmap
{
protected:
    bool** bitmapArray;
    Vector2i size;

    bool isInitialized;

public:
    Bitmap();
    void initialize(Vector2i size);

    void loadFromImage(Image& image);
    void copy(Bitmap& other);
    void copyPartial(Bitmap& other, Vector2i fromCoords, Vector2i toCoords, Vector2i size);

    friend vector<Vector2i> getCollisionPoints(Bitmap& bitmap1, Bitmap& bitmap2);


    bool getPixel(int x, int y);
protected:
    Vector2i getSize();
};
