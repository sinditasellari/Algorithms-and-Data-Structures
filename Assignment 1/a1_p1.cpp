/*
  Sindi Tasellari
  stasellari@jacobs-university.de
  a1.p1.cpp
*/

#include <iostream>
using namespace std;

// Complex class
class Complex {
    private:
        double real, imag;
    public:
        // Parametrized constructor
        Complex(int r, int i): real(r), imag(i) {}
  
        // Overloading operator ==
        int operator==(const Complex obj) {
            return ((this->real == obj.real) && (this->imag == obj.imag));
        }
       
};

template <class T>
int array_search(T arr[], int size, T element) {
    int i;
    for (i = 0; i < size; i++) {
        if(arr[i] == element){
            return i;
        }
    }
    return -1;
}

int main() {
    // Array of integer type
    int arr1[] = {12, 23, 18, 24, 51};
    int el1 = 7;
    if(array_search(arr1, 5, el1) == -1){
        cout << array_search(arr1, 3, el1) << ": " << "Element not found." << endl;
    }else{
        cout << "Element is at position " << array_search(arr1, 5, el1) << endl;
    }
    // Array of float type
    float arr2[] = {1.15, 1.2, 3.343, 2.09, 5.51};
    float el2 = 1.15;
    if(array_search(arr2, 5, el2) == -1){
        cout << array_search(arr2, 3, el2) << ": " << "Element not found." << endl;
     }
    else{
        cout << "Element is at position " << array_search(arr2, 5, el2) << endl;
    }
    // Array of char type
    char arr3[] = {'a', 'b', 'c', 'd', '!'};
    char el3 = '!';
    if(array_search(arr3, 3, el3) == -1){
        cout << array_search(arr3, 3, el3) << ": " << "Element not found." << endl;
    }
    else{
        cout << "Element is at position " << array_search(arr3, 3, el3) << endl;
    }
    // Complex array
    Complex arr4[] = {Complex(3, 5), Complex(-7, 6), Complex(9, -1)};
    Complex el4(9,-1);
    if(array_search(arr4, 3, el4) == -1){
       cout << array_search(arr4, 3, el4) << ": " << "Element not found." << endl;
    }
    else{
        cout << "Element is at position " << array_search(arr4, 3, el4) << endl;
    }
    return 0;
}
