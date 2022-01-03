/*
  Sindi Tasellari
  stasellari@jacobs-university.de
  a2.p2.cpp
*/

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;


int main () {
   //Creating a deque
   deque <float> A;
   float a;
   
   //Reading floats until 0 is entered and inserting them to A  
   while (1){
        cin >> a;
        //if value is positive, store at end
        if (a < 0) {
            A.push_front(a);
        }
        //if value is negative, store at front
        else if (a > 0) {
            A.push_back(a);
            }
        else {
            break;
        }
    }


    // Printing the elements of A separated by spaces
    for ( float x : A) 
    {
        cout << x << " ";
    }
    cout << endl;

    deque <float> :: iterator itr;
     
    //Add the value 0 into the middle of the deque
    for( auto i = 0; i < A.size(); i++) {
        if (A[i] > 0 ) {
            itr = A.begin() + i;
            A.insert(itr, 0);
            break;

        }
    }

    // Printing the elements of A separated by semicolons
    for ( auto it = A.begin(); it != A.end(); ++it) { 

       if(*it == A.back())
        cout << *it ;
        else{
            cout << *it << ",";
        }
    }
    cout << endl;

return 0;

}
