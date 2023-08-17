#include <bits/stdc++.h>

using namespace std;
#define int long long

vector <vector <int>> g;
vector <int> raw;

vector <vector <int>> dp;
vector <bool> vis;
void dfs(int i){
    vis[i] = 1;

    dp[i].assign(raw.size(), 0);
    if(g[i].size()){
        for(auto u:g[i]){
            if(!vis[u])
                dfs(u);
            
            for(int j = 0; j < raw.size(); j++){
                dp[i][j] = min(dp[i][j] + dp[u][j], (int)1e10);
            }
        }
    }
    else{
        dp[i][lower_bound(raw.begin(), raw.end(), i) - raw.begin()]++;
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    g.resize(m);


    vector <int> am;
    for(int i = 0; i < m; i++){
        int qtd;
        cin >> qtd;

        for(int j = 0; j < qtd; j++){
            int x;
            cin >> x;

            x--;
            g[i].push_back(x);
        }

        if(!qtd){
            int x;
            cin >> x;

            am.push_back(x);
            raw.push_back(i);
        }
    }

    vis.assign(m, 0);
    dp.resize(m);
    for(int i = 0; i < n; i++){
        dfs(i);
    }

    int ans = 0;
    for(int i = 1; i < (1LL<<n); i++){
        vector <int> aux(raw.size(), 0);

        for(int j = 0; j < n; j++){
            if(i & (1LL << j)){
                for(int k = 0; k < dp[j].size(); k++){
                    aux[k] = min(aux[k] + dp[j][k], (int) 1e10);
                }
            }
        }
        bool pos = true;
        for(int j = 0; j < aux.size() && pos; j++){
            if(aux[j] > am[j]) pos = false;
        }

        if(pos) ans = max(ans, (long long) __builtin_popcountll(i));
    }

    cout << ans << "\n";

    return 0;
}