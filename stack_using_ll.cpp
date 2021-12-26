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
        cout << x << " is pushed.\n";
    }
    void deleteEnd()
    {
        cout << top->data << " is popped.\n";
        top = top->prev;
        if (top != NULL)
            top->next = NULL;
        else
            head = NULL;
    }
    void display()
    {
        node *p = head;
        cout << "Stack: ";
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
void push(int x)
{
    list.insertEnd(x);
}
void pop()
{
    list.deleteEnd();
}
void print()
{
    list.display();
}
int main()
{
    push(7);
    push(2);
    push(4);
    push(6);
    print();
    pop();
    pop();
    pop();
    print();
    return 0;
}