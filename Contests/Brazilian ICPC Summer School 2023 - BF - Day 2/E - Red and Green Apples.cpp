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

    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;

    priority_queue<ii> pq;
    for(int i = 0; i < a; i++){
        int value;
        cin >> value;
        pq.push({value, 2});
    }
    for(int i = 0; i < b; i++){
        int value;
        cin >> value;
        pq.push({value, 1});
    }
    for(int i = 0; i < c; i++){
        int value;
        cin >> value;
        pq.push({value, 0});
    }

    int picked_red = 0;
    int picked_green = 0;
    int random = 0;

    int answ = 0;
    while(picked_red + picked_green + random != x + y){
        auto [value, color] = pq.top();
        pq.pop();
        if(color == 2 && picked_red != x){
            picked_red++;
            answ += value;
        }
        else if(color == 1 && picked_green != y){
            picked_green++;
            answ += value;
        }
        else if(color == 0){
            random++;
            answ += value;
        }
    }

    cout << answ << '\n';

    return 0;
}