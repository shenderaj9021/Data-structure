//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

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
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    int fl =-1;
    int cl =-1;
    int l=0;
    int r = n-1;
    sort(arr,arr+n);
    while(l<=r){
        int mid = l+(r-l)/2;
        if(arr[mid]==x){
            fl = x;
            cl =x;
            break;
        }else if(arr[mid]<x){
            fl = arr[mid];
            l = mid+1;
        }else{
            cl = arr[mid];
            r = mid-1;
        }
    }
    return {fl,cl};
}