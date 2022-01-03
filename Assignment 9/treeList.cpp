#include <iostream>
using namespace std;

// Binary tree node
class BTSnode {
public:
    int key;
    BTSnode* left;
    BTSnode* right;

    BTSnode(int key)
    {
        this->key = key;
        this->left = NULL;
        this->right = NULL;
    }
};

// Linked list node
class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
  
  
// Function for printing the linked list
void print(ListNode* head)
{
    //check if list is empty
    if (head == NULL) {
        return;
    }

    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
  
// convert binary seach tree to linked list
ListNode* sortedLinkedList(ListNode* head, BTSnode* root)
{
    // return head if root is null
    if (root == NULL) {
        return head;
    }
  
    // proceed with the left sub-tree
    head = sortedLinkedList(head, root->left);
    ListNode* newNode = new ListNode(root->key);
    ListNode* ptr = head;
    ListNode* previous = NULL;
  
    // add the node to the head if linked list is empty
    if (ptr == NULL) {
        head = newNode;
    }
    else {
  
        // Find the correct position of the node
        while (ptr != NULL) {
            if (ptr->data > root->key) {
                break;
            }
            else {
                previous = ptr;
                ptr = ptr->next;
            }
        }
  
        if (ptr == NULL) {
            previous->next = newNode;
        }
        else {

            if (previous == NULL) {
                newNode->next = ptr;
                head = newNode;
            }
            else {
                newNode->next = ptr;
                previous->next = newNode;
            }
        }
    }
  
    // proceed with the right sub-tree
    head = sortedLinkedList(head, root->right);
    return head;
}
  
int main()
{
    BTSnode* root = new BTSnode(12);
    root->left = new BTSnode(5);
    root->right = new BTSnode(14);
    root->left->left = new BTSnode(3);
    root->left->right = new BTSnode(7);
    root->right->left = new BTSnode(13);
    root->right->right = new BTSnode(18);
  
    ListNode* head = sortedLinkedList(NULL, root);
    print(head);
  
    return 0;
}