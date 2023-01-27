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

    vector<int> v(n);
    for(int i = 0;i < n; i++) cin >> v[i];
    vector<int> ps(n + 1);
    ps[0] = 0;
    for(int i = 1; i <= n; i++){
        ps[i] = ps[i - 1] + v[i - 1];
    }
    map<int,int> freq;
    int answ = 0;
    for(int i = 0; i <= n; i++){
        answ += freq[((ps[i]) % n + n) % n];
        freq[((ps[i]) % n + n) % n]++;
    }
   

    cout << answ << '\n';

    return 0;
}