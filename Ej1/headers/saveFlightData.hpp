#ifndef SAVEFLIGHTDATA_HPP
#define SAVEFLIGHTDATA_HPP

#include "posicion.hpp"
#include "presion.hpp"

class SaveFlightData{
    public:
        Posicion posicion;
        Presion presion;
        
        SaveFlightData();
        SaveFlightData(const Posicion& p, const Presion& q);

        void imprimir() const;
        void serializar(ostream& out) const;
        void deserializar(istream& in);

        ~SaveFlightData() = default;
};

#endif