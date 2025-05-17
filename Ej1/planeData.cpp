#include "planeData.hpp"

//======== Constructores =========//
MedicionBase::MedicionBase(float t):
    tiempoMedicion(new float(t))
{}

Presion::Presion(float p, float q, float t):
    MedicionBase(t), presionEstatica(p), presionDinamica(q)
{}

Presion::Presion(const Presion& p):
    MedicionBase(p.getTiempo()), presionEstatica(p.presionEstatica), presionDinamica(p.presionDinamica)
{}

Posicion::Posicion(float lat, float lon, float alt, float t):
    MedicionBase(t), latitud(lat), longitud(lon), altitud(alt)
{}

Posicion::Posicion(const Posicion& p):
    MedicionBase(p.getTiempo()), latitud(p.latitud), longitud(p.longitud), altitud(p.altitud)
{}

SaveFlightData::SaveFlightData(const Posicion& p, const Presion& q):
    posicion(p), presion(q)
{}

float MedicionBase::getTiempo() const{
    return tiempoMedicion ? *tiempoMedicion.get() : -1;
}

//======== Printers =========//
void Presion::imprimir() const{
    cout << "Static preasure: " << presionEstatica << endl;
    cout << "Dynamic preasure: " << presionDinamica << endl;
    cout << "Time: " << this->getTiempo() << endl;
}

void Posicion::imprimir() const{
    cout << "Latitude: " << latitud << endl;
    cout << "Length: " << longitud << endl;
    cout << "Altitude: " << altitud << endl;
    cout << "Time: " << this->getTiempo() << endl;
}

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

//======== Serializers =========//
void Presion::serializar(ostream& out) const{
    out.write(reinterpret_cast<const char*>(&presionEstatica), sizeof(presionEstatica));
    out.write(reinterpret_cast<const char*>(&presionDinamica), sizeof(presionDinamica));
    float time = this->getTiempo();
    out.write(reinterpret_cast<const char*>(&time), sizeof(tiempoMedicion));
}

void Posicion::serializar(ostream& out) const{
    out.write(reinterpret_cast<const char*>(&latitud), sizeof(latitud));
    out.write(reinterpret_cast<const char*>(&longitud), sizeof(longitud));
    out.write(reinterpret_cast<const char*>(&altitud), sizeof(altitud));
    float time = this->getTiempo();
    out.write(reinterpret_cast<const char*>(&time), sizeof(tiempoMedicion));
}

void SaveFlightData::serializar(ostream& out) const{
    posicion.serializar(out);
    presion.serializar(out);
}

//======== Deserializers =========//
void Presion::deserializar(istream& in){
    in.read(reinterpret_cast<char*>(&presionEstatica), sizeof(presionEstatica));
    in.read(reinterpret_cast<char*>(&presionDinamica), sizeof(presionDinamica));
    float time;
    in.read(reinterpret_cast<char*>(&time), sizeof(tiempoMedicion));
    tiempoMedicion = make_unique<float>(time);
}

void Posicion::deserializar(istream& in){
    in.read(reinterpret_cast<char*>(&latitud), sizeof(latitud));
    in.read(reinterpret_cast<char*>(&longitud), sizeof(longitud));
    in.read(reinterpret_cast<char*>(&altitud), sizeof(altitud));
    float time;
    in.read(reinterpret_cast<char*>(&time), sizeof(tiempoMedicion));
    tiempoMedicion = make_unique<float>(time);
}

void SaveFlightData::deserializar(istream& in){
    posicion.deserializar(in);
    presion.deserializar(in);
}

//======== Destructors =========//
Presion::~Presion(){
    presionEstatica = 0;
    presionDinamica = 0;
}

Posicion::~Posicion(){
    latitud = 0;
    longitud = 0;
    altitud = 0;
}