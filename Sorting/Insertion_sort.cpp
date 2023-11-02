#include<bits//stdc++.h>
using namespace std;

void swap(int &a,int &b){
    int temp =a;
    a = b;
    b = temp;
}
void Insertion_sort(vector<int>&arr){
   for(int i=0;i<arr.size();i++){
        int j =i;
        while(j>0 && arr[j]<arr[j-1]){
            swap(arr[j],arr[j-1]);
            j--;
        }
   }
}
int main(){
    vector<int> arr = {6,5,4,3,2,1};
    Insertion_sort(arr);
    for(auto it:arr){
        cout<<it<<" ";
    }
}