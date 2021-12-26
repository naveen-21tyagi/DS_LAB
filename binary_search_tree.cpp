//204251 Naveen Kumar Tyagi
#include <iostream>
using namespace std;

struct node
{
    node *left;
    int data;
    node *right;
};

class BST
{
private:
    node *root = NULL;
    void insert(int x, node *&n)
    {
        if (n == NULL)
        {
            n = new node{NULL, x, NULL};
        }
        else if (x < n->data)
        {
            insert(x, n->left);
        }
        else if (x > n->data)
        {
            insert(x, n->right);
        }
        else
            ; //duplicates are not handled
    }

    int minimum(node *n)
    {
        if (n->left == NULL)
        {
            return n->data;
        }
        return minimum(n->left);
    }
    int maximum(node *n)
    {
        if (n->right == NULL)
        {
            return n->data;
        }
        return maximum(n->right);
    }

    node *search(int x, node *n)
    {
        if (n == NULL)
        {
            return NULL;
        }
        else if (x < n->data)
        {
            return search(x, n->left);
        }
        else if (x > n->data)
        {
            return search(x, n->right);
        }
        else
        { //found
            return n;
        }
    }

    void remove(int x, node *&n)
    {
        if (n == NULL)
        {
            return; //not found
        }
        else if (x < n->data)
        {
            return remove(x, n->left);
        }
        else if (x > n->data)
        {
            return remove(x, n->right);
        }
        else if (n->left != NULL && n->right != NULL)
        { //two children
            n->data = minimum(n->right);
            remove(n->data, n->right);
        }
        else
        {
            node *oldNode = n;
            n = (n->left != NULL) ? n->left : n->right;
            delete oldNode;
        }
    }

    void inOrder(node *n)
    {
        if (n == NULL)
        {
            return;
        }
        inOrder(n->left);
        cout << n->data << " ";
        inOrder(n->right);
    }

public:
    void insert(int x)
    {
        insert(x, root);
    }
    int minimum()
    {
        return minimum(root);
    }
    int maximum()
    {
        return maximum(root);
    }
    bool search(int x)
    {
        return (search(x, root) != NULL);
    }
    int predecessor(int x)
    {
        node *n = search(x, root);

        return maximum(n->left);
    }
    int successor(int x)
    {
        node *n = search(x, root);
        return minimum(n->right);
    }

    void remove(int x)
    {
        remove(x, root);
    }

    void inOrder()
    {
        inOrder(root);
    }
};
int main()
{
    BST T;
    T.insert(21); //               21
    T.insert(35);
    T.insert(5); //        5                 35
    T.insert(23);
    T.insert(18); //    2       18        23         42
    T.insert(14);
    T.insert(42); //         14
    T.insert(2);
    cout << "\n\nTree: ";
    T.inOrder();

    cout << "\nPredecessor of 5 : " << T.predecessor(5);
    cout << "\nSuccecessor of 5 : " << T.successor(5);

    cout << "\nMax: " << T.maximum();
    cout << "\nMin: " << T.minimum();
    cout << (T.search(18) ? "\n\n18 is in tree" : "\n\n18 is not in tree");

    T.remove(5);          //               21
                          //         14                 35
    cout << "\n\nTree: "; //    2       18        23         42
    T.inOrder();
    return 0;
}