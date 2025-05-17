#include "figures.hpp"

//======== Point =========//
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

//======== Circle =========//
Circle::Circle(Point c, float r): 
    center(c), radius(r) 
{}

void Circle::setCenter(Point newCenter) {this->center = newCenter;}
void Circle::setRadius(float newRadius) {this->radius = newRadius;}
Point Circle::getCenter() const {return this->center;}
float Circle::getRadius() const {return this->radius;}

float Circle::area() const {return 3.14f * radius * radius;}

//======== Ellipse =========//
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

//======== Rectangle =========//
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

//======== Manager =========//
template<typename Figure>
float Manager<Figure>::calculateArea(const Figure& figura) {return figura.area();}

float Manager<Point>::calculateArea(const Point& point) {return point.area();}
float Manager<Circle>::calculateArea(const Circle& circle) {return circle.area();}
float Manager<Ellipse>::calculateArea(const Ellipse& ellipse) {return ellipse.area();}
float Manager<Rectangle>::calculateArea(const Rectangle& rectangle) {return rectangle.area();}