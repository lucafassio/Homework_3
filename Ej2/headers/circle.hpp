#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "point.hpp"

class Circle: public Figure<float>{
    private:
        Point center;
        float radius;

    public:
        Circle(Point c, float r);
        
        void setCenter(Point newCenter);
        void setRadius(float newRadius);
        Point getCenter() const;
        float getRadius() const;
        
        float area() const override;
};

#endif