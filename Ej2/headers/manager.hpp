#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "circle.hpp"
#include "ellipse.hpp"
#include "rectangule.hpp"

template<typename Figure>
class Manager{
    public:
        static float calculateArea(const Figure& figura);
};

template<>
class Manager<Point>{
    public:
        static float calculateArea(const Point& p);
};

template<>
class Manager<Circle>{
    public:
        static float calculateArea(const Circle& c);
};

template<>
class Manager<Ellipse>{
    public:
        static float calculateArea(const Ellipse& e);
};

template<>
class Manager<Rectangle>{
    public:
        static float calculateArea(const Rectangle& r);
};

#endif