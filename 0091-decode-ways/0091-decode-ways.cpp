class Solution {
public:
    int rec(int ind,string s){
        if(ind==s.size()){
            return 1;
        }
        if(ind>s.size()){
            return 0;
        }
        int num =0;
        if(s[ind]=='0'){
            return 0;
        }
        int ans =0;
        for(int i=ind;i<s.size();i++){
            num=num*10+s[i]-'0';
            cout<<num<<endl;
            if(num<=26){
               ans+=rec(i+1,s);
            }else{
                break;
            }
        }
        return ans;
    }
   
    int numDecodings(string s) {
     
        int n =s.size();
        vector<int> dp(n+1);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                dp[i]=0;
            }else{
                dp[i] = dp[i+1];
                if(i<n-1){
                if((s[i]=='1') || (s[i]=='2' && s[i+1]<'7'))
                    dp[i] += dp[i+2];
                }
            }
            }
        cout<<s<<endl;
        for(auto it:dp){
            cout<<it<<" ";
        }
        
        if(dp[0]==0){
            return 0;
        }else{
            return dp[0];
        }
       
    }
};