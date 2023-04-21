#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int fibo[50];

bool solve(int n, int x, int y){
    if(n == 0) return true;

    int h = fibo[n];
    int w = fibo[n + 1];
    if(y > fibo[n] || y <= fibo[n + 1] - fibo[n]){
        int nx;
        if(y <= fibo[n + 1] - fibo[n]){
            nx = fibo[n + 1] - fibo[n] - y + 1;
        }
        else{
            nx = y - fibo[n];
        }

        return solve(n - 1, nx, x);
    }

    return false;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    fibo[0] = fibo[1] = 1;
    for(int i = 2; i < 50; i++){
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }

    int t;
    cin >> t;
    while(t--){
        int n, x, y;
        cin >> n >> x >> y;

        if(solve(n,x,y)) cout << "YES" << '\n';
        else cout << "NO" << '\n';

    }

    return 0;
}