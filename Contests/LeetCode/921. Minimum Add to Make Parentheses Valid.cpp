class Solution {
public:
    int minAddToMakeValid(string s) {
        int answ = 0;
        stack<char> st;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') st.push(s[i]);
            else{
                if(st.empty()) answ++;
                else{
                    st.pop();
                }
            }
        }
        return answ + st.size();
    }
};