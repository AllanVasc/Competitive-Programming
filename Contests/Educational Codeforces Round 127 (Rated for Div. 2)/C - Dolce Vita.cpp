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

bool check(int a1, int n, int r, int x){
    if(n == 0) return true;
    int an = a1 + (n - 1) * r;
    return an <= x;
}

signed main() {
    optimize;
    
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());
        int answ = 0;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += v[i];
            int l = 0;
            int r = 1e12;
            int curr = l;
            while(l <= r){
                int m = (l + r) >> 1;
                if(check(sum, m, i + 1, x)){
                    curr = max(curr, m);
                    l = m + 1;
                }
                else{
                    r = m - 1;
                }
            }
            // cout << "sum =" << sum << '\n';
            // cout << "curr = " << curr << '\n';
            answ += curr;
            if(curr == 0) break;
        }
        cout << answ << '\n';
    }
    return 0;
}