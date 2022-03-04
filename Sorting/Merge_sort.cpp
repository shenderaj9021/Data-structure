#include<iostream>
using namespace std;
void merge(int arr[], int beg,int mid,int end){
    i
    while(i<=mid && j<end){
        if(arr[i]<arr[j]){
            temp[k++]=arr[i++];
        }else{
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=end){
        temp[k++]=arr[j++];
    }
    for(int i=0;i<7;i++){
        arr[i]=temp[i];
    }
}
void mergesort(int arr[], int beg,int end){
    if(beg<end){
    int mid = ((end+beg)/2)+beg;
    mergesort(arr,beg,mid);
    mergesort(arr,mid+1,end);
    merge(arr,beg,mid,end);
    }

}
int main(){
    int arr[7] = {12,43,5,16,36,11,20};
    mergesort(arr,0,6);
    for(int i=0;i<7;i++){
        cout << arr[i]<<endl;
    }

    return 0;

}