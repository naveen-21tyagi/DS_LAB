//204251 Naveen Kumar Tyagi
#include <iostream>
using namespace std;

struct node
{
    node *left;
    char data;
    node *right;
};

node *head = NULL;

class DLL
{
    int n_nodes = 0;

public:
    void InsertInSortedOrder(char ch)
    {
        node *n = new node;
        n->data = ch;

        if (head == NULL)
        {
            n->left = NULL;
            n->right = NULL;
            head = n;
            n_nodes++;
        }
        else
        {
            node *temp = head;
            while (temp != NULL)
            {
                if (ch <= temp->data)
                {
                    n->left = temp->left;
                    n->right = temp;
                    temp->left = n;
                    if (n->left != NULL)
                    {
                        n->left->right = n;
                    }
                    n_nodes++;
                    if (temp == head)
                    {
                        head = n;
                    }
                    break;
                }
                // else{
                //     n->right=temp->right;
                //     n->left=temp;
                //     temp->right=n;
                //     if(n->right!= NULL){
                //         n->right->left=n;
                //     }
                //     n_nodes++;
                // }
                if (temp->right != NULL)
                    temp = temp->right;
                else
                {
                    temp->right = n;
                    n->left = temp;
                    n->right = NULL;
                }
            }
        }
    }
    void DeleteEnd()
    {
        node *p = head;
        if (n_nodes == 1)
        {
            cout << head->data << "\n";
            n_nodes = 0;
            head = NULL;
        }
        else
        {
            while (p->right->right != NULL)
            {
                p = p->right;
            }
            cout << p->right->data << endl;
            p->right = NULL;
            n_nodes--;
        }
    }
    void print()
    {
        node *p = head;
        cout << "List: ";
        while (p->right != NULL)
        {
            cout << p->data << " ";
            p = p->right;
        }
        cout << p->data << endl;
    }
    bool isEmpty()
    {
        if (n_nodes == 0)
            return true;
        return false;
    }
    int size()
    {
        return n_nodes;
    }
};

class pr_queue
{
    DLL L;

public:
    void enqueue(char ch)
    {
        L.InsertInSortedOrder(ch);
    }

    void dequeue()
    {
        L.DeleteEnd();
    }
};

int main()
{
    pr_queue q;
    int x = 0;
    char ch;
    do
    {
        cout << "1. EnQueue 2. DeQueue 3. EXIT : ";
        cin >> x;
        switch (x)
        {
        case 1:
            cout << "EnQueue: ";
            cin >> ch;
            q.enqueue(ch);
            break;

        case 2:
            cout << "DeQueued: ";
            q.dequeue();
            break;

        default:
            break;
        }
    } while (x < 3);
    return 0;
}