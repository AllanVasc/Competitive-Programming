#include <bits/stdc++.h>
using namespace std;

// #define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;

const int MAXR = 1e9 + 1;

vector<int> soma, esq, dir;
vector<bool> lazy;

int create(){
    soma.push_back(0);
    lazy.push_back(0);
    esq.push_back(0);
    dir.push_back(0);
    return soma.size() - 1;
}

void propagate(int p, int l, int r){
    if(p == 0 || lazy[p] == 0) return;
    if(lazy[p]){
        soma[p] = (r - l + 1) - soma[p];
    }
    if(l != r){
        if(esq[p] == 0){
            int aux = create();
            esq[p] = aux;
        }
        if(dir[p] == 0){
            int aux = create();
            dir[p] = aux;
        }
        lazy[esq[p]] = !lazy[esq[p]];
        lazy[dir[p]] = !lazy[dir[p]];
    }
    lazy[p] = 0;
}

void update(int p, int l, int r, int ql, int qr){
    propagate(p, l, r);
    if(l > qr || r < ql) return;
    if(ql <= l && r <= qr){
        lazy[p] = true;
        propagate(p, l, r);
    }
    else{
        int m = (l + r) >> 1;
        if(esq[p] == 0){
            int aux = create();
            esq[p] = aux;
        }
        if(dir[p] == 0){
            int aux = create();
            dir[p] = aux;
        }
        update(esq[p], l, m, ql, qr);
        update(dir[p], m + 1, r, ql, qr);
        soma[p] = soma[esq[p]] + soma[dir[p]];
    }
}

int query(int p, int l, int r, int ql, int qr){
    propagate(p, l, r);
    if(l > qr || r < ql) return 0;
    if(p == 0) return 0;
    if(l >= ql && r <= qr) return soma[p];
    int m = (l + r) >> 1;
    return query(esq[p], l, m, ql, qr) + query(dir[p], m + 1, r, ql, qr);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    vector<tuple<int,int,int,int>> events; // { ev, x, y1, y2}
    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
        events.push_back({x1, 0, y1, y2});
        events.push_back({x2, 1, y1, y2});
    }
    sort(events.begin(), events.end());
    create();
    create();
    long long int answ = 0;
    int lastx = get<0>(events[0]);

    for(int i = 0; i < events.size(); i++){
        auto [x, ev, y1, y2] = events[i];
        // cout << "query = " << query(1, -1, MAXR, 0, MAXR) << '\n';
        answ += 1LL * (x - lastx) * query(1, -1, MAXR, 0, MAXR);
        if(ev == 0){
            update(1, -1, MAXR, y1, y2 - 1);
        }
        else{
            update(1, -1, MAXR, y1, y2 - 1);
        }
        lastx = x;
    }
    cout << answ << '\n';
    return 0;
}