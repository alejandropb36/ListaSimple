#ifndef NODO_H
#define NODO_H
#include <iostream>
using namespace std;
template<class T>
class Nodo
{
    public:
        Nodo(T);
        Nodo *sig;
        T getObjeto();

    private:
        T objeto;
};

#endif // NODO_H
