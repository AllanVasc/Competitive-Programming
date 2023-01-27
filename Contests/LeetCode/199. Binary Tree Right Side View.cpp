// Time Complexity: O(N)
// Space Complexity: O(H) in worst-case -> O(N)

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
    vector<int> answ;
public:
    vector<int> rightSideView(TreeNode* root) {
        dfs(root,0);
        return answ;
    }
    
    void dfs(TreeNode* root, int h){
        if(root == NULL) return;
        
        if(h == answ.size()) answ.push_back(root->val);
        
        dfs(root->right,h+1);
        dfs(root->left,h+1);
    }
};