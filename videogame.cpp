#include "videogame.h"


VideoGame::VideoGame()
{

}

//Nombre de usuario
void VideoGame::setUsuario(const string &u)
{
    usuario = u;
}

string VideoGame::getUsuario()
{
    return usuario;
}

//Agregar
void VideoGame::agregarFinal(const Civilizacion &c)
{
    civilizaciones.push_back(c);
}

//Resumen
void VideoGame::mostrar()
{
    cout << left;
    cout << setw(10) << "Nombre";
    cout << setw(12) << "Ubicacion X";
    cout << setw(12) << "Ubicacion Y";
    cout << setw(12) << "Puntuacion";
    cout << endl;

    for(size_t i = 0; i < civilizaciones.size(); i++)
    {
        Civilizacion &c = civilizaciones[i];
        cout << c;
        /*cout<<"Marca: "<<c.getMarca()<<endl;
        cout<<"Sistema operativo: "<<c.getSisop()<<endl;
        cout<<"Peso: "<<c.getPeso()<<endl;
        cout<<"Ram: "<<c.getRam()<<endl;
        cout<<endl;*/
    }
}



// Por cada civilización en el vector
// se guarda el nombre de la civilización 
// en el archivo "civilizaciones.txt"
// y se manda a llamar el método respaldar_aldeano()
void VideoGame::respaldar()
{
    ofstream archivo("civilizaciones.txt", ios::out);

    for (int i = 0; i < civilizaciones.size(); ++i) {
        Civilizacion &c = civilizaciones[i];
        archivo << c.getNombre() << endl;
        c.respaldar_aldeanos();
        archivo << c.getX() << endl;
        archivo << c.getY() << endl;
        archivo << c.getPuntuacion() << endl;
    }
    archivo.close();
}



void VideoGame::recuperar(){
    ifstream archivo("civilizaciones.txt");
    if(archivo.is_open()){
        string temp;
        string aux;
        int ubicacionX;
        int ubicacionY;
        int puntuacion;
        
        while(true){
            
            Civilizacion c;

            getline(archivo,temp);//nombre
            if(archivo.eof()){ break;}
            c.setNombre(temp);
            aux = temp + ".txt";
            c.recuperar_aldeanos(aux);

            getline(archivo,temp);//ubicacionX
            ubicacionX = stoi(temp);
            c.setX(ubicacionX);

            getline(archivo,temp);//ubicacionY
            ubicacionY = stoi(temp);
            c.setY(ubicacionY);

            getline(archivo,temp);//puntuacion
            puntuacion = stoi(temp);
            c.setPuntuacion(puntuacion);

            agregarFinal(c);
            aux = "";
        }

    }
    archivo.close();

}

//insertar
void VideoGame::insertar(const Civilizacion &c, size_t pos)
{
    civilizaciones.insert(civilizaciones.begin()+pos, c);
}

//total
size_t VideoGame::total()
{
    return civilizaciones.size();
}

//crear civilizaciones
void VideoGame::inicializar(const Civilizacion &c, size_t n)
{
    civilizaciones = vector<Civilizacion>(n, c);
}

//primera
Civilizacion VideoGame::primera()
{
    return civilizaciones.front();
}

//ultimo
Civilizacion VideoGame::ultimo()
{
    return civilizaciones.back();
}

//ordenar nombre
void VideoGame::ordenarNombre()
{
    sort(civilizaciones.begin(), civilizaciones.end(),
    [](Civilizacion c1, Civilizacion c2){return c1.getNombre() < c2.getNombre();});
}

//ordenar ubicacion x
void VideoGame::ordenarX()
{
    sort(civilizaciones.begin(), civilizaciones.end(),
    [](Civilizacion c1, Civilizacion c2){return c1.getX() < c2.getX();});
}

//ordenar ubicacion y
void VideoGame::ordenarY()
{
    sort(civilizaciones.begin(), civilizaciones.end(),
    [](Civilizacion c1, Civilizacion c2){return c1.getY() < c2.getY();});
}

//ordenar puntuacion
void VideoGame::ordenarPuntuacion()
{
    sort(civilizaciones.begin(), civilizaciones.end(),
    [](Civilizacion c1, Civilizacion c2){return c1.getPuntuacion() > c2.getPuntuacion();});
}

//eliminar
Civilizacion* VideoGame::eliminar(const Civilizacion &c)
{
    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);

    if(it == civilizaciones.end()){
        return nullptr;
    }
    else{
        civilizaciones.erase(it);
        return 0;
    }
}

//buscar
Civilizacion* VideoGame::buscar(const Civilizacion &c)
{
    //vector<Computadora>::iterator
    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);

    if(it == civilizaciones.end()){
        return nullptr;
    }
    else{
        return &(*it);
    }
}
