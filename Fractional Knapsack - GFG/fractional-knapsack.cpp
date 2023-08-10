//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double,int> > v;
        for(int i=0;i<n;i++){
            v.push_back({double(arr[i].value)/double(arr[i].weight),i});
        }
        sort(v.begin(),v.end(),greater<pair<double,int>>());
        double sum=0.0;
        for(int i=0;i<v.size();i++){
            int ind = v[i].second;
            double s = v[i].first* min(arr[ind].weight,W);
            sum+=s;
            W = W-arr[ind].weight;
            if(W<0){
                break;
            }
        }
        return sum;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends