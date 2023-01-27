class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<bool> dp[2];
        dp[0].assign(n, 0);
        dp[1].assign(n, 0);
        
        dp[0][n-1] = dp[1][n-1] = true; // Base case
        map<int,int> mp;
        
        for(int i = n - 2; i >= 0; i--){
            mp[arr[i+1]] = i + 1;
            auto itr = mp.lower_bound(arr[i]);
            if(itr != mp.end()) dp[0][i] = dp[1][itr->second];
            
            if(mp.begin()->first <= arr[i]){ // I have answ
                if(itr == mp.end() || itr->first > arr[i]) itr--;
                dp[1][i] = dp[0][itr->second];
            }
        }
        
        int answ = 0;
        for(int i = 0; i < n; i++) answ += dp[0][i];
        
        return answ;
    }
};