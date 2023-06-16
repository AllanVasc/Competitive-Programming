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

int32_t main() {
    optimize;
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pii> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i].first >> v[i].second;
        }
        vector<pii> segs;
        for(int i = 0; i < n; i++){
            auto [l1, r1] = v[i];
            for(int j = i + 1; j < n; j++){
                auto [l2, r2] = v[j];
                if((l2 >= l1 && l2 <= r1) || (r2 >= l1 && r2 <= r1) ||
                    (l1 >= l2 && l1 <= r2) || (r1 >= l2 && r1 <= r2)){
                    segs.push_back({min(l1, l2), max(r1, r2)});
                }
            }
        }
        sort(segs.begin(), segs.end(), [&](const pii & a, const pii & b){
            if(a.second != b.second) return a.second < b.second;
            return a.first < b.first;
        });
        int answ = 0;
        int last = -1;
        for(int i = 0; i < segs.size(); i++){
            // cout << segs[i].first << " : " << segs[i].second << '\n';
            if(last < segs[i].first){
                answ++;
                last = max(last, segs[i].second);
            }
        }
        cout << n - 2*answ << '\n';
    }
    return 0;
}