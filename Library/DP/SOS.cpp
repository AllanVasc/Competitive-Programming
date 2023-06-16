#include <bits/stdc++.h>
using namespace std;

#define int long long

// SOS DP
int SumOverSubsets(vector<int> & v, int n){
    int dp[(1 << n)][n + 1];
    for(int mask = 0; mask < (1 << n); mask++){ // Base case
        dp[mask][0] = v[mask];
    }
    for(int mask = 0; mask < (1 << n); mask++){
        for(int i = 1; i <= n; i++){
            if(mask & (1 << (i - 1))){ // bit at i - 1 is ON
                dp[mask][i] = dp[mask][i - 1] + dp[mask ^ (1 << (i - 1))][i - 1];
            }
            else{ // bit at i - 1 is OFF
                dp[mask][i] = dp[mask][i - 1];
            }
        }
    }
    /*  
    Memory optimization
    int dp[1 << n];
    for(int i = 0; i < (1 << n); i++) dp[i] = v[i];
    for(int i = 0; i < n; i++){
        for(int mask = 0; mask < (1 << n); mask++){
            if(mask & (1 << i)){
                dp[i] += dp[mask ^ (1 << i)];
            }
        }
    }
    */
    return dp[(1 << n) - 1][n];
}

/*

Time Complexity:

SOS DP  -> O(n * 2^n)

Links:

https://codeforces.com/blog/entry/45223
https://www.youtube.com/watch?v=mkiK_GCWX50
https://usaco.guide/adv/dp-sos?lang=cpp

*/