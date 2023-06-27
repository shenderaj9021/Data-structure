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

void swap(string &s1,string &s2,int p,int q){
    char temp = s1[p];
    s1[p] = s2[q];
    s2[q] = temp;
}
void solve()
{   
    // cout<<"ne "<<endl;
    string s1,s2;
    cin>>s1>>s2;
    ll t,q;
    cin>>t>>q;
    vector<string>ans;
    map<char,int> mp1;
    map<char,int> mp2;
    for(auto it:s1){
        mp1[it] =-1;
    }
    for(auto it:s2){
        mp1[it] =-1;
    }
    ll ct =1;
    for(int i=0;i<q;i++){
        int g;
        cin>>g;
        if(g==1){
            // cout<<"First "<<endl;
            int pos;
            cin>>pos;
            mp1[s1[pos-1]]=ct;
            mp2[s2[pos-1]] =ct;
        }else if(g==2){
            // cout<<"Second "<<endl;
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            
            if(a==1 && c==1){
                swap(s1,s1,b-1,d-1);
            }else if(a==1 && c==2){
                  swap(s1,s2,b-1,d-1);
            }else if(a==2 && c==2){
                  swap(s2,s2,b-1,d-1);
            }else if(a==2 && c==1){
                  swap(s2,s1,b-1,d-1);
            }
        }else if(g==3){
            // cout<<"THird "<<endl;
            bool flag =false;
            for(int i=0;i<s1.size();i++){
                
                if(mp1[s1[i]]!=-1 && mp2[s2[i]]!=-1 && ((ct-mp1[s1[i]]+1)<=t || (ct-mp2[s2[i]]+1)<=t)){
                    // cout<<"con "<<endl;
                    continue;
                }else if(s1[i]!=s2[i]){
                    ans.push_back("NO");
                    flag =true;
                    break;
                }
            }
            if(!flag){
                ans.push_back("YES");
            }
        }
        ct++;
    }
    for(auto it:ans){
        cout<<it<<endl;
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
           solve();
           t--;
       }
 
    
   

    return 0;
}