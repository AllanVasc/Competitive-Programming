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
vector<int> v;
vector<vector<pair<int,int>>> edges;
int id;
void add(int u, int v){
    for(int i = u + 1; i < v; i++){
        for(auto [number, edgeId] : edges[i]){
            if(number == u) continue;
            g[id].push_back(edgeId);
            g[edgeId].push_back(id);
        }
    }
    edges[u].push_back({v, id});
    edges[v].push_back({u, id});
    id++;
}

vector<int> color;
bool bicolor(int u = 0){
    bool answ = true;
    for(auto v : g[u]){
        if(color[v] == -1){
            color[v] = !color[u];
            answ = answ && bicolor(v);
        }
        else{
            if(color[u] == color[v]) return false;
        }
    }
    return answ;
}

signed main() {
    // optimize;
    int n;
    cin >> n;
    vector<int> freq(1e4, 0);
    g.assign(1e6 + 100, vector<int>());
    edges.assign(1e6 + 100, vector<pair<int,int>>());
    v.assign(n, 0);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        freq[v[i]]++;
        if(freq[v[i]] > 4){
            cout << "N" << '\n';
            return 0;
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(v[i] == v[j]){
                add(i, j);
            }
        }
    }
    color.assign(g.size(), -1);
    bool answ = true;
    for(int i = 0; i < id; i++){
        if(color[i] == -1){
            color[i] = 0;
            answ = answ && bicolor(i);
        }
    }
    if(answ){
        cout << "S" << '\n';
    }
    else{
        cout << "N" << '\n';
    }
    return 0;
}