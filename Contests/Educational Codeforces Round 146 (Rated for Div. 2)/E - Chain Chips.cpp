#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 2;

struct Node{
    int dp[ms][ms];
    Node(){
        init();
    }
    Node(int x){
        init();
        dp[0][0] = 0;
        dp[1][1] = x;
    }
    Node(Node l, Node r){
        init();
        for(int i = 0; i < ms; i++){
            for(int j = 0; j < ms; j++){
                for(int k = 0; k < ms; k++){
                    for(int x = 0; x < ms; x++){
                        if(j == 0 && k == 0) continue;
                        dp[i][x] = min(dp[i][x], l.dp[i][j] + r.dp[k][x]);
                    }
                }
            }
        }
    }
    void init(){
        for(int i = 0; i < ms; i++){
            for(int j = 0; j < ms; j++){
                dp[i][j] = INF;
            }
        }
    }
};

const int N = 2*1e5 + 100;
Node seg[4 * N];
int v[N];

void build(int p, int l, int r){
    if(l == r){
        seg[p] = Node(v[l]);
    }
    else{
        int m = (l + r) >> 1;
        int lc = 2*p;
        int rc = lc + 1;
        build(lc, l, m);
        build(rc, m + 1, r);
        seg[p] = Node(seg[lc], seg[rc]);
    }
}

void update(int p, int l, int r, int idx, int x){
    if(l == r){
        seg[p] = Node(x);
    }
    else{
        int m = (l + r) >> 1;
        int lc = 2*p;
        int rc = lc + 1;
        if(idx <= m) update(lc, l, m, idx, x);
        else update(rc, m + 1, r, idx, x);
        seg[p] = Node(seg[lc], seg[rc]);
    }
}

Node query(int p, int l, int r, int ql, int qr){
    if(l >= ql && r <= qr) return seg[p];
    int m = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    if(qr <= m) return query(lc, l, m, ql, qr);
    else if(ql > m) return query(rc, m + 1, r, ql, qr);
    return Node(query(lc, l, m, ql, qr), query(rc, m + 1, r, ql, qr));
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) cin >> v[i];
    build(1, 0, n - 2);
    int q;
    cin >> q;
    while(q--){
        int idx, x;
        cin >> idx >> x;
        idx--;
        update(1, 0, n - 2, idx, x);
        cout << query(1, 0, n - 2, 0, n - 2).dp[1][1] * 2 << '\n';
    }
    return 0;
}