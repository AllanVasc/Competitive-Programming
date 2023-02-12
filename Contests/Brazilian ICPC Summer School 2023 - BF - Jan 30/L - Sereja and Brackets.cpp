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
    int answ = 0;
    int open = 0;
    int close = 0;
};
const int MAXN = 1e6 + 100;
Node seg[4 * MAXN];
string s;

Node merge(Node& a, Node& b){
    Node aux;
    aux.answ = a.answ + b.answ + min(a.open, b.close);
    aux.open = a.open + b.open - min(a.open, b.close);
    aux.close = a.close + b.close - min(a.open, b.close); 
    return aux;
}

void build(int p, int l, int r){
    if(l == r){
        seg[p].answ = 0;
        seg[p].open = (s[l - 1] == '(');
        seg[p].close = (s[l - 1] == ')');
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

    cin >> s;
    build(1, 1, s.size());

    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << 2 * query(1, 1, s.size(), l, r).answ << '\n';
    }

    return 0;
}