#include <bits/stdc++.h>
using namespace std;
  
#define int long long

// Running in O(n*logn + m*logn^2)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<int> roots, somaSeg, esq, dir;
const int MAXN = 100000 + 100;

int create(){
    somaSeg.push_back(0);
    esq.push_back(0);
    dir.push_back(0);
    return somaSeg.size() - 1;
}

int update(int p, int l, int r, int id, int val){
    int novo = create();
    somaSeg[novo] = somaSeg[p];
    esq[novo] = esq[p];
    dir[novo] = dir[p];

    if(l == r){
        somaSeg[novo] = val;
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
    somaSeg[novo] = somaSeg[esq[novo]] + somaSeg[dir[novo]];
    return novo;
}

int query(int p, int l, int r, int ql, int qr){
    if(qr < l || ql > r) return 0;
    if(p == 0) return 0;
    if(l >= ql && r <= qr) return somaSeg[p];
    int m = (l + r) >> 1;
    return query(esq[p], l, m, ql, qr) + query(dir[p], m + 1, r, ql, qr);
}

int search(int ql, int qr,int k){
    int l = 0;
    int r = roots.size() - 1;
    int version = r;
    while(l <= r){
        int mid = (l + r) >> 1;
        int check = query(roots[mid], 0, MAXN, ql, qr);
        if(check >= k){
            if(check == k) version = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return version;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<ii> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());

    create();
    roots.push_back(create());
    for(int i = 0; i < n; i++){
        auto [val, pos] = v[i];
        roots.push_back(update(roots.back(), 0, MAXN, pos, 1));
    }
    
    while(q--){
        int l, r, k;
        cin >> l >> r >> k;
        l--, r--;
        int version = search(l, r, k);
        cout << v[version - 1].first << '\n';
    }
    return 0;
}