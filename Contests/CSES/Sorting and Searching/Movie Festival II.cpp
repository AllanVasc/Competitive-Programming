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
    
    int n, k;
    cin >> n >> k;
    vector<pii> v(n);
    for(int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    sort(ALL(v), [](auto & a, auto & b){
        if(a.second != b.second) return a.second < b.second;
        else return a.first < b.first;
    });
    set<pii> s;
    int cant = 0;
    for(int i = 0; i < n; i++){
        auto [st, en] = v[i];
        auto it = s.lower_bound({-st, -1});
        if(it != s.end()){
            s.erase(it);
            s.insert({-en, i});
        }
        else{
            if(s.size() < k){
                s.insert({-en, i});
            }
            else{
                cant++;
            }
        }
    }
    cout << n - cant << '\n';
    return 0;
}