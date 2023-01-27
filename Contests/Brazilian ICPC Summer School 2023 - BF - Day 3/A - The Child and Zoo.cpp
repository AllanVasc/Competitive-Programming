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

    int c, n;
    while(cin >> c >> n){
        if(c == 0 && n == 0) return 0;
        vector<int> candy(n);
        for(int i = 0; i < n; i++){
            cin >> candy[i];
        }
        map<int, ii> freq;
        freq[0] = {0, -1};
        int curr = 0;

        for(int i = 0; i < n; i++){
            curr += candy[i];
            curr %= c;
            if(freq.count(curr) != 0){
                int start = freq[curr].second + 1;
                for(int j = start; j <= i; j++){
                    cout << j + 1 << " ";
                }
                cout << '\n';
                break;
            }
            freq[curr] = {curr, i};
        }
    }

    return 0;
}