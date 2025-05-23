#ifndef POSICION_HPP
#define POSICION_HPP

#include "medicionBase.hpp"

class Posicion : public MedicionBase{
    public:
        float latitud;
        float longitud;
        float altitud;

        Posicion();
        Posicion(float lat, float lon, float alt, float t);
        Posicion(const Posicion& p);

        void reset() override;
        void imprimir() const override;
        void serializar(ostream& out) const override;
        void deserializar(istream& in) override;
};

#endif