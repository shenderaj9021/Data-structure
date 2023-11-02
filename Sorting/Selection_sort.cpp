#include<bits//stdc++.h>
using namespace std;


void swap(int &a,int &b){
    int temp = a;
    a =b;
    b = temp;
}
void Selection_sort(vector<int>&arr){
     int mi;
    for(int i=0;i<arr.size();i++){
        mi = i;
        for(int j=i+1;j<arr.size();j++){
            if(arr[mi]>arr[j]){
                mi =j;
            }
        }
        int temp = arr[mi];
        arr[mi] = arr[i];
        arr[i] = temp;
    }
    return ;
}
int main(){
    vector<int> arr = {6,5,4,3,2,1};
    Selection_sort(arr);
    for(auto it:arr){
        cout<<it<<" ";
    }
}