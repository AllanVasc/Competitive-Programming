// Time Complexity: O(W * H*logH) Sendo W a largura da BT e H a altura
// Space Complexity: O(N)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    map<int,vector<pair<int,int>>> mp;
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        
        dfs(root,0,0);
        
        vector<vector<int>> answ;
        for(auto i : mp){
            sort(i.second.begin(), i.second.end(), comp);
            vector<int> aux;
            for(int j = 0; j < i.second.size(); j++){
                aux.push_back(i.second[j].second);
            }
            answ.push_back(aux);
        }
        return answ;
    }
    
private:
    static bool comp(pair<int,int> a, pair<int,int> b){
        if(a.first < b.first){
            return true;
        }
        else{
            return false;
        }
    }
    
    void dfs(TreeNode* root,int row, int column){
        if(root != NULL){
            mp[column].push_back({row, root->val});
            dfs(root->left,row+1,column-1);
            dfs(root->right,row+1,column+1);
        }
    }
    
};

// Using BFS
// Time Complexity: O(N*logN)
// Space Complexity: O(N)

class Solution {
    map<int,vector<int>> mp;
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        
        queue<pair<TreeNode*,int>> q;
        
        q.push({root,0});
        
        while(!q.empty()){
            
            pair<TreeNode*,int> p = q.front();
            q.pop();
            
            if(p.first != NULL){
                mp[p.second].push_back(p.first->val);
                q.push({p.first->left, p.second-1});
                q.push({p.first->right, p.second+1});
            }
        }
        
        vector<vector<int>> answ;
        for(auto i : mp){
            vector<int> aux;
            for(int j = 0; j < i.second.size(); j++){
                aux.push_back(i.second[j]);
            }
            answ.push_back(aux);
        }
        return answ;
    }    
};