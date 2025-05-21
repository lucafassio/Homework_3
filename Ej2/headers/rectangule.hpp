#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "point.hpp"

class Rectangle: public Figure<float>{
    private:
        Point bottomLeft;
        float width;
        float height;
    public:
        Rectangle(Point bL, float w, float h);
        
        void setBottomLeft(Point newBottomLeft);
        void setWidth(float newWidth);
        void setHeight(float newHeight);
        Point getBottomLeft() const;
        float getWidth() const;
        float getHeight() const;

        float area() const override;
};

#endif