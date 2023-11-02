#include<bits//stdc++.h>
using namespace std;

void swap(int &a,int &b){
    int temp = a;
     a =b;
     b = temp;
}
int partition(vector<int>&arr,int low,int high){
    int pivot = arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    i++;
    swap(arr[i],arr[high]);
    return i;
}

void Quick_sort(vector<int>& arr,int low,int high){
    if(low<high){
        int pidx = partition(arr,low,high);
        Quick_sort(arr,low,pidx-1);
        Quick_sort(arr,pidx+1,high);
    }
}

int main(){
    vector<int> arr ={8,4,5,2,7,9,1,3};
    Quick_sort(arr,0,arr.size()-1);
    for(auto it:arr){
        cout<<it<<" ";
    }
    return 0;
}