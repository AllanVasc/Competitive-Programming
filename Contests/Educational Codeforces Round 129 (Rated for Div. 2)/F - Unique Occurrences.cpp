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

struct edge{
    int u, v, w;
    edge(){}
    edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

vector<vector<edge>> seg;
void update(int p, int l, int r, int ql, int qr, const edge & x){
    if(l == ql && r == qr){
        seg[p].push_back(x);
        return;
    }
    int mid = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    if(qr <= mid) update(lc, l, mid, ql, qr, x);
    else if(ql > mid) update(rc, mid + 1, r, ql, qr, x);
    else{
        update(lc, l, mid, ql, mid, x);
        update(rc, mid + 1, r, mid + 1, qr, x);
    }
}

vector<int> parent, sz;
vector<pii> changes;
void build(int n){
    parent.resize(n);
    sz.resize(n);
    for(int i = 0; i < n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int a){
    return a == parent[a] ? a : find(parent[a]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b){
        changes.push_back({-1, -1});
        return;
    }
    if(sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
    changes.push_back({a, b});
}

void rollback(){
    auto [a, b] = changes.back();
    changes.pop_back();
    if(a == -1) return;
    sz[a] -= sz[b];
    parent[b] = b;
}

int solve(int p, int l, int r){
    // cout << "[" << l << "," << r << "] = ";
    // for(auto [u,v,w] : seg[p]){
    //     cout << "(" << u << "," << v << "," << w << ") ";
    // }
    // cout << '\n';
    int save = changes.size();
    for(auto [u,v,w] : seg[p]){
        if(w == 0) merge(u, v);
    }
    int answ = 0;
    if(l == r){
        for(auto [u, v, w] : seg[p]){
            if(w == 1){
                // cout << "u = " << u << " v = " << v << '\n';
                // cout <<"sz u = " << sz[find(u)] << " sz[v] = " << sz[find(v)] << '\n';
                answ += sz[find(u)] * sz[find(v)];
            }
        }
        while(changes.size() > save) rollback();
        return answ;
    }
    else{
        int mid = (l + r) >> 1;
        int lc = 2*p;
        int rc = lc + 1;
        answ += solve(lc, l, mid);
        answ += solve(rc, mid + 1, r);
        while(changes.size() > save) rollback();
        return answ;
    }
}

int32_t main() {
    optimize;

    int n;
    cin >> n;
    vector<edge> e(n - 1);
    for(int i = 0 ; i < n - 1; i++){
        int u, v, w;
        cin >> e[i].u >> e[i].v >> e[i].w;
        e[i].u--, e[i].v--;
    }
    sort(ALL(e), [](auto & a, auto & b){
        return a.w < b.w;
    });
    seg.assign(4 * n, vector<edge>());
    int qtt = e.size();
    for(int i = 0; i < qtt; i++){
        auto [u,v,w] = e[i];
        // cout << "w = " << w << '\n';
        int before = lower_bound(ALL(e), edge(-1,-1, w), [](const edge & a, const edge & b){
            return a.w < b.w;
        }) - e.begin();
        int after = lower_bound(ALL(e), edge(-1,-1, w + 1), [](const edge & a, const edge & b){
            return a.w < b.w;
        }) - e.begin();
        // cout << "before = " << before << " after = " << after << endl;
        if(before - 1 >= 0) update(1, 0, qtt - 1, 0, before - 1, edge(u, v, 0));
        update(1, 0, qtt - 1, i, i, edge(u, v, 1));
        if(after < qtt) update(1, 0, qtt - 1, after, qtt - 1, edge(u, v, 0));
    }
    build(n);
    // cout << "solve: " << '\n';
    int answ = solve(1, 0, qtt - 1);
    cout << answ << '\n';
    return 0;
}