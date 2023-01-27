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
    
    int n, x;
    cin >> n >> x;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    int answ = 0;
    int l = 0;
    int r = n - 1;
    while(l <= r){
        if(v[l] + v[r] <= x){
            l++;
            r--;
            answ++;
        }
        else{
            r--;
            answ++;
        }
    }

    cout << answ << '\n';
    
    return 0;
}