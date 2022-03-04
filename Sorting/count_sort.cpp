#include<iostream>
using namespace std;
void countsort(int arr[],int n){
    int max=0;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    int temp[max+1];
    for(int i=0;i<=max;i++){
        temp[i]=0;
    }
    for(int i=0;i<n;i++){
        temp[arr[i]]++;
    }
    int k=0;
    for(int i=0;i<=max;i++){
        while(temp[i]>0){
            arr[k++]=i;
            temp[i]--;
        }
    }
}
int main(){
    int n;
    cout <<"Eneter size of array"<<endl;
    cin >> n;
    int arr[n];
    cout << "Enter element in array"<<endl;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    countsort(arr,n);
    cout <<"Your sorted array is"<<endl;
    for(int i=0;i<n;i++){
        cout << arr[i]<<endl;
    }
    return 0;
    
}