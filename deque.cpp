// 204251 Naveen Kumar Tyagi
#include<iostream>
#define N 100
using namespace std;

class deQueue{
    int arr[N],f=-1,l=-1,size=0;
    
    public:
    void EnFront(int x){          //insert at front
        if(size==N){
            cout<<"Queue is full.\n";
        }
        else if(f==-1 && l==-1){
            f=l=0;
            arr[f]=x;
            size++;
            cout<<x<<" is enqueued.\n";
        }
        else{
            f--;
            if(f==-1) f=N-1;
            arr[f]=x;
            size++;
            cout<<x<<" is enqueued.\n";
        }
    }

    void EnRear(int x){         //insert at back
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

    void DeRear(){                 //remove from back
        if(size==0){
            cout<<"Queue is empty.\n";
        }
        else{
            cout<<arr[l--]<<" is dequeued.\n";
            if(l==-1) l=N-1;
            size--;
            if(size==0) f=l=-1;
        }
    }

    void DeFront(){                  //remove from front
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
        cout<<"\n\nQueue: ";

        while(i!=l){
            cout<<arr[i]<<" ";
            i=(i+1)%N;
        }

        cout<<arr[i]<<endl;
    }
};
int main(){
    int c=0,x;
    deQueue q;
    while(c<6){
		cout<<"\nEnter:\n";
        cout<<"1. Insert at front   2. Insert at back\n";
        cout<<"3. Remove from first   4. Remove from back\n";
        cout<<"5. Print Queue   6. Exit \nInput: ";
		cin>>c;
		switch(c){
			case 1: 
                cout<<"Enter element: "; 
                cin>>x; q.EnFront(x); 
                break;
            case 2: 
                cout<<"Enter element: "; 
                cin>>x; q.EnRear(x); 
                break;
			case 3: 
                q.DeFront(); 
                break;
            case 4: 
                q.DeRear(); 
                break;
			case 5: 
                q.display(); 
                break;
		}
	}
    return 0;
}