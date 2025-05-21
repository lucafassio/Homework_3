#ifndef FIGURE_HPP
#define FIGURE_HPP

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

#endif