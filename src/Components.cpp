#include "Components.h"
#include <cmath>

#include <iostream>

bool AABB::didSimpleCollide(AABB &other, Vector2d &collision)
{
    int lengthX = (cx - other.cx);
    int gapX = lengthX - rw - other.rw;
    if(gapX > 0)
    {
        return false;
    }
    int lengthY = (cy - other.cy);
    int gapY = lengthY - rh - other.rh;
    if(gapY > 0)
    {
        return false;
    }
    collision._x = gapX;
    collision._y = gapY;
    return true;
}

bool AABB::didMinkowskiCollide(AABB &other)
{
    int height = rh + other.rh;
    int width = rw + other.rw;
    std::cout << "w/h : " << width << " / " << height << std::endl;
    if(other.cx > cx - width && other.cx < cx + width)
    {
        std::cout << "Collide X" << std::endl;
        if(other.cy > cy - height && other.cy < cy + height)
        {
            return true;
        }
    }
    return false;
}
