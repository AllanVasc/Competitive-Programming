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
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int answ = 4;
        if(x1 == 1 && y1 == 1 || x1 == n && y1 == 1 ||
           x1 == 1 && y1 == m || x1 == n && y1 == m){
            answ = min(answ, 2LL);
        }
        if(x2 == 1 && y2 == 1 || x2 == n && y2 == 1 ||
           x2 == 1 && y2 == m || x2 == n && y2 == m){
            answ = min(answ, 2LL);
        }
        if(x1 == 1 || x1 == n || y1 == 1 || y1 == m){
            answ = min(answ, 3LL);
        }
        if(x2 == 1 || x2 == n || y2 == 1 || y2 == m){
            answ = min(answ, 3LL);
        }
        cout << answ << '\n';
    }
    return 0;
}