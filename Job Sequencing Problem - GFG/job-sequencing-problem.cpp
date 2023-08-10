//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<pair<int,pair<int,int>>>v ;
        for(int i=0;i<n;i++){
            v.push_back({arr[i].profit,{arr[i].dead,arr[i].id}});
        }
        sort(v.begin(),v.end(),greater<pair<int,pair<int,int>>>());
        vector<int>deadline (n+1,-1);
        int count=0;
        int profit=0;
        for(int i=0;i<v.size();i++){
            auto p = v[i];
          
            for(int j=p.second.first;j>0;j--){
                
                if(deadline[j]==-1){
                    deadline[j]=p.second.second;
                   
                    profit +=p.first;
                    count++;
                    break;
                }
            }
        }
        return {count,profit};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends