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

bool check(int mid, vector<int> & v, int k){
    int n = v.size();
    vector<int> last(k + 1, -1);
    vector<int> changed(k + 1, false);
    vector<bool> possible(k + 1, true);
    for(int i = 0; i < n; i++){
        int color = v[i];
        int dist = i - last[color];
        if(dist > mid + 1){
            // pintar algum do meio
            if(changed[color]){
                possible[color] = false;
            }
            int central = last[color] + dist/2;
            int d1 = central - last[color];
            int d2 = i - central;
            if(d1 > mid + 1 || d2 > mid + 1){
                possible[color] = false;
            }
            else{
                changed[color] = true;
            }
        }
        last[color] = i;
    }
    for(int i = 1; i <= k; i++){
        int en = n;
        int color = i;
        int dist = en - last[color];
        if(dist > mid + 1){
            // pintar algum do meio
            if(changed[color]){
                possible[color] = false;
            }
            int central = last[color] + dist/2;
            int d1 = central - last[color];
            int d2 = en - central;
            if(d1 > mid + 1 || d2 > mid + 1){
                possible[color] = false;
            }
            else{
                changed[color] = true;
            }
        }
    }
    for(int i = 1; i <= k; i++){
        if(possible[i]) return true;
    }
    return false;
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
        int l = 0;
        int r = n + 1;
        int answ = r;
        // cout << check(1, v, k) << '\n';
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
    return 0;
}