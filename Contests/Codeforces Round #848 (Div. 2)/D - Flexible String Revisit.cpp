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
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];

        bool doubleneg = false;
        int cnt1 = 0, cntneg = 0;
        for(int i = 0; i < n; i++){
            if(v[i] == 1) cnt1++;
            else if(v[i] == -1) cntneg++;
            if(i == 0) continue;
            if(v[i] == v[i - 1] && v[i] == -1) doubleneg = true;
        }

        if(doubleneg){
            cout << cnt1 + 2 - (cntneg - 2) << '\n';
        }
        else if(cntneg > 0){
            cout << cnt1 - cntneg << '\n';
        }
        else{
            cout << cnt1 - 4 << '\n';
        }
    }
    return 0;
}