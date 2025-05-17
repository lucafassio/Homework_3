#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <type_traits>
#include <utility>
using namespace std;

template<typename dataType>
class Vector{
    private:
        dataType* data;
        int size;
        int capacity;

    public:
        Vector(): 
            size(0), capacity(1)
        {data = new dataType[capacity];}

        Vector(initializer_list<dataType> list): 
            size(0), capacity(list.size())
        {data = new dataType[capacity]; for (const auto& value : list) data[size++] = value;}

        void push_back(dataType value){
            if (size == capacity){
                capacity *= 2;
                dataType* newData = new dataType[capacity];
                for (int i = 0; i < size; i++){
                    newData[i] = data[i];
                }
                delete[] data;
                data = newData;
            }   
            data[size++] = value;
        };

        dataType& operator[](int index) {return data[index];}
        int getSize() const {return size;}

        string toString() const {
            string result = "[";
            if constexpr(is_arithmetic_v<dataType>){
                for (int i = 0; i < size; i++){
                    result += to_string(data[i]).substr(0, to_string(data[i]).find(".")+2);
                    if (i < size - 1) result += ", ";
                }
            }
            else if constexpr(is_same_v<dataType, string>){
                for (int i = 0; i < size; i++){
                    result += data[i];
                    if (i < size - 1) result += ", ";
                }
            }
            else if constexpr(is_same_v<dataType, Vector<int>>){
                for (int i = 0; i < size; i++){
                    result += data[i].toString();
                    if (i < size - 1) result += ",\n\t     ";
                }
            }
            else if constexpr(is_same_v<dataType, Vector<float>>){
                result += "\n";
                for (int i = 0; i < size; i++){
                    result += data[i].toString();
                    if (i < size - 1) result += ",\n";
                }
                result += "\n";
            }
            else if constexpr(is_same_v<dataType, pair<string, string>>){
                result = "{ ";
                for (int i = 0; i < size; i++){
                    result += '"' + data[i].first + '"' + ": " + data[i].second;
                    if (i < size - 1) result += ",\n  ";
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