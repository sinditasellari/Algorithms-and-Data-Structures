#include <iostream> 
#include <cstdlib>
#include <chrono>
using namespace std;
 
void heapify(int array[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && array[l] > array[largest])
        largest = l;
 
    // If right child is larger than largest
    if (r < n && array[r] > array[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(array[i], array[largest]);
 
        // Continue heapifying
        heapify(array, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(int array[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);
 
    // Extract elements one by one from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(array[0], array[i]);
 
        //Apply heapify to reduced heap
        heapify(array, i, 0);
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
 
    heapSort(array, n);
 
    cout << "The sorted array is: \n";
    printArray(array, n);

    //Measure the time of 6 arrays
    for (int i = 0; i < 6; i++) {
        int n;
        // Write from the keybord the the size of the array
        cin >> n;
        int A[n];

        sort (A, n);
        
        auto beginA = std::chrono::high_resolution_clock::now(); // Starting time
        heapSort (A, n);
        auto endA = std::chrono::high_resolution_clock::now(); // Finishing time

        // Duration
        auto time1 = std::chrono::duration_cast<std::chrono::nanoseconds>(endA - beginA);

        cout << "The time Heap Sort is: " << time1.count() << endl;

    }

}