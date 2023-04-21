#include<bits/stdc++.h>
using namespace std;

#define int long long
using ii = pair<int,int>;
const int INF = 1e18;

const int ms = 2e5 + 100;
int dp[ms][30];
string s;

int solve(int idx, int last){
    int n = s.size();
    if(idx >= n){
        return 0;
    }
    int& answ = dp[idx][last];
    if(answ != -1) return answ;

    int curr = s[idx] - 'a';
    if(curr < last){
        answ = 1 + solve(idx + 1, last);
    }
    else{
        answ = min(solve(idx + 1, curr), 1 + solve(idx + 1, last));
    }
    return answ;
}

string correct;
void recovery(int idx, int last){
    int n = s.size();
    if(idx >= n) return;

    int curr = s[idx] - 'a';
    if(curr < last){
        correct.push_back(last + 'a');
        recovery(idx + 1, last);
    }
    else{
        if(idx + 1 >= n){
            correct.push_back(curr + 'a');
        }
        else if(dp[idx][last] == dp[idx + 1][curr]){
            correct.push_back(curr + 'a');
            recovery(idx + 1, curr);
        }
        else{
            correct.push_back(last + 'a');
            recovery(idx + 1, last);
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n >> s;

    memset(dp, -1, sizeof dp);
    cout << solve(0, 0) << '\n';
    recovery(0,0);
    cout << correct << '\n';

    return 0;
}