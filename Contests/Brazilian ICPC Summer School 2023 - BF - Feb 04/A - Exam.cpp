#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int k;
    cin >> k;
    string s1, s2;
    cin >> s1 >> s2;

    int match = 0;
    int n = s1.size();
    for(int i = 0; i < n; i++){
        if(s1[i] == s2[i]) match++;
    }

    if(match <= k){
        cout << match + n - k << '\n';
    }
    else{
        cout << k + n - match << '\n';
    }
    return 0;
}