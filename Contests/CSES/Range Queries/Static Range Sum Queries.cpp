#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<vector<int>> g;

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    vector<int> ps(n+1, 0);
    for(int i = 1; i <= n; i++){
        ps[i] = ps[i-1] + v[i-1];
    }

    while(q--){
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);

        cout << ps[b] - ps[a-1] << '\n';
    }
    
    return 0;
}