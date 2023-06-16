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
    // optimize;
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<pii> v(k + 3);
        for(int i = 0; i < 3; i++){
            v[i].first = v[i].second = i + 1;
        }
        for(int i = 0; i < k; i++) cin >> v[i + 3].first;
        for(int i = 0; i < k; i++) cin >> v[i + 3].second;
        sort(ALL(v));
        string answ = "";
        int pattern = 0;
        int curr = 0;
        bool possible = true;
        int last = 0;
        for(int i = 0; i < k + 3; i++){
            auto [sz, qtt] = v[i];
            // cout << "sz = " << sz << " qtt = " << qtt << '\n';
            int delta = sz - answ.size();
            int need;
            if(i == 0) need = qtt;
            else need = qtt - v[i - 1].second;
            if(need < 0 || need > delta){
                possible = false;
                break;
            }
            int cnt = 0;
            while(cnt != need){
                answ.push_back('a' + curr);
                cnt++;
            }
            while(answ.size() != sz){
                answ.push_back('a' + pattern);
                pattern = (pattern + 1) % 3;
            }
            curr++;
            // cout << answ << '\n';
        }
        if(possible){
            cout << "YES" << '\n';
            cout << answ << '\n';
        }
        else{
            cout << "NO" << '\n';
        }
    }
    return 0;
}