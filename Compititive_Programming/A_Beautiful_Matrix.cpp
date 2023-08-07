#include <iostream>
#include <bits//stdc++.h>
#define ll long long
#define ull unsigned long long 
#define MOD 1000000007
#define fi first
#define se second
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

using namespace std;
const ll N = 1000000001;

bool isprime(ll n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {

        if (n % i == 0)
        {

            return false;
        }
    }
    return true;
}
bool issquare(ll n)
{
    ll s = sqrt(n);
    if (s * s == n)
    {

        if (isprime(s))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}


void solve()
{
    vector<vector<int>> mat(5,vector<int>(5,0));
    int ans =0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>mat[i][j];
            if(mat[i][j]!=0){
                ans = abs(2-i)+ abs(2-j);
            }
        }
    }
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
       
        solve();
  
   

    return 0;
}