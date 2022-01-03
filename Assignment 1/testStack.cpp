/*
  Sindi Tasellari
  stasellari@jacobs-university.de
  a1.p2.cpp
*/

#include <iostream>
#include "Stack.h"
using namespace std;

int main () {
    //Testing with a float stack
    cout << "A stack of floats" << endl;
    Stack <float> floatstack(4);

    //Add elements
    floatstack.push(67.23);
    floatstack.push(3.24);
    floatstack.push(424.1);
    floatstack.push(2.76);
    floatstack.push(0.76);

    cout << "The top of the stack is " << floatstack.back() << endl;
    cout << "The number of the elements in the stack is " << floatstack.getNumEntries() << endl;
    
    //Remove element
    float elem;
    floatstack.pop(elem);
    floatstack.pop(elem);
    floatstack.pop(elem);
    floatstack.pop(elem);
    floatstack.pop(elem);
    floatstack.pop(elem);
    cout << "The number of elements in the stack is: " << floatstack.getNumEntries() << endl;
    cout << endl;

    //Testing with an integer stack
    cout << "A stack of integers" << endl;
    Stack <int> intstack;

    //Add elements
    intstack.push(5);
    intstack.push(55);
    intstack.push(123);
    intstack.push(1);
    intstack.push(27);
    intstack.push(6);

    cout << "The top is " << intstack.back() << endl;
    cout << "The size is " << intstack.getNumEntries() << endl;
    
    //Remove element
    int elem1;
    intstack.pop(elem1);
    intstack.pop(elem1);
    cout << "The top of the stack is: " << intstack.back() << endl;
    cout << "The number of elements in the stack is: " << intstack.getNumEntries() << endl;

    //Create a copy stack
    Stack <int> intstack1 (intstack);
    cout << "The top of the stack is is " << intstack1.back() << endl;

}
