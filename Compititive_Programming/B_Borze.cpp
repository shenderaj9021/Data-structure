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

void swap(char & a, char &b){
    char temp = a;
    a = b;
    b = temp;
}
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
   string s;
   cin>>s;
   string num="";
   for(int i=0;i<s.size();i++){
         
       if(s[i]=='.'){
            num+='0';
       }else if(s[i]=='-' && s[i+1]=='.'){
           num+='1';
           i++;
       }else{
           num+='2';
           i++;
       }
   }
   cout<<num<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
       
        solve();
  
   

    return 0;
}