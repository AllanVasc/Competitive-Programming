#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<int> sievePhi(int n){
    vector<int> phi(n + 1);
    for(int i = 0; i <= n; i++) phi[i] = i;
    for(int i = 2; i <= n; i++){
        if(phi[i] == i){
            for(int j = i; j <= n; j += i){
                phi[j] -= phi[j] / i;
            }
        }
    }
    return phi;
}

const int ms = 5*1e6 + 10;
const int LOG = 6;
int depth[ms], up[ms][LOG];

void initTree(int n, vector<int>& phi){
    depth[1] = 0;
    for(int i = 0; i < LOG; i++) up[1][i] = 1;
    for(int i = 2; i <= n; i++){
        depth[i] = depth[phi[i]] + 1;
        up[i][0] = phi[i];
        for(int j = 1; j < LOG; j++){
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
}

int LCA(int u, int v){
    if(depth[u] < depth[v]) swap(u, v);
    int k = depth[u] - depth[v];
    for(int i = LOG - 1; i >= 0; i--){
        if(k & (1 << i)){
            u = up[u][i];
        }
    }
    if(u == v) return u;
    for(int i = LOG - 1; i >= 0; i--){
        if(up[u][i] != up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

int dist(int u, int v){
    return depth[u] + depth[v] - 2 * depth[LCA(u, v)];
}

struct Node{
    int answ, lca;
    bool canReturn;
    Node(){}
    Node(int x){
        answ = 0;
        lca = x;
        canReturn = (x == 1);
    }
    Node(Node lc, Node rc, int l, int r){
        int mid = (l + r) >> 1;
        lca = LCA(lc.lca, rc.lca);
        answ = lc.answ + rc.answ + 
                (mid - l + 1) * dist(lca, lc.lca) +
                (r - mid) * dist(lca, rc.lca);
        canReturn = (lc.canReturn && rc.canReturn);
    }
};

const int maxN = 1e5 + 5;
Node seg[3 * maxN];
vi v;

void build(int p, int l, int r){
    if(l == r){
        seg[p] = Node(v[l]);
    }
    else{
        int mid = (l + r) >> 1;
        int lc = 2*p;
        int rc = lc + 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
        seg[p] = Node(seg[lc], seg[rc], l, r);
    }
}

void updateRange(int p, int l, int r, int ql, int qr){
    if(seg[p].canReturn) return;
    if(l == r){
        seg[p].lca = up[seg[p].lca][0];
        seg[p].canReturn = (seg[p].lca == 1);
        return;
    }
    int mid = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    if(qr <= mid) updateRange(lc, l, mid, ql, qr);
    else if(ql > mid) updateRange(rc, mid + 1, r, ql, qr);
    else{
        updateRange(lc, l, mid, ql, qr);
        updateRange(rc, mid + 1, r, ql, qr);
    }
    seg[p] = Node(seg[lc], seg[rc], l, r);
}

int queryLCA(int p, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr) return seg[p].lca;
    int mid = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    if(qr <= mid) return queryLCA(lc, l, mid, ql, qr);
    else if(ql > mid) return queryLCA(rc, mid + 1, r, ql, qr);
    return LCA(queryLCA(lc, l, mid, ql, qr), queryLCA(rc, mid + 1, r, ql, qr));
}

ll queryAnsw(int p, int l, int r, int ql, int qr, int lca){
    if(ql <= l && r <= qr){
        return (seg[p].answ) + (r - l + 1) * dist(lca, seg[p].lca);
    }
    int mid = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    if(qr <= mid) return queryAnsw(lc, l, mid, ql, qr, lca);
    else if(ql > mid) return queryAnsw(rc, mid + 1, r, ql, qr, lca);
    return queryAnsw(lc, l, mid, ql, qr, lca) + queryAnsw(rc, mid + 1, r, ql, qr, lca);
}

int32_t main() {
    optimize;

    int n, m;
    cin >> n >> m;
    v.assign(n, 0);
    int maxw = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        maxw = max(maxw, v[i]);
    }
    vector<int> phi = sievePhi(maxw);
    initTree(maxw, phi);
    build(1, 0, n - 1);
    while(m--){
        int cmd, l, r; 
        cin >> cmd >> l >> r;
        l--, r--;
        if(cmd == 1){
            // update
            updateRange(1, 0, n - 1, l, r);
        }
        else{
            int lcaRange = queryLCA(1, 0, n - 1, l, r);
            ll answ = queryAnsw(1, 0, n - 1, l, r, lcaRange);
            cout << answ << '\n';
        }
    }
    return 0;
}