#include<iostream>
using namespace std;

int main(){
    int a;
    cout<<"Give element to search from: 5 4 7 6 8 9 10 11 12 14 ";
    cin>>a;
    int arr[10]={5,4,7,6,8,9,10,11,12,14};
    for(int i=0;i<10;i++){
        if(arr[i]==a){
            cout<<"Element "<<a<<" found at position: "<<i;
        }
    }
    int b=15;
    for(int i=0;i<10;i++){
        if(arr[i]<b){
            b=arr[i];
        }
    }
    cout<<"\nSmallest element is : "<<b;
}