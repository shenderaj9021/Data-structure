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
int did(int n,int k,int& d){
    stack<int> st;
    while(n>0){
       st.push(n%10);
        n/=10;
    }
   
    if(d+st.size()<k){
        d+=st.size();
        return -1;
    }else{
        while(d<k-1){
            d++;
            st.pop();
        }
    }
    
    return st.top();
}

void solve()
{
    int n;
    cin>>n;
    int d=0;
    for(int i=1;i<10000;i++){
        int a = did(i,n,d);
      
        if(a!=-1){
            cout<<a<<endl;
            break;
        }
    }
    return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
       
        solve();
    
   

    return 0;
}