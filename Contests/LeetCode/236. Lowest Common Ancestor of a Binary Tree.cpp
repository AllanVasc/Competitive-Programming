// Time Complexity: O(N)
// Space Complexity: O(N)

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
    vector<TreeNode*> nodes;
    vector<int> parent;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        parent.assign(1e5 + 10, -1);
        bfs(root);
        int u,v;
        for(int i = 0; i < nodes.size(); i++){
            if(p == nodes[i]) u = i;
            else if(q == nodes[i]) v = i;
        }

        while(u != v){
            if(u < v) swap(u,v);
            u = parent[u];
        }
        
        return nodes[u];
    }
private:
    void bfs(TreeNode* root){
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        parent[0] = 0;
        int idx = 0;
        while(!q.empty()){
            pair<TreeNode*,int> curr = q.front();
            q.pop();

            if(curr.first != NULL){
                nodes.push_back(curr.first);
                parent[idx] = curr.second;

                q.push({curr.first->left,idx});               
                q.push({curr.first->right,idx});
                idx++;
            }
        }
    }
};