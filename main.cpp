#include <iostream>
#include <stdio.h>

//#include "LList.h"
#include "ArrayList.h"
//#include "DLinkedlist.h"
#define DEFAULT_MAX_SIZE 1024

using namespace std;

int main()
{
    ArrayList<int> L1(10);
    L1.append(5);
    L1.append(5);
    L1.insert(7);
    L1.goToStart();
    L1.insert(8);
    L1.showList();
    L1.next();
    L1.showList();
    int a = L1.remove();

    L1.insert(10);
    L1.showList();
    cout << "hola";

    return 0;
}
