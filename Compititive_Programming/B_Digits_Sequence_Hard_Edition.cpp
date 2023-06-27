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
long long did(long long n,long long k,long long d){
    stack<ll> st;
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

int bs(long long a,long long b,long long k,long long d,int po){
    cout<<"bs "<<endl;
    cout<<a<<" "<<b<<" "<<k<<" "<<d<<" "<<po<<endl;
    int mid = (a) +(b-a)/2;
   cout<<"mid "<<mid<<endl;
   ll temp =d+(mid-a+1)*po;
    cout<<temp<<" "<<temp+d<<" "<<k<<endl;
    if(temp<=(k) && temp>=(k-po)){
        cout<<"First "<<endl;
        ll ans = did(mid,k,(d+(mid-a+1)*po));
        return ans;
    }else if(temp<k){
        cout<<"Second "<<endl;
        bs(mid+1,b,k,d+(mid-a+1)*po,po);
    }else{
        cout<<"Third "<<endl;
        
         bs(a,mid-1,k,d,po);
    }
    return 0;
}
void solve()
{
    long long k;
    cin>>k;
    long long d=0;
    long long prev= 0;
    int i=0;
    for( i=0;i<=12;i++){
       if(pow(10,i)>k){
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