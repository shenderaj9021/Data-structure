//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        int pref =0;
        map<int,int> mp;
        int l =0;
        for(int i=0;i<N;i++){
            pref+=A[i];
            int need = pref-K;
            if(need==0){
                l =max(l,i+1);
            }
            if(mp.find(need)!=mp.end()){
                l = max(l,i-mp[need]);
            }
            if(mp.find(pref)==mp.end()){
                mp[pref] = i;
            }
        }
        return l;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends