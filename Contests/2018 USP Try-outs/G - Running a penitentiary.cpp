#include <bits/stdc++.h>

using namespace std;

vector <pair <int, int>> tree;
const int inf = 1e9 + 5;

void build(int n){
    tree.assign(4*n, {-inf, inf});
}

void update(int n, int l, int r, int p, pair <int, int> val){
    if(l == r){
        tree[n] = val;
        return;
    }

    int mid = (l+r)/2;
    if(p <= mid) update(2*n, l, mid, p, val);
    else update(2*n + 1, mid + 1, r, p, val);

    tree[n].first = max(tree[2*n].first, tree[2*n + 1].first);
    tree[n].second = min(tree[2*n].second, tree[2*n + 1].second);
}

pair <int, int> query(int n, int l, int r, int L, int R){
    if(l > R || r < L) return {-inf, inf};
    if(L <= l && r <= R) return tree[n];

    pair <int, int> ans, q1, q2;
    int m = (l+r)/2;
    q1 = query(2*n, l, m, L, R);
    q2 = query(2*n + 1, m + 1, r, L, R);

    ans.first = max(q1.first, q2.first);
    ans.second= min(q1.second, q2.second);

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;

    build(n);

    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;

        update(1, 0, n-1, i, {l, r});
    }

    while(q--){
        char cmd;
        cin >> cmd;

        if(cmd == 'C'){
            int pos, l, r;
            cin >> pos >> l >> r;
            pos--;

            update(1, 0, n-1, pos, {l, r});
        }

        else{
            int l, r;
            cin >> l >> r;
            l--; r--;
            pair <int, int> ans = query(1, 0, n-1, l, r);

            cout << max(0, ans.second - ans.first + 1) << "\n";
        }
    }

    return 0;
}