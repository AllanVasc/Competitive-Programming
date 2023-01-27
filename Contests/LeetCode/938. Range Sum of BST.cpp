// Time Complexity: O(N)
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
    int answ = 0;
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        dfs(root,low,high);
        return answ;
    }
private:
    void dfs(TreeNode* root, int l, int h){
        if(root != NULL){
            if(root->val >= l && root->val <= h) answ += root->val;
            if(l < root->val) dfs(root->left,l,h);
            if(root->val < h) dfs(root->right,l,h);
        }
    }
};