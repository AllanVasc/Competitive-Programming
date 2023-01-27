// Tricky Solution
// Time Complexity: O(N)
// Space Complexity: O(1)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* p_copy = p;
        Node* q_copy = q;
        
        while(p_copy != q_copy){

            p_copy = p_copy->parent;
            q_copy = q_copy->parent;
            
            if(p_copy == NULL) p_copy = q;
            if(q_copy == NULL) q_copy = p;
        }
        
        return p_copy;
    }
};


// Naive Solution:
// Time Complexity: O(N*LogN)
// Space Complexity: O(N)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
    set<int> visited;
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        while(p != NULL){
            visited.insert(p->val);
            p = p->parent;
        }
        
        while(!visited.count(q->val)){
            q = q->parent;
        }
        
        return q;
    }
};