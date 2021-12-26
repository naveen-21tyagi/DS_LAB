//204251 Naveen Kumar Tyagi
#include<iostream>
#define N 3
using namespace std;

class Queue{
    int arr[N],size=0,f=-1,l=-1;
    //size = no. of elements

    public:
    void EnQueue(int x){
        if(size==N){
            cout<<"Queue is full.\n";
        }
        else if(f==-1 && l==-1){
            f=l=0;
            arr[l]=x;
            size++;
            cout<<x<<" is enqueued.\n";
        }
        else{
            l=(l+1)%N;
            arr[l]=x;
            size++;
            cout<<x<<" is enqueued.\n";
        }
    }
    void DeQueue(){
        if(size==0){
            cout<<"Queue is empty.\n";
        }
        else{
            cout<<arr[f]<<" is dequeued.\n";
            f=(f+1)%N;
            size--;
            if(size==0) f=l=-1;
        }
    }


    void display(){
        int i=f;
        cout<<"Queue: ";

        while(i!=l){
            cout<<arr[i]<<" ";
            i=(i+1)%N;
        }

        cout<<arr[i]<<endl;
    }

};
int main(){
	int c=0,x;
    Queue q;
    while(c<4){
		cout<<"\nEnter: 1. EnQueue  2. DeQueue  3. Print Queue 4. Exit \nInput: ";
		cin>>c;
		switch(c){
			case 1: 
                cout<<"Enter element: "; 
                cin>>x; q.EnQueue(x); 
                break;
			case 2: 
                q.DeQueue(); 
                break;
			case 3: 
                q.display(); 
                break;
		}
	}
	return 0;
}
