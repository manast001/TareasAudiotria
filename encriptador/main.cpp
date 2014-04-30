#include <iostream>
#include "encript.h"

using namespace std;


int main()
{
    string aux;
    int op;
    Encriptador *encript=new Encriptador();
    cout<<"Ingrese archivo:";
    cin>>aux;
    encript->setFile(aux);
    aux.clear();
    cout<<"Ingrese Llave:";
    cin>>aux;
    encript->setKey(aux);


    do{
        cout<<"Ingrese Opcion:";
        cin>>op;
        switch (op)
        {
            case 1:
                aux.clear();
                cout<<"Ingrese nueva Llave:";
                cin>>aux;
                encript->setKey(aux);
                break;
            case 2:
                encript->encriptar();
                break;
            case 3:
                encript->desencriptar();
                break;
            case 4:
                aux.clear();
                cout<<"Ingrese archivo:";
                cin>>aux;
                encript->setFile(aux);
                break;
            default:
                return 0;
                delete(encript);
                exit(0);
                break;
        }
    }while(true);
}
