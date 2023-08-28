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

signed main() {
    optimize;
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pii>> tubes(k);
    bool flag = true;
    int curr = 0;
    for(int i = 0; i < n; i++){
        if(flag){
            for(int j = 0; j < m; j++){
                if(curr != k - 1 && tubes[curr].size() == 2){
                    curr++;
                }
                tubes[curr].push_back({i, j});
            }
        }
        else{
            for(int j = m - 1; j >= 0; j--){
                if(curr != k - 1 && tubes[curr].size() == 2){
                    curr++;
                }
                tubes[curr].push_back({i, j});
            }
        }
        flag = !flag;
    }

    for(int i = 0; i < k; i++){
        cout << tubes[i].size() << " ";
        for(auto [x, y] : tubes[i]){
            cout << x + 1 << " " << y + 1 << " ";
        }
        cout << '\n';
    }
    return 0;
}