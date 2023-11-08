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
    int t; cin >> t;

    map<int, pii> sol;
    for(int i = 0; i < 31; i++){
        for(int j = 0; j < 31; j++){
            if(i == j) continue;
            int val = (1ll << i) - (1ll << j);
            sol[val] = {i, j};
        }
    }

    while(t--){
        int n; cin >> n;
        vector<int> v(n);
        int sum = 0;
        for(int i = 0; i < n; i++){
            cin >> v[i];
            sum += v[i];
        }
        if(sum % n){
            cout << "NO" << '\n';
            continue;
        }
        sum /= n;
        vector<int> bits(31, 0);
        bool f = true;
        for(int i = 0; i < n; i++){
            if(v[i] == sum) continue;
            int diff = abs(v[i] - sum);
            if(sol.count(diff) == 0){
                f = false;
                break;
            }
            auto [x, y] = sol[diff];
            if(v[i] > sum){
                bits[x]++;
                bits[y]--;
            }
            else{
                bits[x]--;
                bits[y]++;
            }
        }
        for(int i = 0; i < 31; i++){
            if(bits[i]) f = false;
        }

        cout << (f ? "YES" : "NO") << '\n';
    }
    return 0;
}