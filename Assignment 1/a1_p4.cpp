/*
  Sindi Tasellari
  stasellari@jacobs-university.de
  a1.p4.cpp
*/

#include <iostream>
#include <vector>
using namespace std;

int main () 
{
    vector <string> vec;
    string i;
    
    while (i != "END")
    {
        cin >> i;
        if (i != "END")
        {
            vec.push_back(i);
         }
    }

    // Printing the words on the standard output separated by spaces using the index operator
    for (int i = 0; i < vec.size(); i++)
         cout << vec[i] << " ";

    cout << endl;
    
    // Printing the words on the standard output separated by comma using an iterator
    for (auto i = vec.begin(); i !=vec.end(); ++i) 
    {
        if(i == vec.end()-1)
        cout << *i ;
        else{
            cout << *i << ",";
        }
    }

    return 0;

}