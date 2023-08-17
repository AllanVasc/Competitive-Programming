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

int backtrack(int idx, int mask, int h, vector<int> & v){
    int n = v.size();
    if(idx >= n){
        return idx;
    }
    if(h > v[idx]){
        h += v[idx]/2;
        return backtrack(idx + 1, mask, h, v);
    }
    else{
        // preciso fazer alguma multiplicacao
        int answ = idx;
        for(int i = 0; i < 3; i++){
            if(mask & (1 << i)) continue;
            if(i == 2){
                // X3
                int new_mask = mask | (1 << i);
                answ = max(answ, backtrack(idx, new_mask, 3*h, v));
            }
            else{
                int new_mask = mask | (1 << i);
                answ = max(answ, backtrack(idx, new_mask, 2*h, v));
            }
        }
        return answ;
    }
}

signed main() {
    optimize;
    int t;
    cin >> t;
    while(t--){
        int n, h;
        cin >> n >> h;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        sort(ALL(v));
        int answ = 0;
        answ = backtrack(0, 0, h, v);
        cout << answ << '\n';
    }
    return 0;
}