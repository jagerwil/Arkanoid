#include "Bitmap.h"
#include <cmath>
using std::min;


Bitmap::Bitmap()
{ }

void Bitmap::initialize(Image& image)
{
    size = image.getSize();

    bitmapArray = new bool*[size.x];
    for (Uint32 x = 0; x < size.x; ++x)
    {
        bitmapArray[x] = new bool[size.y];

        for (Uint32 y = 0; y < size.y; ++y)
        {
            if (image.getPixel(x, y) == Color::Black)
            {
                bitmapArray[x][y] = true;
            }
            else bitmapArray[x][y] = false;
        }
    }
}
/*
Bitmap::~Bitmap()
{
    for (Uint32 x = 0; x < size.x; ++x)
    {
        delete bitmapArray[x];
    }

    delete bitmapArray;
}
*/
bool Bitmap::getPixel(Uint32 x, Uint32 y)
{
    if (x >= size.x
        || y >= size.y)
    {
        return false;
    }

    return  bitmapArray[x][y];
}

Vector2u Bitmap::getSize()
{
    return size;
}

vector<Vector2u> getCollisionPoints(Bitmap& bitmap1, Bitmap& bitmap2)
{
    vector<Vector2u> collisionPoints;

    Vector2u size;
    size.x = min(bitmap1.getSize().x, bitmap2.getSize().x);
    size.y = min(bitmap1.getSize().y, bitmap2.getSize().y);

    for (Uint32 x = 0; x < size.x; ++x)
    {
        for (Uint32 y = 0; y < size.y; ++y)
        {
            if (bitmap1.getPixel(x, y) && bitmap1.getPixel(x, y))
            {
                collisionPoints.push_back(Vector2u{x, y});
            }
        }
    }

    return collisionPoints;
}
