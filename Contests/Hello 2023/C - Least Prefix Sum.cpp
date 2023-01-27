#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> v(n);
        m--;
        for(int i = 0; i < n; i++) cin >> v[i];

        vector<int> ps(n);
        ps[0] = v[0];
        for(int i = 1; i < n; i++){
            ps[i] = ps[i - 1] + v[i];
        }
        
        int answ = 0;
        // Before position "m"
        priority_queue<int> pqmax;
        int offset = 0;
        for(int i = m; i >= 0; i--){
            while(ps[m] + offset > ps[i]){
                int best = pqmax.top();
                pqmax.pop();
                offset += 2*(-best);
                answ++;
            }
            pqmax.push(v[i]);
        }
        // cout << "ps[m] = " << ps[m] << '\n';
        
        // after "m"
        priority_queue<int, vector<int>, greater<int>> pqmin;
        offset = 0;
        for(int i = m + 1; i < n; i++){
            pqmin.push(v[i]);
            while(ps[m] > ps[i] + offset){
                int best = pqmin.top();
                pqmin.pop();
                offset += 2*(-best);
                answ++;
            }
        }

        cout << answ << '\n';
    }
    return 0;
}