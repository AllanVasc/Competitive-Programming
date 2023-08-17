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

signed main() {
    optimize;
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<bool> used(n + 1, false);
        vector<int> answ;
        for(int i = 1; i <= n; i++){
            if(used[i]) continue;
            int aux = i;
            while(aux <= n){
                used[aux] = true;
                answ.push_back(aux);
                aux *= 2;
            }
        }
        for(auto x : answ) cout << x << " ";
        cout << '\n';
    }
    return 0;
}