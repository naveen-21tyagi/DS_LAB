//204251 Naveen Kumar Tyagi
#include <iostream>
#define N 100
using namespace std;

class Stack
{
    int top;
    int arr[N];

public:
    Stack()
    {
        top = -1;
    }
    int peek()
    {
        if (top < 0)
        {
            cout << "Stack is empty.";
            return -1;
        }
        return arr[top];
    }
    int pop()
    {
        if (top < 0)
        {
            cout << "Stack is empty.";
            return -1;
        }
        return arr[top--];
    }
    bool push(int x)
    {
        if (top >= N - 1)
        {
            cout << "Stack is full.";
            return false;
        }
        arr[++top] = x;
        return true;
    }
    bool isEmpty()
    {
        if (top == -1)
            return true;
        return false;
    }
};
int main()
{
    //stack is using int array
    //so ascii values will be stored for characters as int
    //this can be also implementes using char array to implement stack
    Stack st;
    string s;
    cout << "\n\n\nINPUT: ";
    cin >> s;
    int n = s.length();

    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '[')
        {
            st.push(s[i]);
        }

        else if (s[i] == ']')
        {
            if (st.isEmpty())
            {
                flag = false;
                break;
            }
            else if (st.peek() == '[')
            {
                st.pop();
            }
            else
            {
                break;
            }
        }
        else if (s[i] == ')')
        {
            if (st.isEmpty())
            {
                flag = false;
                break;
            }
            else if (st.peek() == '(')
            {
                st.pop();
            }
            else
            {
                break;
            }
        }
    }
    cout << "OUTPUT: ";
    if (st.isEmpty() && flag)
    {
        cout << "Balanced\n\n\n";
    }
    else
    {
        cout << "Not-Balanced\n\n\n";
    }
}
