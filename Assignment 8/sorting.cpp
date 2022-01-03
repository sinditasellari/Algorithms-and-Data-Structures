#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSort(int arr[], int n, int k) {

  int sorted[n];
  int count[k+1];
 
  // Initialize count array with zeros.
  for (int i = 0; i <= k; ++i) {
    count[i] = 0;
  }

  // Store the count of each element
  for (int i = 0; i < n; i++) {
    count[arr[i]]++;
  }

  // Store the cummulative count of each array
  for (int i = 1; i <= k; i++) {
    count[i] += count[i - 1];
  }

  // Store the elements in sorted array by finding the index of each element
  for (int i = n - 1; i >= 0; i--) {
    sorted[count[arr[i]] - 1] = arr[i];
    count[arr[i]]--;
  }

  // Copy the elements into original array
  for (int i = 0; i < n; i++) {
    arr[i] = sorted[i];
  }
}

void BucketSort (float arr[], int size) {

    vector <float> buckets[size]; //create buckets

    //Store elements in respective buckets
    for (int i = 0; i < size; i++) {
        int bucket_index = size * arr[i];
        buckets[bucket_index].push_back(arr[i]);
    }

    //Sort the buckets
    for (int i = 0; i < size; i++) {
        sort (buckets[i].begin(), buckets[i].end());
    }

    //Concatenate the buckets into the original array
    int k = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[k++] = buckets[i][j];
        }
    }

}

// Function to print an array
template <class T>
void printArray(T arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main() {
  int array[] = {9, 1, 6, 7, 6, 2, 1};
  int n = sizeof(array) / sizeof(array[0]);
  cout << "Array before sorting: " << endl;
  printArray(array, n);
  countingSort(array, n, 9);
  cout << "Array after sorting: " << endl;
  printArray(array, n);

  float A[] = { 0.9, 0.1, 0.6, 0.7, 0.6, 0.3, 0.1};
  int m = sizeof(A) / sizeof(A[0]);

  cout << "Array before sorting: " << endl;
  printArray(A, m);
  BucketSort(A, m); 
  cout << "Array after sorting: " << endl;
  printArray(A, m);
}