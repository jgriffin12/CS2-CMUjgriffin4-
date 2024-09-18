#include "point.h"

//Constructor
points::Point::Point(int X, int Y, points::Point* closestPoint)
{
    x = X; 
    y = Y; 
    nearestPoint = closestPoint; 
}

//Destructor
points::Point::~Point()
{

}

//Getters
int points::Point::getX()
{
    return x;
}

int points::Point::getY()
{
    return y;
}

points::Point* points::Point::getNearestPoint()
{
    return nearestPoint;
}

points::Point* points::Point::calcNearestPoint(Point* pointList[], unsigned long arrSize)
{
    int nearest; 
    double temp = 0; 
    for (unsigned long i = 0; i < arrSize; i++)
    {
        if (pointList[i] != this)        // 'this' makes it so that program ignores self
        {
            double distance = this-> distPoints(*pointList[i]);
            if (temp == 0 || distance < temp)
            {
                temp = distance; 
                nearest = i; 
            }
        }
    }
    return pointList[nearest]; 
}

//Setters
void points::Point::setX(int newVal)
{
    x = newVal;
}

void points::Point::setY(int newVal)
{
    y = newVal; 
}

void points::Point::setNearestPoint(Point* newNearestPoint)
{
    nearestPoint = newNearestPoint; 
}

// point.getX() and x are different x values
double points::Point::distPoints(Point& point)
{
    return sqrt(pow(point.getX()- x, 2) + pow(point.getY() - y, 2)); 
}