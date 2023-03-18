#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int MAXN = 1e10;
vector<int> answSeg, lNodes, rNodes;

int create(){
    answSeg.push_back(0);
    lNodes.push_back(0);
    rNodes.push_back(0);
    return answSeg.size() -1;
}

void update(int p, int l, int r, int idx, int val){
    if(idx < l || idx > r) return;
    if(l == r){
        answSeg[p] = val;
    }
    else{
        int m = (l + r) >> 1;
        if(idx <= m){
            if(lNodes[p] == 0){
                int aux = create();
                lNodes[p] = aux;
            }
            update(lNodes[p], l, m, idx, val);
        }
        else{
            if(rNodes[p] == 0){
                int aux = create();
                rNodes[p] = aux;
            }
            update(rNodes[p], m + 1, r, idx, val);
        }
        answSeg[p] = answSeg[lNodes[p]] + answSeg[rNodes[p]];
    }
}

int query(int p, int l, int r, int ql, int qr){
    if(qr < l || ql > r) return 0;
    if(p == 0) return 0;
    if(l >= ql && r <= qr) return answSeg[p];
    int m = (l + r) >> 1;
    return query(lNodes[p], l, m, ql, qr) + query(rNodes[p], m + 1, r, ql, qr);
}

int query2(int p, int l, int r, int k){
    if(l == r) return l;
    int m = (l + r) >> 1;
    return (answSeg[lNodes[p]] >= k ? 
            query2(lNodes[p], l, m, k) : 
            query2(rNodes[p], m + 1, r, k - answSeg[lNodes[p]]));
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int q;
    cin >> q;
    create();
    create();
    while(q--){
        char cmd;
        int x;
        cin >> cmd >> x;

        if(cmd == 'I'){
            update(1, -MAXN, MAXN, x, 1);
        }
        else if(cmd == 'D'){
            update(1, -MAXN, MAXN, x, 0);
        }
        else if(cmd == 'K'){
            if(query(1, -MAXN, MAXN, -MAXN, MAXN) < x){
                cout << "invalid" << '\n';
            }
            else{
                int answ = query2(1, -MAXN, MAXN, x);
                cout << answ << '\n';
            }
        }
        else if(cmd == 'C'){
            cout << query(1, -MAXN, MAXN, -MAXN, x - 1) << '\n';
        }
    }
    return 0;
}