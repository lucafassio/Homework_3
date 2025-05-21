#include "../headers/point.hpp"

Point::Point(): 
    posX(0.0f), posY(0.0f) 
{}

Point::Point(float x, float y): 
    posX(x), posY(y) 
{}

void Point::setX(float newX) {this->posX = newX;}
void Point::setY(float newY) {this->posY = newY;}
float Point::getX() const {return this->posX;}
float Point::getY() const {return this->posY;}

float Point::area() const {return 0.0f;}