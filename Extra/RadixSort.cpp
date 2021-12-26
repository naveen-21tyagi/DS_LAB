#include<iostream>
#include<cmath>
using namespace std;
// considering input to be 0-999
int gD(int N,int pos){
    N/=pow(10,pos-1);
    return N%10;
}
void radixSort(int * arr,int n,int d){
    int C[10],arr_c[n];
    for(int i=1;i<=d;i++){
        fill_n(C,10,0);
        for(int j=0;j<n;j++){
            C[gD(arr[j],i)]++;
        }

        for(int j=1;j<10;j++){
            C[j]+=C[j-1];
        }

        for(int j=n-1;j>-1;j--){
            arr_c[--C[gD(arr[j],i)]]=arr[j];
        }
        for(int j=0;j<n;j++){
            arr[j]=arr_c[j];
        }
    }
}
int main(){
    int n;
    cout << "Enter no. of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    radixSort(arr, n,3);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}