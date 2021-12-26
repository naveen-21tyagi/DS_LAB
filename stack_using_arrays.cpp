//204251 Naveen Kumar Tyagi
#include<iostream>
#define N 100
using namespace std;

class Stack{
    int top;
    int arr[N];

    public:
    Stack(){
        top=-1;
    }
    int peek(){
        if(top<0){
            cout<<"Stack is empty.";
            return -1;
        }
        return arr[top];
    }
    int pop(){
        if(top<0){
            cout<<"Stack is empty.";
            return -1;
        }
        return arr[top--];
    }
    bool push(int x){
        if(top>=N-1){
            cout<<"Stack is full.";
            return false;
        }
        arr[++top]=x;
        cout<<x<<" pushed into stack."<<endl;
        return true;
    }
    bool isEmpty(){
        if(top==-1) return true;
        return false;
    }
    int count(){
        return top+1;
    }
    void print(){
        int i=top;
        cout<<"Elements in stack: ";
        while(i>=0){
            cout<<arr[i--]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    Stack S;
    int a,b,c;
    cout<<"Enter element to push into stack: ";
    cin>>a;
    S.push(a);
    cout<<"Enter element to push into stack: ";
    cin>>b;
    S.push(b);
    cout<<"Enter element to push into stack: ";
    cin>>c;
    S.push(c);
    cout<<"\nTop element: "<<S.peek()<<endl;
    cout<<S.pop()<<" is popped from stack.\n";
    S.print();
    cout<<"NO. of elements in stack: "<<S.count()<<endl;
}