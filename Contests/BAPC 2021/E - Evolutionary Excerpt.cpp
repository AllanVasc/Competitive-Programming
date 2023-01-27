// 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;

string a,b;
const int BLOCK = 100;
int dp[BLOCK][BLOCK];
 
void clear(){
    for(int i = 0; i < BLOCK; i++){
        for(int j = 0; j < BLOCK; j++){
            dp[i][j] = -1;
        }
    }
}
 
int solve(int idx_a, int idx_b, int offset){
 
    if(idx_a == BLOCK || idx_b == BLOCK){
        return 0;
    }
    if(dp[idx_a][idx_b] != -1) return dp[idx_a][idx_b];
 
    if(a[idx_a + offset] == b[idx_b + offset]) return dp[idx_a][idx_b] = 1 + solve(idx_a+1,idx_b+1, offset);
    else return dp[idx_a][idx_b] = max(solve(idx_a+1,idx_b, offset), solve(idx_a, idx_b+1, offset));
}

string answ;
void get(int idx_a, int idx_b, int offset){

    if(idx_a == BLOCK || idx_b == BLOCK) return;

    if(a[idx_a + offset] == b[idx_b + offset] && 
        dp[idx_a][idx_b] == 1 + solve(idx_a+1, idx_b+1, offset)){

            answ.push_back(a[idx_a + offset]);
            get(idx_a+1, idx_b+1, offset);
    }
    else if(dp[idx_a][idx_b] == solve(idx_a+1, idx_b, offset)) get(idx_a+1, idx_b, offset);
    else get(idx_a, idx_b+1, offset);
}

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    cin >> a >> b;
 
    int steps = n/BLOCK;
 
    for(int i = 0; i < steps; i++){
        clear();
        solve(0, 0, i*BLOCK); 
        get(0, 0, i*BLOCK);
    }
   
    cout << answ << '\n';
 
    return 0;
}
