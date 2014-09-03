#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

template <typename E>

class Node
{
public:
    E element;
    Node <E>* next; // puntero al siguiete

    //Constructores

    Node(E pElemnt, Node<E>* pNext = NULL) // si no recibe puntero se inicializa como NULL
    {
        /*Recibe el valor del elemeto y el puntero al sig. */
        element = pElemnt;
        next = pNext;
    }
    Node(Node<E*> pNext = NULL)
    {
        /*inicializa el puntero*/
        next = pNext;
    }
};

#endif
