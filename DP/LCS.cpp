#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 1e4;
int dp[MAXN][MAXN];
string s1, s2;

// Longest Common Subsequence
// Call lcs(0, 0)
int lcs(int i, int j){
    if(i == s1.size() || j == s2.size()) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j])
        return dp[i][j] = 1 + lcs(i + 1, j + 1);

    return dp[i][j] = max(lcs(i + 1, j), lcs(i, j + 1));
}

string answ;

// Recovery lcs answer
void recovery(int i, int j){
    if(i == s1.size() || j == s2.size()) return;
    if(s1[i] == s2[j] && dp[i][j] == 1 + lcs(i + 1, j + 1)){
        answ.push_back(s1[i]);
        recovery(i + 1, j + 1);
    }
    else if(dp[i][j] == lcs(i + 1, j)) recovery(i + 1, j);
    else recovery(i, j + 1);
}

/*

Time Complexity

lcs -> O(n*m)

Links:

https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
https://www.youtube.com/watch?v=sSno9rV8Rhg

*/