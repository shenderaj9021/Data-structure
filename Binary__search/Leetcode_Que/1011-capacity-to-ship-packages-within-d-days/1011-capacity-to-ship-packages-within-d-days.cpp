class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        long long high = 1e9;
        
        long long low = *max_element(weights.begin(),weights.end());
        long long ans =LONG_MAX;
        while(low<=high){
            long long mid = (high+low)/2;
            long long curr=0;
            long long gcurr=0;
            cout<<mid<<endl;
            for(int i=0;i<weights.size();i++){
                curr+=weights[i];
                if(curr>mid){
                    gcurr++;
                    curr = weights[i];
                }
               
            }
             if(curr>0){
                    gcurr++;
                }
            if(gcurr<=days){
                ans = min(ans,mid);
                high = mid-1;
            }else{
                low = mid+1;
            }
            
        }
        return ans;
        
    }
};