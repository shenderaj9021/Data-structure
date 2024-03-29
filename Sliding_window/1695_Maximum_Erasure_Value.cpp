// 1695. Maximum Erasure Value
// https://leetcode.com/problems/maximum-erasure-value/description/

/* You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

Return the maximum score you can get by erasing exactly one subarray.

An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).
*/
#include <bits//stdc++.h>
using namespace std;
 int maximumUniqueSubarray(vector<int>& nums) {
        int i=0;
        int j=0;
        int sum=0;
        int ans=0;
        map<int,int> mp;
        for(;j<nums.size();j++){
            mp[nums[j]]++;
            sum+=nums[j];
            while(mp[nums[j]]>1){
                mp[nums[i]]--;
                sum-=nums[i];
                i++;
            }
            ans = max(ans,sum);
        }
        return ans;
    }
int main(){
    vector<int>  nums = {4,2,4,5,6};
    cout<<maximumUniqueSubarray(nums)<<endl;
}