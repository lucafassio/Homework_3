#include "headers/constructor.hpp"

void clearScreen();
void clearScreen(){
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}

int main(){
    clearScreen();
    //creo los vectores solicitados
    ValueCont<double> doubles = {1.3, 2.1, 3.2};
    ValueCont<string> strings = {"H̲o̲l̲a̲", "Mundo"};
    ValueCont<ValueCont<int>> vectors;

    //creo las filas de la matriz
    ValueCont<int> row1 = {1, 2};
    ValueCont<int> row2 = {3, 4};

    //agrego las filas a la matriz
    vectors.addElement(row1);
    vectors.addElement(row2);

    Constructor::addLine("vec_doubles", doubles.toString());
    Constructor::addLine("palabras", strings.toString());
    Constructor::addLine("listas", vectors.toString());
    Constructor::printJSON();
    cout << endl;
    return 0;
}