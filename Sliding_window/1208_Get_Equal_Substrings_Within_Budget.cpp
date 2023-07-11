//1208. Get Equal Substrings Within Budget
// https://leetcode.com/problems/get-equal-substrings-within-budget/description/


#include <bits//stdc++.h>
using namespace std;

  int equalSubstring(string s, string t, int maxCost) {
        int i=0;
        int j=0;
        int sum =0;
        int ans =0;
        for(;j<s.size();j++){
            sum+=abs(s[j]-t[j]);
            if(sum>maxCost){
                sum-=abs(s[i]-t[i]);
                i++;
            }
            ans = max(j-i+1,ans);
        }
        return ans;
    }
int main(){
    string s = "abcd";
    string t = "bcdf";
    int maxCost = 3;
    cout<<equalSubstring(s,t,maxCost)<<endl;
    return 0;
}