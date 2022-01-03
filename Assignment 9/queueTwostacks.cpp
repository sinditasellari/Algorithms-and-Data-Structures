#include <bits/stdc++.h>
using namespace std;

class Queue {
    public:
       stack <int> stack1, stack2;

       void enqueue (int element) {
           stack1.push(element);
           cout << "Added to queue " << element << endl;
       }

       int dequeue () {
           if (stack1.empty() && stack2.empty()) {
               cout << "Underflow!";
               exit(0);
           }

           if (stack2.empty()) {
               while (!stack1.empty()) {
                   stack2.push (stack1.top());
                   stack1.pop();
               }
           }

           int element = stack2.top();
           stack2.pop();
           cout << "Popped out " << element << endl;
           return element;
       }

};

int main () {
    Queue queue;

    queue.enqueue(6);
    queue.enqueue(10);
    queue.enqueue(15);
    queue.enqueue(11);


    for (int i = 0; i <= 4; i++) {
        queue.dequeue();
    }

}