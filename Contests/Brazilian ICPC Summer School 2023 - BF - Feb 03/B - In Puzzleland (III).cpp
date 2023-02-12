#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;

const int MAXN = 18;

int dp[MAXN][1 << MAXN];
int path[MAXN][1 << MAXN];
vector<vector<int>> g;
vector<char> letras;
int char_to_int[300];

int solve(int v, int mask){
    int n = g.size();
    if(__builtin_popcount(mask) == n){
        if(v == n - 1) return dp[v][mask] = true;
        else return dp[v][mask] = false;
    }
    int & answ = dp[v][mask];
    if(answ != -1) return answ;

    answ = false;
    for(auto i : g[v]){
        if(i == v) continue;
        if((((1 << i) & mask) == 0)){
            int new_mask = mask | (1 << i);
            if(solve(i, new_mask)){
                answ = true;
                if(path[v][mask] == -1) path[v][mask] = i;
                else if(letras[i] < letras[path[v][mask]]) path[v][mask] = i;
            }
        }
    }
    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        int n, m;
        cin >> n >> m;
        letras.assign(n, '*');
        for(int i = 0; i < n; i++){
            char letter;
            cin >> letter;
            letras[i] = letter;
            char_to_int[letter] = i;
        }
        g.assign(n, vector<int>());
        for(int i = 0; i < m; i++){
            char u, v;
            cin >> u >> v;
            g[char_to_int[u]].push_back(char_to_int[v]);
            g[char_to_int[v]].push_back(char_to_int[u]);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < (1 << n); j++){
                dp[i][j] = -1;
                path[i][j] = -1;
            }
        }
        cout << "Case " << cs << ": ";
        if(solve(0, 1 << 0)){
            int curr = 0;
            int curr_mask = 1;
            while(curr != n - 1){
                cout << letras[curr];
                int vtx = path[curr][curr_mask];
                curr = vtx;
                curr_mask = curr_mask | (1 << vtx);
            }
            cout << letras[curr] << '\n';
        }
        else{
            cout << "impossible" << '\n';
        }
    }
    return 0;
}