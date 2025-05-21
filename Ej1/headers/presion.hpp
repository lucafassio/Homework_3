#ifndef PRESION_HPP
#define PRESION_HPP

#include "medicionBase.hpp"

class Presion : public MedicionBase{
    public:
        float presionEstatica;
        float presionDinamica;

        Presion(float p, float q, float t);
        Presion(const Presion& p);

        void reset() override;
        void imprimir() const override;
        void serializar(ostream& out) const override;
        void deserializar(istream& in) override;
};

#endif