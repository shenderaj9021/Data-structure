#include<iostream>
using namespace std;
//array is sequential data structure
int main(){
    int arr[5];
    for(int i=0;i<5;i++){
        cin >> arr[i];
    }
    cout << "Given array is"<<endl;
    for(int i=0;i<5;i++){
        cout << arr[i]<<endl;
    }
}