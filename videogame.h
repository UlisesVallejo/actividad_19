#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include "civilizacion.h"
#include <vector>
#include <algorithm>
#include <fstream>

class VideoGame
{
    string usuario;
    vector<Civilizacion> civilizaciones;

public:
    VideoGame();
    void setUsuario(const string &v);
    string getUsuario();
    void agregarFinal(const Civilizacion &c);
    void insertar(const Civilizacion &c, size_t pos);
    void inicializar(const Civilizacion &c, size_t n);
    Civilizacion primera();
    Civilizacion ultimo();
    void ordenarNombre();
    void ordenarX();
    void ordenarY();
    void ordenarPuntuacion();
    Civilizacion* eliminar(const Civilizacion &c);
    Civilizacion* buscar(const Civilizacion &c);
    size_t total();

    void mostrar();
    void respaldar();
    void recuperar();
    

    friend VideoGame& operator<<(VideoGame &l, const Civilizacion &c)
    {
        l.agregarFinal(c);

        return l;
    }
};
#endif