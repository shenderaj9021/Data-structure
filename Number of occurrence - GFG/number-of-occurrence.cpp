//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int lowerbound(int arr[],int n,int x){
	    int ans = n;
	    int l =0;
	    int r = n-1;
	    while(l<=r){
	        int mid= l+(r-l)/2;
	        if(arr[mid]>=x){
	            ans = mid;
	            r=  mid-1;
	        }else{
	            l = mid+1;
	        }
	    }
	    return ans;
	}
		int upperbound(int arr[],int n,int x){
	    int ans = n;
	    int l =0;
	    int r = n-1;
	    while(l<=r){
	        int mid= l+(r-l)/2;
	        if(arr[mid]>x){
	            ans = mid;
	            r=  mid-1;
	        }else{
	            l = mid+1;
	        }
	    }
	    return ans;
	}
	int count(int arr[], int n, int x) {
	    // code here
	    int lb = lowerbound(arr,n,x);
	    if(lb==n || arr[lb]!=x){
	        return 0;
	    }
	    int ub = upperbound(arr,n,x);
	    return ub-lb;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends