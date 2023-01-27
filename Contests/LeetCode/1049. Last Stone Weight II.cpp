class Solution {
    
    int dp[100*35];
    int n;
    void build(){
        for(int i = 0; i < 100*35; i++){
            dp[i] = -1;
        }
    }
    
    int solve(int curr_w, int idx, vector<int>& stones){
        if(idx >= n || curr_w <= 0) return 0;
        if(dp[curr_w] != -1) return dp[curr_w];
        
        int answ = 0;
        
        if(curr_w >= stones[idx]) answ = max(solve(curr_w, idx+1, stones), stones[idx] + solve(curr_w - stones[idx], idx+1, stones));
        else answ = solve(curr_w, idx+1, stones);
        
        cout << answ << '\n';
        return dp[curr_w] = answ;
    }
    
    public:
    int lastStoneWeightII(vector<int>& stones){
        int total_sum = 0;
        n = stones.size();
        for(int i = 0; i < n; i++) total_sum += stones[i];
        cout << total_sum << '\n';
        
        build();
        cout << solve(total_sum/2, 0, stones) << '\n';
        return  (total_sum - 2*solve(total_sum/2, 0, stones)) ;
    }
};