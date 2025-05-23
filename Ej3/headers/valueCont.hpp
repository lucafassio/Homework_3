#ifndef VALUECONT_HPP
#define VALUECONT_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <type_traits>
#include <utility>
#include <vector>
using namespace std;

template<typename dataType>
class ValueCont{
    private:
        vector<dataType> data;

    public:
        ValueCont();
        ValueCont(initializer_list<dataType> list);
        
        void addElement(dataType value);
        int getSize() const;
        string toString() const;
};

#endif 