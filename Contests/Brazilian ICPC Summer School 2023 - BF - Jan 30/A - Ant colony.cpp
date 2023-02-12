#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

struct Node{
    int gcd = 0;
    int freq = 0;
};

const int MAXN = 1e5 + 100;
Node seg[4 * MAXN];
vector<int> v;

Node merge(Node& a, Node& b){
    Node aux;
    aux.gcd = __gcd(a.gcd, b.gcd);
    if(aux.gcd == a.gcd) aux.freq += a.freq;
    if(aux.gcd == b.gcd) aux.freq += b.freq;
    return aux;
}

void build(int p, int l, int r){
    if(l == r){
        seg[p].gcd = v[l - 1];
        seg[p].freq = 1;
    }
    else{
        int m = (l + r) / 2;
        int lc = 2 * p;
        int rc = lc + 1;
        build(lc, l, m);
        build(rc, m + 1, r);

        seg[p] = merge(seg[lc], seg[rc]);
    }
}

Node query(int p, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr) return seg[p];
    else{
        int m = (l + r) / 2;
        int lc = 2 * p;
        int rc = lc + 1;
        if(qr <= m) return query(lc, l, m, ql, qr);
        else if(ql > m) return query(rc, m + 1, r , ql, qr);
        else{
            Node left = query(lc, l, m, ql, qr);
            Node right = query(rc, m + 1, r , ql, qr);
            return merge(left, right);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    v.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> v[i];
    build(1, 1, n);

    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << (r - l + 1) - query(1, 1, n, l, r).freq << '\n';
    }

    return 0;
}