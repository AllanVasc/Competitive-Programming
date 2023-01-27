class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int n = houses.size();
        vector<int> minDist(n, 0);
        
        for(int i = 0; i < n; i++){
            int idx = lower_bound(heaters.begin(), heaters.end(), houses[i]) - heaters.begin();
            if(idx == 0){
                minDist[i] = abs(heaters[idx] - houses[i]);
            }
            else if(idx == heaters.size()){
                minDist[i] = abs(heaters[idx - 1] - houses[i]);
            }
            else{
                minDist[i] = min(abs(heaters[idx] - houses[i]), abs(heaters[idx - 1] - houses[i]));
            }
        }    
        int answ = 0;
        for(int i = 0; i < n; i++) answ = max(answ, minDist[i]);
        return answ;
    }
};