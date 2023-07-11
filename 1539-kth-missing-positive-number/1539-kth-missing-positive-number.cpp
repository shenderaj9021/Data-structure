class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start = 0, end = arr.size()-1, mid = start+(end-start)/2;
        while(start<=end)
        {
            if(arr[mid] >= k+mid+1)
                end = mid-1;
            else
                start = mid+1;
            mid = start+(end-start)/2;
        }
        return k+start;
    }
};