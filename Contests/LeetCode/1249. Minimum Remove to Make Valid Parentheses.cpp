// Time Complexity: O(n)
// Space Complexity O(n)

// NÃO PODE USAR A FUNÇÃO .erase() pois é O(n)!

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        set<int> remove_idx;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(i);
            }
            if(s[i] == ')'){
                if(st.empty()){
                    remove_idx.insert(i);
                }
                else{
                    st.pop();
                }
            }
        }
        
        while(!st.empty()){
            int idx = st.top();
            st.pop();
            remove_idx.insert(idx);
        }
        string answ;
        for(int i = 0; i < s.size(); i++)
            if(remove_idx.find(i) == remove_idx.end())
                answ += s[i];
        
        return answ;
    }
};