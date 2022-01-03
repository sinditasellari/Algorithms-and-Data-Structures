#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;

void heapify (int array[], int n, int i) {
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
    
    // If left child is larger than root
    if (l < n && array[l] > array[largest]) {
        largest = l;
    }
    
    // If right child is larger than largest
    if (r < n && array[r] > array[largest]) {
        largest = r;
    }
    
    // If largest is not root
    if (largest != i) {
        swap (array[i], array[largest]);
        // Continue heapifying
        heapify (array, n, largest);
    }
}

int findLeaf (int array[], int n)
{
    int pos = 0; // root position
    int LeftChildPos = 2 * pos + 1;
    int RightChildPos = 2 * pos + 2;
    
    //if two children exist
    while (RightChildPos < n) 
    {
        // Compare children
        if (array[RightChildPos] > array[LeftChildPos]) {
            pos = RightChildPos;
        }
        else {
            pos = LeftChildPos;
        }
        LeftChildPos = pos * 2 + 1;
        RightChildPos = pos * 2 + 2;
    }

    // if one child exist
    if (LeftChildPos < n) {
        pos = LeftChildPos;
    }

    return pos;
}

void siftDown (int array[], int n) {
    // Float the new root down to a leaf level
    int i = 0; // root position
    int pos = findLeaf(array, n);

    while (array[i] > array[pos]) {
        //parent position
        pos = (int) (pos-1) / 2;
    }

    int x = array[pos];
    array[pos] = array[i];
    
    while (pos > i) {
        swap (x, array[(int) (pos-1)/2]);
        pos = (int) (pos-1) / 2;
    }
}

void modifiedHeapSort (int array[], int n) {

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

    for (int i = n-1; i > 0; i--) {
        swap (array[0], array[i]);
        n--;

        // float the root down
        siftDown (array, n);    
    }
}

// Function to print array
void printArray(int array[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << array[i] << " ";
    cout << endl;
    
}

// Function to randomly sort the elements
void sort (int array[], int size) {
    srand (static_cast <unsigned int> (time(0))); 

    for (int i = 0; i < size; i++) {
        array[i] = (rand() % size) + 1;
    }
}

int main()
{
    int array[] = { 7, 11, 2, 5, 14, 25 };
    int n = sizeof(array) / sizeof(array[0]);

    cout << "The array before being sorted: \n";
    printArray(array, n);
 
    modifiedHeapSort(array, n);
 
    cout << "The sorted array is: \n";
    printArray(array, n);

    //Measure the time of 6 arrays
    for (int i = 0; i < 6; i++) {
        int n;
        // Write from the keybord the the size of the array
        cin >> n;
        int B[n];

        sort (B, n);
        
        auto beginB = std::chrono::high_resolution_clock::now(); // Starting time
        modifiedHeapSort (B, n);
        auto endB = std::chrono::high_resolution_clock::now(); // Finishing time

        // Duration
        auto time2 = std::chrono::duration_cast<std::chrono::nanoseconds>(endB - beginB);

        cout << "The time for Bottom Up heap sort is: " << time2.count() << endl;

    }
}