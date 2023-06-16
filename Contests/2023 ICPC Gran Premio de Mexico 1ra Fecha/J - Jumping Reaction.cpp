#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
const int MOD = 1e9 + 7;
struct Node{
    int answ, sum;
    bool isLeaf;
    Node(){}
    Node(int a, int b) : answ(a), sum(b) {
        isLeaf = false;
    }
    Node(Node  a, Node  b){
        int answA = (a.isLeaf ? 0 : a.answ);
        int sumA = a.sum;
        int answB = (b.isLeaf ? 0 : b.answ);
        int sumB = b.sum;
        answ = ((answA + answB) % MOD + (sumA * sumB % MOD)) % MOD;
        sum = (a.sum + b.sum) % MOD;
        isLeaf = false;
    }
};


const int ms = 1e6 + 10;
Node seg[4 * ms];
vector<int> v;
void build(int p, int l, int r){
    if(l == r){
        seg[p] = Node(v[l], v[l]);
        seg[p].isLeaf = true;
        // cout << "[" << l << "," << r << "] = " << seg[p].answ << " " << seg[p].sum << endl;
    }
    else{
        int m = (l + r) >> 1;
        int lc = 2*p;
        int rc = lc + 1;
        build(lc, l, m);
        build(rc, m + 1, r);
        seg[p] = Node(seg[lc], seg[rc]);
        // cout << "[" << l << "," << r << "] = " << seg[p].answ << " " << seg[p].sum << endl;
    } 
}

Node query(int p, int l, int r, int ql, int qr){
    if(l >= ql && r <= qr) return seg[p];
    int m = (l + r) >> 1;
    int lc = 2 * p;
    int rc = lc + 1;
    if(qr <= m){
        return query(lc, l, m, ql, qr);
    }
    else if(ql > m){
        return query(rc, m + 1, r, ql, qr);
    }
    else{
        return Node(query(lc, l, m, ql, qr), query(rc, m + 1, r, ql, qr));
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, q;
    cin >> n >> q;
    v.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> v[i];
    build(1, 0, n - 1);
    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        Node answ = query(1, 0, n - 1, l, r);
        cout << answ.answ % MOD << '\n';
    }
    return 0;
}