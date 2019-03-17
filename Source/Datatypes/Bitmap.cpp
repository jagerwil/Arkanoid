#include "Bitmap.h"
#include <cmath>
using std::min;
#include "Headers/DebugHeader.h"


Bitmap::Bitmap()
{
    isInitialized = false;
}

void Bitmap::initialize(Vector2i size)
{
    if (!isInitialized)
    {
        this->size = size;

        bitmapArray = new bool*[size.x];
        for (int x = 0; x < size.x; ++x)
        {
            bitmapArray[x] = new bool[size.y]{false};
        }

        isInitialized = true;
    }
}

void Bitmap::loadFromImage(Image& image)
{
    Vector2i minSize;

    if (!isInitialized)
    {
        Vector2i imageSize = {(int)image.getSize().x, (int)image.getSize().y};
        initialize(imageSize);
        minSize = size;
    }
    else
    {
        minSize.x = min(size.x, (int)image.getSize().x);
        minSize.y = min(size.y, (int)image.getSize().y);
    }

    for (int x = 0; x < minSize.x; ++x)
    {
        for (int y = 0; y < minSize.y; ++y)
        {
            if (image.getPixel(x, y) == Color::Black)
            {
                bitmapArray[x][y] = true;
            }
            else bitmapArray[x][y] = false;
        }
    }
}

void Bitmap::copy(Bitmap& other)
{
    copyPartial(other, Vector2i{0, 0}, Vector2i{0, 0}, other.getSize());
}

void Bitmap::copyPartial(Bitmap& other, Vector2i fromCoords, Vector2i toCoords, Vector2i size)
{
    Vector2i minSize;

    if (!isInitialized)
    {
        initialize(other.getSize());
    }

    if (fromCoords.x < 0 || fromCoords.y < 0)
    {
        return; //invalid data
    }

    minSize.x = min(size.x, other.getSize().x - fromCoords.x);
    minSize.x = min(minSize.x, this->size.x - toCoords.x);
    minSize.y = min(size.y, other.getSize().y - fromCoords.y);
    minSize.y = min(minSize.y, this->size.y - toCoords.y);

    if (minSize.x <= 0 || minSize.y <= 0)
    {
        return;
    }

    for (int x = 0; x < minSize.x; ++x)
    {
        for (int y = 0; y < minSize.y; ++y)
        {
            bitmapArray[x + toCoords.x][y + toCoords.y] = other.bitmapArray[x + fromCoords.x][y + fromCoords.y];
        }
    }
}

bool Bitmap::getPixel(int x, int y)
{
    if (x >= size.x
        || y >= size.y)
    {
        return false;
    }

    return  bitmapArray[x][y];
}

Vector2i Bitmap::getSize()
{
    return size;
}

vector<Vector2i> getCollisionPoints(Bitmap& bitmap1, Bitmap& bitmap2)
{
    vector<Vector2i> collisionPoints;
    Vector2i size;

    size.x = min(bitmap1.getSize().x, bitmap2.getSize().x);
    size.y = min(bitmap1.getSize().y, bitmap2.getSize().y);

    for (int x = 0; x < size.x; ++x)
    {
        for (int y = 0; y < size.y; ++y)
        {
            if (bitmap1.getPixel(x, y) && bitmap2.getPixel(x, y))
            {
                collisionPoints.push_back(Vector2i{x, y});
            }
        }
    }

    return collisionPoints;
}
