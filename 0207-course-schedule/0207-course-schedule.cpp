class Solution {
public:
   
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,vector<int>> mp;
        for(auto it:prerequisites){
            mp[it[1]].push_back(it[0]);
        }
        queue<int> q;
        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it:mp[i]){
                indegree[it]++;
            }
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty()){
            int t = q.front();
            q.pop();
            count++;
            for(auto it:mp[t]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(count!=numCourses){
            return false;
        }
        return true;
    }
};