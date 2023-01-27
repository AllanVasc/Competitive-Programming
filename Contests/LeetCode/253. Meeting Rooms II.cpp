class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int,int>> window;
        for(int i = 0; i < intervals.size(); i++){
            window.push_back({intervals[i][0], 1});
            window.push_back({intervals[i][1], 0});
        }
        
        sort(window.begin(), window.end());
        int answ = 0;
        int curr = 0;
        for(auto i : window){
            if(i.second == 1){
                curr++;
            }
            else{
                curr--;
            }
            
            if(answ < curr) answ = curr;
        }
        
        return answ;
    }
};