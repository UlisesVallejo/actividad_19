#include "civilizacion.h"
#include <algorithm>


Civilizacion::Civilizacion()
{

}

Civilizacion::Civilizacion(const string &nombre, int x, int y, int puntuacion)
{
    this->nombre = nombre;
    this->x = x;
    this->y = y;
    this->puntuacion = puntuacion;
}

void Civilizacion::setNombre(const string &v)
{
    nombre = v;
}
void Civilizacion::setX(int v)
{
    x = v;
}
void Civilizacion::setY(int v)
{
    y = v;
}
void Civilizacion::setPuntuacion(int v)
{
    puntuacion = v;
}



string Civilizacion::getNombre()
{
    return nombre;
}
int Civilizacion::getX()
{
    return x;
}
int Civilizacion::getY()
{
    return y;
}
int Civilizacion::getPuntuacion()
{
    return puntuacion;
}

void Civilizacion::agregarFinal(const Aldeano &a)
{
    aldeanos.push_back(a);
}

void Civilizacion::agregarInicio(const Aldeano &a)
{
    aldeanos.push_front(a);
}

void Civilizacion::print()
{
    cout << left;
    cout << setw(10) << "Nombre";
    cout << setw(7) << "Edad";
    cout << setw(10) << "Genero";
    cout << setw(5) << "Salud";
    cout << endl;
    for (auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        cout << *it << endl;
    }
}

void Civilizacion::eliminarNombre(const string &nombre)
{
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        Aldeano &a = *it;

        if(nombre == a.getNombre()){
            aldeanos.erase(it);
            break;
        }
        else{
            cout << "No existe" << endl;
        }
    }
}

void Civilizacion::eliminarSalud(size_t salud)
{
    aldeanos.remove_if([salud](const Aldeano &a){return a.getSalud()<salud;});
}

bool comparador(const Aldeano &a)
{
    return a.getEdad() >= 60;
}

void Civilizacion::eliminarEdad()
{
    aldeanos.remove_if(comparador);
}


void Civilizacion::ordenarNombre()
{
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2){return a1.getNombre() < a2.getNombre();});
}

void Civilizacion::ordenarEdad()
{
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2){return a1.getEdad() > a2.getEdad();});
}

void Civilizacion::ordenarSalud()
{
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2){return a1.getSalud() > a2.getSalud();});
}

Aldeano* Civilizacion::buscar(const string &nombre)
{
    bool hola = false;
    Aldeano *ptr;
    //vector<Computadora>::iterator
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        Aldeano &a = *it;

        if(nombre == a.getNombre()){
            hola = true;
            ptr = &(*it);
            break;
        }
    }
    if (hola == false)
    {
        ptr = nullptr;
    }
    return ptr;
}

void Civilizacion::respaldar_aldeanos()
{
    ofstream aldeanos(getNombre() + ".txt", ios::out);
    
    for (auto it = this->aldeanos.begin(); it != this->aldeanos.end(); ++it) {
        Aldeano &aldeano = *it; 
        aldeanos << aldeano.getNombre() << endl;
        aldeanos << aldeano.getEdad()   << endl;
        aldeanos << aldeano.getGenero() << endl;
        aldeanos << aldeano.getSalud()  << endl;
    }
    aldeanos.close();
}

void Civilizacion::recuperar_aldeanos(string civ){
    ifstream archivo (civ);
    if(archivo.is_open()){
        string temp;
        size_t edad;
        size_t salud;
        string aux;
        Aldeano a;
        while(true){
            getline(archivo,temp);//nombre
            if(archivo.eof()){
                break;
            }
            aux = temp;
            a.setNombre(aux);

            getline(archivo,temp);//edad
            edad =stoi(temp);
            a.setEdad(edad);

            getline(archivo,temp);//genero
            aux = temp;
            a.setGenero(aux);

            getline(archivo,temp);//salud
            salud = stoi(temp);
            a.setSalud(salud);

            agregarFinal(a);

        }
    }
    archivo.close();
}