class Solution {
public:
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n,0);
        vector<int> adj[n];
        vector<int> out(n,0);
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adj[it].push_back(i);
                out[i]++;
            }
        }
        queue<int> pq;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(out[i]==0){
                pq.push(i);
            }
        }
        while(!pq.empty()){
            int node = pq.front();
            ans.push_back(node);
            pq.pop();
            for(auto it:adj[node]){
                out[it]--;
                if(out[it]==0){
                    pq.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};