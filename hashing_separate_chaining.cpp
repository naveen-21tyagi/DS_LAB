//204251 Naveen Kumar Tyagi
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};
class LL
{
    node *head = NULL;
    int size;

public:
    LL()
    {
        size = 0;
    }
    void insertFront(int x)
    {
        node *nn = new node;
        nn->next = head;
        head = nn;
        nn->data = x;
        size++;
    }
    void insertEnd(int x)
    {
        if (size == 0)
            insertFront(x);
        else
        {
            node *p = head;
            node *nn = new node;
            while (p->next != NULL)
            {
                p = p->next;
            }
            nn->data = x;
            nn->next = NULL;
            p->next = nn;
            size++;
        }
    }

    void deleteVal(int val)
    {
        if (head->data == val)
        {
            head = NULL;
            size--;
        }
        else
        {
            node *p = head;
            node *temp = NULL;
            while (p->next != NULL && p->data != val)
            {
                temp = p;
                p = p->next;
            }
            if (p->data == val)
            {
                temp->next = p->next;
                size--;
            }
        }
    }
    void display()
    {
        node *p = head;
        cout << "--|";
        if (size == 0)
            return;
        while (p->next != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << p->data;
    }
    int search(int val)
    {
        int c = 0;
        node *p = head;
        while (p->data != val && p->next != NULL)
        {
            p = p->next;
            c++;
        }
        if (c == size)
            return -1;
        return c + 1;
    }
};
LL HTable[11];
int HTsize = 11;

int HashF(int key) //constant
{
    return key % HTsize;
}
void insert(int key) //linear
{
    int hI = HashF(key);
    HTable[hI].insertEnd(key);
}
void del(int key) //linear
{
    int hI = HashF(key);
    HTable[hI].deleteVal(key);
}
void search(int key) //linear
{
    int hI = HashF(key);
    int i = HTable[hI].search(key);
    if (i == -1)
        cout << "Not found!.\n";
    else
        cout << key << " found at " << hI << " -> " << i << endl;
}
void displayT()
{
    cout << "\nTABLE\n";
    for (int i = 0; i < 11; i++)
    {
        cout << i;
        HTable[i].display();
        cout << "|" << endl;
    }
}
int main()
{
    insert(12);
    insert(15);
    insert(111);
    insert(99);
    insert(111);
    insert(56);
    insert(831);

    displayT();

    del(15);
    del(99);
    displayT();

    search(111);
    return 0;
}