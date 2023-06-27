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
struct comp {
    int pow;
    int freq;
}
bool compareByPower(const computer& comp1, const computer& comp2) {
    return comp1.pow > comp2.pow;
}

void solve()
{   
    // cout<<"ne "<<endl;
    ll n,m;
    cin>>n>>m;
    vector<comp> computers(N);
    for (int i = 0; i < N; i++) {
        cin >> computers[i].pow;
    }

    for (int i = 0; i < N; i++) {
        cin >> computers[i].freq;
    }
    sort(computers.begin(), computers.end(), compareByPower);

    unordered_set<int> uniqueFrequencies;
    long long totalPower = 0;
     for (int i = 0; i < M; i++) {
        totalPower += computers[i].pow;
        uniqueFrequencies.insert(computers[i].freq);
    }

    long long serverRating = totalPower + (uniqueFrequencies.size() * uniqueFrequencies.size());

    std::cout << serverRating << std::endl;

    return 0;

   

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