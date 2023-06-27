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
  ll n,c,d;
  cin>>n>>c>>d;
  set<ll> st;
  for(ll i=0;i<n;i++){
      ll g;
      cin>>g;
     st.insert(g);
  }
 
  ll ans =n*c+d;
  ll count =1;
  vector<ll> arr;
  for(ll it:st){
      arr.push_back(it);
  }
  for(ll i=arr.size()-1;i>=0;i--){
      ans = min(ans,((arr.size()-(i+1))*c+(arr[i]-(i+1))*d));
  }
//   for(ll i=arr.size()-1;i>=0;i--){
//        ll a = arr[i];
//        ll ins = arr[i]-i-1;
//        ll rem = arr.size()-i-1;
//        ll temp = ins*d + rem*c +demp*c;
//        ans = min(ans,temp);
//   }
  
  ans +=(n-arr.size())*c;

  cout<<ans<<endl;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   ll t;
   cin>>t;
   while(t>0){
       
        solve();
    t--;
   }
   

    return 0;
}