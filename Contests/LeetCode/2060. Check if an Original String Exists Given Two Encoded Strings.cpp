#define MAXN 45
#define MAXOFF 2100

class Solution {
    int dp[MAXN][MAXN][MAXOFF];
    const int offset = 1050;
    int n1, n2;
public:
    bool possiblyEquals(string s1, string s2) {
        n1 = s1.size();
        n2 = s2.size();
        for(int i = 0; i < MAXN; i++){
            for(int j = 0; j < MAXN; j++){
                for(int k = 0; k < MAXOFF; k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        
        return solve(s1, s2, 0, 0, 0);
    }

private:
    // Se missing_s1 for positivo, tenho que andar por s1
    // Se missing_s1 for negativo, na realidade é o s2 que esta devendo
    bool solve(string& s1, string& s2, int i, int j, int missing_s1){
        
        if(i == n1 && j == n2){
            if(missing_s1 == 0) return dp[i][j][missing_s1 + offset] = true;
            else return dp[i][j][missing_s1 + offset] = false;
        }
        if(i > n1 || j > n2) return dp[i][j][missing_s1 + offset] = false;
        
        if(dp[i][j][missing_s1 + offset] != -1) return dp[i][j][missing_s1 + offset];
        
        bool answ = false;
        
        if(missing_s1 > 0){ // Tenho que andar por S1 !
            
            if(i == n1) return dp[i][j][missing_s1 + offset] = false;
            if(isalpha(s1[i])){
                answ = solve(s1, s2, i+1, j, missing_s1 - 1);
            }
            else{ // é algum numero e tenho que andar por s1
                
                int curr = s1[i] - '0';
                answ = answ || solve(s1, s2, i+1, j, missing_s1 - curr);
                
                if(i+1 < n1 && isdigit(s1[i+1])){
                    curr = curr*10 + s1[i+1] - '0';
                    answ = answ || solve(s1, s2, i+2, j, missing_s1 - curr);
                    
                    if(i+2 < n1 && isdigit(s1[i+2])){
                        curr = curr*10 + s1[i+2] - '0';
                        answ = answ || solve(s1, s2, i+3, j, missing_s1 - curr);
                    }
                }
            }
            
            return dp[i][j][missing_s1 + offset] = answ;
        }
        
        else if(missing_s1 < 0){ // Agora tenho que andar por S2 !
            
            if(j == n2) return dp[i][j][missing_s1 + offset] = false;
            if(isalpha(s2[j])){
                answ = solve(s1, s2, i, j+1, missing_s1 + 1);
            }
            else{ // é algum numero e tenho que andar por s2
                
                int curr = s2[j] - '0';
                answ = answ || solve(s1, s2, i, j+1, missing_s1 + curr);
                
                if(j+1 < n2 && isdigit(s2[j+1])){
                    curr = curr*10 + s2[j+1] - '0';
                    answ = answ || solve(s1, s2, i, j+2, missing_s1 + curr);
                    
                    if(j+2 < n2 && isdigit(s2[j+2])){
                        curr = curr*10 + s2[j+2] - '0';
                        answ = answ || solve(s1, s2, i, j+3, missing_s1 + curr);
                    }
                }
            }
            
            return dp[i][j][missing_s1 + offset] = answ;
            
        }
        else if (missing_s1 == 0){
            if(i == n1 || j == n2) return dp[i][j][missing_s1 + offset] = answ;
        
            if(isalpha(s1[i]) && isalpha(s2[j])){
                if(s1[i] == s2[j]) return dp[i][j][missing_s1 + offset] = solve(s1,s2, i+1, j+1, missing_s1);
                else return dp[i][j][missing_s1 + offset] = answ;
            }
            else if(isdigit(s1[i])){
                int curr = s1[i] - '0';
                answ = answ || solve(s1, s2, i+1, j, missing_s1 - curr);
                
                if(i+1 < n1 && isdigit(s1[i+1])){
                    curr = curr*10 + s1[i+1] - '0';
                    answ = answ || solve(s1, s2, i+2, j, missing_s1 - curr);
                    
                    if(i+2 < n1 && isdigit(s1[i+2])){
                        curr = curr*10 + s1[i+2] - '0';
                        answ = answ || solve(s1, s2, i+3, j, missing_s1 - curr);
                    }
                }
                
                return dp[i][j][missing_s1 + offset] = answ;
                
            }
            else if(isdigit(s2[j])){
                int curr = s2[j] - '0';
                answ = answ || solve(s1, s2, i, j+1, missing_s1 + curr);

                if(j+1 < n2 && isdigit(s2[j+1])){
                    curr = curr*10 + s2[j+1] - '0';
                    answ = answ || solve(s1, s2, i, j+2, missing_s1 + curr);
                    
                    if(j+2 < n2 && isdigit(s2[j+2])){
                        curr = curr*10 + s2[j+2] - '0';
                        answ = answ || solve(s1, s2, i, j+3, missing_s1 + curr);
                    }
                }

                return dp[i][j][missing_s1 + offset] = answ;
            }
            
            return dp[i][j][missing_s1 + offset] = answ;
        }
        
        return dp[i][j][missing_s1 + offset] = answ;
    }
};