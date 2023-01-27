// Time Complexity: O(N^2)
// Space Complexity : O(N^2)

// We can do better using only O(N) memory
// There are another ways to solve, like using LCS or LPS

class Solution {
#define MAXN 1000 + 10
    
    int dp[MAXN][MAXN];
public:
    bool isValidPalindrome(string s, int k) {
        for(int i = 0; i < MAXN; i++){
            for(int j = 0; j < MAXN; j++){
                dp[i][j] = -1;
            }
        }
        
        if(solve(s, 0, s.size()-1) > k){
            return false;
        }
        else return true;
    }
private:
    int solve(string& s, int i, int j){
        if(i > j){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        
        int answ;
        if(s[i] == s[j]){
            answ = solve(s, i+1, j-1);
        }
        else{
            answ = min(1 + solve(s, i+1, j), 1 + solve(s, i, j-1) );
        }
        return dp[i][j] = answ;
    }
};