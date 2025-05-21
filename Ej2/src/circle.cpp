#include "../headers/circle.hpp"

Circle::Circle(Point c, float r): 
    center(c), radius(r) 
{}

void Circle::setCenter(Point newCenter) {this->center = newCenter;}
void Circle::setRadius(float newRadius) {this->radius = newRadius;}
Point Circle::getCenter() const {return this->center;}
float Circle::getRadius() const {return this->radius;}

float Circle::area() const {return 3.14f * radius * radius;}