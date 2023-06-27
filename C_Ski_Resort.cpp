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
int countnum(ll num){
    int sum=0;
    while(num>0){
        sum+=num%10;
        num/=10;
    }
    return sum;
}


void solve()
{
    ll n,k,q;
    cin>>n>>k>>q;
    int p =0;
    vector<ll> arr(n);
    for(auto &it:arr){
        cin>>it;
    }
    ll count=0;
    for(ll i=0;i<n;i++){
        if(arr[i]<=q){
            p++;
        }else{
            p =0;
        }
        if(p>=k){
            count+=(p-k+1);
        }
    }
    cout<<count<<endl;

    
 

  
   
    return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
       int t;
       cin>>t;
       while(t>0){
           solve();
           t--;
       }
 
    
   

    return 0;
}
