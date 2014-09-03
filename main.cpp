#include <iostream>
#include <stdio.h>

#include "LinkedList.h"
#include "ArrayList.h"
//#include "DLinkedlist.h"
#define DEFAULT_MAX_SIZE 1024

using namespace std;

int main()
{
    //ArrayList<int> L1(10);
    LinkedList<int> L1;
    L1.append(1);
    L1.append(2);
    L1.append(3);
    L1.append(4);
    L1.append(5);
    L1.append(6);
  //  L1.showList();
    cout << "---" <<endl;
   // L1.invert();
    //L1.showList();


    return 0;
}
