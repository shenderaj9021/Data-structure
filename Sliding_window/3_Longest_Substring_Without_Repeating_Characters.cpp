// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <bits//stdc++.h>
using namespace std;
 int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        int ans =0;
        map<char,int>mp;
        string temp="";
        for(;j<s.size();j++){
            temp+=s[j];
            while(mp[s[j]]==1){
               mp[s[i]]--;
                i++;
            }
            mp[s[j]]++;
            ans = max(ans,j-i+1);
        }
        return ans;
    }
int main()
{
    string s = "abcabcbb";
    cout<<lengthOfLongestSubstring(s);
}
