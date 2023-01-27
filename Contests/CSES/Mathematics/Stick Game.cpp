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
    
    int n, k;
    cin >> n >> k;

    vector<int> moves(k);
    for(int i = 0; i < k; i++) cin >> moves[i];
    sort(moves.begin(), moves.end());

    vector<bool> answ(n + 1);
    answ[0] = 0;
    for(int i = 1; i <= n; i++){
        bool canWin = false;
        for(int j = 0; j < k; j++){
            if(moves[j] > i) break;
            if(answ[i - moves[j]] == 0) canWin = true;
        }
        if(canWin) answ[i] = true;
        else answ[i] = false;
        cout << (answ[i] == true ? "W" : "L");
    }
    cout << '\n';
    
    return 0;
}