#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define double long double

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int x, y;
    cin >> x >> y;
    bool changed = false;
    double answ = INF;
    if(y - x > 0 && 2*x - y > 0){
        answ = 2*(y - x) + 2*(2*x - y);
        changed = true;
    }
    if(y - x > 0){
        if(changed){
            answ = min(answ, (double) x + 2*(y - x));
        }
        else{
            answ = x + 2*(y - x);
        }
        changed = true;
    }
    if(2*y - x > 0){
        if(changed){
            answ = min(answ, (double) x + 2*((2*y - x) / 4.0));
        }
        else{
            answ = x + 2*((2*y - x) / 4.0);
        }
        changed = true;
    }

    if(changed){
        cout << fixed << setprecision(6);
        cout << answ << '\n';
    }
    else{
        cout << -1 << '\n';
    }
    
    return 0;
}