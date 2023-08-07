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
bool isvalid(int n){
    set<int> s;
    while(n>0){
        if(s.find(n%10)!=s.end()){
            return false;
        }else{
            s.insert(n%10);
            n/=10;
        }
    }
    return true;
}

void solve()
{
    vector<vector<int>> mat(3,vector<int> (3,1));
  
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int a;
            cin>>a;
            if(a%2==1){
                if(j-1>=0){
                    mat[i][j-1]=!mat[i][j-1];
                }
                if(j+1<3){
                    mat[i][j+1] =! mat[i][j+1];
                }
                if(i-1>=0){
                    mat[i-1][j] =! mat[i-1][j];
                }
                if(i+1<3){
                    mat[i+1][j] =! mat[i+1][j];
                }
                mat[i][j] =!mat[i][j];
            }   
        }
    }
    for(auto it:mat){
        for(auto jt:it){
            cout<<jt;
        }
        cout<<endl;
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