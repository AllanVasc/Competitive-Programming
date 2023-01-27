class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 3) return 0;
        
        sort(nums.begin(), nums.end());
        long long answ = LONG_LONG_MAX;
        
        for(int i = 0; i < 4; i++){
            long long curr = nums[(n - 3 + i - 1)%n] - nums[i];
            answ = min(answ, curr);
        }
        
        return answ;
    }
};