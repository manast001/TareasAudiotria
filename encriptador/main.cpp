#include <iostream>
#include "encript.h"

using namespace std;

int main()
{
    Encriptador *encript=new Encriptador();
    string s="perro";
    encript->setKey(s);
    cout<<encript->getKey()<<endl;
    s="gato";
    encript->setKey(s);
    cout<<encript->getKey()<<endl;
    delete(encript);
    return 0;
}
