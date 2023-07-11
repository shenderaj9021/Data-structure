class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        long long high = 1e6+1;
        long long low = 1;
        long long ans =LONG_MAX;
        while(low<=high){
            long long mid = (low+high)/2;
            long long count =0;
            for(int i=0;i<nums.size();i++){
                count+= ceil((double)nums[i]/(double)mid);
            }
      
            if(count<=threshold){
         
                ans = min(ans,mid);
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};