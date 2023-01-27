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
    const int MAXN = 1e4 + 10;
    vector<long long> level;
    int max_level = 1;
    
    void dfs(TreeNode* v, int curr_level){
        if(v == NULL) return;
        
        level[curr_level] += v->val;
        max_level = max(max_level, curr_level);
        
        dfs(v->left, curr_level + 1);
        dfs(v->right, curr_level + 1);
    }
    
public:
    int maxLevelSum(TreeNode* root) {
        level.assign(MAXN, 0);
        dfs(root, 1);
        
        long long answ = 1;
        long long curr_sum = level[1];
        for(int i = 1; i <= max_level; i++){
            if(level[i] > curr_sum){
                answ = i;
                curr_sum = level[i];
            }
        }
        
        return answ;
    }
};