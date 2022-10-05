#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> v;

// Longest Increasing Subsequence
int lis(int n){
    vector<int> dp(n, 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(v[j] < v[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int answ = 0;
    for(int i = 0; i < n; i++) answ = max(answ, dp[i]);
    return answ;
}

// Longest Increasing Subsequence using Binary Search
vector<int> LISBS(int n){
    const int INF = 0x3f3f3f3f3f3f3f3f;
    vector<int> dp(n + 1, INF);
    vector<int> idx(n + 1, -1);
    vector<int> parent(n + 1, -1);
    dp[0] = -INF;

    for(int i = 0; i < n; i++){
        int j = upper_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
        if(dp[j-1] < v[i] && v[i] < dp[j]){
            dp[j] = v[i];
            idx[j] = i; 
            parent[j] = idx[j-1];
        }
    }

    vector<int> answ;
    int pos = 0;
    for(int i = 0; i <= n; i++){
        if(dp[i] < INF) pos = i;
    }
    while(pos != -1){
        answ.push_back(v[pos]);
        pos = parent[pos];
    }
    return answ;
}

/*

Time Complexity

lis     -> O(n^2)
LISBS   -> O(n*logn)

Links:

https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/
https://www.youtube.com/watch?v=1RpMc3fv0y4

*/