#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 1e5 + 100;
int seg[4*ms];
void update(int p, int l, int r, int idx){
    if(l == r) seg[p] = 1;
    else{
        int m = (l + r) >> 1;
        int lc = 2*p;
        int rc = lc + 1;
        if(idx <= m) update(lc, l, m, idx);
        else update(rc, m + 1, r, idx);
        seg[p] = seg[lc] + seg[rc];
    }
}

int query(int p, int l, int r, int ql, int qr){
    if(r < ql || l > qr) return 0;
    if(l >= ql && r <= qr) return seg[p];
    int m = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    return query(lc, l, m, ql, qr) + query(rc, m + 1, r, ql, qr);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n, d;
    cin >> n >> d;
    vector<ii> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end(), [](ii& a, ii&b){
        if(a.first != b.first) return a.first > b.first;
        else{
            return a.second < b.second;
        }
    });

    vector<iii> maxlen;
    for(int i = 0; i < n; i++){
        auto [val, pos] = v[i];
        int l = pos;
        int r = n - 1;
        int answ = pos;
        while(l <= r){
            int mid = l + (r - l)/2;
            int check = query(1,0, n - 1, l, mid);
            if(check <= 0){
                answ = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        // cout << "val = " << val << " pos = " << pos << " end = " << answ << "\n";
        maxlen.push_back({answ - pos + 1, pos, answ});
        update(1,0, n-1, pos);
    }
    sort(maxlen.begin(), maxlen.end(), greater<iii>());
    vector<bool> visited(n, false);
    int answ = 0;
    int cnt = 0;
    for(int i = 0; i < n && cnt < d; i++){
        auto  [sz, st, en] = maxlen[i];
        if(!visited[st]){
            for(int j = st; j <= en; j++) visited[j] = true;
            answ += sz;
            cnt++;
        }
    }
    cout << answ << '\n';
    return 0;
}