#include<bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;
 
//Lomoto partition
int Lomoto_partition(int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
 

void QuickSort_Lomoto(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = Lomoto_partition(arr, low, high);
 
        // sort elements before partition and after partition
        QuickSort_Lomoto(arr, low, p - 1);
        QuickSort_Lomoto(arr, p + 1, high);
    }
}

   // Hoare partition
int Hoare_partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;
 
    while (true) {

        // search for element greater than or equal to pivot
        do {
            i++;
        } while (arr[i] < pivot);
 
        // search for element smaller than or equal to pivot
        do {
            j--;
        } while (arr[j] > pivot);
 
        // If two pointers cross
        if (i >= j)
            return j;
 
        swap(arr[i], arr[j]);
    }
}


void QuickSort_Hoare(int arr[], int low, int high)
{
    if (low < high) {
       
        int p = Hoare_partition(arr, low, high);
 
        // sort elements before partition and after partition
        QuickSort_Hoare(arr, low, p);
        QuickSort_Hoare(arr, p + 1, high);
    }
}


void swap(int *array, int index1, int index2)
{
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

int QuickSort_Median(int *array, int l, int r);

int Median_Partition(int *array, int l, int r)
{
    
    int n = r - l;
    int middle = ((n - (n % 2)) / 2) + l;

    // order left and middle value
    if(array[l] > array[middle]) {
        swap(array, l, middle);
    }
    // order left and right values
    if(array[l] > array[r]) {
        swap(array, l, r);
    }
    // order middle and right values
    if(array[middle] > array[r]) {
        swap(array, middle, r);
    }
    swap(array, l, middle);
    int p = array[l];
    int i = l + 1;
    int end = 0;
    int j;
    for (j = l + 1; j <= r; j++)
    {
        if (array[j] < p){
            int k = array[j];
            array[j] = array[i];
            array[i] = k;
            i++;
        }
        end = j;
    }
    //swap A[l] and A[i-1]
    int a = array[l];
    array[l] = array[i-1];
    array[i-1] = a;
    QuickSort_Median(array, l, i - 2);
    QuickSort_Median(array, i, end);
}

int QuickSort_Median(int *array, int l, int r)
{
    if (l < r)
    {
        Median_Partition(array, l, r);
    }
    else
    {
        return 0;
    }
}


/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void random_sort (int array[], int size) {
    srand (static_cast <unsigned int> (time(0))); 

    for (int i = 0; i < size; i++) {
        array[i] = (rand() % size) + 1;
    }
}


int main()
{
    int arr[] = {6, 13, 9, 2, 5, 10};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "The array before being sorted: " << endl;
    printArray(arr, n);

    QuickSort_Lomoto(arr, 0, n-1);
    cout << "Sorted array (Lomoto partition): " << endl;
    printArray(arr, n);


    QuickSort_Hoare(arr, 0, n-1);
    cout << "Sorted array (Hoare partition): " << endl;
    printArray(arr, n);

    QuickSort_Median(arr, 0, n-1);
    cout << "Sorted array (Median of three): " << endl;
    printArray(arr, n);


    auto LomutoTime = 0, HoareTime = 0, MedianTime = 0;

    for (int i=0; i < 10000; i++)
    {

        int arrLomoto [1000];

        random_sort (arrLomoto, 1000);
        
        auto beginA = std::chrono::high_resolution_clock::now(); // Starting time
        QuickSort_Lomoto(arrLomoto, 0, 1000-1);
        auto endA = std::chrono::high_resolution_clock::now(); // Finishing time

        // Duration
        auto time1 = std::chrono::duration_cast<std::chrono::nanoseconds>(endA - beginA);

        LomutoTime = LomutoTime + time1.count();

        int arrHoare [1000];

         for(int j = 0; j<1000; j++)
        {
            arrHoare[j] = arrLomoto[j];
        }

        auto beginB = std::chrono::high_resolution_clock::now(); // Starting time
        QuickSort_Lomoto(arrHoare, 0, 1000-1);
        auto endB = std::chrono::high_resolution_clock::now(); // Finishing time

        // Duration
        auto time2 = std::chrono::duration_cast<std::chrono::nanoseconds>(endB - beginB);

        HoareTime = HoareTime + time2.count();


        int arrMedian [1000];

         for(int j = 0; j<1000; j++)
        {
            arrMedian[j] = arrLomoto[j];
        }

        auto beginC = std::chrono::high_resolution_clock::now(); // Starting time
        QuickSort_Lomoto(arrMedian, 0, 1000-1);
        auto endC = std::chrono::high_resolution_clock::now(); // Finishing time

        // Duration
        auto time3 = std::chrono::duration_cast<std::chrono::nanoseconds>(endC - beginC);

        MedianTime = MedianTime + time3.count();



    }

    cout << "The average time for Lomoto partition is: " << (LomutoTime/10000) << endl;
    cout << "The average time for Hoare partition is: " << (HoareTime/10000) << endl;
    cout << "The average time for Median of Three partition is: " << (MedianTime/10000) << endl;


    return 0;
}