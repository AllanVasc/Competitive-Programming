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

bool check(int time, vector<int> & v){
    int n = v.size();
    int cnt = 0;
    int curr = -INF;
    for(int i = 0; i < n; i++){
        if(abs(v[i] - curr) > time){
            cnt++;
            curr = v[i] + time;
        }
        if(cnt > 3) return false;
    }
    return true;
}

signed main() {
    optimize;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        sort(ALL(v));
        int l = 0;
        int r = 1e12;
        int answ = r;
        while(l <= r){
            int m = (l + r) >> 1;
            if(check(m, v)){
                answ = min(answ, m);
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        cout << answ << '\n';
    }
    return 0;
}