#include<iostream>
#include<map>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n],sum=0;
    map<int,int> mp;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        sum+=arr[i];

        mp[arr[i]]++;
    }

    for(int i=0;i<n-1;i++){
        int n_swaps=0;

        for(int j=0;j<n-1;j++){

            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                n_swaps++;
            }

        }
        if(n_swaps==0) break;
    }

    cout<<"Sorted array:\n";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<"\nSum of array elements "<<sum<<endl;

    cout<<"\nDuplicate Elements:\n";
    
    for(auto pair : mp){
        if(pair.second>1) cout<<pair.first<<endl;
    }

}
