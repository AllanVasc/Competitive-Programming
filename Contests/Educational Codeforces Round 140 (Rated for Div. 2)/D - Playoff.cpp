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
    
    int n;
    cin >> n;
    string s;
    cin >> s;

    int one = 0, zero = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1') one++;
        else zero++;
    }

    vector<int> power2(20, 1);
    for(int i = 1; i < 20; i++) power2[i] = 2 * power2[i - 1];

    for(int i = power2[one]; i <= power2[n] -(power2[zero] - 1); i++){
        cout << i << " ";
    }

    cout << '\n';
    
    return 0;
}