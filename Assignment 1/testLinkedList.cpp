/*
  Sindi Tasellari
  stasellari@jacobs-university.de
  a1.p3.cpp
*/

#include <iostream>
#include "LinkedList.h"
using namespace std;

int main ()
{
    //Creating first list
    cout << "Linked list with integers:" << endl;
    List <int> intlist;

    intlist.InsertAtBegin(7);
    intlist.InsertAtBegin(9);
    intlist.InsertAtEnd(2);
    intlist.InsertAtBegin(1);
    intlist.InsertAtEnd(5);

    cout << "The first data in the list: " << intlist.first() << endl;
    cout << "The last data in the list: " << intlist.last() << endl;
    intlist.DeleteAtBegin();
    intlist.DeleteAtEnd();
    cout << "The first data in the list now: " << intlist.first() << endl;
    cout << "The last data in the list now: " << intlist.last() << endl;
    cout << "The total number of data: " << intlist.NoOfElements() << endl << endl;

    //Creating second list
    cout << "Linked list with characters:" << endl;
    List <char> charlist;

    charlist.InsertAtBegin('n');
    charlist.InsertAtBegin('s');
    charlist.InsertAtEnd('&');
    charlist.InsertAtBegin('l');
    charlist.InsertAtEnd('h');

    cout << "The first data in the list: " << charlist.first() << endl;
    cout << "The last data in the list: " << charlist.last() << endl;
    charlist.DeleteAtBegin();
    charlist.DeleteAtEnd();
    cout << "The first data in the list now: " << charlist.first() << endl;
    cout << "The last data in the list now: " << charlist.last() << endl;
    cout << "The total number of data: " << charlist.NoOfElements() << endl;
}