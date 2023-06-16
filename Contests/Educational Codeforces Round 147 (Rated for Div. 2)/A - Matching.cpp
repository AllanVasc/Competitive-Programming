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
        string s;
        cin >> s;
        int n = s.size();

        if(s[0] == '0'){
            cout << 0 << '\n';
        }
        else if(s[0] == '?'){
            int answ = 9;
            for(int i = 1; i < n; i++){
                if(s[i] == '?') answ *= 10;
            }
            cout << answ << '\n';
        }
        else{
            int answ = 1;
            for(int i = 0; i < n; i++){
                if(s[i] == '?') answ *= 10;
            }
            cout << answ << '\n';
        }
    }
    return 0;
}