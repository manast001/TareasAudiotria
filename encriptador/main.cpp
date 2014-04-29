#include <iostream>
#include "encript.h"

using namespace std;

int main()
{
    Encriptador *encript=new Encriptador();
    string s="perro",s1;
    encript->setKey(s);
    s1=encript->encriptar(encript->encriptar(encript->encriptar("AbeJa")));
    cout<<encript->desencriptar(encript->desencriptar(encript->desencriptar(s1)))<<endl;

    delete(encript);
    return 0;
}
