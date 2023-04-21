#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 1e5 + 100;
const int LOG = 30;
int dpL[ms][LOG], dpR[ms][LOG];

int jump(int u, int k){
    for(int i = LOG - 1; i >= 0; i--){
        if(k & (1 << i)) u = dpL[u][i];
    }
    for(int i = LOG - 1; i >= 0; i--){
        if(k & (1 << i)) u = dpR[u][i];
    }
    for(int i = LOG - 1; i >= 0; i--){
        if(k & (1 << i)) u = dpL[u][i];
    }
    for(int i = LOG - 1; i >= 0; i--){
        if(k & (1 << i)) u = dpR[u][i];
    }
    return u;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> dpL[i][0] >> dpR[i][0];
        dpL[i][0]--, dpR[i][0]--;
    }

    for(int i = 1; i < LOG; i++){
        for(int j = 0; j < n; j++){
            dpL[j][i] = dpL[dpL[j][i - 1]][i - 1];
            dpR[j][i] = dpR[dpR[j][i - 1]][i - 1];
        }
    }
    int q;
    cin >> q;
    while(q--){
        int u, k;
        cin >> u >> k;
        u--;
        cout << jump(u, k) + 1 << '\n';
    }

    return 0;
}