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
    
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> desired(n);
    for(int i = 0; i < n; i++) cin >> desired[i];
    vector<int> sizes(m);
    for(int i = 0; i < m; i++) cin >> sizes[i];

    sort(desired.begin(), desired.end());
    sort(sizes.begin(), sizes.end());

    int answ = 0;
    int apt = 0;
    for(int i = 0; i < n; i++){
        while(apt < m && sizes[apt] < desired[i] - k) apt++;
        if(apt == m) break;
        if(abs(desired[i] - sizes[apt]) <= k){
            answ++;
            apt++;
        }
    }

    cout << answ << '\n';
    return 0;
}