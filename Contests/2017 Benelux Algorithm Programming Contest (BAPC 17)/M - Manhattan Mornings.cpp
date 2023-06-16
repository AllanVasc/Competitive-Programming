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
int seg[4 * ms];

void update(int p, int l, int r, int idx, int val){
    if(l == r){
        seg[p] = max(seg[p], val);
    }
    else{
        int m = (l + r) >> 1;
        int lc = 2 * p;
        int rc = lc + 1;
        if(idx <= m) update(lc, l, m, idx, val);
        else update(rc, m + 1, r, idx, val);
        seg[p] = max(seg[lc], seg[rc]);
    }
}

int query(int p, int l, int r, int ql, int qr){
    if(l >= ql && r <= qr) return seg[p];
    int m = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    if(qr <= m) return query(lc, l, m, ql, qr);
    else if(ql > m) return query(rc, m + 1, r, ql, qr);
    return max(query(lc, l, m, ql, qr), query(rc, m + 1, r, ql, qr));
}

int32_t main() {
    optimize;
    int n;
    cin >> n;
    pii house, work;
    cin >> house.first >> house.second >> work.first >> work.second;
    vector<pii> v;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        if(work.first < house.first){
            x = house.first + (house.first - x);
        }
        if(work.second < house.second){
            y = house.second + (house.second - y);
        }
        v.push_back({x, y});
    }
    sort(ALL(v));
    if(work.first < house.first){
        work.first = house.first + (house.first - work.first);
    }
    if(work.second < house.second){
        work.second = house.second + (house.second - work.second);
    }
    vector<int> compress;
    compress.pb(house.second);
    compress.pb(work.second);
    for(int i = 0; i < n; i++){
        compress.pb(v[i].second);
    }
    sort(compress.begin(), compress.end());
    map<int, int> mp;
    for(int i = 0; i < compress.size(); i++){
        int val = compress[i];
        if(mp.count(val) == 0) mp[val] = mp.size();
    }

    for(int i = 0; i < n; i++){
        auto [x, y] = v[i];
        if(x < house.first || x > work.first) continue;
        if(mp[y] < mp[house.second] || mp[y] > mp[work.second]) continue;
        int currAnsw = 1 + query(1, 0, ms - 1, mp[house.second], mp[y]);
        update(1, 0, ms - 1, mp[y], currAnsw);
    }

    cout << query(1, 0, ms - 1, mp[house.second], mp[work.second]) << '\n';

    return 0;
}