#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

// In main we need to call create 2 times
// p == 0 -> NULL
// p == 1 -> Root

vector<int> answSeg, lazySeg, lNodes, rNodes;

// Returns the node index
int create(){
    answSeg.push_back(0);   // Must be a default value 
    lazySeg.push_back(0);   // Must be a default value
    lNodes.push_back(0);    // The index "0" will always represent the null node 
    rNodes.push_back(0);    // The index "0" will always represent the null node
    return answSeg.size() - 1;
}

void propagate(int p, int l, int r){
    if(p == 0 || lazySeg[p] == 0) return;
    answSeg[p] += (r - l + 1) * lazySeg[p];
    if(l != r){
        if(lNodes[p] == 0){
            int aux = create();
            lNodes[p] = aux;
        }
        if(rNodes[p] == 0){
            int aux = create();
            rNodes[p] = aux;
        }
        lazySeg[lNodes[p]] += lazySeg[p];
        lazySeg[rNodes[p]] += lazySeg[p];
    }
    lazySeg[p] = 0;
}

void update(int p, int l, int r, int ql, int qr, int val){
    propagate(p, l, r);
    if(l > qr || r < ql) return;
    if(ql <= l && r <= qr){
        lazySeg[p] = val;
        propagate(p, l, r);
    }
    else{
        int m = (l + r) >> 1;
        if(lNodes[p] == 0){
            int aux = create();
            lNodes[p] = aux;
        }
        if(rNodes[p] == 0){
            int aux = create();
            rNodes[p] = aux;
        }
        update(lNodes[p], l, m, ql, qr, val);
        update(rNodes[p], m + 1, r, ql, qr, val);
        answSeg[p] = answSeg[lNodes[p]] + answSeg[rNodes[p]];
    }
}

int query(int p, int l, int r, int ql, int qr){
    propagate(p, l, r);
    if(l > qr || r < ql) return 0;
    if(p == 0) return 0;
    if(l >= ql && r <= qr) return answSeg[p];
    int m = (l + r) >> 1;
    return query(lNodes[p], l, m, ql, qr) + query(rNodes[p], m + 1, r, ql, qr);
}

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
        answSeg.clear();
        lazySeg.clear();
        lNodes.clear();
        rNodes.clear();
        create();
        create();
        // segTree seg(n + 1);
        vector<int> resto(n + 100, 0);
        int offset = 0;
        for(int i = 0; i < n; i++){
            int val = numbers[i];
            val += offset;
            // cout << "to procurando " << val << '\n';
            auto pos = lower_bound(ps.begin(), ps.end(), val);
            
            // if(pos == ps.begin()) continue;
            if(pos == ps.end()){
                // seg.update(1, 1, n + 1, i + 1, n, 1);
                update(1, 0, n + 1, i + 1, n, 1);
            }
            else{
                int idx = pos - ps.begin();
                // cout << "ate " << idx <<'\n';
                if(ps[idx] >= val){
                    resto[idx] += val - ps[idx - 1];
                    // cout << "Vou add = " << val - ps[idx - 1] << '\n';
                }
                // seg.update(1, 1, n + 1, i + 1, idx - 1, 1);
                update(1, 0, n + 1, i + 1, idx - 1, 1);
            }
            offset += canDrink[i];
        }

        for(int i = 1; i <= n; i++){
            cout << query(1, 0, n + 1, i, i) * canDrink[i - 1] + resto[i] << " ";
            //cout << seg.query(1, 1, n + 1, i, i) * canDrink[i - 1] + resto[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}