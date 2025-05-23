#include "../headers/valueCont.hpp"

template<typename dataType>
ValueCont<dataType>::ValueCont(): 
    data(vector<dataType>())
{}

template<typename dataType>
ValueCont<dataType>::ValueCont(initializer_list<dataType> list): 
    data(vector<dataType>(list))
{}

template<typename dataType>
void ValueCont<dataType>::addElement(dataType value) {
    data.push_back(value);
}

template<typename dataType>
int ValueCont<dataType>::getSize() const {
    return static_cast<int>(data.size());
}

template<typename dataType>
string ValueCont<dataType>::toString() const {
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
        result = "[\n\t  ";
        for (unsigned i = 0; i < data.size(); i++){
            result += data[i].toString();
            if (i < data.size() - 1) result += ",\n\t  ";
        }
        result += "\n\t";
    }
    else if constexpr(is_same_v<dataType, pair<string, string>>){
        result = "{\n ";
        for (unsigned i = 0; i < data.size(); i++){
            result += '"' + data[i].first + '"' + ": " + data[i].second;
            if (i < data.size() - 1) result += ",\n  ";
        }
        result += "\n}";
        cout << result;
        return result;
    }
    else return "Unsupported type";
    result += "]";
    return result;
};

template ValueCont<int>::ValueCont();
template ValueCont<double>::ValueCont();
template ValueCont<string>::ValueCont();
template ValueCont<ValueCont<int>>::ValueCont();
template ValueCont<pair<string, string>>::ValueCont();

template ValueCont<int>::ValueCont(initializer_list<int> list);
template ValueCont<double>::ValueCont(initializer_list<double> list);
template ValueCont<string>::ValueCont(initializer_list<string> list);
template ValueCont<ValueCont<int>>::ValueCont(initializer_list<ValueCont<int>> list);
template ValueCont<pair<string, string>>::ValueCont(initializer_list<pair<string, string>> list);

template void ValueCont<int>::addElement(int value);
template void ValueCont<double>::addElement(double value);
template void ValueCont<string>::addElement(string value);
template void ValueCont<ValueCont<int>>::addElement(ValueCont<int> value);
template void ValueCont<pair<string, string>>::addElement(pair<string, string> value);

template int ValueCont<int>::getSize() const;
template int ValueCont<double>::getSize() const;
template int ValueCont<string>::getSize() const;
template int ValueCont<ValueCont<int>>::getSize() const;
template int ValueCont<pair<string, string>>::getSize() const;

template string ValueCont<int>::toString() const;
template string ValueCont<double>::toString() const;
template string ValueCont<string>::toString() const;
template string ValueCont<ValueCont<int>>::toString() const;
template string ValueCont<pair<string, string>>::toString() const;
