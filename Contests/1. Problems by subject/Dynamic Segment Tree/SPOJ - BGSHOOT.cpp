#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int MAXN = 1e10;
vector<int> answSeg, lazySeg, lNodes, rNodes;

int create(){
    answSeg.push_back(0);
    lazySeg.push_back(0);
    lNodes.push_back(0);
    rNodes.push_back(0);
    return answSeg.size() - 1;
}

void propagate(int p, int l, int r){
    if(p == 0 || lazySeg[p] == 0) return;
    answSeg[p] += lazySeg[p];
    if(l != r){
        if(lNodes[p] == 0){
            int aux = create();
            lNodes[p] = aux;
        }
        if(rNodes[p] == 0){
            int aux = create();
            rNodes[p] = aux;
        }
        lazySeg[lNodes[p]] += lazySeg[p];
        lazySeg[rNodes[p]] += lazySeg[p];
    }
    lazySeg[p] = 0;
}

void update(int p, int l, int r, int ql, int qr){
    propagate(p, l, r);
    if(l > qr || r < ql) return;
    if(ql <= l && r <= qr){
        lazySeg[p]++;
        propagate(p, l, r);
    }
    else{
        int m = (l + r) >> 1;
        if(lNodes[p] == 0){
            int aux = create();
            lNodes[p] = aux;
        }
        if(rNodes[p] == 0){
            int aux = create();
            rNodes[p] = aux;
        }
        update(lNodes[p], l, m, ql, qr);
        update(rNodes[p], m + 1, r, ql, qr);

        answSeg[p] = max(answSeg[lNodes[p]], answSeg[rNodes[p]]);
    }
}

int query(int p, int l, int r, int ql, int qr){
    propagate(p, l, r);
    if(ql > r || l > qr) return 0;
    if(p == 0) return 0;
    if(l >= ql && r <= qr) return answSeg[p];
    int m = (l + r) >> 1;
    return max(query(lNodes[p], l, m, ql, qr), query(rNodes[p], m + 1, r, ql, qr));
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    create();
    create();
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        update(1, 0, MAXN, l, r);
    }
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << query(1, 0, MAXN, l, r) << '\n';
    }
    return 0;
}