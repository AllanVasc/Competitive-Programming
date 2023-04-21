#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;
const int MOD = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n, c, d;
        cin >> n >> c >> d;
        priority_queue<int> pq;
        map<int,int> freq;
        int removed = 0;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            freq[x]++;
            if(freq[x] > 1) removed++;
            else pq.push(x);
        }
        int answ = INF;
        while(!pq.empty()){
            int x = pq.top();
            pq.pop();
            int cost = ((x - 1) - (n - removed - 1)) * d + 
                       (removed * c);
            answ = min(answ, cost);
            removed++;
        }
        answ = min(answ, n * c + d);
        cout << answ << '\n';
    }
    return 0;
}