#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<int> v;

vector<int> LISBS(int n){
    const int INF = 0x3f3f3f3f3f3f3f3f;
    vector<int> dp(n + 1, INF);
    vector<int> idx(n + 1, -1);
    vector<int> parent(n + 1, -1);
    dp[0] = -INF;

    for(int i = 0; i < n; i++){
        int j = upper_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
        if(dp[j-1] < v[i] && v[i] < dp[j]){
            dp[j] = v[i];
            idx[j] = i; 
            parent[i] = idx[j-1];
        }
    }

    vector<int> answ;
    int pos = 0;
    for(int i = 0; i <= n; i++){
        if(dp[i] < INF) pos = idx[i];
    }
    while(pos != -1){
        answ.push_back(v[pos]);
        pos = parent[pos];
    }
    reverse(answ.begin(), answ.end());
    return answ;
}

int32_t main(){
  
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    
    int n;
    cin >> n;
    v.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> v[i];

    vector<int> answ = LISBS(n);
    // for(int i = 0; i < answ.size(); i++){
    //     cout << answ[i] << " ";
    // }
    cout << answ.size() << '\n';

    return 0;
}