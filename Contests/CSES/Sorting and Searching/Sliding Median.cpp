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

const int ms = 2e5 + 100;
int seg[4 * ms];
void update(int p, int l, int r, int idx, int val){
    if(l == r){
        seg[p] += val;
        return;
    }
    int mid = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    if(idx <= mid) update(lc, l, mid, idx, val);
    else update(rc, mid + 1, r, idx, val);
    seg[p] = seg[lc] + seg[rc];
}

int query(int p, int l, int r, int k){
    if(l == r) return l;
    int mid = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    if(k > seg[lc]) return query(rc, mid + 1, r, k - seg[lc]);
    else return query(lc, l, mid, k);
}

int32_t main() {
    optimize;
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int cnt = 0;
    vector<int> comp = v;
    sort(ALL(comp));
    map<int,int> compression;
    map<int,int> original;
    for(int i = 0; i < n; i++){
        if(compression.count(comp[i]) == 0){
            compression[comp[i]] = cnt++;
            original[compression[comp[i]]] = comp[i];
        }
    }
    int l = 0;
    int r = 0;
    while(r < n){
        while(r - l < k){
            update(1, 0, n, compression[v[r]], 1);
            r++;
        }
        int mid = (k % 2 == 0 ? k/2 : k/2 + 1);
        cout << original[query(1, 0, n, mid)] << " ";
        update(1, 0, n, compression[v[l]], -1);
        l++;
    }
    cout << '\n';
    return 0;
}