class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        
        bool change = false;
        while(i <= j){
            if(s[i] != s[j]){
                bool op1 = true;
                int k = i+1;
                int l = j;
                while(k <= l){
                    if(s[k] != s[l]){
                        op1 = false;
                        break;
                    }
                    k++;
                    l--;
                }
                if(op1) return true;
                bool op2 = true;
                k = i;
                l = j-1;
                while(k <= l){
                    if(s[k] != s[l]){
                        op2 = false;
                        break;
                    }
                    k++;
                    l--;
                }
                if(op2) return true;
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};