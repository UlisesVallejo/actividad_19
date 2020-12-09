#ifndef CIVILIZACION_H
#define CIVILIZACION_H
#include "aldeano.h"
#include <list>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Civilizacion
{
    string nombre;
    int x;
    int y;
    int puntuacion;

    list<Aldeano> aldeanos;

public:
     Civilizacion();
     Civilizacion(const string &nombre, int x, int y, int puntuacion);

     void setNombre(const string &v);
     void setX(int v);
     void setY(int v);
     void setPuntuacion(int v);

    string getNombre();
    int getX();
    int getY();
    int getPuntuacion();

    void agregarFinal(const Aldeano &a);
    void agregarInicio(const Aldeano &a);
    void print();

    void eliminarNombre(const string &nombre);
    void eliminarSalud(size_t salud);
    void eliminarEdad();

    void ordenarNombre();
    void ordenarEdad();
    void ordenarSalud();

    Aldeano* buscar(const string &a);
    //Aldeano* buscar(const Aldeano &a);

    void respaldar_aldeanos();
    void recuperar_aldeanos(string civ);


    friend ostream& operator<<(ostream &out, const Civilizacion &c)
    {
        out << left;
        out << setw(10) << c.nombre;
        out << setw(12) << c.x;
        out << setw(12) << c.y;
        out << setw(12) << c.puntuacion;
        out << endl;

        return out;
    }

    friend istream& operator>>(istream &in, Civilizacion &c)
    {
        cout << "Nombre: ";
        getline(cin, c.nombre);

        cout << "Ubicacion en x: ";
        cin >> c.x;

        cout << "Ubicacion en y: ";
        cin >> c.y;

        cout << "Puntuacion: ";
        cin >> c.puntuacion;

        return in;
    }

    bool operator==(const Civilizacion& c)
    {
        return nombre == c.nombre;
    }
    bool operator==(const Civilizacion& c) const
    {
        return nombre == c.nombre;
    }

    bool operator<(const Civilizacion& c)
    {
        return nombre < c.nombre;
    }
    bool operator<(const Civilizacion& c) const
    {
        return nombre < c.nombre;
    }
};
#endif