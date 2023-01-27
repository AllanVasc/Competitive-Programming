// Time Complexity: O(N)
// Space Complexity: O(1) -> It has only 26 possible char

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mp;
        if(s.size() != t.size()) return false;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }
        
        for(auto i : mp){
            if(i.second != 0) return false;
        }
        return true;
    }
};