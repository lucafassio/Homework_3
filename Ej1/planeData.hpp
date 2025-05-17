#include <iostream>
#include <fstream>
#include <memory>
using namespace std;

class IMediciones{
    public:
        virtual void serializar(ostream& out) const = 0;
        virtual void deserializar(istream& in) = 0;
        
        virtual ~IMediciones() = default;
};

class MedicionBase : public IMediciones{
    protected:
        unique_ptr<float> tiempoMedicion;
    
    public:
        MedicionBase(float t);

        float getTiempo() const;
        virtual void imprimir() const = 0;
        
        virtual ~MedicionBase() = default;
};

class Presion : public MedicionBase{
    public:
        float presionEstatica;
        float presionDinamica;

        Presion(float p, float q, float t);
        Presion(const Presion& p);

        void imprimir() const override;
        void serializar(ostream& out) const override;
        void deserializar(istream& in) override;
        
        virtual ~Presion();
};

class Posicion : public MedicionBase{
    public:
        float latitud;
        float longitud;
        float altitud;

        Posicion(float lat, float lon, float alt, float t);
        Posicion(const Posicion& p);

        void imprimir() const override;
        void serializar(ostream& out) const override;
        void deserializar(istream& in) override;
        
        virtual ~Posicion();
};

class SaveFlightData{
    public:
        Posicion posicion;
        Presion presion;
        
        SaveFlightData(const Posicion& p, const Presion& q);
        void serializar(ostream& out) const;
        void deserializar(istream& in);
        void imprimir() const;
};