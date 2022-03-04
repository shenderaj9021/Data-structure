#include<iostream>
#include<bits//stdc++.h>
using namespace std;
typedef long long ll;
int main(){
string s;
cin >> s;
string st;
cin >>st;
if(s.length()!=st.length()){
    cout<<"NO"<<endl;
    return 0;
}
map<char,int> mp;
for(int i=0;i<s.length();i++){
    mp[s[i]]++;
}
int count=0;
for(int i=0;i<st.length();i++){
    if(s[i]!=st[i]){
        count++;
    }
    if(mp.find(st[i])==mp.end()){
        cout<<"NO"<<endl;
        return 0;
    }
    if(mp[st[i]]==0){
        cout<<"NO"<<endl;
        return 0;
    }
    mp[st[i]]--;
}
if(count>3 || count%2==1){
    cout<<"NO"<<endl;
}else{
    cout<<"YES"<<endl;
}



   

}
