#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int Partition (int arr[], int low, int high, int *ptr)
{
    // check if the two pivots are sorted
    if(arr[low] > arr[low+1])
    {
        // swap pivots if not sorted
        swap(arr[low], arr[low+1]); 
    }
    
    int pivot1 = arr[low];
    int pivot2 = arr[low+1];
    
    int h;
    int i = low;
    int j = low+1;
    int idx = j; // Index of the second pivot

    for(h=low+2; h<=high; h++)
    {
        // If the element is smaller than pivot 2
        if(arr[h] <= pivot2)
        {
            // Increment j
            j++; 
            // Perform swapping
            swap (arr[j], arr[h]);
            // If the element is smaller than pivot 1 too
            if(arr[j] <= pivot1)
            {
                // Increment i
                i++;
                // Perform swapping
                swap(arr[i], arr[j]);
                
                if(arr[j] == pivot2)
                {
                    idx = j;
                }
                if(arr[i] == pivot2)
                {
                    idx = i;
                }
            }
        }
    }
    
    // Bring the pivots to their positions
    swap(arr[j], arr[idx]);
    swap(arr[low], arr[i]);

    // First pivot
    *ptr = i; // Because two elements cannot be returned from a function
    // Second pivot
    return j;
}

void First2Pivots(int arr[], int low, int high)
{
    // if there are only 2 elements
    if(high == 1)
    {
        if(arr[low] > arr[high]){
            swap(arr[low], arr[high]);
        }
        return;
    }
    if(low < high)
    {
        int i;
        int j = Partition (arr, low, high, &i);
        First2Pivots (arr, 0, i-1);
        First2Pivots (arr, i+1, j-1);
        First2Pivots (arr, j+1, high);
    }
}

void RandomPivots(int arr[], int low, int high)
{
    // Two random numbers to be pivots
    srand(static_cast < unsigned int > (time(0)));
    int x = 0;
    int y = 0;

    while(x == y)
    {
        x = rand() % high;
        y = rand() % high;
    }
    // Swap the pivots with the first two elements of array
    swap(arr[x], arr[low]);
    swap(arr[y], arr[low+1]);
    
    First2Pivots (arr,low,high);
}

// function to print array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {5, 7, 9, 3, 6, 2, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "The array before being sorted: " << endl;
    printArray(arr, n);

    cout << "Sorted array (using the first 2 elements as pivots): " << endl;
    First2Pivots (arr, 0, n-1);
    printArray(arr, n);

    cout << "Sorted array (using random elements as pivots): " << endl;
    RandomPivots(arr, 0, n-1);
    printArray(arr, n);

    return 0;
}