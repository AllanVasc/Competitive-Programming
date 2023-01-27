#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

void bruteforce(){
    const int ms = 1e6 + 10;
    vector<int> nimber(ms, 0);
    cout << "1 = " << nimber[1] << '\n';
    cout << "2 = " << nimber[2] << '\n';
    for(int i = 3; i < ms; i++){
        set<int> mex;
        for(int j = 1; j <= i / 2; j++){
            if(2*j != i){
                mex.insert(nimber[j] ^ nimber[i - j]);
            }
        }
        int answ = 0;
        while(mex.count(answ)) answ++;
        nimber[i] = answ;
        // cout << i << " = " << answ << '\n';
        if(nimber[i] == 0) cout << "dp[" << i << "] = 0;\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    // bruteforce();
    const int ms = 1e6 + 10;
    vector<bool> dp(ms, 1);

    int t;
    cin >> t;

    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 0;
    dp[4] = 0;
    dp[7] = 0;
    dp[10] = 0;
    dp[20] = 0;
    dp[23] = 0;
    dp[26] = 0;
    dp[50] = 0;
    dp[53] = 0;
    dp[270] = 0;
    dp[273] = 0;
    dp[276] = 0;
    dp[282] = 0;
    dp[285] = 0;
    dp[288] = 0;
    dp[316] = 0;
    dp[334] = 0;
    dp[337] = 0;
    dp[340] = 0;
    dp[346] = 0;
    dp[359] = 0;
    dp[362] = 0;
    dp[365] = 0;
    dp[386] = 0;
    dp[389] = 0;
    dp[392] = 0;
    dp[566] = 0;
    dp[630] = 0;
    dp[633] = 0;
    dp[636] = 0;
    dp[639] = 0;
    dp[673] = 0;
    dp[676] = 0;
    dp[682] = 0;
    dp[685] = 0;
    dp[923] = 0;
    dp[926] = 0;
    dp[929] = 0;
    dp[932] = 0;
    dp[1222] = 0;

    while(t--){
        int n;
        cin >> n;

        cout << (dp[n] ? "first" : "second") << '\n';
    }
    
    return 0;
}