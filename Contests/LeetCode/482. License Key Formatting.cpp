class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string answ;
        int n = s.size();
        int count = 0;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] != '-'){
                if(isalpha(s[i])) answ.push_back(toupper(s[i]));
                else answ.push_back(s[i]);
                count++;
            }
            if(count == k){
                answ.push_back('-');
                count = 0;
            }
        }
        
        if(answ.back() == '-') answ.pop_back();
        reverse(answ.begin(), answ.end());
        
        return answ;
        
    }
};