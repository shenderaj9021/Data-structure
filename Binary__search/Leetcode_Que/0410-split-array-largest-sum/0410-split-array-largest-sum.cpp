class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long high =0;
        for(auto it:nums){
            high+=it;
        }
        long long low =*max_element(nums.begin(),nums.end());
        long long ans = LONG_MAX;
        while(low<=high){
            long long mid = (low+high)/2;
            long long curr =0;
            long long gcurr =0;
            for(int i=0;i<nums.size();i++){
                curr+=nums[i];
                if(curr>mid){
                    cout<<curr<<endl;
                    gcurr++;
                    curr = nums[i];
                }
               
            }
             if(curr>0){
                    gcurr++;
                    curr =0;
                }
            cout<<mid <<"  "<<gcurr<<endl;
          
            if(gcurr<=k){
                high = mid-1;
                 ans = min(ans,mid);
            }else{
                low= mid+1;
            }
        }
        return ans;
    }
};