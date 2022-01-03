/*
  Sindi Tasellari
  stasellari@jacobs-university.de
  a2.p1.cpp
*/

#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

int main () {

    list <int> A;
    list <int> B;
    
    int data;
    while(1){
        //Read integers from the keyboard until zero or negative is entered
        cin >> data;
        if (data <= 0)
          break;

          //Inserting the elements
          A.push_front(data);
          B.push_back(data);
    }

    // Print list A on the standard output
    for (int x : A){
        cout << x << " ";
    }
    cout<< endl;

    //print list B into the file “listB.txt”.
    ofstream MyFile;
    MyFile.open("listB.txt", ios :: out);

    if (!MyFile.is_open())
    {
        cout << "Error!" << endl;
    }
    else {
    for ( int y : B) {
        MyFile << y << endl;
      }
    }

    cout << endl;

    //Move the first element of the lists to the end 
    A.push_back(A.front());
    A.pop_front();
   
    B.push_back(B.front());
    B.pop_front();


    for ( auto it = A.begin(); it != A.end(); ++it) {
     if(*it == A.back())
        cout << *it ;
        else{
            cout << *it << ",";
        }
    }
    cout << endl;

    for ( auto it = B.begin(); it != B.end(); ++it) { 

       if(*it == B.back())
        cout << *it ;
        else{
            cout << *it << ",";
        }
    }

    cout << endl;

    //Merge list B into list A
    A.merge(B);

    //A sorted list
    A.sort();

    for (int z : A){
        cout << z << " ";
    }
    cout << endl;

   MyFile.close();
   return 0;

}