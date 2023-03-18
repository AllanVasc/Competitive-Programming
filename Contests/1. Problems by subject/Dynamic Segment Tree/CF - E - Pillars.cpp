#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int MAXN = 1e16;
vector<int> answSeg, lNodes, rNodes;

int create(){
    answSeg.push_back(0);
    lNodes.push_back(0);
    rNodes.push_back(0);
    return answSeg.size() - 1;
}

void update(int p, int l, int r, int id, int val){
    if(l > id || r < id) return;
    if(l == r){
        answSeg[p] = val;
    }
    else{
        int m = (l + r) >> 1;
        if(id <= m){
            if(lNodes[p] == 0){
                int aux = create();
                lNodes[p] = aux;
            }
            update(lNodes[p], l, m, id, val);
        }
        else{
            if(rNodes[p] == 0){
                int aux = create();
                rNodes[p] = aux;
            }
            update(rNodes[p], m + 1, r, id, val);
        }
        answSeg[p] = max(answSeg[lNodes[p]], answSeg[rNodes[p]]);
    }
}

int query(int p, int l, int r, int ql, int qr){
    if(ql > r || l > qr) return 0;
    if(p == 0) return 0;
    if(l >= ql && r <= qr) return answSeg[p];
    int m = (l + r) >> 1;
    return max(query(lNodes[p], l, m, ql, qr), query(rNodes[p], m + 1, r, ql, qr));
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    create();
    create();
    vector<int> answ(n);
    int best = 0;
    for(int i = n - 1; i >= 0; i--){
        int curr_h = v[i];
        int curr_answ = 0;
        curr_answ = max(curr_answ, query(1, -MAXN, MAXN, curr_h + d, MAXN));
        if(curr_h - d >= 1){
            curr_answ = max(curr_answ, query(1, -MAXN, MAXN, 1, curr_h - d));
        }
        curr_answ++;
        update(1, -MAXN, MAXN, curr_h, curr_answ);
        answ[i] = curr_answ;
        best = max(best, curr_answ);
    }

    cout << best << '\n';
    int lastH = -MAXN;
    for(int i = 0; i < n && best; i++){
        if(answ[i] == best && abs(v[i] - lastH) >= d){
            cout << i + 1 << " ";
            best--;
            lastH = v[i];
        }
    }
    cout << '\n';
    return 0;
}