// https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/

// use sliding window technique , also template availble in sliding window section of this repo;


int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long i=0;
        long long j=0;
        long long ans =1;
        long long sum=0;
        for(;j<nums.size();j++){
            sum+=nums[j];
            while((((j-i+1)*nums[j])-k)>sum && i<nums.size()){
                sum-=nums[i];
                i++;
            }
            ans = max(j-i+1,ans);
        }
        return ans;
};

int main(){
    vector<int> arr ={1,4,8,13}
    int k = 5;
    cout<<maxFrequency(arr,k)<<endl;
}