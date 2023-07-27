#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

__int128_t sq(__int128_t x){
    return x * x;
}

__int128_t check(int w, vector<int> & v){
    __int128_t sum = 0;
    int n = v.size();
    for(int i = 0; i < n; i++){
        sum += sq(2*w + v[i]);
    }
    return sum;
}

signed main() {
    optimize;
    int t;
    cin >> t;
    while(t--){
        int n, c;
        cin >> n >> c;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        int l = 0;
        int r = 1e10;
        int answ = r;
        while(l <= r){
            int mid = (l + r) >> 1;
            __int128_t val = check(mid, v);
            if(val >= c){
                if(val == c) answ = min(answ, mid);
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        cout << answ << '\n';
    }
    return 0;
}