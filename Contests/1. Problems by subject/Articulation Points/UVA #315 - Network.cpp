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
vector<bool> visited, cutpoint;
vector<int> discovered, low;
int timer;

void dfs(int v, int p = -1){
    visited[v] = true;
    discovered[v] = low[v] = timer;
    timer++;
    int children = 0;
    for(auto to : g[v]){
        if(to == p) continue;
        if(visited[to]) low[v] = min(low[v], discovered[to]);
        else{
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if(p != -1 && low[to] >= discovered[v]){ // Caution: Can be called multiple times for "v"
                cutpoint[v] = true;
            }
            children++;
        }
    }
    if(p == -1 && children > 1) cutpoint[v] = true;
}

void find_cutpoints(int n){
    timer = 0;
    visited.assign(n, false);
    cutpoint.assign(n, false);
    discovered.assign(n, -1);
    low.assign(n, -1);
    for(int i = 0; i < n; i++){
        if(!visited[i]) dfs(i);
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