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

    int n, m;
    cin >> n >> m;

    vector<int> coprimes;
    for(int i = 1; i <= m; i++){
        if(gcd(i, m) == 1) coprimes.push_back(i);
    }
    int PHI = coprimes.size();
    
    while(n--){
        int k;
        cin >> k;

        int answ = coprimes[((k % PHI) - 1 + PHI) % PHI];
        answ += (k / PHI) * m;
        if(k % PHI == 0) answ -= m;
        
        cout << answ << " ";
    }
    cout << '\n';
    
    return 0;
}