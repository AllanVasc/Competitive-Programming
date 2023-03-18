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

    int t;
    cin >> t;
    int pw2[25];
    pw2[0] = 1;
    for(int i = 1; i < 25; i++){
        pw2[i] = pw2[i - 1] * 2;
    }
    while(t--){
        int l, r;
        cin >> l >> r;

        int k = 0;
        int aux = l;
        while(aux <= r) k++, aux *= 2;

        int answ = 0;
        answ += (r/(pw2[k - 1])) - l + 1;
        if(k > 1) answ += (k - 1) * max(0LL, ((r/(pw2[k - 2] * 3)) - l + 1));
        cout << k << " " << answ << '\n';
    }
    return 0;
}