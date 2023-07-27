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
        int n; cin >> n;
        int answ = INF;
        vector<int> v(2*n);
        int cnt = 0;
        for(int i = 0; i < 2*n; i++){
            cin >> v[i];
            cnt += abs(v[i]); 
        }
        answ = min(answ, cnt);
        if(n == 1){
            answ = min(answ, abs(v[0] - v[1]));
        }
        else if(n == 2){
            cnt = 0;
            for(int i = 0; i < 2*n; i++){
                cnt += abs(v[i] - 2);
            }
            answ = min(answ, cnt);
        }
        if(n % 2 == 0){ // {-1, -1, -1, ..., n}
            cnt = 0;
            int mx = INF;
            for(int i = 0; i < 2*n; i++){
                cnt += abs(v[i] + 1);
                mx = min(mx, abs(v[i] - n) - abs(v[i] + 1));
            }
            cnt += mx;
            answ = min(answ, cnt);
        }
        cout << answ << '\n';
    }
    return 0;
}