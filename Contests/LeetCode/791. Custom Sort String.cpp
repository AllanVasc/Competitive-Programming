// Time Complexity: O(|S| + |Order|)
// Space Complexity: O(|Order| = max 26) -> O(1)

class Solution {
    map<char,int> mp;
public:
    string customSortString(string order, string s) {
        string answ;
        vector<int> freq;
        freq.assign(26,0);
        
        for(int i = 0; i < s.size(); i++) freq[s[i]-'a']++;
        
        for(int i = 0; i < order.size(); i++){
            while(freq[order[i]-'a']){
                answ += order[i];
                freq[order[i]-'a']--;
            }  
        }
        
        for(int i = 0; i < 26; i++){
            while(freq[i]){
                answ += char(i + 'a');
                freq[i]--;
            } 
        }
        return answ;
    }
private:
    
};