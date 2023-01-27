// Time Complexity: O(N)
// Space Complexity: O(N)

// We can optimize to O(1) in space using Morris Traversal


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
    Node* head = NULL;
    Node* tail = NULL;
public:
    Node* treeToDoublyList(Node* root) {
        if(root == NULL) return root;
        dfs(root);
        head->left = tail;
        tail->right = head;
        
        return head;
    }
private:
    void dfs(Node* root){
        if(root == NULL) return;
        
        dfs(root->left);
        if(tail == NULL){
            head = root;
            tail = root;
            
        }
        else{
                
            root->left = tail;
            tail->right = root;
            
            tail = root;
        }
        
        dfs(root->right);
    }
};