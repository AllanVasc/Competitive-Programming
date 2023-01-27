class Solution {
    bool check(vector<int>& s){
        if(s[0] > 2) return false;
        if(s[0] == 2){
            if(s[1] > 3) return false;
        }
        if(s[2] > 5) return false;
        
        return true;
        
    }
    
    string build(vector<int>& s){
        string answ;
        answ.push_back(s[0] + '0');
        answ.push_back(s[1] + '0');
        answ.push_back(':');
        answ.push_back(s[2] + '0');
        answ.push_back(s[3] + '0');
        
        return answ;
    }
    
public:
    string largestTimeFromDigits(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        string answ = "";
        if(check(arr)){
            answ = build(arr);
        }
        while(next_permutation(arr.begin(), arr.end())){
            if(check(arr)){
                answ = build(arr);
            }
        }
        
        return answ;
    }
};