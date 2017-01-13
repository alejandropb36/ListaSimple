#include "lista.h"

//Contructor por defecto
template<typename T>
Lista<T>::Lista()
{
    head=NULL;
    //ctor
}

//Inicializa hace lo mismo que el constructor (nos puede servir para borrar)
template<typename T>
void Lista<T>::inicializa()
{
    head=NULL;
}

//Comprueba que este vacia y retorna true o false
template<typename T>
bool Lista<T>::vacia()
{
    return (head==NULL);
}

//Inserta en head (primero)
template<typename T>
void Lista<T>::insertarinicio(T objeto)
{
    Nodo<T> *tmp=new Nodo<T>(objeto);
    if (vacia())
    {
        head=tmp;
    }
    else
    {
        tmp->sig=head;
        head=tmp;
    }

}

//Inserta en ultimo
template<typename T>
void Lista<T>::insetafinal(T objeto)
{
    Nodo<T> *aux;
    Nodo<T> *tmp=new Nodo<T>(objeto);
    if (vacia())
    {
        head=tmp;
    }
    else
    {
        aux=ultimo();
        aux->sig=tmp;
    }
}

//Inserta elemnto en la posicion deseada
template<typename T>
void Lista<T>::insetaposicion(T objeto,int i)
{
    int pos = 0;
    Nodo<T> *ant=NULL;
    Nodo<T> *aux;
    Nodo<T> *tmp=new Nodo<T>(objeto);
    if (!vacia())
    {
        for(aux= head; aux; aux=aux->sig)
        {
            if(pos==i)
            {
                if(aux==head)
                {
                    insertarinicio(objeto);
                }
                else if (aux->sig==NULL)
                {
                    insetafinal(objeto);
                }
                else
                {
                    ant->sig=tmp;
                    tmp->sig=aux;
                }
            }
            ant=aux;
            pos++;
        }
        if (!aux)
            cout << "La posicion No existe!"<< endl;
    }
    else
        cout << "Error...Lista Vacia" << endl;
}//*/

//Busca un soldado por su nombre y muestra la posicion
template<typename T>
Nodo<T> *Lista<T>::buscar(T objeto)
{
    Nodo<T> *aux;
    if (vacia())
        cout << "Error...Lista Vacia" << endl;
    else{
        for (aux=head; aux  ; aux=aux->sig)
        {
            if (aux->getObjeto().GetName()==objeto.GetName())
                return aux;
        }
        if(!aux)
            return aux;
    }
}

//Imprime todo los elementos aunque esto pudo llamarse imprimelista (mas formal)
template<typename T>
void Lista<T>::muestratodo()
{
    if (vacia())
    {
        cout << "Error...Lista Vacia" << endl;
    }
    else
    {
        Nodo<T> *aux;
        for( aux=head; aux; aux=aux->sig)
            cout<<aux->getObjeto().tostring()<<endl;
    }
}

//Muestra (o recupera) un elemento por la pocicion
template<typename T>
void Lista<T>::mostrarelemento(Nodo<T> *direccion)
{
    if(!vacia()){
        if(direccion!=NULL)
            cout<<direccion->getObjeto().tostring()<<endl;
        else
            cout << "El elemento No existe!"<< endl;
    }
    else
        cout << "Error...Lista Vacia" << endl;
}//*/

//Muestra el primer elemento
template<typename T>
void Lista<T>::mostrarprimero()
{
    if(!vacia())
        mostrarelemento(head);
    else
        cout << "Error...Lista Vacia" << endl;

}

//Muestra el ultimo elemento
template<typename T>
Nodo<T> *Lista<T>::ultimo()
{
    Nodo<T> *aux;
    if(!vacia()){
        for(aux=head; aux->sig!=NULL; aux=aux->sig){}
        return aux;
    }
    else
       cout << "Error...Lista Vacia" << endl;
}

