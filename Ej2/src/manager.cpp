#include "../headers/manager.hpp"

template<typename Figure>
float Manager<Figure>::calculateArea(const Figure& figura) {return figura.area();}

float Manager<Point>::calculateArea(const Point& point) {return point.area();}
float Manager<Circle>::calculateArea(const Circle& circle) {return circle.area();}
float Manager<Ellipse>::calculateArea(const Ellipse& ellipse) {return ellipse.area();}
float Manager<Rectangle>::calculateArea(const Rectangle& rectangle) {return rectangle.area();}