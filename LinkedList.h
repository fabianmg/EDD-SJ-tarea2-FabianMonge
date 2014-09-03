
#ifndef LLIST_H
#define LLIST_H
#include "Node.h"
#include <stdexcept>

using namespace std;


template <typename E>
class LinkedList
{
private:
    Node<E> *head; //puntero al inicio de la lista
    Node<E> *tail; //puntero al final de la lista
    Node<E> *current; // putero a la posicion actual
    int size; // tamaño actual de la lista




public:
    //Constructor
    LinkedList()
    {
        /*Crea el nodo especial,
        sin elemento y el puntero
        siguiente en NULL. */
        head = tail = current = new Node<E>();
        size = 0; //tamaño de la lista
    }
    //Destructor

    ~LinkedList()
    {
        /*Elimina todos los elementos
        de la lista y luego elimina el
        nodo especial*/
        clear();
        delete head;

    }

    Node<E>* searchPrevious(Node<E>* pNode)
    {
        /*Método auxiliar que recibe un puntero a un nodo
            y retorna el puntero al nodo anterior en la lista
            Retorna NULL si el puntero recibido es head*/

        if (current == head)
            return NULL;

        Node<E> *res = head;
        while (res->next != current)
            res = res->next;
        return res;
       }

    void insert( E pElement)
    {
        /*Creación del nuevo nodo con el elemento enviado y el
        puntero siguiente hacia el nodo siguiente de current.
        El puntero siguiente de current se asigna a la
        dirección del nuevo nodo.*/

        current->next = new Node <E> (pElement,current->next);

        if (current == tail) /*si el current apunta al final de
                              la lista,debe actualizarse el tail*/
            tail = tail->next;

        size++;
    }

    void append(E pElement)
    {
        /*Se crea el nodo y se asigna en la posición siguiente al
            puntero tail.*/
        tail->next = new Node<E>(pElement);
        tail = tail->next; //Se actualiza el tail.
        size++;
    }


    E remove() throw (runtime_error)
    {
        // eliminar elemnto de la lista
        if (current->next == NULL) // verifica si hay elemnto en la lista
            throw runtime_error("No element to remove.");

        E result = current -> next -> element; // guarda, el que borraremos
        Node<E> * temp = current -> next; //Puntero temporal para mantener
                                        //el elemento aeliminar.
        current -> next = current -> next-> next;//Se enlaza el puntero
                        //siguiente para sacar el elemento de la lista.

        if (temp ==tail)  // si se borra el ultimo
            tail = current; // actualizar el tail

        delete temp;
        size --;
        return result;
    }

    void clear()
    {
        current = head;
        while (head->next != NULL) //recorre la lista
        {
            //elimina ¡todos! los nodos
            head = head->next;
            delete current;
            current = head;
        }
        head = tail = current = new Node<E>(); //crea node especial
        size = 0;
        cout<< "Acaba de limpiar el Arreglo"<< endl;
    }
    E getElement() throw(runtime_error){//Metodo que retorna el elemento en la posicion actual
        if (current->next == NULL)
            throw runtime_error("No element to get");

        return  current-> next-> element;
        cout<<" borrame El elemento es:(" <<current->next->element<< ")" << endl;
    }
    void goToStart()
    {
        current = head;
        cout<<"Usted se ha movido al inicio"<< endl;
    }

    void goToEnd()
    {
        current = tail;
        cout<<"Usted se ha movido al final"<< endl;
    }

    void goToPos(int nPos) throw (runtime_error)
    {
        if ((nPos < 0) || (nPos > size))// ídice valido?
            throw runtime_error("Index out of bounds");

        current = head;
        for (int i = 0; i < nPos; i++)
            current = current->next;
    }

    void next()
    {
        //Asigna al current el siguiente nodo en la lista.
        if (current != tail)
            current = current->next;
    }

    void previous()
    {
        /*Asigna al current el valor
         retornado por el método que
         busca el elemento anterior.*/
        if (current != head)
            current = searchPrevious(current);
    }

    int getSize()
    {
        return size ;
    }

    int getPos()
    {
        int pos = 0;
        Node <E>*temp = head;
        while(temp != current)
        {
            pos ++ ;
            temp = temp->next;
        }
        return pos;
    }
};

#endif // LLIST_H
