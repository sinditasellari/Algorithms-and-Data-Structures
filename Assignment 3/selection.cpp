#include <iostream>
using namespace std;

// a) Implement Selection Sort
void sort (int a[], int size) {
    int smallest;
    
    // Unsorted subarray
    for (int i=0; i<size-1; i++ ) 
    {
        smallest = i;

        // Find the smallest element in the unsorted array
        for (int j=i+1; j<size; j++) 
        {
            if (a[j] < a[smallest]) {
                smallest = j;
            }
        }

        if (smallest != i) {
            // Swap the found smallest element with the first element
            int temp = a[smallest];
            a[smallest] = a[i];
            a[i] = temp;
        }
    }
}

int main () {
    int array[10] = {22, 14, 5, 46, 3, 11, 8, 19, 25, 37};

    cout << "The array: ";
    for (int idx = 0; idx < 10; idx++) {
		cout << array[idx] << " ";
	}
	cout << endl;

    cout << "Elements are about to be sorted..." << endl;
    sort(array, 10);

    cout << "The sorted array: ";
	for (int idx = 0; idx < 10; idx++) {
		cout << array[idx] << " ";
	}
	cout << endl;

    return 0;
}