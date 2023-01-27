// Ao invés de usar map usa um vector!

// Time Complexity: O(N*logN)
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
    unordered_map<int, priority_queue<pair<int,int>>> mp;
    int min_column = 0;
    int max_column = 0;
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        dfs(root, 0, 0);
        
        vector<vector<int>> answ;
        
        for(int i = min_column; i <= max_column; i++){
            answ.push_back(vector<int>());
            // cout << "column = " << pq.first << '\n';
            
            while(!mp[i].empty()){
                pair<int,int> aux = mp[i].top();
                // cout << "row = " << aux.first << " value = " << aux.second << '\n';
                answ.back().push_back(aux.second * -1);
                mp[i].pop();
            }
        }
        
        return answ;
    }
private:
    void dfs(TreeNode* root, int c, int r){
        if(root == NULL) return;
        
        if(c < min_column) min_column = c;
        if(c > max_column) max_column = c;
        
        mp[c].push({r * -1, root->val * -1});   // Min Heap
        
        dfs(root->left, c-1, r+1);
        dfs(root->right, c+1, r+1);
   }
    
};


// Usando map e priority queue

// Time Complexity: O(logN * N * logN)
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
    map<int, priority_queue<pair<int,int>>> mp;
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        dfs(root, 0, 0);
        
        vector<vector<int>> answ;
        
        for(auto pq : mp){
            answ.push_back(vector<int>());
            // cout << "column = " << pq.first << '\n';
            
            while(!pq.second.empty()){
                pair<int,int> aux = pq.second.top();
                //cout << "row = " << aux.first << " value = " << aux.second << '\n';
                answ.back().push_back(-1*aux.second);
                pq.second.pop();
            }
        }
        
        return answ;
    }
private:
    void dfs(TreeNode* root, int c, int r){
        if(root == NULL) return;
        
        mp[c].push({r* -1, root->val * -1});
        
        dfs(root->left, c-1, r+1);
        dfs(root->right, c+1, r+1);
   }
    
};

// Mais Easy!

// Time Complexity: O(logN * logN * logN * N)
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
    map<int,map<int,multiset<int>>> mp;
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        solve(root,0,0);
        
        vector<vector<int>> answ;
        
        for(auto m1 : mp){
            
            answ.push_back(vector<int>());
            for(auto m2 : m1.second){
                
                for(auto i : m2.second){
                    answ.back().push_back(i);
                }
            }
        }
        
        return answ;
    }
private:
    void solve(TreeNode* root, int r, int c){
        if(root == NULL) return;
        
        mp[c][r].insert(root->val);
        solve(root->left, r+1, c-1);
        solve(root->right, r+1, c+1);
    }
};