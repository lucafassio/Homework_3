#include "planeData.hpp"

int main(){
    Posicion posicion(-34.6f, -58.4f, 950.0f, 5.3f);
    Presion presion(101.3f, 5.8f, 6.1f);

    SaveFlightData data(posicion, presion);
    cout << "Data created." << endl << endl;
    data.imprimir();

    cout << endl << "Serializing data..." << endl;
    ofstream outFile("flight_data.dat", ios::binary);
    if (outFile.is_open()){
        data.posicion.serializar(outFile);
        data.presion.serializar(outFile);
        outFile.close();
        cout << "Data serialized." << endl;
    }
    else cout << "Error opening file for writing." << endl;

    cout << endl << "Destroying data..." << endl;
    data.posicion.~Posicion();
    data.presion.~Presion();
    cout << "Data destroyed." << endl << endl;

    data.imprimir();

    cout << endl << "Deserializing data..." << endl;
    ifstream inFile("flight_data.dat", ios::binary);
    if (inFile.is_open()){
        data.posicion.deserializar(inFile);
        data.presion.deserializar(inFile);
        inFile.close();
        cout << "Data deserialized." << endl;
    }
    else cout << "Error opening file for reading." << endl;

    cout << endl << "Data recovered:" << endl;
    data.imprimir();

    //no se si hay que borrar el archivo, tendria sentido que no, pero tampoco es como que lo este
    //usando para nada. Me era mas comodo que se borre solo asi no tengo que estar borrandolo a mano :)
    cout << endl << "Deleting file.dat..." << endl;
    remove("flight_data.dat");
    return 0;
}