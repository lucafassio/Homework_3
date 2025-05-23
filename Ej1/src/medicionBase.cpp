#include "../headers/medicionBase.hpp"

MedicionBase::MedicionBase(): 
    tiempoMedicion(nullptr) 
{}

MedicionBase::MedicionBase(float t): 
    tiempoMedicion(make_unique<float>(t)) 
{}

float MedicionBase::getTiempo() const{
    return tiempoMedicion ? *tiempoMedicion.get() : -1;
}