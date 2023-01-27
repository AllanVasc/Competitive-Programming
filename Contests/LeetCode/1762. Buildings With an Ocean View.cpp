class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        
        int max = 0;
        vector<int> v;
        for(int i = heights.size()-1; i >= 0; i--){
            if(heights[i] > max){
                v.push_back(i);
                max = heights[i];
            }
        }
        reverse(v.begin(), v.end());
        return v;
    }
};