/* Que - Count the numbe of Binary search trees that can be formed using N nodes, numbered from 1 to N.

eg-  input - 3 output- 5
     input - 4 output = 14

     
                i
              /   \
        f(i-1)    f(N-i)

    F(N) =  summation from( i to n) of (f(i-1)*f(N-i))

    f(0) =f(1) = 1   // Base value
*/

#include<bits//stdc++.h>
using namespace std;

// Recursion - exponential time
int countBST(int n){
    if(n==0 || n==1){
        return 1;
    }
    int ans =0;
    for(int i=1;i<=n;i++){
        int x = countBST(i-1);
        int y = countBST(n-i);
        ans +=x*y;
    }
    return ans;
}

// Dp  approch - O(n2)
int countBSTdp(int n,vector<int>&dp){
    if(n==0 || n==1){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans =0;
    for(int i=1;i<=n;i++){
        int x = countBSTdp(i-1,dp);
        int y = countBSTdp(n-i,dp);
        ans +=x*y;
    }
    return dp[n] =ans;
}

int main(){
    int n;
    cin>>n;
    cout<<countBST(n)<<endl;
    vector<int> dp(n+1,-1);
    countBSTdp(n,dp);
    cout<<dp[n]<<endl;

return 0;
}