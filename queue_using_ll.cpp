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
node *top = NULL;
class DLL
{
public:
    void insertEnd(int x)
    {
        if (head == NULL)
        {
            head = new node;
            head->data = x;
            head->next = head->prev = NULL;
            top = head;
        }
        else
        {
            node *temp = new node;
            top->next = temp;
            temp->prev = top;
            temp->next = NULL;
            temp->data = x;
            top = temp;
        }
        cout << x << " is enqueued.\n";
    }
    void deleteFront()
    {
        cout << head->data << " is dequeued.\n";
        head = head->next;
        if (head != NULL)
            top->prev = NULL;
    }
    void display()
    {
        node *p = head;
        cout << "Queue: ";
        if (head != NULL)
        {
            while (p->next != NULL)
            {
                cout << p->data << " ";
                p = p->next;
            }
            cout << p->data << endl;
        }
        else
            cout << "Empty.\n";
    }
};
DLL list;
void Enqueue(int x)
{
    list.insertEnd(x);
}
void Dequeue()
{
    list.deleteFront();
}
void print()
{
    list.display();
}
int main()
{
    Enqueue(21);
    Enqueue(2);
    Enqueue(5);
    Enqueue(9);
    print();
    Dequeue();
    Dequeue();
    Dequeue();
    print();
    return 0;
}