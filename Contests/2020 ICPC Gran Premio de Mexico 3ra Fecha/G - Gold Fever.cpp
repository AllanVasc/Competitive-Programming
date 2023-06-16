#include<bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 1e6;
int seg[4 * ms];

void upd(int p, int l, int r, int idx, int val){
    if(l == r){
        seg[p] = val;
    }
    else{
        int m = (l + r) >> 1;
        int lc = 2*p;
        int rc = lc + 1;
        if(idx <= m) upd(lc, l, m, idx, val);
        else upd(rc, m + 1, r, idx, val);
        seg[p] = max(seg[lc], seg[rc]);
    }
}

int query(int p, int l, int r, int ql, int qr){
    if(l >= ql && r <= qr) return seg[p];
    int m = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    if( qr <= m) return query(lc, l, m, ql, qr);
    else if(ql > m) return query(rc, m + 1, r, ql, qr);
    return max(query(lc, l, m, ql, qr), query(rc, m + 1, r, ql, qr));
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> gold(n, 0);
    vector<pair<int,int>> range(n);
    for(int i = 0; i < n; i++){
        cin >> gold[i] >> range[i].first >> range[i].second;
    }

    vector<int> dp(n, 0);
    for(int i = n - 1; i >= 0; i--){
        dp[i] = gold[i] + query(1, 0, ms - 1, i + range[i].first, i + range[i].second);
        upd(1, 0, ms - 1, i, dp[i]);
    }
    int answ = 0;
    for(int i = 0; i < n; i++) answ = max(answ, dp[i]);
    cout << answ << '\n';
    return 0;

}