/*
  Sindi Tasellari
  stasellari@jacobs-university.de
  a1.p5.cpp
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
        getline(cin,i);
        if (i != "END")
        {
            vec.push_back(i);
         }
    }
    for (int i = 0; i < vec.size(); i++)
    {
        //The size should be greater than 4 in order to swap 2th and 5th element
        if(vec.size() > 4)
        {
            vec[1].swap(vec[4]);

        }
        else {
            cout << "Cannot swap second and fifth element" << endl;
            break;
        }
    }

    //Replacing the last element
    vec.at(vec.size()-1) = "???";
    
    //Printing the strings separated by comma using the index operator
    for (int i = 0; i < vec.size(); i++)
    {
        if(i == vec.size()-1)
        cout << vec[i] ;
        else{
            cout << vec[i] << ",";
        }
    }
    cout << endl;

    //Printing the strings separated by semicolon using an iterator
    for (auto it = vec.begin(); it !=vec.end(); ++it) 
    {
        if(it == vec.end()-1)
        cout << *it ;
        else{
            cout << *it << ";";
        }
    }
    cout << endl;

    //Printing the strings in the reversed order separated by space using an iterator
    for (auto it = vec.end()-1; it != vec.begin()-1; it--) 
        cout << *it << " ";

cout << endl;
        

}