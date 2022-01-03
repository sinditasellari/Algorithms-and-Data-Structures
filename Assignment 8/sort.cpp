#include <iostream>
#include <string>
using namespace std;

void CountSort (string A[], int n, int pos)
 {
    int k = 123; // ASCII code equivalent till letter z
    int count[k];
    string B[n];

    for (int i = 0; i <= k; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (pos < A[i].size()) {
            count[A[i][pos] + 1]++;
        }
        else {
            count[0]++;
        }
    }

    for (int i = 1; i <= k; i++) {
        count[i] = count[i] + count[i - 1];
    }

    for (int i = n-1; i >= 0; i--) {
        if (pos < A[i].size()) {
            B[count[A[i][pos] + 1]-1] = A[i];     
            count[A[i][pos] + 1]--;
        }
        else {
            B[count[0] - 1] = A[i];
            count[0]--;
        }
    }

    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }

}

void RadixSort (string A[], int n)
 {
     //get maximum value of the string array
    int max = A[0].size();
    for (int i = 1; i < n; i++) {
        if (A[i].size() > max) {
            max = A[i].size();
        }
    }

    for (int pos = max - 1; pos >= 0; pos--) 
    {
        CountSort (A, n, pos);
    }
}

// Function for printing array
void printArray(string A[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << A[i] << " ";
        cout << endl;
    
}

int main() {
    string array[] = { "word", "category", "cat", "new", "news", "world", "bear", "at", "work", "time" };
    int n = sizeof(array) / sizeof(array[0]);

    cout << "Array before being sorting:" << endl;
    printArray(array, n);
    
    RadixSort (array, n);

    cout << "Array after being sorting:" << endl;
    printArray(array, n);
}