#include <iostream>

using namespace std;

class Node {
    public:
       int key;
       int value;
       
       Node(int key, int value){
           this->value = value;
           this->key = key;
        }
};

class HashTable {
    private:
    
       Node **arr;
       int maxSize;
       int currentSize;
       
    public:
      
       HashTable(){
           // m is chosen according to the size of the array.In this case: 
           //m = 11 as it is a number not too close the powers of 2 and not
           // often used in computing environments
           maxSize=11;
           currentSize=0;
           arr = new Node* [maxSize];
           
           for (int i = 0; i < maxSize; i++){
               arr[i] = NULL;
            }
        }
        
       int hashCode(int key){
            // using the division method: h'= k mod m
            return key % maxSize;
        };
        
       void insertNode(int key, int value)
       {
           if (maxSize > currentSize)
           {
               Node *ptr = new Node(key, value);
               
               // hash function to find index for given key
               int hashIdx = hashCode(key);
               
               while(arr[hashIdx] != NULL && arr[hashIdx]->key != key)
               {
                   hashIdx++;
                   hashIdx %= maxSize;
               }
               
               if(arr[hashIdx] == NULL)
                    currentSize++;
               arr[hashIdx] = ptr;
            }
            else 
            {
            cout << "Overflow condition!" << endl;
            }
        }   
        
        int get(int key)
        {
            // hash function to find index for given key
            int hashIdx = hashCode(key);

            while(arr[hashIdx] != NULL){    
                int counter =0;
                
                if(counter++>maxSize) 
                    return -1;  
                    
                //return the node's value if it is found
                if(arr[hashIdx]->key == key)
                    return arr[hashIdx]->value;

                hashIdx++;
                hashIdx %= maxSize;
            }
            
            return -1;
        };

        bool isEmpty()
        {
            return currentSize == 0;
        }

        void print()
        {
            for(int i=0 ; i<maxSize ; i++)
            {
                if(arr[i] != NULL)
                { 
                    cout << "Position " << i << " -> " << "key = " << arr[i]->key 
                    << "  value = "<< arr[i]->value << endl;
                }
                
                else
                { 
                    cout << i << " -> " << " - " << endl;
                }

            }
        }
};

int main()
{
    HashTable *hash = new HashTable;

    cout<<"Insert elements into the table..."<<endl;
    hash->insertNode(5,3);
    hash->insertNode(7,1);
    hash->insertNode(6,2);
    hash->insertNode(1,4);
    hash->insertNode(11,0);

    cout<<"Printing the elements of the table:"<<endl;
    hash->print();
    cout<<endl;

    cout<<"Find the value of a key in the table"<<endl;
    int x;
    cin >> x;

    int y = hash->get(x);

    if (y != -1){ 
    cout << "The value of key " << x << " is " << y;
    }
    else if (y = -1)
    { 
    cout << "Element not found" << endl;
    }

    return 0;
   
}