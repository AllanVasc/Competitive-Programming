// Without STACK!
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution {
public:
    int calculate(string s) {
        
        int answ = 0;
        int curr = 0;
        int last = 0;
        char op = '+';
        
        for(int i = 0; i < s.size(); i++){
            
            if(isdigit(s[i])){
                curr = curr*10 + (s[i] - '0');
            }
            
            if((!isdigit(s[i]) && s[i] != ' ') || i == s.size() - 1){
                if(op == '+'){
                    answ += last;
                    last = curr;
                }
                else if(op == '-'){
                    answ += last;
                    last = -curr;
                }
                else if(op == '*'){
                    last = last*curr;
                }
                else{
                    last = last/curr;
                }
                op = s[i];      
                curr = 0;
           }
        }
        
        answ += last;
        
        return answ;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution {
public:
    int calculate(string s) {
        
        int curr = 0;
        stack<int> st;
        char op = '+';
        
        for(int i = 0; i < s.size(); i++){
            
            if(isdigit(s[i])){
                curr = curr*10 + (s[i] - '0');
            }
            
            if((!isdigit(s[i]) && s[i] != ' ') || i == s.size() - 1){
                if(op == '+'){
                    st.push(curr);
                }
                else if(op == '-'){
                    st.push(-curr);
                }
                else if(op == '*'){
                    int aux = st.top();
                    st.pop();
                    st.push(aux*curr);
                }
                else{
                    int aux = st.top();
                    st.pop();
                    st.push(aux/curr);
                }
                op = s[i];      
                curr = 0;
           }
        }
        
        int answ = 0;
        while(!st.empty()){
            answ += st.top();
            st.pop();
        }
        
        return answ;
    }
};