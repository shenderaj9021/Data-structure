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
int did(int n,int b){
   for (int i = 2; i <= sqrt(n); i++)
    {

        if (n % i == 0 && b!=i && n/i!=i && n/i!=b)
        {

            return i;
        }
    }
    return -1;
}

void solve()
{
   int n;
   cin>>n;
   bool flag = false;
   int i=2;
   for(i=2;i<sqrt(n);i++){
       if(n%i==0){
          int a = n/i;
          int b = i;
          int c =did(a,b);
          if(c!=-1){
              cout<<"YES"<<endl;
              cout<<i<<" "<<c<<" "<<a/c<<endl;
              flag= true;
              break;
          }
           c = did(b,a);
          if(c!=-1){
              cout<<"YES"<<endl;
                cout<<a<<" "<<c<<" "<<b/c<<endl;
              flag= true;
              break;
          }

       }
   }
   if(!flag){
       cout<<"NO"<<endl;
      
   }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t>0){
        t--;
        solve();
    }
   

    return 0;
}