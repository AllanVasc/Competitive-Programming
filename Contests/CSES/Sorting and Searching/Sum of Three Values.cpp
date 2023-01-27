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
    
    int n, x;
    cin >> n >> x;

    vector<ii> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        int k = n - 1;
        for(int j = i + 1; j < n; j++){
            while(j < k && v[i].first + v[j].first + v[k].first > x) k--;
            if(j < k && v[i].first + v[j].first + v[k].first == x){
                cout << v[i].second << " " << v[j].second << " " << v[k].second << '\n';
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << '\n';
    
    
    return 0;
}