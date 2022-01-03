#include <iostream>
using namespace std;

enum Color {RED, BLACK};

struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;
};

class RedBlackTree 
{
    private:
        Node *root;
    
    protected:
        
        void rotateLeft (Node *&x) 
        {
            if (x->right == NULL)
                return;
            else {
                Node* y = x->right;
                if (y->left != NULL)
                {
                    x->right = y->left;
                    y->left->parent = x;
                }
                else
                    x->right = NULL;

                if (x->parent != NULL)
                    y->parent = x->parent;
                
                if (x->parent == NULL)
                    root = y;
                else 
                {
                    if (x == x->parent->left)
                        x->parent->left = y;
                    else
                        x->parent->right = y;
                }

                y->left = x;
                x->parent = y;
             }
        }

        void rotateRight(Node *&x) 
        {
            if (x->left == NULL)
                return;
            else 
            {
                Node* y = x->left;

                if (y->right != NULL) 
                {
                    x->left = y->right;
                    y->right->parent = x;
                }
                else
                    x->left = NULL;

                if (x->parent != NULL)
                    y->parent = x->parent;

                if (x->parent == NULL)
                    root = y;
                else 
                {
                    if (x == x->parent->left)
                        x->parent->left = y;
                    else
                        x->parent->right = y;
                }

                y->right = x;
                x->parent = y;
            }
        }

    public:

        // Default constructor
        RedBlackTree () {
            root = NULL;
        }
        
    //Implementation with reference to the pseudocodes of lecture


        void insertRB (int newNode) {

            Node *y, *x;
             y = NULL;
             x = root;

            Node *z;
            z = new Node;
            z->data = newNode;

            
            if (root == NULL) 
            {
                root = z;
                z->parent = NULL;
            } 
            else 
            {
                while (x != NULL) 
                {
                    y = x;
                    
                    if(x->data < z->data)
                        x = x->right;
                    else
                        x = x->left;
                }
                    
                z->parent = y;
                    
                if(y->data < z->data)
                    y->right = z;
                else
                    y->left = z;
            }

            z->left = NULL;
            z->right = NULL;
            z->color = RED;
            FixUpInsertion(z);
        }

        void FixUpInsertion (Node *&z) 
        {
            Node *y;

            if (root == z) 
            {
                z->color = BLACK;
                return;
            }
            
            while (z->parent != NULL && z->parent->color == RED) 
            {

                if (z->parent == z->parent->parent->left) 
                {
                    if (z->parent->parent->right != NULL) 
                    {
                        y = z->parent->parent->right;
                        
                        if (y->color == RED) 
                        {
                            //Case 1
                            z->parent->color = BLACK;  
                            y->color = BLACK;
                            z->parent->parent->color = RED;
                            z = z->parent->parent;
                        }
                    } 
                    else 
                    {
                        if (z == z->parent->right) 
                        {    
                            //  Case 2
                            z = z->parent;   
                            rotateLeft(z);
                        }
                        
                        //  Case 3
                        z->parent->color = BLACK;   
                        z->parent->parent->color = RED;
                        rotateRight(z->parent->parent);
                    }
                } 
                else {
                    if (z->parent->parent->left != NULL) 
                    {
                        y = z->parent->parent->left;
                        
                        if (y->color == RED) 
                        {
                            z->parent->color = BLACK;
                            y->color = BLACK;
                            z->parent->parent->color = RED;
                            z = z->parent->parent;
                        }  
                    } 
                    else {
                        if (z == z->parent->left) 
                        {
                            z = z->parent;
                            rotateRight(z);
                        }
                        
                        z->parent->color = BLACK;
                        z->parent->parent->color = RED;
                        rotateLeft(z->parent->parent);
                    }
                }
                
                root->color = BLACK;
            }
        }


        void deleteRB (Node *&z) 
        {
            if (root == NULL) 
            {
                cout << "Tree is empty." << endl;
                return ;
            }
            
            Node* x; 
            x = root;

            Node* y = NULL;
            Node* w = NULL;

            int found = 0;
            
            while (x != NULL && found == 0) 
            {
                if (x->data == z->data) 
                {
                    found = 1;
                }
                
                if (found == 0) {
                    if (x->data < z->data) 
                    {
                        x = x->right;
                    } 
                    else
                     {
                        x = x->left;
                    }
                }
            }
            
            if (found == 0) 
            {
                cout << "Element is not here." << endl;
                return ;
            } 
            else 
            {
                if (x->left == NULL || x->right == NULL) 
                {
                    y = x;
                }
                else {
                    y = successor(x);
                }
                
                if (y->left != NULL) 
                {
                    w = y->left;
                }
                else 
                {
                    if (y->right != NULL)
                    { 
                       w = y->right;
                    }
                    else
                    { 
                       w = NULL;
                    }
                }
                
                if (w != NULL)
                { 
                    w->parent = y->parent;
                }
                   
                if (y->parent == NULL) 
                {
                    root = w;
                }
                else 
                {
                    if (y == y->parent->left)
                    { 
                       y->parent->left = w;
                    }
                    else
                    { 
                       y->parent->right = w;
                    }
                }   
                
                if (y != x) 
                {
                    x->color = y->color;
                    x->data = y->data;
                }
                
                if (y->color == BLACK)
                    FixUpDeletion(w);
            }
        }
        
