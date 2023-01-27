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
public:
    int closestValue(TreeNode* root, double target) {
        int val, closest = root->val;
        
        while(root != nullptr){
            val = root->val;
            if(abs(val - target) < abs(closest - target)) closest = val;
            if(target > val) root = root->right;
            else root = root->left;
        }
        
        return closest;
    }
};

/* 

Time complexity = O(log2 N)
Space complexity = O(1)

*/