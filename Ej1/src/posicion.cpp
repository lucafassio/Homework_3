#include "../headers/posicion.hpp"

Posicion::Posicion(float lat, float lon, float alt, float t): 
    MedicionBase(t), latitud(lat), longitud(lon), altitud(alt) 
{}

Posicion::Posicion(const Posicion& p): 
    MedicionBase(p.getTiempo()), latitud(p.latitud), longitud(p.longitud), altitud(p.altitud) 
{}

void Posicion::reset(){
    latitud = 0;
    longitud = 0;
    altitud = 0;
    MedicionBase::~MedicionBase();
}

void Posicion::imprimir() const{
    cout << "Latitude: " << latitud << endl;
    cout << "Longitude: " << longitud << endl;
    cout << "Altitude: " << altitud << endl;
    cout << "Time: " << this->getTiempo() << endl;
}

void Posicion::serializar(ostream& out) const{
    out.write(reinterpret_cast<const char*>(&latitud), sizeof(latitud));
    out.write(reinterpret_cast<const char*>(&longitud), sizeof(longitud));
    out.write(reinterpret_cast<const char*>(&altitud), sizeof(altitud));
    float time = this->getTiempo();
    out.write(reinterpret_cast<const char*>(&time), sizeof(tiempoMedicion));
}

void Posicion::deserializar(istream& in){
    in.read(reinterpret_cast<char*>(&latitud), sizeof(latitud));
    in.read(reinterpret_cast<char*>(&longitud), sizeof(longitud));
    in.read(reinterpret_cast<char*>(&altitud), sizeof(altitud));
    float time;
    in.read(reinterpret_cast<char*>(&time), sizeof(tiempoMedicion));
    tiempoMedicion = make_unique<float>(time);
}