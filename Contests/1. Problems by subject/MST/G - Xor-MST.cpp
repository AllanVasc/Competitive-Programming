#include <bits/stdc++.h>
using namespace std;

#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = INT_MAX;
const int MOD = 1e9 + 7;

const int ms = 200000 + 10;
const int sigma = 2;
const int msb = 31;
int trie[msb * ms + 100][sigma], terminal[msb * ms + 100];
vector<vector<int>> v;
int par[ms];
int z = 1;

void initDsu(int n){
    for(int i = 0; i < n; i++) par[i] = i;
}
int find(int u){ return u == par[u] ? u : par[u] = find(par[u]); }

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    if(v[a].size() < v[b].size()) swap(v[a], v[b]);
    for(auto x : v[b]) v[a].push_back(x);
    v[b].clear();
    par[b] = a;
}

void add(int x){
    int curr = 0;
    for(int i = msb - 1; i >= 0; i--){
        bool bit = (x & (1LL << i));
        if(!trie[curr][bit]) trie[curr][bit] = z++;
        curr = trie[curr][bit];
        terminal[curr]++;
    }
}

void rem(int x){
    int curr = 0;
    for(int i = msb - 1; i >= 0; i--){
        bool bit = (x & (1LL << i));
        curr = trie[curr][bit];
        terminal[curr]--;
    }
}

int solve(int x){
    int curr = 0;
    int answ = 0;
    for(int i = msb - 1; i >= 0; i--){
        bool bit = (x & (1LL << i));
        int nxt = trie[curr][bit];
        if(terminal[nxt]){
            if(bit) answ = answ | (1 << i);
            curr = nxt;
        }
        else{
            if(!bit) answ = answ | (1 << i);
            curr = trie[curr][!bit];
        }
    }
    return answ;
}

struct Edge{
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator < (Edge & other){ return w < other.w; }
};

signed main() {
    optimize;
    int n;
    cin >> n;
    v.assign(n, vector<int>());
    vector<int> mp;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        add(x);
        mp.push_back(x);
    }
    sort(mp.begin(), mp.end());
    for(int i = 0; i < n; i++) v[i].push_back(mp[i]);
    long long answ = 0;
    initDsu(n);
    int comp = n;
    while(comp > 1){
        vector<Edge> best;
        for(int i = 0; i < n; i++){
            if(v[i].size() == 0) continue;
            for(auto x : v[i]) rem(x);
            int bestW = INF;
            int bestV = -1;
            for(auto x : v[i]){
                int mn = solve(x);
                if(bestW > (x ^ mn)){
                    bestW = (x ^ mn);
                    bestV = mn;
                }
            }
            best.push_back(Edge(i, bestV, bestW));
            for(auto x : v[i]) add(x);
        }
        for(Edge e : best){
            e.v = lower_bound(mp.begin(), mp.end(), e.v) - mp.begin();
            int pu = find(e.u), pv = find(e.v);
            if(pu == pv) continue;
            merge(e.u, e.v);
            answ += e.w;
            comp--;
        }
    }
    cout << answ << '\n';
    return 0;
}