// Better Solution with Binary Search
// Time Complexity: O(LogN)
// Space Complexity: O(1)

class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > missing(nums, n-1)){ // Out of array
            return nums[n-1] + k - missing(nums, n-1);
        }
        
        int l = 0;
        int r = n-1;
        while(l < r){
            int m = l + (r-l)/2;
            
            if(missing(nums, m) >= k){
                r = m;
            }
            else{
                l = m+1;
            }
        }
        
        return nums[l-1] + k - missing(nums,l-1);
    }
private:
    int missing(vector<int>& nums, int idx){
        return nums[idx] - nums[0] - idx;
    }
};

// Naive Solution:
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        
        for(int i = 0; i < n-1; i++){
            int missing = nums[i+1] - nums[i] - 1;
            if(missing >= k){
                return nums[i] + k;
            }
            else{
                k -= missing;
            }
        }
        
        return nums[n-1] + k;
    }
};