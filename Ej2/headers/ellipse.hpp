#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include "point.hpp"

class Ellipse: public Figure<float>{
    private:
        Point center;
        float longD;
        float shortD;

    public:
        Ellipse(Point c, float lD, float sD);

        void setCenter(Point newCenter);
        void setLongD(float newLongD);
        void setShortD(float newShortD);
        Point getCenter() const;
        float getLongD() const;
        float getShortD() const;
        
        float area() const override;
};

#endif