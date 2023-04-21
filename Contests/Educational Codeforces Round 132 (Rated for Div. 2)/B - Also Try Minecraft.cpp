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

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    vector<int> ps(n, 0);
    for(int i = 1; i < n; i++){
        if(v[i] < v[i - 1]) ps[i] = ps[i - 1] + v[i - 1] - v[i];
        else ps[i] = ps[i - 1];
    }

    vector<int> ss(n, 0);
    for(int i = n - 2; i >= 0; i--){
        if(v[i] < v[i + 1]) ss[i] = ss[i + 1] + v[i + 1] - v[i];
        else ss[i] = ss[i + 1];
    }
    
    while(m--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        if(l < r){
            cout << ps[r] - ps[l] << '\n';
        }
        else{ // l > r
            cout << ss[r] - ss[l] << '\n';
        }
    }


    return 0;
}