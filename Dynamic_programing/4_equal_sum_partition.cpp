/*
 bool canPartition(vector<int>& nums) {
        int sum =0;
        int  n = nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2==1){
            return false;
        }
    
        bool t[n+1][sum+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                t[i][j] = false;
            }
        }
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                 if(i==0){
                    t[i][j] = false;
                }
                if(j==0){
                    t[i][j]=true;
                }
             }
         }
        t[0][0] =true;
        sum=sum/2;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(nums[i-1]<=j){
                    t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];
                }else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<t[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i=0;i<n+1;i++){
            if(t[i][sum]==true){
                return true;
            }
        }
        return false;
        
    }

*/