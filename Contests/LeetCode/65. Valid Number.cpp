// Time Complexity: O(n)
// Space Complexity: O(1)

// Obs.: We can use  Deterministic Finite Automaton too!
class Solution {
public:
    bool isNumber(string s) {
        bool dot = false;
        bool found_e = false;
        bool has_number = false;
        
        for(int i = 0; i < s.size(); i++){
            
            if(s[i] == '-' || s[i] == '+'){ // Check signal
                if(i == 0) continue;
                else if(i > 0 && (s[i-1] == 'e' || s[i-1] == 'E')) continue;
                else return false;
            }
            else if(s[i] == 'e' || s[i] == 'E'){
                if(found_e || has_number == false) return false;
                else{
                    found_e = true;
                    has_number = false;
                    dot = true;
                }
            }
            else if(s[i] == '.'){
                if(dot) return false;
                else dot = true;
            }
            else{
                if(isdigit(s[i])) has_number = true;
                else return false;
            }
        }

        return has_number;
    }
};