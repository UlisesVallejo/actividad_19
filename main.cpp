#include <iostream>
#include "videogame.h"
#include "menu.h"

using namespace std;

int main(){

    VideoGame vg;
    string opc;

    while (true)
    {
        cout << "1.- Nombre de usuario" << endl;
        cout << "2.- Agregar civilizacion" << endl;
        cout << "3.- Insertar civilizacion" << endl;
        cout << "4.- Crear civilizaciones" << endl;
        cout << "5.- Primera civilizacion" << endl;
        cout << "6.- Ultima civilizacion" << endl;
        cout << "7.- Ordenar" << endl;
        cout << "8.- Eliminar civilizacion" << endl;
        cout << "9.- Buscar" << endl;
        cout << "10.- Modificar" << endl;
        cout << "11.- Resumen" << endl;
        cout << "12.- Respaldar" << endl;
        cout << "13.- Recuperar" << endl;
        cout << "14.- Salir" << endl;
        cout << "Ingresa una opcion " << vg.getUsuario() << ": ";
        getline(cin, opc);

        if(opc == "1")
        {
            string aux;
            cout << "Nombre de usuario: ";
            cin >> aux;
            vg.setUsuario(aux); cin.ignore();
        }
        else if(opc == "2")
        {
            Civilizacion c;

            cin >> c;

            vg.agregarFinal(c);
            cin.ignore();
        }
        else if(opc == "3")
        {
            Civilizacion c;
            cin >> c;

            size_t pos;
            cout << "posicion: ";
            cin >> pos; cin.ignore();
            if(pos >= vg.total()){
                cout << "Posicion no valida" << endl;
            }
            else{
                vg.insertar(c, pos);
            }
        }
        else if(opc == "4")
        {
            Civilizacion c;
            cin >> c;

            size_t n;
            cout << "n: "; 
            cin >> n; cin.ignore();

            vg.inicializar(c, n);
        }
        else if(opc == "5")
        {
            if(vg.total()>0){
                cout << vg.primera();
            }
            else{
                cout << "El vector esta vacio" << endl;
            }
        }
        else if(opc == "6")
        {
            if(vg.total()>0){
                cout << vg.ultimo();
            }
            else{
                cout << "El vector esta vacio" << endl;
            }
        }
        else if(opc == "7")
        {
            string opc2;
            cout << "1.-Ordenar Nombre" <<endl;
            cout << "2.-Ordenar Ubicacion X" <<endl;
            cout << "3.-Ordenar Ubicacion Y" <<endl;
            cout << "4.-Ordenar Puntuacion" <<endl;
            cout << "Elige una opcion: ";
            getline(cin, opc2);
            if(opc2=="1")
            {
                vg.ordenarNombre();
            }
            else if(opc2=="2")
            {
                vg.ordenarX();
            }
            else if(opc2=="3")
            {
                vg.ordenarY();
            }
            else if(opc2=="4")
            {
                vg.ordenarPuntuacion();
            }
        }
        else if(opc == "8")
        {
            string aux;
            cout << "Ingresa el nombre a eliminar: ";
            cin >> aux; cin.ignore();
            Civilizacion c;
            c.setNombre(aux);

            Civilizacion *ptr = vg.buscar(c);

            if(ptr == nullptr){
                cout << "No hay coincidencias" << endl;
            }
            else{
                vg.eliminar(*ptr);
            }
        }
        else if(opc == "9")
        {
            string aux;
            cout << "Ingresa el nombre a buscar: ";
            cin >> aux; cin.ignore();
            Civilizacion c;
            c.setNombre(aux);

            Civilizacion *ptr = vg.buscar(c);

            if(ptr == nullptr){
                cout << "No hay coincidencias" << endl;
            }
            else{
                cout << *ptr << endl;
                menu(*ptr);
            }
        }
        else if(opc == "10")
        {
            string opc3, aux;
            int aux1, aux2, aux3;
            string aux4;
            cout << "Ingresa el nombre a buscar: ";
            cin >> aux4; cin.ignore();
            Civilizacion c;
            c.setNombre(aux4);

            Civilizacion *ptr = vg.buscar(c);

            if(ptr == nullptr){
                cout << "No hay coincidencias" << endl;
            }
            else{
                cout << *ptr << endl;
                cout << "1.- Modificar Nombre" << endl;
                cout << "2.- Modificar Ubicacion X" << endl;
                cout << "3.- Modificar Ubicacion Y" << endl;
                cout << "4.- Modificar Puntuacion" << endl;
                cout << "Elige una opcion: ";
                getline(cin, opc3);
                if(opc3 == "1")
                {
                    cout << "Dame el nuevo nombre: ";
                    cin >> aux;
                    ptr->setNombre(aux); cin.ignore();
                }
                if(opc3 == "2")
                {
                    cout << "Dame la nueva ubicacion X: ";
                    cin >> aux1;
                    ptr->setX(aux1); cin.ignore();
                }
                if(opc3 == "3")
                {
                    cout << "Dame la nueva ubicacion Y: ";
                    cin >> aux2;
                    ptr->setY(aux2); cin.ignore();
                }
                if(opc3 == "4")
                {
                    cout << "Dame la nueva puntuacion: ";
                    cin >> aux3;
                    ptr->setPuntuacion(aux3); cin.ignore();
                }
            }
        }
        else if(opc == "11")
        {
            vg.mostrar();
        }

        else if(opc == "12")
        {
            vg.respaldar();
        }
        else if(opc == "13")
        {
            vg.recuperar();
        }
        else if(opc == "14")
        {
            break;
        }
    }

    return 0;
}