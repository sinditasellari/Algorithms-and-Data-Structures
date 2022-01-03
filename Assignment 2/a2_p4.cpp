/*
  Sindi Tasellari
  stasellari@jacobs-university.de
  a2.p4.cpp
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    vector <int> vec;

    //Storing values from 1 to 30
    for(int i = 1; i <= 30; i++) {
        vec.push_back(i);
    }

    vec.push_back(5);

    //Reverse the vector
    reverse(vec.begin(), vec.end());

    for(auto it = vec.begin(); it != vec.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    //replace all values 5 by the value 129
    replace(vec.begin(), vec.end(), 5, 129);

    for (int i = 0;  i < vec.size(); i++) {
        cout << vec[i] << " ";
    }

return 0;


}
