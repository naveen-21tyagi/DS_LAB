#include<iostream>
using namespace std;

class ComplexNo{
    public:
    int real,img;

    ComplexNo(int r, int i){
        real=r;
        img=i;
    }
    
    void disp(){
        if(img<0) cout<<real<<" "<<img<<"i"<<endl;
        else cout<<real<<" + "<<img<<"i"<<endl;
    }
    
};


void add(ComplexNo A,ComplexNo B){
        ComplexNo ans(A.real+B.real , A.img+B.img);
        ans.disp();
    }

void subtract(ComplexNo A,ComplexNo B){
        ComplexNo ans(A.real-B.real , A.img-B.img);
        ans.disp();
    }

void multiply(ComplexNo A,ComplexNo B){
    int ansR=A.real*B.real - A.img*B.img, ansI=A.real*B.img + A.img*B.real;
    ComplexNo ans(ansR,ansI);
    ans.disp();
}

void multiplyS(ComplexNo A, int n){
    A.real*=n;
    A.img*=n;
    A.disp();
}  

int main(){
    int a1,b1,a2,b2,n;
    cout<<"Enter real part of first complex no: ";
    cin>>a1;
    cout<<"Enter imaginary part of first complex no: ";
    cin>>b1;
    cout<<"Enter real part of second complex no: ";
    cin>>a2;
    cout<<"Enter imaginary part of second complex no: ";
    cin>>b2;
    cout<<"Enter scalar value by which first complex no. should be multiplied: ";
    cin>>n;

    ComplexNo C1(a1,b1),C2(a2,b2);

    cout<<"Addition\n";
    add(C1,C2);
    cout<<"Subtraction\n";
    subtract(C1,C2);
    cout<<"Multiplication\n";
    multiply(C1,C2);
    cout<<"Multiplicaton with Scalar\n";
    multiplyS(C1,n);

    return 0;
}