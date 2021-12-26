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
        return true;
    }
    bool isEmpty(){
        if(top==-1) return true;
        return false;
    }
};

int main()
{
	Stack S;
	
	string exp;
    cout<<"Enter postfix expression: ";
    cin>>exp;
	
	int size=exp.length();
	
	for (int i=0;i<size;i++){
		if ((exp[i]>='0') && (exp[i]<='9')){
			S.push(exp[i]-'0');
		}
		
		else{
			if (exp[i]=='+'){
	        	int v1=S.pop();
	        	int v2=S.pop();
	        	S.push(v1+v2);
	        } 
	
	        if (exp[i]=='-'){
	        	int v1=S.pop();
		        int v2=S.pop();
	        	S.push(v2-v1);
	        }
	
         	if (exp[i]=='*'){
	        	int v1=S.pop();
	        	int v2=S.pop();
	        	S.push(v1*v2);
        	}  
	
	        if (exp[i]=='/'){
	        	int v1=S.pop();
		        int v2=S.pop();
	  	        S.push(v2/v1);
        	} 
		}
	}
	
	cout<<"Value after evaluating Postfix expression = "<<S.peek();
	return 0;
}
