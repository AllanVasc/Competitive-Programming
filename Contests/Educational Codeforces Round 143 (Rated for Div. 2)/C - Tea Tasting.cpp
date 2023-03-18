#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

class segTree{
    vector<int> seg;
    vector<int> lazy;

public:
    // n = number of elements or v.size() - 1
    segTree(int n){
        seg.assign(4*n, 0);
        lazy.assign(4*n, 0);
        build(1,1,n);
    }
    // Call using update(1,1,n,ql,qr,value) (ql and qr need to be 1-Based)
    void update(int p, int l, int r, int ql, int qr, int value){
        propagate(p,l,r);
        if(r < ql || l > qr) return;
        if(ql <= l && r <= qr){
            lazy[p] = value;
            propagate(p,l,r);
        }
        else{
            int m = (l+r)/2;
            int lc = 2*p;
            int rc = lc + 1;

            update(lc,l,m,ql,qr,value);
            update(rc,m+1,r,ql,qr,value);

            seg[p] = seg[lc] + seg[rc];
        }
    }
    // Call using query(1,1,n,ql,qr) (ql and qr need to be 1-Based)
    int query(int p, int l, int r, int ql, int qr){
        propagate(p,l,r);
        if(r < ql || l > qr) return 0;
        if(ql <= l && r <= qr) return seg[p];

        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        return query(lc,l,m,ql,qr) + query(rc,m+1,r,ql,qr);
    }
    
private:

    void build(int p, int l, int r){
        if(l == r){
            seg[p] = 0;
            lazy[p] = 0;
        }
        else{
            int m = (l+r)/2;
            int lc = 2*p;
            int rc = lc + 1;

            build(lc,l,m);
            build(rc,m+1,r);

            seg[p] = seg[lc] + seg[rc];
        }
    }

    void propagate(int p, int l, int r){
        if(lazy[p] == 0) return;

        seg[p] += (r-l+1)*lazy[p];
        if(l != r){
            lazy[2*p] += lazy[p];
            lazy[2*p + 1] += lazy[p];
        }
        lazy[p] = 0;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> numbers(n), canDrink(n);
        for(int i = 0; i < n; i++) cin >> numbers[i];
        for(int i = 0; i < n; i++) cin >> canDrink[i];

        vector<int> ps(n + 1, 0);
        for(int i = 1; i <= n; i++){
            ps[i] = ps[i - 1] + canDrink[i - 1];
        }

        // cout << "ps: ";
        // for(int i = 0; i <= n; i++) cout << ps[i] << " ";
        // cout << '\n';

        segTree seg(n + 1);
        vector<int> resto(n + 100, 0);
        int offset = 0;
        for(int i = 0; i < n; i++){
            int val = numbers[i];
            val += offset;
            // cout << "to procurando " << val << '\n';
            auto pos = lower_bound(ps.begin(), ps.end(), val);
            
            // if(pos == ps.begin()) continue;
            if(pos == ps.end()){
                seg.update(1, 1, n + 1, i + 1, n, 1);
            }
            else{
                int idx = pos - ps.begin();
                // cout << "ate " << idx <<'\n';
                if(ps[idx] >= val){
                    resto[idx] += val - ps[idx - 1];
                    // cout << "Vou add = " << val - ps[idx - 1] << '\n';
                }
                seg.update(1, 1, n + 1, i + 1, idx - 1, 1);
            }
            offset += canDrink[i];
        }

        for(int i = 1; i <= n; i++){
            cout << seg.query(1, 1, n + 1, i, i) * canDrink[i - 1] + resto[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}