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

const int ms = 6000;
int seg[4 * ms];

void build(int p, int l, int r){
    if(l == r){
        seg[p] = INF;
    }
    else{
        int m = (l + r) >> 1;
        int lc = 2*p;
        int rc = lc + 1;
        build(lc, l, m);
        build(rc, m + 1, r);
        seg[p] = min(seg[lc], seg[rc]);
    }
}

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
    if(l >= ql && r <= qr){
        return seg[p];
    }
    int m = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    if(qr <= m) return query(lc, l, m, ql, qr);
    else if(ql > m) return query(rc, m + 1, r, ql, qr);
    else{
        return min(query(lc, l, m, ql, qr), query(rc, m + 1, r, ql, qr));
    }
}

vector<int> ant;
bool check(int range, int dist, int b){
    int m = ant.size();
    vector<vector<int>> dp(m + 5, vector<int>(dist + 5, INF));

    // Base case
    for(int i = 0; i <= min(dist, range); i++){
        dp[0][i] = min(dp[0][i], abs(i - ant[0]));
    }
    for(int i = 1; i < m; i++){
        build(1, 0, ms - 1);
        for(int j = 0; j <= dist; j++){
            update(1, 0, ms - 1, j, dp[i - 1][j]);
        }
        for(int j = 0; j <= dist; j++){
            dp[i][j] = min(dp[i][j],
                           query(1, 0, ms - 1, max(0LL, j - range), j)
                           + abs(ant[i] - j));
        }
    }
    build(1, 0, ms - 1);
    for(int j = 0; j <= dist; j++){
        update(1, 0, ms - 1, j, dp[m - 1][j]);
    }
    // cout << "dp final:" << endl;
    // for(int i = 0; i < m; i++){
    //     cout << "ant = " << i << ": ";
    //     for(int j = 0; j <= dist + 4; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int minCost = query(1, 0, ms - 1, max(0LL, dist - range), dist);
    //cout << "min cost = " << minCost << endl;
    return minCost <= b;
}

int32_t main() {
    optimize;
    
    int d, b, m;
    cin >> d >> b >> m;
    ant.assign(m, 0);
    for(int i = 0; i < m; i++) cin >> ant[i];
    sort(ant.begin(), ant.end());
    int l = 1;
    int r = 5000 + 5;
    int answ = r;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(check(mid, d, b)){
            answ = min(answ, mid);
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout << answ << '\n';
    return 0;
}