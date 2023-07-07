//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int nums[], int n) {
	    // code here
	    int l =0;
	    int r = n-1;
	    int ans = INT_MAX;
	    int ind =-1;
	    while(l<=r){
	        int mid = l+(r-l)/2;
	        if(nums[l]<=nums[r]){
	            if(ans>nums[l]){
	                ans = nums[l];
	                ind = l;
	                break;
	            }
	        }
	       if(nums[l]<=nums[mid]){
	           if(ans>nums[l]){
	               ans =nums[l];
	                ind =l;
	           }
	             l = mid+1;
	       }else{
	           if(ans>nums[mid]){
	               ans = nums[mid];
	               ind = mid;
	           }
	           r = mid-1;
	       }
	   }
	   return ind;
	 }
	    
	

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends