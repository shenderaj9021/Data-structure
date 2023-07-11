class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long high = 1e9+1;   
        // for(auto it:bloomDay){
        //     high  = max(high,(long long)it);
        // }
        // high++;
        long long low =1;
        long long ans =LONG_MAX;
        while(low<=high){
            long long  mid = (low+high)/2;
            int curr =0;
            int gcurr =0;
            for(int i=0;i<bloomDay.size();i++){
                if(bloomDay[i]<=mid){
                    curr++;
                }else{
                    curr=0;
                }
                if(curr==k){
                    gcurr++;
                    curr=0;
                }
                if(gcurr==m){
                    break;
                }
            }
            if(gcurr==m){
                ans = min(ans,mid);
            }
            if(gcurr>=m){
                high = mid-1;
            }else{
                low = mid+1;
            }
            
        }
        if(ans==LONG_MAX){
            return -1;
        }else{
            return ans;
        }
    }
};