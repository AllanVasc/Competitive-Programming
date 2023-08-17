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
const int MOD = 1e9 + 7;

vector<vector<int>> drones;

int f(int x, int a, int b, int c){
    return x*x*a - x*b + c;
}
int solve(int flag){
    int n = drones[0].size();
    int a = 0, b = 0, c = 0;
    for(int i = 0; i < n; i++){
        a += drones[3][i];
        b += 2 * drones[3][i]  * drones[flag][i];
        c += drones[3][i] * drones[flag][i] * drones[flag][i];
    }
    int l = -1;
    int r = 1e8;
    while(r - l > 1){
        int mid = (l + r) >> 1;
        if(f(mid, a, b, c) <= f(mid + 1, a, b, c)){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    return l + 1;
}

signed main() {
    optimize;
    int n; cin >> n;
    drones.assign(4, vector<int>());
    for(int i = 0; i < n; i++){
        int x, y, z, w;
        cin >> x >> y >> z >> w;
        drones[0].push_back(x);
        drones[1].push_back(y);
        drones[2].push_back(z);
        drones[3].push_back(w);
    }
    int x = solve(0);
    int y = solve(1);
    int z = solve(2);
    cout << x << " " << y << " " << z << '\n';
    return 0;
}