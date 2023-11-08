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
    // optimize;
    int t; cin >> t;
    while(t--){
        int n, q; cin >> n >> q;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        vector<int> ord;
        vector<bool> exist(n + 1, false);
        for(int i = 0; i < n; i++){
            exist[v[i]] = true;
        }
        for(int i = 0; i <= n; i++){
            if(exist[i] == false){
               ord.push_back(i);
                break;
            }
        }
        for(int i = 0; i < n; i++){
            ord.push_back(v[i]);
        }
        // cout << "ord: ";
        // for(int i = 0; i < ord.size(); i++) cout << ord[i] << " ";
        // cout << '\n';
        vector<int> answ;
        int idxStart = (q - 1) * n % ord.size();
        // cout << "idx start = " << idxStart << '\n';
        for(int i = idxStart; i < ord.size(); i++){
            answ.push_back(ord[i]);
            if(answ.size() == n) break;
        }
        for(int i = 0; i < answ.size(); i++){
            if(answ.size() == n) break;
            answ.push_back(ord[i]);
        }
        for(auto x : answ) cout << x << " ";
        cout << '\n';
    }
    return 0;
}