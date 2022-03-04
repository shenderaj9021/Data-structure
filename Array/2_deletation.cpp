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
    int p;
    cout << "Enter position of element you want to delete"<<endl;
    cin >> p;
    for(int i=p;i<n;i++){
        arr[p]=arr[p+1];
    }
    n--;
    for(int i=0;i<n;i++){
        cout << arr[i]<<"  ";
    }
}