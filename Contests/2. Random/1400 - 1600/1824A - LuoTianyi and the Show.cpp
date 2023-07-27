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
        int n, m;
        cin >> n >> m;
        vector<int> prefix(m + 5, 0);
        set<int> conj;
        int cntLeft = 0;
        int cntRight = 0;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            if(x == -1) cntLeft++;
            else if(x == -2) cntRight++;
            else{
                conj.insert(x);
                prefix[x] = 1;
            }
        }
        for(int i = 1; i < prefix.size(); i++){
            prefix[i] += prefix[i - 1];
        }
        // for(auto x : prefix){
        //     cout << x << " ";
        // }
        // cout << '\n';
        int answ = 0;
        for(auto pos : conj){
            int cnt = 1 + min(pos - 1, cntLeft + prefix[pos - 1]) +
                      min(m - pos, cntRight + prefix[m] - prefix[pos]);
            answ = max(answ, cnt);
        }
        // falta ver botando primeiro -1 e botando primeiro -2
        if(cntLeft){
            // gastei 1 cntLeft para botar o primeiro no "m"
            int pos = m;
            int cnt = 1 + min(pos - 1, cntLeft - 1 + prefix[pos - 1]) +
                      min(m - pos, cntRight + prefix[m] - prefix[pos]);
            answ = max(answ, cnt);
        }
        if(cntRight){
            // gastei 1 cntRight para botar o primeiro no "1"
            int pos = 1;
            int cnt = 1 + min(pos - 1, cntLeft + prefix[pos - 1]) +
                      min(m - pos, cntRight - 1 + prefix[m] - prefix[pos]);
            answ = max(answ, cnt);
        }
        cout << answ << '\n';
    }
    return 0;
}