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
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        int answ = 1;
        int offset = 0;
        for(int i = 1; i < n; i++){
            if(v[i] > v[i - 1]){
                if(offset != 1){
                    answ++;
                }
                offset = 1;
            }
            else if(v[i] < v[i - 1]){
                if(offset != -1){
                    answ++;
                }
                offset = -1;
            }
            else{ // ta igual

            }
        }
        cout << answ << '\n';
    }
    return 0;
}