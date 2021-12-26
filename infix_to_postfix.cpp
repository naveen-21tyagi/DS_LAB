//204251 Naveen Kumar Tyagi
#include<iostream>
#define N 100
using namespace std;

class Stack{
    int top;
    char arr[N];

    public:
    Stack(){
        top=-1;
    }
    char peek(){
        if(top<0){
            return '$';
        }
        return arr[top];
    }
    char pop(){
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
    int priority(char ch){
	    switch(ch){
            case '/':
                return 2; break;
            case '*': 
                return 2; break;
            case '+':
                return 1; break;
            case '-': 
                return 1; break;
            default: return 0;
	    }
    }
    void print(){
        int i=top;
        while(i>=0){
            cout<<arr[i--];
        }
        cout<<endl;
    }
};


int main()
{
	Stack S;
	string exp;
	
	cout<<"Enter infix expression: ";
	cin>>exp;
    int size=exp.length();
	
    cout<<"Postfix expression: ";
	for (int i=0;i<size; i++){

		if(isalpha(exp[i])){
			cout<<exp[i];
		}
		
		else if (exp[i]=='('){
			S.push(exp[i]);
		}
		
		else if (exp[i]==')'){
            char ch;
			while (ch=S.pop()){
                if(ch=='(') break;
				cout<<ch;
			}
		}
		
		else if(exp[i]=='*' || exp[i]=='/' || exp[i]=='+' || exp[i]=='-'){
			char ch1=S.peek(); 
			char ch2=exp[i];
			
			if(S.priority(ch1)<S.priority(ch2)){
				S.push(exp[i]);
			}
			
			else {
				while(S.priority(ch1)>=S.priority(ch2)){
						cout<<S.pop();
						ch1=S.peek();		
				}
				S.push(ch2);
			}
		}
	}
    S.print();
	return 0;
}
