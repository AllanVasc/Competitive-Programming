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
    
    vector<int> v(3);
    for(int i = 0; i < 3; i++) cin >> v[i];
    sort(v.begin(), v.end());
    int answ = 0;
    if(v[1] == v[0] && v[1] == 0){
        cout << -1 << '\n';
    }
    else if((v[1] - v[0]) % 2 != 0){
        cout << -1 << '\n';
    }
    else{
        answ += (v[1] - v[0]) / 2;
        v[0] += answ;
        v[1] -= answ;
        v[2] -= answ;

        if((v[2] - v[1]) % 2 != 0){
            cout << -1 << '\n';
        }
        else{
            answ += (v[2] - v[1]);
            cout << answ << '\n';
        }
    }
    return 0;
}