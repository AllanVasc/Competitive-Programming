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

vector<vector<int>> g;
vector<int> lvl, dp; // dp[u] = min lvl that "u" can reach using backedge
vector<bool> cutpoint;

void dfs(int u, int p = -1){
    int children = 0;
    for(auto v : g[u]){
        if(lvl[v] == 0){ // Edge to child
            lvl[v] = lvl[u] + 1;
            dfs(v, u);
            if(dp[v] < lvl[u]){
                dp[u] = min(dp[u], dp[v]);
            }
            else if(p != -1){ // this subtree has no backedge to some "u" ancestor
                cutpoint[u] = true;
            }
            children++;
        }
        else if(lvl[v] < lvl[u]){ // Edge upwards
            dp[u] = min(dp[u], lvl[v]);
        }
    }
    if(p == -1 && children > 1) cutpoint[u] = true;
}

void find_cutpoints(int n){
    lvl.assign(n, 0);
    dp.assign(n, INF);
    cutpoint.assign(n, false);
    for(int i = 0; i < n; i++){
        if(!lvl[i]){
            lvl[i] = 1;
            dfs(i);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    while(cin >> n){
        if(n == 0) break;
        g.assign(n, vector<int>());
        stringstream buf;
        string aux;
        int st, en;
        cin.ignore();
        while(true){
            getline(cin, aux);
            buf.clear();
            buf << aux;
            buf >> st;
            if(st == 0) break;
            st--;
            while(buf >> en){
                en -= 1;
                g[st].push_back(en);
                g[en].push_back(st);
            }
        }
        find_cutpoints(n);
        int answ = 0;
        for(int i = 0; i < cutpoint.size(); i++){
            if(cutpoint[i]) answ++;
        }
        cout << answ << '\n';
    }
    return 0;
}