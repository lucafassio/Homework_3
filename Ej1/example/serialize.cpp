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
    clearScreen();
    Posicion posicion(-34.6f, -58.4f, 950.0f, 5.3f);
    Presion presion(101.3f, 5.8f, 6.1f);

    SaveFlightData data(posicion, presion);
    cout << "Data created." << endl << endl;
    data.imprimir();

    cout << endl << "Serializing data..." << endl;
    ofstream outFile("flight_data.dat", ios::binary);
    if (outFile.is_open()){
        data.serializar(outFile);
        outFile.close();
        cout << "Data serialized." << endl;
    }
    else cout << "Error opening file for writing." << endl;
    cout << "Ending program..." << endl;
}