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
    
    int n, k;
    cin >> n >> k;
    vector<ii> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }
    int answ = 0;
    int l = 0, r = 0;
    int curr = 0;
    while(r < n){
        while(r - l + 1 > k){
            curr -= v[l].first * v[l].second;
            l++;
        }
        curr += v[r].first * v[r].second;
        answ = max(answ, curr);
        r++;
    }

    cout << answ << '\n';
    return 0;
}