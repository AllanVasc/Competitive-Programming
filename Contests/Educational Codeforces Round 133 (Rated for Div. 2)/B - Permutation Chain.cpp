#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

void print(vector<int>& v){
    for(auto x : v) cout << x << " ";
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) v[i] = i + 1;
        cout << n << '\n';
        for(int i = n - 2; i >= 0; i--){
            print(v);
            swap(v[i], v[i + 1]);
        }
        print(v);
    }
    return 0;
}