// Time Complexity: O(2^|S|)
// Space Complexity: O(N)

class Solution {
    vector<string> answ;
    set<string> unique_answ;
public:
    vector<string> removeInvalidParentheses(string s) {
        int min_remove = 0;
        int dif = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') dif++;
            else if(s[i] == ')'){
                if(dif) dif--;
                else min_remove++;
            }
        }
        min_remove += dif;
        // cout << min_remove << '\n';
        backtrack(s,0,min_remove,0);
        return answ;
    }
    
private:
    void backtrack(string s, int idx, int qtd_remove,int dif){
        if(dif < 0)
        if(idx == s.size()){
            // cout << "Analisando: " << s << '\n';
            if(dif == 0 && unique_answ.find(s) == unique_answ.end()){
                answ.push_back(s);
                unique_answ.insert(s);
            }
        }
        else{
            // Não removo
            if(s[idx] == '(') backtrack(s,idx+1,qtd_remove,dif+1);
            else if(s[idx] == ')'){
                backtrack(s,idx+1,qtd_remove,dif-1);
            }
            else backtrack(s,idx+1,qtd_remove,dif);
            
            // Removo
            if( (s[idx] == '(' || s[idx] == ')') && qtd_remove){
                s.erase(idx,1);
                backtrack(s,idx,qtd_remove-1,dif);
            }
        }
    }
};