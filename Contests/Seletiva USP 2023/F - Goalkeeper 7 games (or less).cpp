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

const int ms = 2e5;
int seg[4*ms];

void update(int p, int l, int r, int idx, int val){
    if(l == r){
        seg[p] = val;
    }
    else{
        int m = (l + r) >> 1;
        int lc = 2*p;
        int rc = lc + 1;
        if(idx <= m) update(lc, l, m, idx, val);
        else update(rc, m + 1, r, idx, val);
        seg[p] = min(seg[lc], seg[rc]);
    }
}

int query(int p, int l, int r, int ql, int qr){
    if(l > qr || r < ql) return INF;
    if(l >= ql && r <= qr) return seg[p];
    int m = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    return min(query(lc, l, m, ql, qr), query(rc, m + 1, r, ql, qr));
}

void debug_seg(int n){
    cout << "seg = ";
    for(int i = 0; i < n; i++){
        int val = query(1, 0, n - 1, i, i);
        cout <<  (val == INF ? -1 : val) << " ";
    }
    cout << '\n';
}

void delete_val(map<int, set<int>> & loc, vector<int> & v, int idx, bool flag = false){
    int n = v.size();
    auto itr = loc[v[idx]].lower_bound(idx);
    if(itr != loc[v[idx]].begin()){
        if(next(itr) != loc[v[idx]].end()){
            update(1, 0, n - 1, *prev(itr), *next(itr));
        }
        else{
            update(1, 0, n - 1, *prev(itr), INF);
        }
    }
    loc[v[idx]].erase(itr);
}

void insert_val(map<int, set<int>> & loc, vector<int> & v, int idx, int x, bool flag = false){
    int n = v.size();
    v[idx] = x;
    auto itr = loc[x].lower_bound(idx);
    if(itr != loc[x].begin()){
        update(1, 0, n - 1, *prev(itr), idx);
    }
    if(itr != loc[x].end()){
        update(1, 0, n - 1, idx, *itr);
    }
    else{
        update(1, 0, n - 1, idx, INF);
    }
    loc[x].insert(idx);
}

signed main() {
    optimize;
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    map<int, set<int>> loc;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        insert_val(loc, v, i, v[i]);
    }
    while(q--){
        int cmd; cin >> cmd;
        if(!cmd){
            // update
            int idx, x;
            cin >> idx >> x;
            idx--;
            delete_val(loc, v, idx);
            insert_val(loc, v, idx, x);
        }
        else{
            int ql, qr; cin >> ql >> qr;
            ql--, qr--;
            int val = query(1, 0, n - 1, ql, qr);
            if(val > qr){
                cout << -1 << '\n';
            }
            else{
                pair<int,int> pos1;
                pos1.first = val;
                pos1.second = *prev(loc[v[val]].lower_bound(val));
                int bckp = v[pos1.first];
                delete_val(loc, v, pos1.first);
                insert_val(loc, v, pos1.first, -1);
                delete_val(loc, v, pos1.second);
                insert_val(loc, v, pos1.second, -2);
                pair<int, int> pos2;
                val = query(1, 0, n - 1, ql, qr);
                if(val > qr){
                    cout << -1 << '\n';
                }
                else{
                    pos2.first = val;
                    pos2.second = *prev(loc[v[val]].lower_bound(val));
                    cout << pos1.first + 1 << " " << pos1.second + 1 << " ";
                    cout << pos2.first + 1 << " " << pos2.second + 1 << '\n';
                }
                delete_val(loc, v, pos1.first);
                insert_val(loc, v, pos1.first, bckp);
                delete_val(loc, v, pos1.second);
                insert_val(loc, v, pos1.second, bckp);
            }
        }
    }
    return 0;
}