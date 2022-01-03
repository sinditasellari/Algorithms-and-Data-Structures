/*
  Sindi Tasellari
  stasellari@jacobs-university.de
  a1.p2.cpp
*/

#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
using namespace std;

template <class T>
class Stack
{
    private:
        int top;
        int size;
        T *array;
    public:
        // Default constructor
        Stack()
        {
            size = 10;
            array = new T[size];
            if (array == NULL)
                exit(1);
            top = -1;
        }

        //Copy constructor
        Stack(const Stack& obj)
        {
            top = obj.top;
            size = obj.size;
            array = new T[size];
            if (array == NULL)
                exit(1);

            for (int i=0 ; i < size; i++)
            {
                array[i] = obj.array[i];
            }

        }

        //Parametrized constructor
        Stack(int size)
        {
            this->size = size;
            array = new T[size];
            if (array == NULL)
                exit(1);
            top = -1;
        }

        bool push(T element)
        {
            if (top == size -1)
            {
                cout << "Error : stack overflow" << endl;
                return false;
            }
                 top++;
                 array[top] = element;
                 return true;
        }

        bool pop(T& out)
        {
            if (top == -1)
            {
                cout << "Error : stack underflow" << endl;
                return false;
            }
            out = array[top];
            array[top] = 0;
            top--;
            return true;
        }


        T back(void) 
        {
            if (top == -1)
            {
                cout << "No datas" << endl;
            }
            return array[top];
        }

        int getNumEntries() 
        {
            return top + 1;
        }

        // Destructor
        ~Stack() {
            delete []array;
        }

};

#endif