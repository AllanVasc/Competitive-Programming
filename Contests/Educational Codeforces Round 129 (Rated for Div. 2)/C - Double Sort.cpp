#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
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
            cin >> v[i].first;
        }
        for(int i = 0; i < n; i++){
            cin >> v[i].second;
        }
        vector<pii> answ;
        for(int i = 0; i < n; i++){
            pii curMn = v[i];
            int idx = -1;
            for(int j = i; j < n; j++){
                if(curMn.first > v[j].first){
                    curMn = v[j];
                    idx = j;
                }
                else if(curMn.first == v[j].first){
                    if(curMn.second > v[j].second){
                        curMn = v[j];
                        idx = j;
                    }
                }
                // cout << "idx = " << idx << '\n';
            }
            if(idx != -1){
                swap(v[i], v[idx]);
                answ.push_back({i + 1, idx + 1});
            }
        }
        sort(ALL(v));
        bool has_answ = true;
        for(int i = 1; i < n; i++){
            if(v[i].second < v[i - 1].second) has_answ = false;
        }

        if(!has_answ) cout << -1 << '\n';
        else{
            cout << answ.size() << '\n';
            for(auto x : answ) cout << x.first << " " << x.second << '\n';
        }
    }
    return 0;
}