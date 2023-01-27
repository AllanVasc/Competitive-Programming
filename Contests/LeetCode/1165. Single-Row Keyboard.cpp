class Solution {
public:
    int calculateTime(string keyboard, string word) {
        vector<int> mapping(26, 0);
        for(int i = 0; i < keyboard.size(); i++) mapping[keyboard[i] - 'a'] = i;
        
        int answ = 0;
        int last_idx = 0;
        for(int i = 0; i < word.size(); i++){
            answ += abs(mapping[word[i] - 'a'] - last_idx);
            last_idx = mapping[word[i] - 'a'];
        }
        
        return answ;
    }
};