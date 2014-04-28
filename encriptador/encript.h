#include <cstdio>
#include <cstdlib>
#include <string>
#include<fstream>

#ifndef ENCRIPT_H_INCLUDED
#define ENCRIPT_H_INCLUDED

using namespace std;

class Encriptador
{
    public:
    //Constructor
    Encriptador()
    {
        palabra=new string("");
        ruta=new string("");
    }
    //Metodos Set
    void setKey(string encriptador)
    {
        if(!palabra->empty())
        {
            palabra->clear();
        }
        palabra->insert(0,encriptador);
    }

    void setFile(string nombre)
    {
        if(!ruta->empty())
        {
            ruta->clear();
            archivo->close();
            delete(archivo);
        }
        ruta->insert(0,nombre);
        archivo=new fstream(ruta->c_str(), ios::in|ios::out|ios::trunc|ios::binary);
    }

    //Metodos GET
    string getKey()
    {
        return *palabra;
    }


    string getFile(){
        return *ruta;
    }
    //Metodos de encriptación
    void encriptar();
    void encriptar(string frase);
    //Metodos de desencriptacion
    void desencriptar();
    void desencriptar(string frase);
    //Destructor
    ~Encriptador()
    {

        delete(palabra);
        delete(ruta);
        delete(archivo);

    }

    private:
    string *palabra;
    string *ruta;
    string *destino;
    fstream *archivo;
};



#endif // ENCRIPT_H_INCLUDED
