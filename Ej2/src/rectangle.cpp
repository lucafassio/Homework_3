#include "../headers/rectangule.hpp"

Rectangle::Rectangle(Point bL, float w, float h): 
    bottomLeft(bL), width(w), height(h) 
{}

void Rectangle::setBottomLeft(Point newBL) {this->bottomLeft = newBL;}
void Rectangle::setWidth(float newWidth) {this->width = newWidth;}
void Rectangle::setHeight(float newHeight) {this->height = newHeight;}
Point Rectangle::getBottomLeft() const {return this->bottomLeft;}
float Rectangle::getWidth() const {return this->width;}
float Rectangle::getHeight() const {return this->height;}

float Rectangle::area() const {return width * height;}