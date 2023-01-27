class Solution {
    vector<long long> prefixSum;
public:
    Solution(vector<int>& w) {
        prefixSum.push_back(0);
        for(int i = 0; i < w.size(); i++){
            long long value = w[i] + prefixSum[i];
            prefixSum.push_back(value);
        }   
    }
    
    int pickIndex() {
        long long value = rand() % prefixSum.back();
        auto answ = upper_bound(prefixSum.begin(), prefixSum.end(), value);
        return answ - prefixSum.begin() - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

/*

Time Complexity = O(N + Q*Log2(N))
Space Complexity = O(N)

*/