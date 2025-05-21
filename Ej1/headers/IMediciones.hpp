#ifndef IMEDICIONES_HPP
#define IMEDICIONES_HPP

#include <iostream>
#include <fstream>
#include <memory>
using namespace std;

class IMediciones{
    public:
        virtual void serializar(ostream& out) const = 0;
        virtual void deserializar(istream& in) = 0;

        virtual ~IMediciones() = default;
};

#endif