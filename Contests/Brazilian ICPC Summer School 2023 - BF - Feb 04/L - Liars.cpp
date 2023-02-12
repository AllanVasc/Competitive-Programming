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

    int n;
    cin >> n;
    vector<int> freq(n + 1, 0);
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        for(; l <= r; l++){
            freq[l]++;
        }
    }
    int answ = -1;
    for(int i = 1; i <= n; i++){
        if(freq[i] == i) answ = i;
    }
    cout << answ << '\n';
    return 0;
}