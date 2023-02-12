#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int distance(ii x, ii y){
    return abs(x.first - y.first) + abs(x.second - y.second);
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;

        int dist_a_b = distance({x,y}, {0, 0});
        ii answ = {-1, -1};
        for(int i = 0; i <= 100 && answ.first == -1; i++){
            for(int j = 0; j <= 100 && answ.first == -1; j++){
                int dist_a_c = distance({i,j}, {0,0});
                int dist_b_c = distance({i,j}, {x,y});

                if(dist_a_b == 2 * dist_a_c && dist_a_b == 2 * dist_b_c){
                    answ = {i, j};
                }
            }
        }

        cout << answ.first << " " << answ.second << '\n';
    }


    return 0;
}