// Time Complexity: O(N)
// Space Complexity: O(N)

#include <bits/stdc++.h>
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
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return answ;
    }
private:
    int height(TreeNode* node){
        if(node == NULL) return 0;
        
        int l_h = height(node->left);
        int r_h = height(node->right);
        
        int curr = 1 + max(l_h,r_h);
        
        answ = max(answ,l_h + r_h);
        
        return curr;
    }
}; 