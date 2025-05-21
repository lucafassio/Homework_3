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
        ValueCont(): 
            data(vector<dataType>())
        {}

        ValueCont(initializer_list<dataType> list): 
            data(vector<dataType>(list))
        {}
        
        void addElement(dataType value){
            data.push_back(value);
        };

        dataType& operator[](int index) {return data[index];}
        int getSize() const {return data.size();}

        string toString() const {
            string result = "[";
            if constexpr(is_arithmetic_v<dataType>){
                for (unsigned i = 0; i < data.size(); i++){
                    result += to_string(data[i]).substr(0, to_string(data[i]).find(".")+2);
                    if (i < data.size() - 1) result += ", ";
                }
            }
            else if constexpr(is_same_v<dataType, string>){
                for (unsigned i = 0; i < data.size(); i++){
                    result += data[i];
                    if (i < data.size() - 1) result += ", ";
                }
            }
            else if constexpr(is_same_v<dataType, ValueCont<int>>){
                for (unsigned i = 0; i < data.size(); i++){
                    result += data[i].toString();
                    if (i < data.size() - 1) result += ",\n\t     ";
                }
            }
            else if constexpr(is_same_v<dataType, pair<string, string>>){
                result = "{\n ";
                for (unsigned i = 0; i < data.size(); i++){
                    result += '"' + data[i].first + '"' + ": " + data[i].second;
                    if (i < data.size() - 1) result += ",\n  ";
                }
                result += "\n}";
                cout << result << endl;
                return "";
            }
            else return "Unsupported type";
            result += "]";
            return result;
        };
};

#endif 