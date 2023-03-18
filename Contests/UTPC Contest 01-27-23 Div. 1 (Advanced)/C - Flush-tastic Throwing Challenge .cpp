#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int sq(int x){
    return x * x;
}
int dist(int x1, int y1, int x2, int y2){
    return sq(x1 - x2) + sq(y1 - y2);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, cx, cy, r;
    cin >> n >> cx >> cy >> r;
    
    int answ = 0;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        if(dist(x,y,cx,cy) <= r * r){
            answ++;
        }
    }
    cout << answ << '\n';
    return 0;
}