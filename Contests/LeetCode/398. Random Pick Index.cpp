// Time Complexity:
// Build -> O(N)
// Pick -> O(1)
// Space Complexity -> O(N)

class Solution {
    unordered_map<int, vector<int>> mp;
    
public:
    Solution(vector<int>& nums) {
        
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        // int random = (mp[target].first) + (rand() % (mp[target].second - mp[target].first + 1) );
        
        int len = mp[target].size();
        return mp[target][rand() % len];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */


// Reservoir Sampling


// Time Complexity:
// Build -> O(1)
// Pick -> O(N)
// Space Complexity -> O(1)

class Solution {
    vector<int> v;
public:
    Solution(vector<int>& nums) {
        v.swap(nums);
    }
    
    int pick(int target) {
        int count = 0;
        int answ = -1;
        
        for(int i = 0; i < v.size(); i++){
            if(v[i] == target){
                count++;
                if(rand() % count == 0){
                    answ = i;
                }
            }
        }
        
        return answ;
    }
};

/**
Probabilidade de escolher o primeiro numero = 1/i
probabilidade de ficar com o primeiro apos o segundo = 1 - 1/(i+1)
probabilidade de ficar com o primeiro apos o terceiro = 1 - 1/(i+2)

1/i * (1 - 1/(i+1)) * (1 - 1/(i + 2)) * ... * (1 - 1/n)

1/i * (i/(i+1)) * ((i+1)/(i+2)) * ... * ((n-1)/n) Organizando...

1/n

**/





/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */