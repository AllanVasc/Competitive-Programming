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
    
    int n, x;
    cin >> n >> x;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    int l = 0, r = 0;
    int answ = 0;
    int currsum = 0;
    while(r < n){
        currsum += v[r];
        while(currsum >= x){
            if(currsum == x) answ++;
            currsum -= v[l];
            l++;
        }
        r++;
    }
    cout << answ << '\n';
    return 0;
}