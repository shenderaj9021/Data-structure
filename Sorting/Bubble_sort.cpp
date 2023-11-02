#include<bits//stdc++.h>
using namespace std;
void swap(int &a,int &b){
    int temp = a;
    a =b;
    b = temp;
}
void Bubble_sort(vector<int>&arr){
    
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr.size()-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    return ;
}
int main(){
    vector<int> arr = {6,5,4,3,2,1};
    Bubble_sort(arr);
    for(auto it:arr){
        cout<<it<<" ";
    }
}