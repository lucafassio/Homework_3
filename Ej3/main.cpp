#include "vector.hpp"
#include "constructor.hpp"

int main(){
    //creo los vectores solicitados
    Vector<double> doubles = {1.3, 2.1, 3.2};
    Vector<string> strings = {"H̲o̲l̲a̲", "Mundo"};
    Vector<Vector<int>> vectors;

    //creo las filas de la matriz
    Vector<int> row1 = {1, 2};
    Vector<int> row2 = {3, 4};

    //agrego las filas a la matriz
    vectors.push_back(row1);
    vectors.push_back(row2);

    Constructor::addLine("vec_doubles", doubles.toString());
    Constructor::addLine("palabras", strings.toString());
    Constructor::addLine("listas", vectors.toString());
    Constructor::printJSON();
}