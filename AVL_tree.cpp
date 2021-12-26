//204251 Naveen Kumar Tyagi
#include <iostream>
#include <queue> // for levelOrder Traversal
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

struct node
{
    node *left;
    int data;
    node *right;
    int height;
};

class AVL
{
private:
    node *root = NULL;
    int height(node *n)
    {
        if (n == NULL)
            return 0;
        return n->height;
    }

    //function for right rotation
    node *rightRotate(node *y)
    {
        node *x = y->left;
        node *T2 = x->right;

        // rotation
        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    //function for left rotation
    node *leftRotate(node *y)
    {
        node *x = y->right;
        node *T2 = x->left;

        //rotation
        x->left = y;
        y->right = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }
    int balanceF(node *n)
    {
        if (n == NULL)
            return 0;

        return height(n->left) - height(n->right);
    }

    int minimum(node *n)
    {
        if (n->left == NULL)
        {
            return n->data;
        }
        return minimum(n->left);
    }

    void insert(int x, node *&n)
    {
        if (n == NULL)
            n = new node{NULL, x, NULL, 1};

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

        //updating height of node
        n->height = max(height(n->left), height(n->right)) + 1;

        int balF = balanceF(n);

        //tree balancing

        // 1--- LL
        if (balF > 1 && x < n->left->data)
            n = rightRotate(n);

        // 2--- RR
        if (balF < -1 && x > n->right->data)
            n = leftRotate(n);

        // 3--- LR
        if (balF > 1 && x > n->left->data)
        {
            n->left = leftRotate(n->left);
            n = rightRotate(n);
        }
        // 4--- RL
        if (balF < -1 && x < n->right->data)
        {
            n->right = rightRotate(n->right);
            n = leftRotate(n);
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
        // updating height
        if (n != NULL)
            n->height = max(height(n->left), height(n->right)) + 1;

        int balF = balanceF(n);

        //tree balancing

        //1--- LL
        if (balF > 1 && balanceF(n->left) >= 0)
        {
            n = rightRotate(n);
        }

        //2--- RR
        if (balF < -1 && balanceF(n->right) <= 0)
        {
            n = leftRotate(n);
        }

        //3--- LR
        if (balF > 1 && balanceF(n->left) == -1)
        {
            n->left = leftRotate(n->left);
            n = rightRotate(n);
        }

        //4--- RL
        if (balF < -1 && balanceF(n->right) == 1)
        {
            n->right = rightRotate(n->right);
            n = leftRotate(n);
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

    void levelOrder(node *n)
    {
        if (n == NULL)
        {
            return;
        }
        queue<node *> q;
        q.push(n);
        while (q.empty() == false)
        {
            node *nn = q.front();
            cout << nn->data << " ";
            q.pop();

            if (nn->left != NULL)
            {
                q.push(nn->left);
            }
            if (nn->right != NULL)
            {
                q.push(nn->right);
            }
        }
    }

public:
    void insert(int x)
    {
        insert(x, root);
    }

    void remove(int x)
    {
        remove(x, root);
    }
    void inOrder()
    {
        inOrder(root);
    }
    void levelOrder()
    {
        levelOrder(root);
    }
};
int main()
{
    AVL T;
    T.insert(21);
    T.insert(10);
    T.insert(30);
    T.insert(40);
    T.insert(50);
    T.insert(5);
    T.insert(7);
    T.insert(2);
    T.insert(55);

    // ------AVL   TREE------
    //           21
    //     7        -- 40--
    //  5    10     30    50
    // 2                      55

    //  -- 1 on inserting 50 (RR-- 30)
    //  -- 2 on inserting 7  (LR -- L(5),R(10))

    cout << "\ninOrder: ";
    T.inOrder();
    cout << "\nlevelOrder: ";
    T.levelOrder();

    T.remove(40); // deleting 40

    // ------AVL   TREE------
    //           21
    //     7           50
    //  5    10     30    55
    // 2
    cout << "\n\nAfter deleting 40";
    cout << "\ninOrder: ";
    T.inOrder();
    cout << "\nlevelOrder: ";
    T.levelOrder();
}