#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int cnt0 = 0, cnt1 = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0') cnt0++;
            else cnt1++;
        }

        int cswap = 1e12, cdelete = cswap + 1;
        int p0 = 0, p1 = 0;
        int answ = cdelete * min(cnt0, cnt1);
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                p1++;
                cnt1--;
            }
            else{
                p0++;
                cnt0--;
            }

            if(s[i] == '1' && i + 1 < n && s[i + 1] == '0'){
                int cost = (p1 - 1)*cdelete + min((cnt0 - 1),(cnt1 + 1))*cdelete + cswap;
                answ = min(answ, cost);
            }

            int cost = p1*cdelete + min(cnt0, cnt1)*cdelete;
            answ = min(answ, cost);
        }
        cout << answ << '\n';
    }
    return 0;
}