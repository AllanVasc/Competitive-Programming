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
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];

        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 1; i < n; i++) pq.push(v[i]);

        int answ = v[0];
        while(!pq.empty()){
            int aux = pq.top();
            pq.pop();
            if(aux <= answ) continue;
            answ = (answ + aux + 1) / 2;
        }

        cout << answ << '\n';
    }
    
    return 0;
}