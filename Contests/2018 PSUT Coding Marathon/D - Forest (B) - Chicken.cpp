#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<vector<int>> g;
vector<int> visited;
map<int,int> v_to_number;
int last = 1;
vector<int> answ;

void putNumber(int u){
    for(auto v : g[u]){
        putNumber(v);
    }
    v_to_number[u] = last;
    last++;
}

void dfs(int u){
    answ.push_back(v_to_number[u]);
    for(auto v : g[u]) dfs(v);
}

int32_t main(){
  
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    int n;
    cin >> n;
    vector<int> parents(n);
    for(int i = 0; i < n; i++) cin >> parents[i];

    g.assign(n, vector<int>());
    vector<int> roots;

    for(int i = 0; i < n; i++){
        if(parents[i] == 0){
            roots.push_back(i);
        }
        else{
            g[parents[i] - 1].push_back(i);
        }
    }

    // cout << "roots = ";
    // for(auto i : roots){
    //     cout << i << " ";
    // }
    // cout << '\n';
    // cout << "g = " << '\n';
    // for(int i = 0; i < n; i++){
    //     cout << i << ": ";
    //     for(auto u : g[i]){
    //         cout << u << " ";
    //     }
    //     cout << '\n';
    // }

    for(int i = 0; i < roots.size(); i++){        
        putNumber(roots[i]);
        dfs(roots[i]);
    }

    for(auto i : answ){
        cout << i << " ";
    }
    cout << '\n';

    return 0;
}