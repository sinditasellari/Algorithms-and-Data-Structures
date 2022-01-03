/*
  Sindi Tasellari
  stasellari@jacobs-university.de
  a2.p6.cpp
*/

#include <iostream>
#include <map>
#include <fstream>
using namespace std;

int main () {
    //Creating map
    map <string, string> myMap;

    ifstream file;
    file.open("data.txt", ios::in);

    if (!file.is_open())
    {
        cout << "Error!" << endl;
    }
    //read the data from file “data.txt”
    while (!file.eof()){
        string line1, line2;

        getline (file, line1);
        getline (file, line2);

        myMap[line1] = line2;
    }
    
    cout << "Enter name:" << endl;
    //Ask a name from the keyboard
    string str;
    getline (cin, str);

    map <string, string>:: iterator it;
    it = myMap.find(str);

    if (it == myMap.end()) {
        cout << "Name not found!" << endl;
    }
    else {
        cout << it-> second << endl;
    }
    
    file.close();
    return 0;
}