#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <string>
#include<fstream>
#define MAX 255
#define MIN 6

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
        corrimiento=0;
    }
    //Metodos Set
    void setKey(string encriptador)
    {
        if(!palabra->empty())
        {
            palabra->clear();
            corrimiento=0;
        }
        palabra->insert(0,encriptador);

        for(int i = 0 ; i < palabra->size() ; i++ )
            corrimiento+=(int) palabra->at(i);
        corrimiento*=palabra->size();
        corrimiento=(corrimiento%(MAX-MIN)+MIN); //numero entre 4 y 25

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
    void encriptar()
    {
         while(!archivo->eof())
         {

         }
    }

    string encriptar(string frase)
    {
        int codascii=0;
        for(int i=0;i<frase.size();i++)
        {
            if (frase[i]+corrimiento > MAX)
            {
                codascii = MIN + ((frase[i]+corrimiento) - MAX);
            }
            else
            {
                codascii = frase[i]+corrimiento;
            }
            frase[i]=codascii;
        }
        return frase;
    }

    //Metodos de desencriptacion
    void desencriptar();
    string desencriptar(string frase)
    {
        int codascii=0;
        for(int i=0;i<frase.size();i++)
        {
            if (frase[i]>=MIN && frase[i]<=MAX)
            {
                if (frase[i]-corrimiento < MIN && frase[i]-corrimiento >= (MIN-corrimiento))
                {
                    codascii = MAX - (MIN - (frase[i]-corrimiento));
                }
                else
                {
                    codascii = frase[i]-corrimiento;
                }
            }
            else
            {
                codascii = frase[i]-corrimiento;
            }
            frase[i]=codascii;
        }
        return frase;
    }
    //Destructor
    ~Encriptador()
    {
        if(!ruta->empty())
        {
            ruta->clear();
            archivo->close();
            delete(archivo);
        }
        delete(palabra);
        delete(ruta);
        delete(destino);
    }

    private:
    string *palabra;
    string *ruta;
    string *destino;
    fstream *archivo;
    int corrimiento;
};



#endif // ENCRIPT_H_INCLUDED
