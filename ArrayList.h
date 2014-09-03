//#ifndef ARRAYLIST_H
//#define ARRAYLIST_H
#define DEFAULT_MAX_SIZE 1024
#include <stdexcept>

using namespace std;

template <typename E>

class ArrayList
{
private:

    E* elements;/* Puntero a un arreglo de elemtos:
        * Contiene los elemtos de una lista. Al crearlo
        * din�micamente debe conocerse el tama�o del arreglo*/
    int max; // tama�o maximo del arreglo. fijo
    int size; // cantidad de elementnos almacenados. variable
    int pos; // posici�n actual. Para insertar,eliminar y ver elementos

public:
    //Constructor
    ArrayList(int pMax = DEFAULT_MAX_SIZE)
    {
        /* Recibe como par�metro el tama�o m�ximo de la lista.
         * Si no se especifica se utiliza la constante
         * Inicializa el tama�o y la posici�n actual en cero.
         * Crea en memoria din�mica el arreglo de elementos con
         * el tama�o m�ximo.*/
        elements = new E[pMax];
        max = pMax;
        size = 0;
        pos = 0;
    }
    //Destructor
    virtual ~ArrayList()
    {
        //Elimina de menoria din�mica el arreglo creado
        delete [] elements;
    }

    /*-Los elementos se almacenan en posiciones contiguas
    * -Para insertar en medio de elementos deben moverse
    * los elementos para crear un espacio
    * -Al insertar en la posici�n i, deben moverse n-i
    * elementos*/

    void insert(E pElen)
    {
        /*-Los elementos se almacenan en posiciones contiguas
        * -Para insertar en medio de elementos deben moverse
        * los elementos para crear un espacio
        * -Al insertar en la posici�n i, deben moverse n-i
        * elementos*/

        if (size == max) // si lista llena, no puede agregar mas
            throw runtime_error("List full");

        for(int i = size; i > pos; i--)
            elements[i] = elements[i -1];
            /*A partir del �ltimo elemento
            se mueven un espacio hasta la
            posici�n actual */

        elements[pos] =  pElen;/* Se asigna el nuevo elemento
                                    en la posici�n atual*/
        size++; // Aumentamos el # de elemento que tiene la lista
    }

    void append(E pElement) throw(runtime_error)
    {
        //Agregar elemento al final de la lista
        if(size == max) // si lista llena, no puede agregar mas
            throw runtime_error("List full");
        elements[size] = pElement;// Se agrega al final de la lista
        size++; // Aumentamos el # de elemento que tiene la lista
    }

    E remove() throw(runtime_error)
    {
        /*Elimina el elemento actual y retorna su valor
           como resultado*/
        if(size == 0) // si lista vacia, no puede borrar
            throw runtime_error("Empty list");
        if((pos<0) || (pos >= size))
            throw runtime_error("Index out of bounds");

        E res = elements[pos]; // se guarda valor a retornar/eliminar
        for (int i = pos; i < size - 1; i++)
            elements[i] = elements[i + 1];/*A partir de la
                pos atual se mueven los elemntos un espacio
                hasta la ultima pos.*/

        size--;
        return res;
    }

    void clear()
    {
        //Inicializa la lista y la deja sin elementos
        size = 0; // tama�o y posicion
        pos = 0; //     actual en 0
        delete [] elements; /*Elimina de memoria dinamica
            al arreglo de elemntos. Al eliminar el arreglo, se
            ejecuta el destructor de cada uno de los elementos*/
        elements = new E[max];// Nuevo de arreglo de elemntos
                                //con tama�o maximo
    }

    E getElement() throw(runtime_error)
    {
        //Retorna el elemento ubicado en la posici�n actual
        if((pos < 0) || (pos >= size))
            throw runtime_error ("Index out of bounds");

        return elements[pos];
    }
    void goToStart()
    {
        //Inicio de la lista, posici�n cero
        pos = 0;
    }
    void goToEnd()
    {
        //Final de la lista
       pos = size;
    }

    void goToPos(int nPos) throw(runtime_error)
    {
        if ((nPos < 0) || (nPos > size)) //!si posici�n indicada es v�lida
            throw runtime_error("Index out of bounds");
        pos = nPos; //a
    }
    void previous()
    {
        //ir a pos anterior
        if (pos > 0)
            pos--;
    }
    void next()
    {
        //ir a pos siguiente
        if (pos < size)
            pos++;
    }
    int getPos()  //retorna la pos actual
    {
        return pos;
    }
    int getSize()  // :P
    {
        return size;
    }

    void showList()
    {
        //imprime la lista
        for(int i=0; i<size; i++)
            cout << " [" <<  elements[i] << "] " << endl;
    }

    void invert()
    {
        //invertir orden de lista
        int cant = (size)/2;
        for(int i=0 ;i <=cant-1 ;i++)
        {
            E temp = elements[i];// se guarda valor para luego moverlo
            elements[i] = elements[size-1-i];
            elements[size-1-i] = temp;
        }
    }
};