        void FixUpDeletion (Node *&x) 
        {
            Node *w;
            
            while (x != root && x->color == BLACK) 
            {
                if (x == x->parent->left) 
                {
                    w = x->parent->right;
                    
                    if (w->color == RED) 
                    {                                       
                        //  Case 1
                        w->color = BLACK;
                        x->parent->color = RED;
                        rotateLeft(x->parent);
                        w = x->parent->right;
                    }
                    
                    if (w->right->color == BLACK && w->left->color == BLACK) 
                    {   
                        //  Case 2
                        w->color = RED;
                        x = x->parent;
                    }
                    else 
                    {
                        if (w->right->color == BLACK) 
                        {   
                            //Case 3
                            w->left->color == BLACK;
                            w->color = RED;
                            rotateRight(w);
                            w = x->parent->right;
                        }

                        //Case 4
                        w->color = x->parent->color; 
                        x->parent->color = BLACK;
                        w->right->color = BLACK;
                        rotateLeft(x->parent);
                        x = root;
                    }
                } 

                else 
                {
                    w = x->parent->left;
                    
                    if (w->color == RED) 
                    {
                        w->color = BLACK;
                        x->parent->color = RED;
                        rotateRight(x->parent);
                        w = x->parent->left;
                    }
                    
                    if (w->left->color == BLACK && w->right->color == BLACK) 
                    {
                        w->color = RED;
                        x = x->parent;
                    }
                    else 
                    {
                        if(w->left->color == BLACK) 
                        {
                            w->right->color = BLACK;
                            w->color = RED;
                            rotateLeft(w);
                            w = x->parent->left;
                        }
                        
                        w->color = x->parent->color; 
                        x->parent->color = BLACK;
                        w->left->color = BLACK;
                        rotateRight(x->parent);
                        x = root;
                    }
                }
                
                x->color = BLACK;
                root->color = BLACK;
            }
        }

         Node* search (int wanted) 
        {
            if (root == NULL)
             {
                cout << "Tree is empty!" << endl;
                return  0;
            }
            
            Node* ptr;
            ptr = root;
            int found = 0;
            
            while (ptr != NULL && found == 0) 
            {
                if (ptr->data == wanted) 
                {
                    found = 1;
                }
                
                if (found == 0) 
                {
                    if (wanted < ptr->data)
                    { 
                       ptr = ptr->left;
                    }
                    else
                    { 
                       ptr = ptr->right;
                    }
                }
            }
            
            if (found == 0)
            {
                cout << "Element is not here!" << endl;
                return 0;
            }
            else 
            {
                return ptr;
            }
        }
    

        Node* predecessor (Node *& x) 
        {
            Node* y = new Node;
            
            if (x->left) 
            {
                while (x->left->right)
                { 
                   x->left = x->left->right;
                }
                return x->left;
            }
            
            y = x->parent;
            
            while (y != NULL && x == y->left) 
            {
                x = y;
                y = y->parent;
            }
            
            return y;
        }
        

        Node* successor (Node *&x) 
        {
            Node* y = new Node;
            
            if (x->right) 
            {
                while (x->right->left)
                { 
                   x->right = x->right->left;
                }
                return x->right;
            }
            
            y = x->parent;
            
            while (y != NULL && x == y->right) 
            {
                x = y;
                y = y->parent;
            }

            return y;
        }


        Node* getMinimum() 
        {
            Node* ptr;
            ptr = new Node;
            ptr = root;
            
            while (ptr->left != NULL) 
            {
                ptr = ptr->left;
            }
    
            return ptr;
        }

        Node* getMaximum() 
        {
            Node* ptr;
            ptr = new Node;
            ptr = root;
            
            while (ptr->right != NULL)
            { 
                ptr = ptr->right;
            }
            
            return ptr;
        }
        

        // Function to print a node
        void print (Node *ptr) {
            cout << ptr->data;

            if (ptr->color == BLACK)
               cout << " -> A black node" << endl;
            else
               cout << " -> A red node" << endl;
        }

};


int main () {
    RedBlackTree tree;

    // Search for an element when the tree is empty
    tree.search(44);

    tree.insertRB(5);
    tree.insertRB(12);
    tree.insertRB(25);
    tree.insertRB(1);

    Node* node1;
    node1 = tree.getMinimum();
    cout << "The minimum element: ";
    tree.print(node1);
    
    Node* node2;
    node2 = tree.getMaximum();
    cout << "The maximum element: ";
    tree.print(node2);

    Node* node3;
    node3 = tree.predecessor(node2);
    cout << "The predecessor of the maximum element: ";
    tree.print(node3);

    Node* node4;
    node4 = tree.successor(node1);
    cout << "The successor of the minimum element: ";
    tree.print(node4);

    Node* node5 = new Node;
    node5->data = 5;
    tree.deleteRB(node5);

    Node* node6;
    node6 = tree.successor(node1);
    cout << "Now the successor of the minimum element: ";
    tree.print(node6);



}