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
        int n, s1, s2;
        cin >> n >> s1 >> s2;
        priority_queue<ii> pq;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            pq.push({x, i + 1});
        }

        vector<int> a, b;
        while(!pq.empty()){
            auto [freq, val] = pq.top();
            pq.pop();

            if((a.size() + 1)*s1 < (b.size() + 1)*s2){
                a.push_back(val);
            }
            else{
                b.push_back(val);
            }
        }

        cout << a.size() << " ";
        for(auto x : a) cout << x << " ";
        cout << '\n';
        cout << b.size() << " ";
        for(auto x : b) cout << x << " ";
        cout << '\n';
    }
    return 0;
}