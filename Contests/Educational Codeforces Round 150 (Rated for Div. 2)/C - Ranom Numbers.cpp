#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

string s;
const int ms = 2e5 + 100;
vector<vector<vector<int>>> dp;
vector<int> vals;
int solve(int idx, int greater, bool flag){
    if(idx < 0){
        return 0;
    }
    int & answ = dp[idx][greater][flag];
    if(answ != -INF) return answ;
    if(flag){
        // ja mudei;
        if((s[idx] - 'A' + 1) < greater){
            int val = vals[s[idx] - 'A'];
            answ = max(answ, -val + solve(idx - 1, greater, flag));
        }
        else{
            int val = vals[s[idx] - 'A'];
            answ = max(answ, val + solve(idx - 1, (s[idx] - 'A' + 1), flag));
        }
    }
    else{
        // posso mudar
        for(int i = 0; i < 5; i++){
            if((s[idx] - 'A') == i){
                int val = vals[i];
                if((s[idx] - 'A' + 1) < greater){
                    answ = max(answ, -val + solve(idx - 1, greater, flag));
                }
                else{
                    answ = max(answ, val + solve(idx - 1, (s[idx] - 'A' + 1), flag));
                }
            }
            else{
                int val = vals[i];
                if(i + 1 < greater){
                    answ = max(answ, -val + solve(idx - 1, greater, !flag));
                }
                else{
                    answ = max(answ, val + solve(idx - 1, i + 1, !flag));
                }
            }
        }
    }

    return answ;
}

int32_t main() {
    optimize;
    
    int t;
    cin >> t;
    vals.assign(10, 1);
    for(int i = 1; i < 10; i++){
        vals[i] = vals[i - 1] * 10;
    }
    while(t--){
        cin >> s;
        dp.assign(s.size(), vector<vector<int>>(7, vector<int>(2, -INF)));
        cout << solve(s.size() - 1, 0, false) << '\n';
    }
    return 0;
}