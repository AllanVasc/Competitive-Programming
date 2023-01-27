// Time Complexity: O(N)
// Space Complexity: O(N)

// Cuidado, se usasse map<int,int> a operação é em O(logN)!

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        
        for(int i = 0; i < nums.size(); i++){ // O(N)
            freq[nums[i]]++;
        }
        
        vector<vector<int>> list;
        list.assign(nums.size() + 1, vector<int>());
        
        for(auto i : freq){ // O(N)
            list[i.second].push_back(i.first);
        }
        
        vector<int> answ;
        for(int i = list.size() - 1; i >= 0 && k > 0; i--){ // O(N)
            if(list[i].size() != 0){
                for(int j = 0; j < list[i].size(); j++){
                    answ.push_back(list[i][j]);
                    k--;
                }
            }
        }
        
        return answ;
    }
};