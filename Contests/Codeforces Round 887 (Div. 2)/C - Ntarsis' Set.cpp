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

bool check(int mid, vector<int> & v, int day){
    int n = v.size();
    int tot = 0;
    for(int i = n - 1; i >= 0; i--){
        if(v[i] > mid) continue;
        int qtt = (mid - v[i]) / (i + 1);
        qtt++;
        tot += qtt;
        mid -= qtt * (i + 1);
    }
    return tot > day;
}

signed main() {
    optimize;
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        if(v[0] != 1){
            cout << 1 << '\n';
        }
        else{
            int l = 1;
            int r = 1e12;
            int answ = r;
            while(l <= r){
                int mid = (l + r) >> 1;
                if(check(mid, v, k)){
                    answ = min(answ, mid);
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            cout << answ << '\n';
        }
    }
    return 0;
}