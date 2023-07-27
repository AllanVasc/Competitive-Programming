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
        vector<int> v(n);
        set<int> dif;
        map<int,int> freq;
        for(int i = 0; i < n; i++){
            cin >> v[i];
            dif.insert(v[i]);
            freq[v[i]]++;
        }
        if(dif.size() == 1){
            cout << n / 2 << '\n';
        }
        else{
            int answ = 0;
            int cnt = 0;
            for(auto x : dif){
                answ = max(answ, cnt * (n - cnt));
                cnt += freq[x];
            }
            cout << answ << '\n';
        }
    }
    return 0;
}