/* Question -  Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

*/

// Deutche national flag  algorith is used to solve this 

#include<bits//stdc++.h>
using namespace std;
void swap(int &a,int &b){
    int temp  =a;
    a = b;
    b = temp;
}
int main(){
    vector<int> arr = {0,1,1,0,2,0,1,2,0,0,1,2};
    int high = 12-1;   // n-1
    int low = 0;
    int mid =0;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }else if(arr[mid]==1){
            mid++;
        }else{
            swap(arr[mid],arr[high]);
                high--;
            
        }

    }
    for(auto it:arr){
        cout<<it<<" ";
    }
    cout<<endl;

}