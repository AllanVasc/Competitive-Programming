#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<int> production;
bool check(int time, int k){
    int product = 0;
    for(int i = 0; i < production.size(); i++){
        product += time / production[i];
        if(product >= k) return true;
    }
    return false;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n, t;
    cin >> n >> t;
    production.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> production[i];

    int left = 0;
    int right = 1e18 + 100;
    int answ = right;

    while(left <= right){
        int m = left + (right - left) / 2;

        if(check(m, t)){
            answ = m;
            right = m - 1;
        }
        else{
            left = m + 1;
        }
    }

    cout << answ << '\n';
    return 0;
}