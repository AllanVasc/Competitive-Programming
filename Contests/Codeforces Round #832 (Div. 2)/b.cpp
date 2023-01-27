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
    
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        string s;
        for(int i = 0; i < n; i++){
            s = s + "BAN";
        }

        // cout << (n + 2 - 1)/2 << '\n';
        vector<ii> answ;
        int left = 0; 
        int right = s.size() - 1;
        while(left < right){
            answ.push_back({left, right});
            left += 3;
            right -= 3;
        }

        cout << answ.size() << '\n';
        for(auto i : answ){
            cout << i.first + 1 << " " << i.second + 1 << '\n';
        }
    }
    return 0;
}