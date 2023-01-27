// Time Complexity: Average = O(n), in Worst Case O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        return quickselect(nums, 0, nums.size()-1, k);
    }
    
private:
    int quickselect(vector<int>& nums, int l, int r, int k){
        int pivot = r;
        int change = l;
        
        for(int i = l; i < r; i++){
            if(nums[i] <= nums[pivot]){
                swap(nums[i], nums[change]);
                change++;
            }
        }
        
        swap(nums[change], nums[pivot]);
        
        if(change == k){
            return nums[k];
        }
        else if(change > k){
            return quickselect(nums, l, change-1, k);
        }
        else{
            return quickselect(nums, change+1, r, k);
        }
    }
};