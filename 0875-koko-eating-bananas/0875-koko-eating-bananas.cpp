class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low =1;
        long long high=0;
        for(auto it:piles){
            high+=it;
            
        }
        high++;
      
        long long  ans = LONG_MAX;
        while(low<=high){
            long long mid = (high+low)/2;
            int hours =0;
            for(int i=0;i<piles.size();i++){
                hours+=ceil(double(piles[i])/(double(mid))); 
            }
            if(hours<=h){
                ans = min(ans,mid);
            }
            if(hours>h){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
};