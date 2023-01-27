class Solution {
public:
    int numSplits(string s) {
        int answ = 0;
        vector<int> freq_left(26, 0);
        vector<int> freq_right(26, 0);
        int dif_left = 0;
        int dif_right = 0;
        
        for(int i = s.size() - 1; i >= 0; i--){
            if(freq_right[s[i] - 'a'] == 0) dif_right++;
            freq_right[s[i] - 'a']++;
        }
        
        for(int i = 0; i < s.size(); i++){
            if(freq_right[s[i] - 'a'] == 1){
                freq_right[s[i] - 'a']--;
                dif_right--;
            }
            else{
                freq_right[s[i] - 'a']--;  
            }
            
            if(freq_left[s[i] - 'a'] == 0){
                freq_left[s[i] - 'a']++;
                dif_left++;
            }
            else{
                freq_left[s[i] - 'a']++;
            }
            
            if(dif_left == dif_right) answ++;
        }
        
        return answ;
    }
};