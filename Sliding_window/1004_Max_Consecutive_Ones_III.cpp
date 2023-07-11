// 1004. Max Consecutive Ones III
// https://leetcode.com/problems/max-consecutive-ones-iii/description/

#include <bits//stdc++.h>
using namespace std;
  int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int j =0; 
        int count =0;
        int ans =0;
        int i=0;
       while(j<n){
           if(nums[j]==0){
               count++;
           }
           while(count>k && i<n){
               if(nums[i]==0){
                   count--;
               }
               i++;
           }

           ans = max(ans,j-i+1);
           j++;
       }
        
        return ans;
    }
int main(){
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0} ;
    int k = 2;
    cout<<longestOnes(nums,k)<<endl;
}