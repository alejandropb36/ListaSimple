#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "nodo.h"
#include "nodo.cpp"
using namespace std;

template<class T>
class Lista
{
    public:
        Lista();
        void inicializa();
        bool vacia();
        void insertarinicio(T);
        void insetafinal(T);
        void insetaposicion(T,int);
        Nodo<T> *buscar (T);
        void muestratodo();
        void mostrarelemento(Nodo<T> *);
        void mostrarprimero();
        Nodo<T> *ultimo();
        Nodo<T> *anterior(T);
        Nodo<T> *siguiente(T);
        void borrarelemento(T);
        void modificar(Nodo<T> *,T);
        int tamano();
        void borrartodo();

    private:
        Nodo<T> *head; //Primero
};

#endif // LISTA_H
