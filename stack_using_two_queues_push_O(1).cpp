//204251 Naveen Kumar Tyagi
#include <iostream>
#define N 100
using namespace std;

class Queue
{
public:
    int arr[N], f = -1, l = -1;

    void EnQueue(int x)
    {
        if (f == -1 && l == -1)
        {
            f = l = 0;
            arr[l] = x;
        }
        else
        {
            arr[++l] = x;
        }
    }
    int DeQueue()
    {
        return arr[f++];
    }
};

Queue q1, q2;

void push(int x)
{
    q1.EnQueue(x);
}
void pop()
{
    while (q1.f != q1.l)
    {
        q2.EnQueue(q1.DeQueue());
    }
    cout << q1.arr[q1.f] << " is popped.\n";
    q1.f = q1.l = -1;
    swap(q1, q2);
}

void display()
{
    int i = q1.f, l = q1.l;
    cout << "\nStack: ";

    while (i != l)
    {
        cout << q1.arr[i++] << " ";
    }
    cout << q1.arr[i] << endl;
}

int main()
{
    push(1);
    push(2);
    display();
    push(3);
    push(4);
    display();
    pop();
    pop();
    display();
    return 0;
}