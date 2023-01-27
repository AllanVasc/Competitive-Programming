//  B - Ahoy, Pirates!
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;

string v;

class segTree{
    vector<ii> seg;
    vector<int> lazy;

public:
    segTree(int n){
        seg.assign(4*n, {0,0});
        lazy.assign(4*n, 0);
        build(1,1,n);
    }
    void update(int p, int l, int r, int ql, int qr, int op){
        propagate(p,l,r);
        if(r < ql || l > qr) return;
        if(ql <= l && r <= qr){
            lazy[p] = op;
            propagate(p,l,r);
        }
        else{
            int m = (l+r)/2;
            int lc = 2*p;
            int rc = lc + 1;

            update(lc,l,m,ql,qr,op);
            update(rc,m+1,r,ql,qr,op);

            ii left = seg[lc];
            ii right = seg[rc];
            seg[p] = {left.first+right.first, left.second + right.second};
        }
    }
    // Call using query(1,1,n,ql,qr) (ql and qr need to be 1-Based)
    ii query(int p, int l, int r, int ql, int qr){
        propagate(p,l,r);
        if(r < ql || l > qr) return {0,0};
        if(ql <= l && r <= qr) return seg[p];

        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;
        
        ii left = query(lc,l,m,ql,qr);
        ii right = query(rc,m+1,r,ql,qr);
        return {left.first+right.first, left.second+right.second};
    }

private:
    void build(int p, int l, int r){
        if(l == r){
            if(v[l] == '1') seg[p] = {1,0};
            else seg[p] = {0,1};
            lazy[p] = 0;
        }
        else{
            int m = (l+r)/2;
            int lc = 2*p;
            int rc = lc + 1;

            build(lc,l,m);
            build(rc,m+1,r);

            ii left = seg[lc];
            ii right = seg[rc];
            seg[p] = {left.first+right.first, left.second+right.second};
        }
    }

    void propagate(int p, int l, int r){
        if(lazy[p] == 0) return;

        if(lazy[p] == 1){ // Todo mundo virou '1'
            seg[p] = {seg[p].first + seg[p].second, 0};
            if(l != r){
                lazy[2*p] = lazy[p];
                lazy[2*p + 1] = lazy[p];
            }
            lazy[p] = 0;
        }
        else if(lazy[p] == 2){  // Todo mundo virou '0'
            seg[p] = {0, seg[p].first + seg[p].second};
            if(l != r){
                lazy[2*p] = lazy[p];
                lazy[2*p + 1] = lazy[p];
            }
            lazy[p] = 0;
        }
        else if(lazy[p] == 3){  // Inverteu
            seg[p] = {seg[p].second, seg[p].first};
            if(l != r){
                if(lazy[2*p] == 0) lazy[2*p] = 3;
                else if(lazy[2*p] == 1) lazy[2*p] = 2;
                else if(lazy[2*p] == 2) lazy[2*p] = 1;
                else lazy[2*p] = 0;
                
                if(lazy[2*p+1] == 0) lazy[2*p+1] = 3;
                else if(lazy[2*p+1] == 1) lazy[2*p+1] = 2;
                else if(lazy[2*p+1] == 2) lazy[2*p+1] = 1;
                else lazy[2*p+1] = 0;
            }
            lazy[p] = 0;
        }
    }
};

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    int count = 1;

    while(t--){

        int m;
        cin >> m;
        v.clear();
        v += '*';

        cout << "Case " << count << ":\n";

        for(int i = 0; i < m; i++){
            int times;
            string aux;
            cin >> times >> aux;
            while(times--){
                v += aux;
            }
        }
        // cout << v << '\n';

        segTree seg(v.size()-1);
        
        int q;
        cin >> q;

        int qtdQuery = 1;

        for(int i = 0; i < q; i++){
            char cmd;
            int ql,qr;
            cin >> cmd >> ql >> qr;
            if(cmd == 'F'){ // index a to b to Buccaneer Pirates.
                seg.update(1,1,v.size()-1,ql+1,qr+1,1);
            }
            else if(cmd == 'E'){ //  index a to b to Barbary Pirates.
                seg.update(1,1,v.size()-1,ql+1,qr+1,2);
            }
            else if(cmd == 'I'){ // index a to b to inverse pirates.
                seg.update(1,1,v.size()-1,ql+1,qr+1,3);
            }
            else{ // How many Buccaneer Pirates
                // cout << "{" << seg.query(1,1,v.size()-1,ql+1,qr+1).first << "," << seg.query(1,1,v.size()-1,ql+1,qr+1).second << "}\n";
                cout << "Q" << qtdQuery << ": " << seg.query(1,1,v.size()-1,ql+1,qr+1).first << '\n';
                qtdQuery++;
            }
        }
        count++;
    }
    return 0;
}
