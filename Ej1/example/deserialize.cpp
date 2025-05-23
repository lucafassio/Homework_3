#include "../headers/saveFlightData.hpp"

void clearScreen();
void clearScreen(){
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}

int main(){
    cout << "Creating empty data..." << endl;
    SaveFlightData data;

    data.imprimir();

    cout << endl << "Deserializing data..." << endl;
    ifstream inFile("flight_data.dat", ios::binary);
    if (inFile.is_open()){
        data.deserializar(inFile);
        inFile.close();
        cout << "Data deserialized." << endl;
    }
    else cout << "Error opening file for reading." << endl;

    cout << endl << "Data recovered:" << endl;
    data.imprimir();

    //no se si hay que borrar el archivo, tendria sentido que no, pero tampoco es como que lo este
    //usando para algo. Me era mas comodo que se borre solo asi no tengo que estar borrandolo a mano :)
    cout << endl << "Deleting file.dat..." << endl;
    remove("flight_data.dat");
    return 0;
}