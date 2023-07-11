/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> parent ;
        queue<pair<TreeNode*,TreeNode*>> q;
        if(root==NULL){
            return {}; 
        }
        q.push({root,NULL});
        while(!q.empty()){
            TreeNode* temp = q.front().first;
            TreeNode* par = q.front().second;
            parent[temp] = par;
            if(temp->left!=NULL){
                q.push({temp->left,temp});
                
            }
            if(temp->right!=NULL){
                q.push({temp->right,temp});
            }
            q.pop();
        } 
        vector<int> ans;
        queue<pair<TreeNode*, int>> pq;
        pq.push({target,0});
       map<int,bool>mp;
           mp[target->val] = true;
         while(!pq.empty()){
            TreeNode* node = pq.front().first;
            int cnt = pq.front().second;
            pq.pop();
             if(node==NULL){
                 continue;
             }
            
            if(cnt==k && node!=NULL){
                ans.push_back(node->val);
            }
            if(node->left!=NULL && mp.find(node->left->val)==mp.end()){
                pq.push({node->left,cnt+1});
                mp.insert({node->left->val,true});
            }
            if(node->right!=NULL  && mp.find(node->right->val)==mp.end()){
                pq.push({node->right,cnt+1});
                 mp.insert({node->right->val,true});
            }
             if(parent[node]!=NULL &&  mp.find(parent[node]->val)==mp.end()){
                pq.push({parent[node],cnt+1});
                 mp[parent[node]->val]= true;
             }
        }
       
        return ans;
    }
};