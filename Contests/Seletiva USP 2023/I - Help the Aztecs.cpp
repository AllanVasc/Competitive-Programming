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

signed main() {
    optimize;
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> g(n);
    vector<int> dead(n);
    vector<int> isMilho(n, false);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<pair<int,int>> queries;
    for(int i = 0; i < q; i++){
        int cmd; cin >> cmd;
        int x = -1;
        if(cmd == 1){
            cin >> x;
            x--;
            dead[x] = true;
        }
        queries.push_back({cmd, x});
    }
    // tras pra frente
    set<int> milhos;
    for(int i = 0; i < n; i++){
        if(dead[i]) continue;
        int cntF = 0;
        int cntM = 0;
        for(auto x : g[i]){
            if(dead[x]) continue;
            if(x > i) continue;
            cntM += isMilho[x];
            cntF += !isMilho[x];
        }
        // cout << "i = " << i + 1 << " F = " << cntF << " M = " << cntM << '\n';
        if(cntF >= cntM){
            isMilho[i] = true;
            milhos.insert(i);
        }
    }
    vector<vector<int>> answ;
    for(int i = q - 1; i >= 0; i--){
        auto [cmd, val] = queries[i];
        if(cmd == 2){
            vector<int> aux;
            for(auto x : milhos) aux.push_back(x + 1);
            answ.push_back(aux);
        }
        else{
            int cntF = 0;
            int cntM = 0;
            for(auto x : g[val]){
                if(dead[x]) continue;
                cntM += isMilho[x];
                cntF += !isMilho[x];
            }
            if(cntF >= cntM){
                isMilho[val] = true;
                milhos.insert(val);
            }
            dead[val] = false;
        }
    }
    reverse(answ.begin(), answ.end());
    for(auto v : answ){
        cout << v.size() << " ";
        for(auto x : v) cout << x << " ";
        cout << '\n';
    }
    return 0;
}