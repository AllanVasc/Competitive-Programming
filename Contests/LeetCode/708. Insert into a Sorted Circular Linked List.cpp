/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(head == nullptr){
            head  = new Node (insertVal);
            head->next = head;
            return head;
        }
        
        Node* curr = head;
        Node* prev = head;
        
        while(1){
            
            // Case 1
            if(insertVal >= curr->val && insertVal <= curr->next->val){
                curr->next = new Node(insertVal, curr->next);
                return head;
            }
            
            // Case 2
            else if(curr->val > curr->next->val){
                
                if(insertVal >= curr-> val || insertVal <= curr->next->val){
                    curr->next = new Node(insertVal, curr->next);
                    return head;
                }
                
            }
            prev = curr;
            curr = curr->next;
            if(curr == head) break;
        }
        // Case 3
        head->next = new Node(insertVal, head->next);
        return head;
    }
};