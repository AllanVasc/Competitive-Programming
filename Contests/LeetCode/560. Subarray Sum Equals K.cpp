class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> freq;
        freq[0]++;
        int answ = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            answ += freq[sum-k];
            freq[sum]++;
        }
        
        return answ;
    }
};