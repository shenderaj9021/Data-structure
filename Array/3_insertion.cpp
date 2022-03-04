#include<iostream>
using namespace std;
int main(){
    int n =5;
    int arr[n];
    cout << "Enter array"<<endl;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << "your array is"<<endl;
    for(int i=0;i<n;i++){
        cout << arr[i]<<"  ";
    }
    int p,q;
    cout << "Enter element and position of element you want to delete"<<endl;
    cin >> p>>q;
    n++;
    for(int i=n-1;i>q;i--){
        cout << arr[i]<<arr[i-1]<<endl;
        arr[i]=arr[i-1];
        
    }
    arr[q]= p;
    for(int i=0;i<n;i++){
        cout << arr[i]<<"  ";
    }
}