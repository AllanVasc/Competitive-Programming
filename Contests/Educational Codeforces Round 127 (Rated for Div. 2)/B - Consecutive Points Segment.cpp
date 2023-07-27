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
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        vector<pair<int,int>> intervals;
        bool possible = true;
        int cnt2 = 0;
        int cnt3 = 0;
        for(int i = 1; i < n; i++){
            if(v[i] - v[i - 1] > 3){
                possible = false;
                break;
            }
            if(v[i] - v[i - 1] == 2){
                cnt2++;
            }
            if(v[i] - v[i - 1] == 3){
                cnt3++;
            }
        }

        if(!possible || (cnt3 > 1) || (cnt3 && cnt2) || (cnt2 > 2)){
            cout << "NO" << '\n';
        }
        else{
            cout << "YES" << '\n';
        }
    }
    return 0;
}