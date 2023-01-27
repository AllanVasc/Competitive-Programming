#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    int answ = 0;
    while(v.size() != 1){
        vector<int> new_match;
        sort(v.begin(), v.end());
        int l = 0;
        int r = v.size() - 1;
        while(l < r){
            answ += abs(v[r] - v[l]);
            new_match.push_back(v[r]);
            l++;
            r--;
        }
        v = new_match;
    }

    cout << answ << '\n';

    return 0;
}