//Muestra el elemento anterior
template<typename T>
Nodo<T> *Lista<T>::anterior(T objeto)
{
    if(!vacia()){
        Nodo<T> *aux;
        for(aux=head; aux; aux=aux->sig){
            if(buscar(objeto)){
                if(aux->sig==buscar(objeto))
                    return aux;
            }

        }
        if(!aux)
            return aux;
    }
    else
        cout << "Error...Lista Vacia" << endl;
}

//Muestra el siguiente elemento
template<typename T>
Nodo<T> *Lista<T>::siguiente(T objeto)
{
    if(!vacia()){
        Nodo<T> *aux;
        for(aux=head; aux; aux=aux->sig){
            if(buscar(objeto)){
                if(buscar(objeto)->sig==aux)
                    return aux;
            }
        }
        if(!aux)
            return aux;
    }
    else
        cout << "Error...Lista Vacia" << endl;
}

//Borra el elemento deacuerdo a su nombre  (Hice lo mismo pero con while en la v2) this is v4
template<typename T>
void Lista<T>::borrarelemento(T objeto)
{
    Nodo<T> *aux=buscar(objeto);
    Nodo<T> *ant=anterior(objeto);
    if (!vacia())
    {
        if(aux){
           if(aux==head){
                head=head->sig;
                delete aux;
            }
            else if(aux->sig==NULL){
                ant->sig=NULL;
                delete aux;
            }
            else{
                ant->sig=aux->sig;
                delete aux;
            }
        }
        else
            cout << "El elemento No existe!"<< endl;

    }
    else
        cout << "Error...Lista Vacia" << endl;
}//*/

//Devuelve el numero de elementos que hay en la lista
template<typename T>
int Lista<T>::tamano()
{
    Nodo<T> *aux;
    int tam=1;
    if(vacia())
    {
        cout << "Error...Lista Vacia" << endl;
    }
    else
    {
        for(aux=head; aux->sig!=NULL; aux=aux->sig)
        {
            tam++;
        }
        return tam;
    }
}

//Modifica el elemento deseado
template<typename T>
void Lista<T>::modificar(Nodo<T> *direccion,T objeto)
{
    Nodo<T> *tmp=new Nodo<T>(objeto);
    if(!vacia()){
            if(direccion){
                if(direccion==head){
                    tmp->sig=direccion->sig;
                    head=tmp;
                    delete direccion;
                }
                else if(direccion->sig==NULL){
                    anterior(direccion->getObjeto())->sig=tmp;
                    delete direccion;
                }
                else{
                    anterior(direccion->getObjeto())->sig=tmp;
                    tmp->sig=direccion->sig;
                    delete direccion;
                }
            }
            else
                cout << "El elemento No existe!" << endl;
        }
}

//Borra todos los elementos de la lista y sus nodos
template<typename T>
void Lista<T>::borrartodo()
{
    Nodo<T> *aux=NULL;
    //Nodo<T> *ant=NULL;
    if(!vacia())
    {
        /*while(head){
            aux=head;
            head=head->sig;
            delete aux;
        }//*/
        //Primera vez que le veo uso especifico al while pero me gusta mas el for XD #teamFor
        for(head=head; head; /*head=head->sig*/){
            aux=head;
            head=head->sig;
            delete aux;//
        }//*/

    }
    else
        cout << "Error...Lista Vacia" << endl;
}

//Borrar con while v2
/*void Lista::borrarelemento(Soldado s)
{
    Nodo *ant=NULL;
    Nodo *aux=head;
    if(!vacia()){
        while(aux){
            if (aux->GetSoldado().GetName() == s.GetName())
                break;
            ant=aux;
            aux=aux->sig;
        }
        if(aux==head){
            head=head->sig;
            delete aux;
        }
        else if(aux==ultimo){
            ultimo=ant;
            ultimo->sig=NULL;
            delete aux;
        }
        else if(aux==NULL){
            cout << "El Soldado No existe!"<< endl;
        }
        else{
            ant->sig=aux->sig;
            delete aux;
        }
    }
    else cout << "Error...Lista Vacia" << endl;
}//*/
