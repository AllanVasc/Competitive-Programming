// Approach 2: Iterative with O(N) Space

// Time Complexity : O(N)
// Space Complexity : O(N)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    map<Node*,Node*> mp;
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
        Node* curr = head;
        Node* answ = new Node(curr->val);
        mp[curr] = answ;
        while(curr != NULL){
            answ->next = clone(curr->next);
            answ->random = clone(curr->random);
            
            curr = curr->next;
            answ = answ->next;
        }
        
        return mp[head];
    }

private:
    Node* clone(Node* node){
        if(node != NULL){
            if(mp.find(node) != mp.end()) return mp[node];
            else{
                mp[node] = new Node(node->val);
                return mp[node];
            }
        }
        return NULL;
    }
};

// Approach 3: Iterative with O(1) Space

// Time Complexity : O(N)
// Space Complexity : O(1)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    map<Node*,Node*> mp;
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
        Node* curr = head;
        while(curr != NULL){ // Mesclando as listas
            Node* node = new Node(curr->val);
            
            node->next = curr->next;
            curr->next = node;
            
            curr = node->next;
        }
        
        curr = head;
        while(curr != NULL){ // Copying random pointers
            curr->next->random = (curr->random == NULL) ? NULL : curr->random->next;
            curr = curr->next->next;
        }
        
        curr = head;
        Node* answ = head->next;
        Node* backup = head->next;
        while(curr != NULL){    // Separating
            curr->next = curr->next->next;
            answ->next = answ->next == NULL ? NULL : answ->next->next;
            
            curr = curr->next;
            answ = answ-> next;
        }
        return backup;
    }
};