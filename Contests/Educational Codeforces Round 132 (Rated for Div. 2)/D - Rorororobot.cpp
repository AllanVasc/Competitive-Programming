#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 2*1e5 + 100;
int seg[4 * ms];
vector<int> v;

void build(int p, int l, int r){
    if(l == r){ // Building Leaf
        seg[p] = v[r];
    }
    else{
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        build(lc, l, m);        // Building Left Children
        build(rc, m + 1, r);    // Building Rigth Children
        
        // Building Node (Sum Operation) 
        seg[p] = max(seg[lc], seg[rc]);
    }
}

int query(int p, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){ // This node is inside the range answer
        return seg[p];
    }
    else{
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        // Our answer is just in the Left Children
        if(qr <= m) return query(lc, l, m, ql, qr);

        // Our answer is just in the Rigth Children
        else if(ql > m) return query(rc, m + 1, r, ql, qr);

        // Our answer is an intersection of the 2 sides
        else return max(query(lc, l, m, ql, qr), query(rc, m + 1, r, ql, qr));
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;

    v.assign(m + 1, 0);
    for(int i = 1; i <= m; i++){
        cin >> v[i];
    }

    build(1, 1, m);

    int q;
    cin >> q;
    while(q--){
        int rs, cs, rf, cf, k;
        cin >> rs >> cs >> rf >> cf >> k;

        if(cs > cf){
            swap(cs, cf);
            swap(rs, rf);
        }

        int maxHeight = query(1, 1, m, cs, cf);
        // cout << "maxHeight = " << maxHeight << '\n';

        int hNeed = rs;
        if(maxHeight >= rs){
            int jumps = (maxHeight - rs) / k + 1;
            hNeed = jumps * k + rs;
            //cout << "hNeed = " << hNeed << '\n';
        }
        if(hNeed > n){
            cout << "NO" << '\n';
        }
        else{
            if((cf - cs) % k != 0){
                cout << "NO" << '\n';
            }
            else{
                if(abs(hNeed - rf) % k == 0){
                    cout << "YES" << '\n';
                }
                else{
                    cout << "NO" << '\n';
                }
            }
        }
    }
    return 0;
}