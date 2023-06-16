#include <bits/stdc++.h>
using namespace std;


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

const int ms = 105;
int dp[(1 << 10) + 1][ms][ms];
vector<int> energy, dfc, score;

int solve(int team, int idxP, int en){
    int qttP = dfc.size();
    if(idxP >= qttP) return 0;
    int & answ = dp[team][idxP][en];
    if(answ != -1) return answ;

    answ = solve(team, idxP + 1, en);
    if(en >= dfc[idxP]){
        answ = max(answ, score[idxP] + solve(team, idxP + 1, en - dfc[idxP]));
    }
    int qttT = energy.size();
    for(int i = 0; i < qttT; i++){
        if(team & (1 << i)) continue;
        answ = max(answ, solve(team | (1 << i), idxP, energy[i]));
    }
    return answ;
}
int32_t main() {
    optimize;
    
    int t, p;
    cin >> t >> p;
    energy.assign(t, 0);
    for(int i = 0; i < t; i++) cin >> energy[i];
    dfc.assign(p, 0);
    for(int i = 0; i < p; i++) cin >> dfc[i];
    score.assign(p, 0);
    for(int i = 0; i < p; i++) cin >> score[i];
    memset(dp, -1, sizeof dp);
    cout << solve(0,0,0) << '\n';
    return 0;
}