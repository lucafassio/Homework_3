#include "vector.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <type_traits>
#include <utility>
using namespace std

class Constructor{
    private:
        Constructor() = delete;
        static Vector<pair<string, string>> data;

    public:
        static void addLine(string tag, string value) {data.push_back(make_pair(tag, value));}
        static void printJSON() {data.toString();}
};
Vector<pair<string, string>> Constructor::data;