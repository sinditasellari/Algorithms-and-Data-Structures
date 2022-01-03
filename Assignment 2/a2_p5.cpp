/*
  Sindi Tasellari
  stasellari@jacobs-university.de
  a2.p5.cpp
*/

#include <iostream>
#include <set>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    //The container is a set, because each element
    //is unique and it is in ascending order
    set <int> mySet;

    int el;
    srand(static_cast < unsigned int > (time(0)));
    // Get 6 random elements
    
   while(1){
     el = rand() % 49 + 1;
     mySet.insert(el);

    if(mySet.size() == 6){
            break;
       } 
   }
        
    //Print the elements on the standard output
    for (auto it = mySet.begin(); it != mySet.end(); it++) {
        cout << *it << " ";
    }


}
