//204251 Naveen Kumar Tyagi
#include <iostream>
using namespace std;
struct node
{
    node *prev;
    int data;
    node *next;
};
node *head = NULL;

class DLL
{
    int size = 0;

public:
    void insertFront(int x)
    {
        node *nn = new node;
        if (head == NULL)
        {
            head = nn;
            nn->next = NULL;
            nn->prev = NULL;
            nn->data = x;
        }
        else
        {
            nn->next = head;
            head->prev = nn;
            nn->prev = NULL;
            head = nn;
            nn->data = x;
        }
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
        nn->prev = p;
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
        nn->prev = p;
        if (nn->next != NULL)
            nn->next->prev = nn;
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
        nn->prev = p;
        if (nn->next != NULL)
            nn->next->prev = nn;
        cout << x << " is inserted.\n";
        size++;
    }
    void deleteFront()
    {
        cout << head->data << " is deleted.\n";
        head = head->next;
        head->prev = NULL;
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
        int cnt = 1;
        while (p->next != NULL && cnt < pos)
        {
            p = p->next;
            cnt++;
        }
        if (cnt != pos)
        {
            cout << "Key not found.\n";
        }
        else
        {
            p->prev->next = p->next;
            if (p->next != NULL)
                p->next->prev = p->prev;
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
            p = p->next;
            p->prev->next = p->next;
            if (p->next != NULL)
                p->next->prev = p->prev;
            cout << p->data << " is deleted.\n";
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
    DLL list;
    list.insertFront(21);
    list.insertFront(2);
    list.insertEnd(34);
    list.insertAt(99, 2);
    list.insertVal(77, 34); //insert 77 after 34
    list.display();
    list.deleteFront();
    list.deleteEnd();
    list.display();
    list.insertFront(333);
    list.insertFront(66);
    list.insertFront(30);
    list.display();
    list.deleteAt(3);
    list.deleteVal(66); // delete element which is after 66
    list.display();
    list.search(21);
    return 0;
}