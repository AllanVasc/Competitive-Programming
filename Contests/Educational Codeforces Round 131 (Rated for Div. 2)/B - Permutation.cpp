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
        int n;
        cin >> n;
        vector<bool> used(n + 1, false);
        vector<int> answ;
        for(int i = 1; i <= n; i++){
            if(!used[i]){
                for(int j = i; j <= n; j *= 2){
                    if(!used[j]){
                        answ.push_back(j);
                        used[j] = true;
                    }
                }
            }
        }

        cout << 2 << "\n";
        for(int i = 0; i < answ.size(); i++){
            cout << answ[i] << (i == answ.size() - 1 ? '\n' : ' ');
        }

    }

    return 0;
}