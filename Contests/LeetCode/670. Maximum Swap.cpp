class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        bool can = 1;
        
        for(int i = 0; i < s.size() && can; i++){
            int idx = i;
            for(int j = i+1; j < s.size(); j++){
                if(s[j] >= s[idx]){
                    idx = j;
                }
            }
            if(idx != i && s[idx] != s[i]){
                swap(s[i],s[idx]);
                can = 0;
            }
        }
        return stoi(s);
    }
};