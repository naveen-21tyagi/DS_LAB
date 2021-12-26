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
        return true;
    }
    bool isEmpty(){
        if(top==-1) return true;
        return false;
    }
    bool isfull(){
        if(top==N-1){
            return true;
        }
        return false;
    }
};
 
Stack s1,s2;

void enQueue(int x){
	while(!s1.isEmpty()){
        int n=s1.pop();
		s2.push(n);
	}
	
	s1.push(x);
	
	while(!s2.isEmpty()){
        int n=s2.pop();
		s1.push(n);
	}
}

int deQueue(){
	if(s1.isEmpty()){
		cout<<"Queue is empty \n";
	}
	int n = s1.pop();
	return n;
}
int main(){
    int q=0,n;

	while(q<3){
		cout<<"Enter:\n1->Enqueue\n2->Dequeue\n3->Exit\n";
		cin>>q;
		
		switch(q){
			case 1: 
                if(s1.isfull())
                cout<<"Queue is full"<<endl;
                else{
                    cout<<"Enter element to be pushed: ";
                    cin>>n;
                    enQueue(n);
                }		   		   
			break;
			
			case 2: 
			    cout<<"Dequeued element: "<<deQueue()<<"\n\n";
			break;	
		}
	}
}