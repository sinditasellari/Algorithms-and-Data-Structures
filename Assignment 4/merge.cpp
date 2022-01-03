#include <iostream>
using namespace std;

// a)

int k; // k as global variable

void Insertion (int array[], int lbound, int ubound) {
    int i, j, key;

    for (i = lbound + 1; i <= ubound; i++) {
        key = array[i];
        j = i - 1;

        while (j >= lbound && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void merge (int array[], int lbound, int mid, int ubound) {
    int i, j, k;

    int left = mid - lbound + 1;
    int right = ubound - mid;

    int larray[left];

    for (i = 0; i < left; i++) {
        larray[i] = array[lbound + i];
    }

    int rarray[right];

    for (j = 0; j < right; j++) {
        rarray[j] = array[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = lbound;

    while (i < left && j < right) {
        if (larray[i] <= rarray[j]) {
            array[k] = larray[i];
            i++;
        }
        else {
            array[k] = rarray[j];
            j++;
        }
        k++;
    }

    while (i < left) {
        array[k] = larray[i];
        i++;
        k++;
    }

    while (j < right) {
        array[k] = rarray[j];
        j++;
        k++;
    }
}

void MergeSort (int array[], int lbound, int ubound) {
    if (ubound-lbound <= k) {
        Insertion (array, lbound, ubound);
    }
    else {
        int mid;
        mid = (lbound + ubound) / 2;
        
        MergeSort (array, lbound, mid);
        MergeSort (array, mid+1, ubound);
        merge (array, lbound, mid, ubound);
    }
}

int main () {
    int array[6] = {34, 82, 1, 10, 7, 32};

    cout << "The value of k:" << endl;
    cin >> k;

    cout << "The initial array:" << endl;
    for (int idx = 0; idx < 6; idx++) {
        cout << array[idx] << " ";
    }
    cout << endl;
    cout << endl;

    MergeSort (array, 0, 5);

    cout << "The final array:" << endl;
    for (int idx = 0; idx < 6; idx++) {
        cout << array[idx] << " ";
    }
    cout << endl;

}