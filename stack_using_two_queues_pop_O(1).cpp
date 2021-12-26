//204251 Naveen Kumar Tyagi
#include <iostream>
#define N 100
using namespace std;

class Queue
{
public:
    int arr[N], f = -1, l = -1, size = 0;

    void EnQueue(int x)
    {
        if (f == -1 && l == -1)
        {
            f = l = 0;
            arr[l] = x;
            size++;
        }
        else
        {
            arr[++l] = x;
            size++;
        }
    }
    int DeQueue()
    {
        size--;
        return arr[f++];
    }
    bool isEmpty()
    {
        if (size = 0)
            return true;
        return false;
    }
};

Queue q1, q2;

void push(int x)
{
    q2.EnQueue(x);

    if (!q1.isEmpty())
    {
        while (q1.f != q1.l + 1)
        {
            q2.EnQueue(q1.DeQueue());
        }
    }
    q1.f = q1.l = -1;
    swap(q1, q2);
}
void pop()
{
    q1.DeQueue();
}

void display()
{
    int i = q1.l - 1, l = q1.f;
    cout << "\nStack: ";

    while (i != l)
    {
        cout << q1.arr[i--] << " ";
    }
    cout << q1.arr[i] << endl;
}

int main()
{
    push(10);
    push(20);
    push(30);
    pop();
    display();
    push(40);
    push(50);
    display();
    pop();
    pop();
    display();
    return 0;
}