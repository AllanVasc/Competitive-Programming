#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define t4 tuple<int,int,int,int>
const int INF = 1e18;

struct node{
    int a, b, idx;
    node() {};
    node(int a, int b, int idx) : a(a), b(b), idx(idx) {}
};

// Debug function
ostream &operator << (ostream &os, const node &p){
    return os << "[" << p.a << ", " << p.b << ", " << p.idx << "]";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, energy;
    cin >> n >> energy;
    vector<node> v(n);
    for(int i = 0; i < n; i++){
        int val; cin >> val;
        v[i].a = val;
        v[i].idx = i;
    }
    for(int i = 0; i < n; i++){
        int val; cin >> val;
        v[i].b = val;
    }
    sort(v.begin(), v.end(), [&](const node a, const node b){
        return a.a < b.a;
    });
    vector<int> answ(n, 0);
    int qtt = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        auto [a,b,idx] = v[i];
        if(cnt + a <= energy){
            cnt += a;
            answ[idx] = 1;
            qtt++;
        }
        else break;
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int i = 0; i < qtt; i++){
        pq.push({v[i].b - v[i].a, v[i].idx});
    }
    vector<node> minimalb;
    for(int i = qtt; i < n; i++){
        minimalb.push_back(v[i]);
    }
    sort(minimalb.begin(), minimalb.end(), [&](const node a, const node b){
        return a.b < b.b;
    });
    int mnbSz = minimalb.size();
    int l = qtt - 1;
    int r = 0;
    // for(auto x : v) cout << x << " ";
    // cout << '\n';
    // cout << "antes de ajeitar: ";
    // for(auto x : answ) cout << x;
    // cout << '\n';
    if(l >= 0){
        bool f = true;
        while(f){
            f = false;
            pii inPq = {INF, -1};
            while(!pq.empty()){
                pii aux = pq.top();
                if(answ[aux.second] == 1){
                    inPq = aux;
                    break;
                }
                else{
                    pq.pop();
                }
            }
            // cout << "op1 = " << "{" << inPq.first << ", " << inPq.second << "}\n";
            while(l >= 0 && (answ[v[l].idx] == 2)) l--;
            while(r < mnbSz && answ[minimalb[r].idx]) r++;
            int op1 = inPq.first;
            int op2 = INF;
            if(l >= 0 && r < mnbSz){
                op2 = minimalb[r].b - v[l].a;
            }
            // cout << "l = " << l << " r = " << r << '\n';
            // cout << "op1 = " << op1 << '\n';
            // cout << "op2 = " << op2 << '\n';
            if(cnt + min(op1, op2) <= energy){
                f = true;
                if(op1 < op2){
                    cnt += op1;
                    pq.pop();
                    answ[inPq.second] = 2;
                }
                else{
                    cnt += op2;
                    answ[v[l].idx] = 0;
                    answ[minimalb[r].idx] = 2;
                    l--;
                }
            }
            // cout << "Ajeitei: ";
            // for(auto x : answ) cout << x;
            // cout << '\n';
            // cout << '\n';
        }
    }

    for(auto x : answ) cout << x;
    cout << '\n';
    return 0;
}


