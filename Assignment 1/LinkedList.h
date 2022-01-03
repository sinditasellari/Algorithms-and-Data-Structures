/*
  Sindi Tasellari
  stasellari@jacobs-university.de
  a1.p3.cpp
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

template <class T>
class List {
    struct node {
        T info;
        node* p;
        node* n;

        //Constuctor for node
        node (T newinfo) 
        {
            info = newinfo;
            p = NULL;
            n = NULL;
        } 
    };
    node* head;
    node* tail;

    public:

    //Constructor
    List() 
    {
        head = NULL;
        tail = NULL;
    }
    
    //Destructor
    ~List()
        {
            node* temp = head;
            node* temp1;

            while(!(temp == NULL))
            {
                temp1 = temp;
                temp = temp -> n;
                delete temp1;
            }
        }
    
    // Function for inserting data at the beginning
    void InsertAtBegin(T data) 
    {
        if (head == NULL && tail == NULL)
        {
            head = new node (data);
            tail = head;
        }
        else {
            node *temp = head;
            temp -> p = new node (data);
            temp -> p -> n = head;
            head = temp -> p;

        }
    }
    
    // Function for deleting data at the beginning
    void DeleteAtBegin() 
    {
        if (head == tail)
        {
            head = tail = NULL;
        }
        else {
            head = head -> n;
            head -> p = NULL;
        }
    }

    // Function for inserting data at the end
    void InsertAtEnd(T data)
    {
        if (head == NULL && tail == NULL)
        {
            tail = new node (data);
            head = tail;
        }
        else {
            node *temp = tail;
            temp -> n = new node (data);
            temp -> n -> p = tail;
            tail = temp -> n;
        }

    }
    
    // Function for deleting data at the end
    void DeleteAtEnd()
    {
        if (head == tail)
        {
            head = tail = NULL;
        }
        else{
            tail = tail -> p;
            tail -> n = NULL;
        }

    }
    
    // Function for showing the first data
    T first() 
    {
        return head -> info;
    }

    // Function for showing the last data
    T last()
    {
        return tail -> info;
    }

    // Function for counting the data in a list
    int NoOfElements()
    {
        int num = 0;
        node* temp = head;

        while( temp != NULL )
        {
            num++;
            temp = temp -> n;
        }
        return num;

    } 

};

#endif