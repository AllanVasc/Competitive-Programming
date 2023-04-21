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
        int n, m;
        cin >> n >> m;
        vector<int> freq(n + 1, 0);
        for(int i = 0; i < m; i++){
            int x;
            cin >> x;
            freq[x]++;
        }

        set<ii> times;
        for(int i = 1; i <= n; i++){
            times.insert({freq[i], i});
        }

        if(n == 1){
            cout << times.begin()->first << '\n';
        }
        else{

            while(1){
                auto [tG, idxG] = *times.rbegin();
                auto [tS, idxS] = *times.begin();
                if(tG > tS + 1){
                    times.insert({tG - 1, idxG});
                    times.insert({tS + 2, idxS});
                    times.erase(times.find({tG, idxG}));
                    times.erase(times.find({tS, idxS}));
                }
                else{
                    break;
                }
            }

            cout << times.rbegin()->first << '\n';
        }

    }

    return 0;
}