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
    ll n,k;
    cin>>n>>k;
    ll m=1000000007;
    ll temp=0;
    if(k<=30){
        temp = pow(2,k)-1;
        
    }else{
        cout<<n+1<<endl;
        return ;
    }
    cout<<min(temp,n)+1<<endl;

  
   
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