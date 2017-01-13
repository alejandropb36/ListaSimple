#include "nodo.h"
template <typename T>
Nodo<T>::Nodo(T objeto)
{
    this->objeto=objeto;
    sig=NULL;
    //ctor
}

template<typename T>
T Nodo<T>::getObjeto()
{
    return objeto;
}
