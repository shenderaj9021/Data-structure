class Solution {
public:

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,1);
        dp[0] =0;
        for(int i=1;i<=n;i++){
            dp[i] = nums[i-1];
            for(int j=0;j<i-1;j++){
                dp[i] = max(dp[i],nums[i-1]+dp[j]);
            }
           
        }
        for(auto it:dp){
            cout<<it<<" ";
        }
        return max(dp[n],dp[n-1]);
        
    }
};