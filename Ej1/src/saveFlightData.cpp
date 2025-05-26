#include "../headers/saveFlightData.hpp"

SaveFlightData::SaveFlightData(): 
    posicion(), presion() 
{}

SaveFlightData::SaveFlightData(const Posicion& p, const Presion& q): 
    posicion(p), presion(q) 
{}

void SaveFlightData::imprimir() const{
    if (posicion.getTiempo() >= 0){
        cout << "- Position: " << endl;
        posicion.imprimir();
    } else cout << "Waiting a valid position..." << endl;
    if (presion.getTiempo() >= 0){
        cout << "- Preasure: " << endl;
        presion.imprimir();
    } else cout << "Waiting a valid preasure..." << endl;
}

void SaveFlightData::serializar(ostream& out) const{
    posicion.serializar(out);
    presion.serializar(out);
}

void SaveFlightData::deserializar(istream& in){
    posicion.deserializar(in);
    presion.deserializar(in);
}