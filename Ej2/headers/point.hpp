#ifndef POINT_HPP
#define POINT_HPP

#include "figure.hpp"

class Point : public Figure<float>{
    private:
        float posX;
        float posY;

    public:
        Point();
        Point(float x, float y);
        
        void setX(float x);
        void setY(float y);
        float getX() const;
        float getY() const;
        
        float area() const override;
};

#endif