#include "../headers/ellipse.hpp"

Ellipse::Ellipse(Point c, float lD, float sD): 
    center(c), longD(lD), shortD(sD) 
{}

void Ellipse::setCenter(Point newCenter) {this->center = newCenter;}
void Ellipse::setLongD(float newLongD) {this->longD = newLongD;}
void Ellipse::setShortD(float newShortD) {this->shortD = newShortD;}
Point Ellipse::getCenter() const {return this->center;}
float Ellipse::getLongD() const {return this->longD;}
float Ellipse::getShortD() const {return this->shortD;}

float Ellipse::area() const { return 3.14f * longD * shortD;}