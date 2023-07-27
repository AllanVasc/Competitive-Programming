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

vector<vector<pii>> g;
vector<bool> visited;
vector<int> coord;

bool dfs(int u, int p = -1){
    visited[u] = true;
    bool answ = true;
    for(auto [v, w] : g[u]){
        if(!visited[v]){
            coord[v] = coord[u] + w;
            answ &= dfs(v, u);
        }
        if(coord[v] != coord[u] + w) return false;
    }
    return answ;
}

signed main() {
    // optimize;
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pii> points(n);
        for(int i = 0; i < n; i++){
            cin >> points[i].first >> points[i].second;
        }
        map<int,int> freqx;
        map<int,int> freqy;
        int answ = 0;
        for(int i = 0; i < n; i++){
            auto [x, y] = points[i];
            freqx[x]++;
            freqy[y]++;
        }
        for(int i = 0; i < n; i++){
            auto [x, y] = points[i];
            answ += freqx[x] - 1;
            answ += freqy[y] - 1;
        }
        for(int i = 0; i < n; i++){
            auto [x, y] = points[i];
            points[i].first = x + y;
            points[i].second = -x + y;
        }
        freqx.clear();
        freqy.clear();
        for(int i = 0; i < n; i++){
            auto [x, y] = points[i];
            freqx[x]++;
            freqy[y]++;
        }
        for(int i = 0; i < n; i++){
            auto [x, y] = points[i];
            answ += freqx[x] - 1;
            answ += freqy[y] - 1;
        }
        cout << answ << '\n';
    }
    return 0;
}