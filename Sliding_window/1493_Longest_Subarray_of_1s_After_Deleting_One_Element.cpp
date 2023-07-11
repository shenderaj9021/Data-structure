// 1493. Longest Subarray of 1's After Deleting One Element
//https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/


/* Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

 */

#include <bits//stdc++.h>
using namespace std;
  int longestSubarray(vector<int>& nums) {
        int i=0;
        int j=0;
        int sum=0;
        int ans =0;
        for(;j<nums.size();j++){
            if(nums[j]==0){
                sum++;
            }
            while(sum>1 && i<=j){
                if(nums[i]==0){
                    sum--;
                }
                i++;
            }
            ans= max(ans,j-i+1);
        }
        return ans-1;
    }

int main(){
    vector<int> nums = {1,1,0,1};
       cout<<longestSubarray(nums)<<endl;
 
}