#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Bucket sort algorithm
void BucketSort (vector <int>& array, int pos)
 {
    vector <int> buckets[10];
    
    //Store elements in respective buckets
    for (int i = 0; i < array.size(); i++) 
    {
        int bucket_index = (array[i] / pos) % 10;
        buckets[bucket_index].push_back(array[i]);
    } 

    for (int i = 0; i < 10; i++)
    {
        if (buckets[i].size() > 1) {
            BucketSort (buckets[i], pos/10); //recursive call for the other bits
        }
    }
    
    int k = 0;
    for (int i = 0; i < 10; i++) 
    {
        for (int j = 0; j < buckets[i].size(); j++) {
            array[k++] = buckets[i][j];
        }
    }
    
}

void RadixSort (vector <int>& array) 
{
    int max = array[0];

    for (int i = 1; i < array.size(); i++) 
    {
        if (max < array[i]) {
            max = array[i];
        }
    }

    //set the most significant bit
    int pos = 1;
    while (max/pos > 0) {
        pos = pos * 10;
    }


    BucketSort (array, pos);
}

// function to print elements of the vector
void print(std::vector<int> const &array) {
    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
    cout << endl;

}

int main() {
    vector <int> array = {9, 253, 5, 88, 2301, 156};
    
    cout << "Array before being sorted:" << endl;
    print(array);

    RadixSort (array);

    cout << "Array after being sorted:" << endl;
    print(array);
}