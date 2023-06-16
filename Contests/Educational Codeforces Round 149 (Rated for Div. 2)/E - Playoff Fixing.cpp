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
const int MOD = 998244353;

int32_t main() {
    optimize;
    
    const int ms = 20;
    vector<int> fat((1 << ms) + 1, 1);
    for(int i = 1; i <= (1 << ms); i++){
        fat[i] = fat[i - 1] * i % MOD;
    }
    int k; cin >> k;
    int n = (1 << k);
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(v[i] != -1) v[i]--;
    }
    int answ = 1;
    for(int stage = k - 1; stage >= 0; stage--){
        int losers = 0;
        vector<int> nxtRound(1 << stage);
        for(int i = 0; i < (1 << stage); i++){
            int mn = min(v[2 * i], v[2 * i + 1]);
            int mx = max(v[2 * i], v[2 * i + 1]);
            if(mn == -1){
                if(mx >= (1 << stage)){
                    // mx eh perdedor, Fixo o ganhador no mn
                    nxtRound[i] = -1;
                }
                else if(mx != -1){
                    // mx eh um ganhador alocado
                    nxtRound[i] = mx;
                    losers++;
                }
                else{
                    // mx e mn eh -1 
                    nxtRound[i] = -1;
                    losers++;
                    answ *= 2;
                    answ %= MOD;
                }
            }
            else if((v[2 * i] < (1 << stage)) == (v[2 * i + 1] < (1 << stage))){
                cout << 0 << '\n';
                return 0;
            }
            else{
                nxtRound[i] = mn;
            }
        }
        answ *= fat[losers];
        answ %= MOD;
        v = nxtRound;
    }
    cout << answ << '\n';

    return 0;
}