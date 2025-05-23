#ifndef MEDICIONBASE_HPP
#define MEDICIONBASE_HPP

#include "IMediciones.hpp"

class MedicionBase : public IMediciones{
    protected:
        unique_ptr<float> tiempoMedicion;
    
    public:
        MedicionBase();
        MedicionBase(float t);

        float getTiempo() const;
        virtual void reset() = 0;
        virtual void imprimir() const = 0;

        virtual ~MedicionBase() = default;
};

#endif