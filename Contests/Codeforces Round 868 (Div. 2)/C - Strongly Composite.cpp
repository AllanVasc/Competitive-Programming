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
        int n; cin >> n;
        vi v(n);
        for(int i = 0; i < n; i++) cin >> v[i];

        map<int,int> factors;
        for(int i = 0; i < n; i++){
            int curr = v[i];
            for(int j = 2; j * j <= curr; j++){
                while(curr % j == 0){
                    curr /= j;
                    factors[j]++;
                }
            }
            if(curr > 1) factors[curr]++;
        }
        int answ = 0;
        int miss = 0;
        map<int,int> qtt;
        for(auto [x, y] : factors){
            // cout << "x = " << x << " y = " << y << '\n';
            //qtt[y]++;
            answ += y / 2;
            miss += y % 2;
        }
        
        // for(auto [x, y] : qtt){
        //     if(x == 1){
        //         answ += y / 3;
        //         miss += y % 3;
        //     }
        //     else{
        //         answ += (y*x) / 2;
        //         miss += (y*x) % 2;
        //     }
        // }
        cout << (answ + miss / 3) << '\n';
    }
    return 0;
}