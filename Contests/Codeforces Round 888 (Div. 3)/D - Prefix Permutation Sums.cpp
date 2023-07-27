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
        vector<int> v;
        v.push_back(0);
        for(int i = 0; i < n - 1; i++){
            int aux; cin >> aux;
            v.push_back(aux);
        }
        bool possible = true;
        int last = n*(n + 1) / 2;
        v.push_back(last);
        set<int> used;
        int idx = -1;
        for(int i = v.size() - 1; i > 0; i--){
            int dif = v[i] - v[i - 1];
            if(dif < 0){
                possible = false;
                break;
            }
            if(i == v.size() - 1){
                if(v[i - 1] != v[i]){
                    idx = i;
                }
            }
            else if(dif > n || used.count(dif)){
                if(idx != -1){
                    possible = false;
                    break;
                }
                else{
                    idx = i;
                }
            }
            used.insert(dif);
        }
        // cout << "idx = " << idx << '\n';
        // cout << "used: ";
        // for(auto x : used){
        //     cout << x << " ";
        // }
        // cout << '\n';
        if(possible){
            int miss = 1;
            while(used.count(miss)) miss++;
            if(idx == -1) cout << "OPA" << '\n';
            int dif = v[idx] - v[idx - 1];
            // cout << "dif = " << dif << '\n';
            // cout << "mis == " << miss << '\n';
            if(used.count(dif - miss)) possible = false;
        }
        cout << (possible ? "YES" : "NO") << '\n';
    }
    return 0;
}