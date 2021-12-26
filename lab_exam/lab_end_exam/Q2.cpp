//204251 Naveen Kumar Tyagi
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node
{
    node *left;
    int data;
    node *right;
    int n_chl;
};

class BST
{
public:
    int nodes = 0;
    node *root = NULL;

private:
    void insert(int x, node *&n)
    {
        if (n == NULL)
        {
            n = new node{NULL, x, NULL, 0};
        }
        else if (x < n->data)
        {
            n->n_chl++;
            insert(x, n->left);
        }
        else if (x > n->data)
        {
            n->n_chl++;
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

    void DisplayNodes(node *n)
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
    void DisplayNodes()
    {
        DisplayNodes(root);
    }

    vector<int> CountChildren(node *n)
    {
        vector<int> arr;
        queue<node *> q;
        q.push(n);
        while (q.empty() == false)
        {
            node *nn = q.front();
            // cout<<nn->data<<" ";
            arr.emplace_back(nn->n_chl);
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
        return arr;
    }

    vector<int> CountSibling(node *n)
    {
        vector<int> arr;

        arr.emplace_back(0); // for root node

        queue<node *> q;
        q.push(n);
        while (q.empty() == false)
        {
            node *nn = q.front();
            // cout<<nn->data<<" ";

            if (nn->left != NULL && nn->left != NULL)
            {
                arr.emplace_back(1);
                arr.emplace_back(1);
                // 1 for both child
            }
            else if (nn->left == NULL && nn->right == NULL)
            {
                // do nothing
            }
            else
            {
                arr.emplace_back(0);
                // no sibling for single child
            }
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
        return arr;
    }
};

int main()
{
    BST T;
    cout << "Enter no. of nodes: ";
    cin >> T.nodes;
    int n;
    cout << "Enter nodes: ";
    for (int i = 0; i < T.nodes; i++)
    {
        cin >> n;
        T.insert(n);
    }

    cout << "\n\nTREE in level order\n";
    T.DisplayNodes();

    cout << "\n\nNo. of children of each node in present in level wise\n";
    vector<int> arr = T.CountChildren(T.root);
    for (int i = 0; i < T.nodes; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n\n\nNo. of sibling of each node in present in level wise\n";
    arr = T.CountSibling(T.root);
    for (int i = 0; i < T.nodes; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n\n";
}