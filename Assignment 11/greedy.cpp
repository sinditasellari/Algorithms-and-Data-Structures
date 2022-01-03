#include <bits/stdc++.h>
using namespace std;

struct Activitiy 
{
    int start;
    int finish;
};

// helping function for sorting activities according to start time 
bool compare (Activitiy a1, Activitiy a2) {
    return (a1.start < a2.start);
}

void greedy (Activitiy arr[], int n) {
    // Sort activities according to their start time 
    // ascending order
    sort (arr, arr + n, compare); 

	cout<< "Following activities are selected:" << endl; 

    // Select the activity with the latest starting time
    int i = n - 1;
    cout << "(" << arr[i].start << ", " << arr[i].finish << ")" << endl;

    // Consider the remaining activities from the penultimate to the first one
    for (int j = n - 2; j >= 0; j--) 
    {
        // Select this activity if it has finish time less than or equal
    	// to the start time of current activity
        if (arr[j].finish <= arr[i].start) 
        {
            cout << "(" << arr[j].start << ", " << arr[j].finish << ")" << endl;
            i = j;
        }
    }
}

int main () {
    Activitiy arr[] = {{2, 4}, {1, 5}, {7, 12}, {12, 13}, {4, 7}};
    int n = sizeof(arr) / sizeof(arr[0]);

    greedy (arr, n);

    return 0;
}