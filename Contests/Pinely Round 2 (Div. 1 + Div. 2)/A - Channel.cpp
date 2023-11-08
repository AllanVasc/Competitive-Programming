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
        int n, on, q;
        cin >> n >> on >> q;
        string s; cin >> s;
        int cntPlus = on;
        int mxOn = on;
        for(int i = 0; i < q; i++){
            if(s[i] == '+'){
                cntPlus++;
                on++;
            }
            else{
                on--;
            }
            mxOn = max(mxOn, on);
        }

        if(mxOn >= n){
            cout << "YES" << '\n';
        }
        else if(cntPlus >= n){
            cout << "MAYBE" << '\n';
        }
        else cout << "NO" << '\n';
    }
    return 0;
}