// Time Complexity: O(m+n)
// Space Complexity: O(1)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int pos = m+n-1;
        
        for(; i >= 0 || j >= 0;){
            if(i == -1){
                nums1[pos] = nums2[j];
                j--;
                pos--;
            }
            else if(j == -1){
                nums1[pos] = nums1[i];  // I can end
                i--;
                pos--;
            }
            else if(nums1[i] < nums2[j]){
                nums1[pos] = nums2[j];
                j--;
                pos--;
            }
            else{
                nums1[pos] = nums1[i];
                i--;
                pos--;
            }
        }
        
    }
};