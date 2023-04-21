#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;

const int ms = 1e5 + 100;
int dp[ms];
vector<vector<int>> g;
vector<vector<int>> children;
vector<vector<int>> prefix, suffix;
int MOD, PHI;
int answ[ms];

void precalc(int u, int p){
    dp[u] = 1;
    for(auto v : g[u]){
        if(v == p) continue;
        precalc(v, u);
        children[u].push_back(v);
        dp[u] *= (1 + dp[v]);
        dp[u] %= MOD;
    }
}

void reroot(int u, int pAnsw = 0){
    answ[u] = dp[u];
    int n = children[u].size();
    // cout << "u = " << u + 1 << " tenho " << n << "filhos" << '\n';
    // cout << "pansw = " << pAnsw << '\n';
    for(int i = 0; i < n; i++){
        int v = children[u][i];

        int new_value = prefix[u][i] * suffix[u][i + 1] % MOD 
                        * (1 + pAnsw) % MOD;
        // new_value = dp[u]'

        // cout << "pref = " << prefix[u][i] << '\n';
        // cout << "suf = " << suffix[u][i + 1] << '\n';
        // cout << "u = " << u + 1 << " val = " << new_value << '\n';
        dp[v] *= (1 + new_value);
        dp[v] %= MOD;
        reroot(v, new_value);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n >> MOD;

    g.assign(n, vector<int>());
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    children.assign(n, vector<int>());
    precalc(0, 0);
    for(int i = 0; i < n; i++){
        vector<int> aux;
        aux.push_back(1);
        for(int j = 0; j < children[i].size(); j++){
            aux.push_back(aux.back() * (1 + dp[children[i][j]]) % MOD);
        }
        prefix.push_back(aux);
        aux.clear();
        aux.push_back(1);
        for(int j = children[i].size() - 1; j >= 0; j--){
            aux.push_back(aux.back() * (1 + dp[children[i][j]]) % MOD);
        }
        reverse(aux.begin(), aux.end());
        suffix.push_back(aux);
    }

    // cout << "pref: " << "\n";
    // for(int i = 0; i < n; i++){
    //     cout << "u = " << i + 1 << "\n";
    //     for(int j = 0; j < prefix[i].size(); j++){
    //         cout << prefix[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // cout << "suffix: " << "\n";
    // for(int i = 0; i < n; i++){
    //     cout << "u = " << i + 1 << "\n";
    //     for(int j = 0; j < suffix[i].size(); j++){
    //         cout << suffix[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    reroot(0, 0);

    for(int i = 0; i < n; i++){
        cout << answ[i] << '\n';
    }

    return 0;
}