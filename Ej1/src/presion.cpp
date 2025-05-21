#include "../headers/presion.hpp"

Presion::Presion(float p, float q, float t): 
    MedicionBase(t), presionEstatica(p), presionDinamica(q) 
{}

Presion::Presion(const Presion& p): 
    MedicionBase(p.getTiempo()), presionEstatica(p.presionEstatica), presionDinamica(p.presionDinamica) 
{}

void Presion::reset(){
    presionEstatica = 0;
    presionDinamica = 0;
    MedicionBase::~MedicionBase();
}

void Presion::imprimir() const{
    cout << "Static preasure: " << presionEstatica << endl;
    cout << "Dynamic preasure: " << presionDinamica << endl;
    cout << "Time: " << this->getTiempo() << endl;
}

void Presion::serializar(ostream& out) const{
    out.write(reinterpret_cast<const char*>(&presionEstatica), sizeof(presionEstatica));
    out.write(reinterpret_cast<const char*>(&presionDinamica), sizeof(presionDinamica));
    float time = this->getTiempo();
    out.write(reinterpret_cast<const char*>(&time), sizeof(tiempoMedicion));
}

void Presion::deserializar(istream& in){
    in.read(reinterpret_cast<char*>(&presionEstatica), sizeof(presionEstatica));
    in.read(reinterpret_cast<char*>(&presionDinamica), sizeof(presionDinamica));
    float time;
    in.read(reinterpret_cast<char*>(&time), sizeof(tiempoMedicion));
    tiempoMedicion = make_unique<float>(time);
}