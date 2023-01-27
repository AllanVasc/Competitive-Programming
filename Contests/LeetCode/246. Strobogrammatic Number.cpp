class Solution {
public:
    bool isStrobogrammatic(string num) {
        
        vector<char> map{'0','1','*','*','*','*','9','*','8','6'};
        
        int l = 0;
        int r = num.size()-1;
        while(l <= r){
            
            if(map[num[r]-'0'] == '*') return false;
            if(num[l] != map[num[r]-'0']) return false;
            
            l++;
            r--;
        }
        return true;
    }
};