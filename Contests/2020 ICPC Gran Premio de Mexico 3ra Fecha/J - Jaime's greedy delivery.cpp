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
const int INF = 1e12;
const int MOD = 998244353;

vector<vector<int>> g;
vector<int> orderPack;
vector<pii> special;
vector<vector<int>> minDist;
void buildDist(int cost){
    int n = g.size();
    minDist.assign(n, vector<int>(n, INF));
    for(int i = 0; i < n; i++){
        queue<int> q;
        minDist[i][i] = 0;
        q.push(i);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto v : g[u]){
                if(minDist[i][v] != INF) continue;
                minDist[i][v] = minDist[i][u] + cost;
                q.push(v);
            }
        }
    }
}

vector<vector<int>> dp;
int solve(int idx, int time){
    int qttPack = orderPack.size();
    if(time < 0){
        return -INF;
    }
    if(idx >= qttPack){
            return 0;
    }
    int & answ = dp[idx][time];
    if(answ != -1) return answ;
    answ = -INF;
    auto [city, extra] = special[idx];
    int curr = orderPack[idx];
    int next = (idx != qttPack - 1 ? orderPack[idx + 1] : 0);
    answ = max(extra + solve(idx + 1, time - 
                                      minDist[curr][city] -
                                      minDist[city][next]),
               solve(idx + 1, time - minDist[curr][next]));

    return answ;
}

int32_t main() {
    optimize;

    int n, m, k;
    cin >> n >> m >> k;
    g.assign(n, vector<int>());
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int qttPack, totalTime;
    cin >> qttPack >> totalTime;
    orderPack.assign(qttPack, 0);
    for(int i = 0; i < qttPack; i++){
        cin >> orderPack[i];
        orderPack[i]--;
    }
    special.assign(qttPack, {-1,-1});
    for(int i = 0; i < qttPack; i++){
        cin >> special[i].first >> special[i].second;
        special[i].first--;
    }
    buildDist(k);
    dp.assign(n, vector<int>(totalTime + 1, -1));
    
    int answ = solve(0, totalTime - minDist[0][orderPack[0]]);

    cout << (answ < 0 ? "Impossible" : to_string(answ)) << '\n';
    
    return 0;
}