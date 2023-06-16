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

struct event{
    int u, v, e;
    event(){}
    event(int u, int v, int e) : u(u), v(v), e(e) {}
};

vector<vector<event>> seg;
vector<int> answ;
void update(int p, int l, int r, int ql, int qr, const event &  x){
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
int cmps;

void build(int n){
    parent.resize(n);
    sz.resize(n);
    cmps = n;
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
    cmps--;
}

void rollback(){
    auto [a, b] = changes.back();
    changes.pop_back();
    if(a == -1) return;
    parent[b] = b;
    sz[a] -= sz[b];
    cmps++;
}

void solve(int p, int l, int r){
    int save = changes.size();
    for(auto [u,v,e] : seg[p]){
        if(e == 1){
            merge(u,v);
        }
    }
    if(l == r){
        answ[l] = cmps;
        while(changes.size() > save) rollback();
        return;
    }
    int mid = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    solve(lc, l, mid);
    solve(rc, mid + 1, r);
    while(changes.size() > save) rollback();
}

int32_t main() {
    optimize;
    
    int n, m, k;
    cin >> n >> m >> k;
    map<pii, vector<int>> endEdge;
    vector<event> events;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        if(u > v) swap(u,v);
        events.push_back(event(u,v,1));
    }
    for(int i = 0; i < k; i++){
        int cmd, u, v;
        cin >> cmd >> u >> v;
        u--, v--;
        if(u > v) swap(u,v);
        if(cmd == 1){
            events.push_back(event(u,v,1));
        }
        else{
            events.push_back(event(u,v,0));
            endEdge[{u,v}].push_back(i + m);
        }
    }
    int qtt = events.size();
    seg.resize(4 * qtt);
    answ.resize(qtt);
    for(int i = 0; i < qtt; i++){
        auto [u,v,e] = events[i];
        // cout << "u = " << u << " v = " << v << " event = " << e << endl;
        if(!e) continue;
        auto it = lower_bound(endEdge[{u,v}].begin(), endEdge[{u,v}].end(), i);
        if(it == endEdge[{u,v}].end()){
            // Edge atual nao eh mais removida
            update(1, 0, qtt - 1, i, qtt - 1, events[i]);
        }
        else{
            update(1, 0, qtt - 1, i, *it - 1, events[i]);
        }
    }
    build(n);
    solve(1, 0, qtt - 1);
    for(int i = m - 1; i < qtt; i++){
        cout << answ[i] << " ";
    }
    cout << '\n';
    return 0;
}