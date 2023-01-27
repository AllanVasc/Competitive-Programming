// Time Complexity: O(N*logN)
// Space Complexity: O(N)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> answ;
        
        sort(intervals.begin(), intervals.end());
        
        for(int i = 0; i < intervals.size(); i++){
            
            if(answ.size() > 0 && answ.back()[1] >= intervals[i][0]){
                if(answ.back()[1] < intervals[i][1])
                    answ.back()[1] = intervals[i][1];
            }
            else{
                answ.push_back({intervals[i][0], intervals[i][1]});
            }
        }
        
        return answ;
    }
};