#include <iostream>
using namespace std;

template <class T>
class Stack {
    private:
       struct StackNode {     // linked list
           T data;
           StackNode *next;
       };
       StackNode *top;        // top of stack
       int size;              // -1 if not set, value otherwise
       int current_size;      // unused if size = -1
       
    public:
       // We do not iterate , we only insert elements from the top 
       // so Time complexity of push() is O(1) 
       void push (T x) { 
           // check for overflow
           if (current_size == size) {
                cout << "Overflow!" << endl;
           } 
           else {
                struct StackNode *newnode = new StackNode;
                newnode->data = x;
                newnode->next = top;
                top = newnode;
                current_size++;
                cout << "Pushing..." << newnode->data << endl;
           }

       }
       
       /* Time complexity of pop() is O(1) as there is no need to iterate.
       Simply change the pointer direction and free the memory. */
       T pop () {              
           if (isEmpty()) {
               cout << "Underflow!" << endl;
           }
           else {
               struct StackNode *ptr = new StackNode;
               ptr = top;
               T element = ptr->data;
               top = ptr->next;
               delete ptr;
               current_size--;
               cout << "Popping..." << element << endl;
               return element;
            }
        } 

       // We only check for the top element so
       // time complexity is O (1)
       bool isEmpty() {         // true if empty, false otherwise
           return top == NULL;
        }

       Stack (int new_size) {   // Parameterized constructor
           size = new_size;
           current_size = 0;
           top = NULL;
        }
        
        Stack () {              // Default constructor
           size = -1;
           current_size = 0;
           top = NULL;
        }
};


int main () {
    Stack <int> stack (5);

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    
    for (int i = 0; i <= 5; i++) {
        stack.pop();
    }

    return 0;
}
