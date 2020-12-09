#include "civilizacion.h"

void menu(Civilizacion &c)
{
    string op;

    while (true)
    {
        cout << "1) Agregar aldeano" << endl;
        cout << "2) Eliminar aldeano" << endl;
        cout << "3) Clasificar aldeano" << endl;
        cout << "4) Buscar aldeano" << endl;
        cout << "5) Modificar aldeano" << endl;
        cout << "6) Mostrar aldeano" << endl;
        cout << "0) Salir" << endl;
        cout << "Ingresa una opcion: ";
        getline(cin, op);

        if(op == "1")
        {
            string op2;
            cout << "1.- Agregar al inicio" << endl;
            cout << "2.- Agregar al final" << endl;
            cout << "Elige una opcion: ";
            getline(cin, op2);

            if(op2 == "1")
            {
                Aldeano a;
                cin >> a;
                c.agregarInicio(a);
                c.setPuntuacion(c.getPuntuacion()+100);
            }
            if(op2 == "2")
            {
                Aldeano a;
                cin >> a;
                c.agregarFinal(a);
                c.setPuntuacion(c.getPuntuacion()+100);
            }
        }
        else if(op == "2")
        {
            string op4;
            cout << "1.- Eliminar por nombre" << endl;
            cout << "2.- Eliminar los que su salud sea menor a x" << endl;
            cout << "3.- Eliminar los que su edad sea menor o igual a 60" << endl;
            cout << "Elige una opcion: ";
            getline(cin, op4);

            if(op4 == "1")
            {
                string nombre;
                cout << "Dame el nombre a eliminar: ";
                getline(cin, nombre);
                c.eliminarNombre(nombre);
            }
            if(op4 == "2")
            {
                size_t salud;
                cout << "Salud: ";
                cin >> salud; cin.ignore();
                c.eliminarSalud(salud);
            }
            if(op4 == "3")
            {
                c.eliminarEdad();
            }
        }
        else if(op == "3")
        {
            string op3;
            cout << "1.- Clasificar por nombre (ascendente)" << endl;
            cout << "2.- Clasificar por edad (descendente)" << endl;
            cout << "3.- Clasificar por salud (descendente)" << endl;
            cout << "Elige una opcion: ";
            getline(cin, op3);

            if(op3 == "1")
            {
                c.ordenarNombre();
            }
            if(op3 == "2")
            {
                c.ordenarEdad();
            }
            if(op3 == "3")
            {
                c.ordenarSalud();
            }
        }
        else if(op == "4")
        {
            string aux;
            cout << "Ingresa el nombre a buscar: ";
            cin >> aux; cin.ignore();
            Aldeano a;
            a.setNombre(aux);

            Aldeano *ptr = c.buscar(aux);

            if(ptr == nullptr){
                cout << "No hay coincidencias" << endl;
            }
            else{
                cout << *ptr << endl;
            }
        }
        else if(op == "5")
        {
            string opcion, nombre, aux2, auxi;
            size_t aux3, aux4;
            cout << "Ingresa el nombre a buscar: ";
            cin >> auxi; cin.ignore();
            Aldeano a;
            a.setNombre(auxi);

            Aldeano *ptr = c.buscar(auxi);

            if(ptr == nullptr){
                cout << "No hay coincidencias" << endl;
            }
            else{
                cout << *ptr << endl;
                cout << "1.- Modificar Nombre" << endl;
                cout << "2.- Modificar Edad" << endl;
                cout << "3.- Modificar Genero" << endl;
                cout << "4.- Modificar Salud" << endl;
                cout << "Elige una opcion: ";
                getline(cin, opcion);
                if(opcion == "1")
                {
                    cout << "Dame el nuevo nombre: ";
                    cin >> nombre; cin.ignore();
                    ptr->setNombre(nombre); 
                }
                if(opcion == "2")
                {
                    cout << "Dame la nueva edad: ";
                    cin >> aux3; cin.ignore();
                    ptr->setEdad(aux3);
                }
                if(opcion == "3")
                {
                    cout << "Dame el nuevo genero: ";
                    cin >> aux2; cin.ignore();
                    ptr->setGenero(aux2);
                }
                if(opcion == "4")
                {
                    cout << "Dame la nueva salud: ";
                    cin >> aux4; cin.ignore();
                    ptr->setSalud(aux4);
                }
            }
        }
        else if(op == "6")
        {
            c.print();
        }
        else if(op == "0")
        {
            break;
        }
    }
    
}