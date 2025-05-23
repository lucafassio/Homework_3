#include "../headers/constructor.hpp"

ValueCont<pair<string, string>> Constructor::data = ValueCont<pair<string, string>>();

void Constructor::addLine(string tag, string value){
    data.addElement(make_pair(tag, value));
}

void Constructor::printJSON(){
    data.toString();
}