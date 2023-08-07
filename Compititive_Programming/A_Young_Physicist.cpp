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
       vector<int> arr(3);
       ll t;
       cin>>t;
       for(int i=0 ;i<t;i++){
           ll a,b,c;
           cin>>a>>b>>c;
           arr[0]+=a;
           arr[1]+=b;
           arr[2]+=c;
       }
       if(arr[0]==0 && arr[1]==0 && arr[2]==0){
           cout<<"YES"<<endl;
       }else{
           cout<<"NO"<<endl;
       }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
       
        solve();
  
   

    return 0;
}