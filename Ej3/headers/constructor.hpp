#ifndef CONSTRUCTOR_HPP
#define CONSTRUCTOR_HPP

#include "valueCont.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <type_traits>
#include <utility>
using namespace std;

class Constructor{
    private:
        Constructor() = delete;
        static ValueCont<pair<string, string>> data;

    public:
        static void addLine(string tag, string value) {data.addElement(make_pair(tag, value));}
        static void printJSON() {data.toString();}
};
ValueCont<pair<string, string>> Constructor::data;

#endif