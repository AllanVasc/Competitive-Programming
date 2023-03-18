#include <bits/stdc++.h>
using namespace std;
  
#define int long long

// Running in O(nlogn + m*logn)!!

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<int> soma, roots, esq, dir;
const int MAXN = 1e9 + 100;
int create(){
    soma.push_back(0);
    esq.push_back(0);
    dir.push_back(0);
    return soma.size() - 1;
}

int update(int p, int l, int r, int id, int val){
    int novo = create();
    soma[novo] = soma[p];
    esq[novo] = esq[p];
    dir[novo] = dir[p];
    if(l == r){
        soma[novo] = val;
        return novo;
    }
    int m = (l + r) >> 1;
    if(id <= m){
        int aux = update(esq[novo], l, m, id, val);
        esq[novo] = aux;
    }
    else{
        int aux = update(dir[novo], m + 1, r, id, val);
        dir[novo] = aux;
    }
    soma[novo] = soma[esq[novo]] + soma[dir[novo]];
    return novo;
}

int descent(int rootL, int rootR, int l, int r, int k){
    if(l == r){
        return l;
    }
    int m = (l + r) >> 1;
    int check = soma[esq[rootR]] - soma[esq[rootL]];
    if(k <= check) return descent(esq[rootL], esq[rootR], l, m, k);
    else return descent(dir[rootL], dir[rootR], m + 1, r, k - check);
}

int query(int p, int l, int r, int ql, int qr){
    if(qr < l || ql > r) return 0;
    if(p == 0) return 0;
    if(l >= ql && r <= qr) return soma[p];
    int m = (l + r) >> 1;
    return query(esq[p], l, m, ql, qr) + query(dir[p], m + 1, r, ql, qr);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    create();
    roots.push_back(create());
    for(int i = 0; i < n; i++){
        roots.push_back(update(roots.back(), -MAXN, MAXN, v[i], 1));
    }

    while(m--){
        int l, r, k;
        cin >> l >> r >> k;
        cout << descent(roots[l - 1], roots[r], -MAXN, MAXN, k) << '\n';
    }
    return 0;
}