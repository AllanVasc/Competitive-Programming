#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int MAXVAL = 1e9 + 100;
vector<int> roots, somaSeg, esq, dir;

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
        somaSeg[novo] += val;
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
    if(r < ql || l > qr) return 0;
    if(p == 0) return 0;
    if(l >= ql && r <= qr) return somaSeg[p];
    int m = (l + r) >> 1;
    return query(esq[p], l, m, ql, qr) + query(dir[p], m + 1, r, ql ,qr);
}

int query2(int ql, int qr, int val, int limit){
    // cout << "de " << ql << " ah " << qr << "contando " << val << " limit = " << limit << '\n';
    int sumQr = query(roots[qr], 0, MAXVAL, 0, val);
    int sumQl = query(roots[ql - 1], 0, MAXVAL, 0, val);
    // cout << "prefix[0,qr] = " << sumQr << '\n';
    // cout << "prefix[0,ql - 1] = " << sumQl << '\n';
    return sumQr - sumQl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    create();
    roots.push_back(create());
    for(int i = 0; i < n; i++){
        roots.push_back(update(roots.back(), 0, MAXVAL, v[i], v[i]));
    }

    int last = 0;
    while(q--){
        int xi, yi, zi;
        cin >> xi >> yi >> zi;
        int ql = 1 + (xi + last - 1) % n;
        int qr = 1 + (yi + last - 1) % n;
        int limit = (zi + last);

        int answ = 0;
        int l = 0;
        int r = 1e9 + 10;
        while(l <= r){
            int mid = l + (r - l) / 2;
            int check = query2(ql, qr, mid, limit);
            if(check <= limit){
                answ = check;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        last = answ;
        cout << answ << '\n';
    }
    return 0;
}