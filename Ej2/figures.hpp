#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template<typename metric>
class Figure{
    public:
        virtual metric area() const = 0;
        virtual ~Figure() = default;
};

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

class Circle: public Figure<float>{
    private:
        Point center;
        float radius;

    public:
        Circle(Point _center, float _radius);
        
        void setCenter(Point _center);
        void setRadius(float _radius);
        Point getCenter() const;
        float getRadius() const;
        
        float area() const override;
};

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