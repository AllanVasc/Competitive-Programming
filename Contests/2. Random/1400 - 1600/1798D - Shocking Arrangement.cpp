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
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        vector<int> answ;
        vector<int> pos, neg;
        for(int i = 0; i < n; i++){
            if(v[i] == 0) answ.push_back(v[i]);
            else if(v[i] > 0) pos.push_back(v[i]);
            else neg.push_back(v[i]);
        }

        if(answ.size() == n){
            cout << "No" << '\n';
        }
        else{
            int cnt = 0;
            sort(ALL(pos));
            sort(ALL(neg));
            while(answ.size() != n){
                if(cnt >= 0){
                    answ.push_back(neg.back());
                    neg.pop_back();
                    cnt += answ.back();
                }
                else{
                    answ.push_back(pos.back());
                    pos.pop_back();
                    cnt += answ.back();
                }
            }
            cout << "Yes" << '\n';
            for(auto x : answ) cout << x << " ";
            cout << '\n';
        }
    }
    return 0;
}