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
    
    int n;
    cin >> n;

    vector<bool> death(n, false);
    
    int last = -1, curr = 0;
    int flag = 0;
    while(last != curr){
        if(flag == 0 && !death[curr]){
            flag = 1;
            last = curr;
        }
        else if(flag == 1 && !death[curr]){
            flag = 0;
            death[curr] = true;
            cout << curr + 1 << " ";
        }

        curr = (curr + 1) % n;
    }
    cout << last + 1 << '\n';
    return 0;
}