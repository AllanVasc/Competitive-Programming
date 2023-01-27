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
        vector<ii> v(3);
        map<int,int> freq_x;
        map<int,int> freq_y;
        for(int i = 0; i < 3; i++){
            cin >> v[i].first >> v[i].second;
            freq_x[v[i].first]++;
            freq_y[v[i].second]++;
        }
        
        bool matchx = false;
        bool matchy = false;
        for(auto i : freq_x){
            if(i.second >= 2) matchx = true;
        }
        for(auto i : freq_y){
            if(i.second >= 2) matchy = true;
        }

        if(matchx && matchy){
            cout << "NO" << '\n';
        }
        else{
            cout << "YES" << '\n';
        }
    }
    
    return 0;
}