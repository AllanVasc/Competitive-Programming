// Approach 2: Recursive Preorder Traversal

// Time complexity: O(n) since one has to visit each node.
// Space complexity: up to O(H) to keep the recursion stack, where H is a tree height.

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
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
private:
    int dfs(TreeNode* root, int sum){
        if(root == NULL) return 0;

        sum *= 10;
        sum += root->val;
    
        if(root->left == NULL && root->right == NULL) return sum;
        return dfs(root->left,sum) + dfs(root->right, sum);
    }
};

// Approach 3: Morris Preorder Traversal

// Time complexity: O(n)
// Space complexity: O(1)


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
    int sumNumbers(TreeNode* root) {
        TreeNode* current = root;
        int answ = 0;
        int sum = 0;
        int step;
        
        while(current != NULL){
            if(current->left == NULL){  // Don't have childrens in the left to processe.
                sum = sum*10 + current->val;
                if(current->right == NULL) answ += sum;
                current = current->right;
            }
            else{
                TreeNode* predecessor = current->left; // We are going to use this to make a link to go back
                step = 1;
                while(predecessor->right != current && predecessor->right != NULL){
                    predecessor = predecessor->right;
                    step++;
                }
                
                if(predecessor->right == NULL){ // Make a link to know how to go back to current
                    sum = sum*10 + current->val;
                    predecessor-> right = current;
                    current = current->left;
                }
                else{ // We need to break the link
                    if(predecessor->left == NULL) answ += sum;
                    for(int i = 0; i < step; i++) sum /= 10;    // Backtracking in val
                    predecessor->right = NULL;
                    current = current->right;
                }
            }
        }
        return answ;
    }
};