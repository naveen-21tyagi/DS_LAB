//204251 Naveen Kumar Tyagi
#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *head = NULL;

class LL
{
    int size = 0;

public:
    void insertFront(int x)
    {
        node *nn = new node;
        nn->next = head;
        head = nn;
        nn->data = x;
        cout << x << " is inserted.\n";
        size++;
    }
    void insertEnd(int x)
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
        cout << x << " is inserted.\n";
        size++;
    }
    void insertAt(int x, int pos)
    {
        node *p = head;
        node *nn = new node;
        int cnt = 1;
        while (p->next != NULL && cnt + 1 < pos)
        {
            p = p->next;
            cnt++;
        }
        nn->data = x;
        nn->next = p->next;
        p->next = nn;
        cout << x << " is inserted.\n";
        size++;
    }
    void insertVal(int x, int val)
    {
        node *p = head;
        node *nn = new node;
        while (p->next != NULL && p->data != val)
        {
            p = p->next;
        }
        nn->data = x;
        nn->next = p->next;
        p->next = nn;
        cout << x << " is inserted.\n";
        size++;
    }

    void deleteFront()
    {
        cout << head->data << " is deleted.\n";
        head = head->next;
        size--;
    }
    void deleteEnd()
    {
        node *p = head;
        while (p->next->next != NULL)
        {
            p = p->next;
        }
        cout << p->next->data << " is deleted.\n";
        p->next = NULL;
        size--;
    }
    void deleteAt(int pos)
    {
        node *p = head;
        node *pr;
        int cnt = 1;
        while (p->next != NULL && cnt < pos)
        {
            pr = p;
            p = p->next;
            cnt++;
        }
        if (cnt != pos)
        {
            cout << "Key not found.\n";
        }
        else
        {
            pr->next = p->next;
            cout << p->data << " is deleted.\n";
        }
        size--;
    }
    void deleteVal(int val)
    {
        node *p = head;
        while (p->next != NULL && p->data != val)
        {
            p = p->next;
        }
        if (p->next == NULL)
        {
            cout << "Last element, no element can be deleted.\n";
        }
        else
        {
            cout << p->next->data << " is deleted.\n";
            p->next = p->next->next;
        }
        size--;
    }
    void display()
    {
        node *p = head;
        cout << "List: ";
        while (p->next != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << p->data << endl;
    }
    void search(int val)
    {
        int c = 0;
        node *p = head;
        while (p->data != val && p->next != NULL)
        {
            p = p->next;
            c++;
        }
        if (c == size)
            cout << "Not found!\n";
        else
            cout << val << " found at " << c + 1 << endl;
    }
};
int main()
{
    LL list;
    list.insertFront(21);
    list.insertEnd(546);
    list.insertAt(99, 2);
    list.insertVal(27, 99); //insert 27 after 99
    list.display();
    list.deleteFront();
    list.deleteEnd();
    list.display();
    list.insertFront(42);
    list.insertFront(0);
    list.display();
    list.deleteAt(3);
    list.deleteVal(42); // delete element which is after 42
    list.display();
    list.search(42);
    return 0;
}