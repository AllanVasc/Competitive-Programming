#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<ii> solve(int n, int initial, int end, int help){
    if(n == 1){
        vector<ii> answ;
        answ.push_back({initial, end});
        return answ;
    }
    else{
        vector<ii> answ = solve(n - 1, initial, help, end);
        answ.push_back({initial, end});
        vector<ii> aux = solve(n - 1, help, end, initial);
        for(auto i : aux){
            answ.push_back(i);
        }

        return answ;
    }
}

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ii> answ = solve(n, 1, 3, 2);
    cout << answ.size() << '\n';
    for(auto i : answ){
        cout << i.first << " " << i.second << '\n';
    }

    return 0;
}