#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

signed main() {
    optimize;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> L(n), R(n), A(n), B(n);
        vector<int> coord;
        for(int i = 0 ; i < n; i++){
            cin >> L[i] >> R[i] >> A[i] >> B[i];
            coord.push_back(L[i]);
            coord.push_back(R[i]);
            coord.push_back(A[i]);
            coord.push_back(B[i]);
        }
        int q; cin >> q;
        vector<int> Q(q);
        for(int i = 0; i < q; i++){
            cin >> Q[i];
            coord.push_back(Q[i]);
        }
        sort(ALL(coord));
        for(int i = 0; i < n; i++){
            L[i] = lower_bound(ALL(coord), L[i]) - coord.begin();
            R[i] = lower_bound(ALL(coord), R[i]) - coord.begin();
            A[i] = lower_bound(ALL(coord), A[i]) - coord.begin();
            B[i] = lower_bound(ALL(coord), B[i]) - coord.begin();
        }
        for(int i = 0; i < q; i++){
            Q[i] = lower_bound(ALL(coord), Q[i]) - coord.begin();
        }
        vector<tuple<int,int,int>> events;
        for(int i = 0; i < n; i++){
            events.emplace_back(R[i], B[i], L[i]);
        }
        sort(ALL(events)); reverse(ALL(events));
        priority_queue<pii> pq;
        vector<int> answ(coord.size(), -1);
        int idx = 0;
        for(int i = coord.size() - 1; i >= 0; i --){
            while(idx < n){
                auto[rc, bc, lc] = events[idx];
                if(rc >= i){
                    pq.push({bc, lc});
                    idx++;
                }
                else break;
            }
            while(!pq.empty() && pq.top().second > i) pq.pop();
            if(!pq.empty()) answ[i] = answ[pq.top().first];
            answ[i] = max(answ[i], i);
        }
        for(int i = 0; i < q; i++){
            cout << coord[answ[Q[i]]] << " ";
        }
        cout << '\n';
    }
    return 0;
}