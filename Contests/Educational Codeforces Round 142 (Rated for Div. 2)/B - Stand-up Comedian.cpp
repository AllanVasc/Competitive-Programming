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
        int a1, a2, a3, a4;
        cin >> a1 >> a2 >> a3 >> a4;

        int answ = a1;
        int life = a1;

        if(life == 0){
            if(a2 > 0 || a3 > 0 || a4 > 0)
                cout << answ + 1 << '\n';
            else
                cout << answ << '\n';
            continue;
        }

        int match = min(a2, a3);
        answ += 2 * match;
        a2 -= match;
        a3 -= match;
        // ou a2 eh zero ou a3 eh zero!

        match = min(life, a2);
        answ += match;
        life -= match;
        a2 -= match;

        if(life == 0){
            if(a2 > 0 || a3 > 0 || a4 > 0)
                cout << answ + 1 << '\n';
            else
                cout << answ << '\n';
            continue;
        }

        match = min(life, a3);
        answ += match;
        life -= match;
        a3 -= match;

        if(life == 0){
            if(a3 > 0 || a4 > 0){
                cout << answ + 1 << '\n';
            }
            else{
                cout << answ << '\n';
            }
            continue;
        }

        match = min(life, a4);
        answ += match;
        life -= match;
        a4 -= match;

        if(life == 0){
            if(a4 > 0){
                cout << answ + 1 << '\n';
            }
            else{
                cout << answ << '\n';
            }
            continue;
        }
        cout << answ << '\n';
    }
    return 0;
}